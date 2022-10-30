ErrorCode CreateQueueC(QueueHandler* queue);
ErrorCode CloneQueueC(QueueHandler source, QueueHandler* queue);
ErrorCode DestroyQueueC(QueueHandler queue);
ErrorCode PopC(QueueHandler queue);
ErrorCode PushC(QueueHandler queue, int32_t value);
ErrorCode IsEmptyC(QueueHandler queue, int32_t* result);
ErrorCode TopC(QueueHandler queue, int32_t* result);
