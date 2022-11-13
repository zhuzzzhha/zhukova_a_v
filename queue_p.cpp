// PriorityQueue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#ifndef QUEUEP_QUEUEP_H
#define QUEUEP_QUEUEP_H
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include<queue_p/queue_p.h>
void QueueP::push(const int& value)
{
	if (this->head.get() == nullptr)
	{
		std::unique_ptr<Node> new_value = std::make_unique<Node>();
		new_value->data = value;
		new_value->next = nullptr;
		head = std::move(new_value);
	}
	else {
		Node* prev = head.get();
		while (prev->next != nullptr && value <= prev->next->data)
		{
			prev = (prev->next).get();
		}
		std::unique_ptr<Node> new_value = std::make_unique<Node>();
		new_value->data = value;
		new_value->next = std::move(prev->next);
		prev->next = std::move(new_value);
	}
}
void QueueP::pop() noexcept
{
	head = std::move(head->next);
}
const int& QueueP::top() const

{
	return head->data;
}
bool QueueP::operator==(const QueueP& rhs) const
{
	Node* left = head.get();
	Node* right = rhs.head.get();
	while (left != nullptr && right != nullptr)
	{
		if (left->data != right->data)
			return false;
		left = (left->next).get();
		right = (right->next).get();

	}
	return true;
}
bool QueueP::isEmpty() noexcept
{
	if (this->head == nullptr)
		return true;
	else
		return false;
}



#endif
