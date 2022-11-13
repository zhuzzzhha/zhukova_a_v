#include<queue_p/queue_p.h>
#include<c_queue_p/c_queue_p.h>
#include <iostream>
#include<unordered_map>
class Manager
{
	std::unordered_map<QueueHandler, QueueP> storage;
	Manager() = default;
	~Manager() = default;

	ErrorCode CreateQueue(QueueHandler* queue);
	ErrorCode CloneQueue(QueueHandler source, QueueHandler* queue);
	ErrorCode DestroyQueue(QueueHandler queue);
	ErrorCode Pop(QueueHandler queue);
	ErrorCode Push(QueueHandler queue, int32_t value);
	ErrorCode IsEmpty(QueueHandler queue, int32_t* result);
	ErrorCode Top(QueueHandler queue, int32_t* result);

};
static Manager manager;
