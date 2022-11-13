#include <cpp_manager/cpp_manager.h>

ErrorCode Manager::CreateQueue(QueueHandler* queue)
{
	if (*queue != EmptyHandler)
	{
		return ErrorCode::kHandlerError;
	}
	else
	{
		*queue = Handle;
		storage[Handle] = QueueP();
		Handle++;
		return ErrorCode::kGood;
	}
}

ErrorCode Manager::CloneQueue(QueueHandler source, QueueHandler* queue)
{

	if (*queue != EmptyHandler)
	{
		return ErrorCode::kHandlerError;
	}
	else {
		*queue = Handle;
		storage[Handle] = storage[source];
		return ErrorCode::kGood;
	}
}

ErrorCode Manager::DestroyQueue(QueueHandler queue)
{
	if (storage.find(queue) == storage.end())
	{
		return ErrorCode::kHandlerError;
	}
	else
	{
		storage.erase(storage.find(queue));
		return ErrorCode::kGood;
	}
}

ErrorCode Manager::Pop(QueueHandler queue)
{
	if (storage.find(queue) == storage.end())
	{
		return ErrorCode::kHandlerError;
	}
	else
	{
		storage[queue].pop();
		return ErrorCode::kGood;
	}
}

ErrorCode Manager::Push(QueueHandler queue, int32_t value)
{
	
	if (storage.find(queue) == storage.end())
	{
		return ErrorCode::kHandlerError;
	}
	else
	{
		storage[queue].push(value);
		return ErrorCode::kGood;
	}
}

ErrorCode Manager::IsEmpty(QueueHandler queue, int32_t* result)
{
	if (storage.find(queue) == storage.end())
	{
		return ErrorCode::kHandlerError;
	}
	else
		return ErrorCode::kGood;
	if (storage[queue].isEmpty())
		*result = 1;
	else
		*result = 0;
	
}

ErrorCode Manager::Top(QueueHandler queue, int32_t* result)
{

	if (storage.find(queue) == storage.end())
	{
		return ErrorCode::kHandlerError;
	}
	else
	{
		*result = storage[queue].top();
		return ErrorCode::kGood;
	}
}
extern "C" ErrorCode CreateQueueC(QueueHandler * queue)
{
	return manager.CreateQueue(queue);
}
extern "C" ErrorCode CloneQueueC(QueueHandler source, QueueHandler * queue)
{
	return manager.CloneQueue(source, queue);
}
extern "C" ErrorCode DestroyQueueC(QueueHandler queue)
{
	return manager.DestroyQueue(queue);
}
extern "C" ErrorCode PopC(QueueHandler queue)
{
	return manager.Pop(queue);
}
extern "C" ErrorCode PushC(QueueHandler queue, int32_t value)
{
	return manager.Push(queue, value);
}
extern "C" ErrorCode IsEmptyC(QueueHandler queue, int32_t * result)
{
	return manager.IsEmpty(queue, result);
}
extern "C" ErrorCode TopC(QueueHandler queue, int32_t * result)
{
	return manager.Top(queue, result);
