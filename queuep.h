
#pragma once
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
struct Queue {
	struct Node {
		int data;
		std::unique_ptr <Node> next;
		Node() :
			data(0),
			next(nullptr)
		{}
		Node(int value) :
			data(value),
			next(nullptr)
		{}
	};
	std::unique_ptr<Node> head;
	~Queue()
	{
		while (head)
			head = std::move(head->next);
	}
	Queue() = default;
	Queue(const std::vector<int>& v)
	{

		for (int i = 0; i < v.size(); i++)
		{
			push(v[i]);
		}
	}
	Queue(const Queue& copy) = default;
	void push(int value)
	{
		Node* prev = head.get();
		while (value >= prev->next->data && prev->next != nullptr)
		{
			prev = (prev->next).get();
		}
		std::unique_ptr<Node> new_value=std::make_unique<Node>();
		new_value->data = value;
		new_value->next = std::move(prev->next);
		prev->next = std::move(new_value);

	}
	void pop()
	{
		head = std::move(head->next);
	}
	int top()
	{
		return head->data;
	}
	bool operator==(const Queue& rhs) const
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
	/*std::ostream& operator<<(std::ostream& ostream, const Queue& temp)
	{
			while (temp->next != nullptr)
			{
				ostream << temp.top()<<' ';
				temp.pop();
			}
		return ostream;
	}
	std::istream& operator>>(std::istream& istream, Queue& temp)
	{
		std::vector<int> c;
		for (int i = 0; i < c.size(); i++)
		{
			istream >> c[i];
			temp.push(c[i]);
		}
		return istream;
	}*/
};
std::ostream& operator<<(std::ostream& ostrm, const Queue& rhs);

std::istream& operator>>(std::istream& istrm, Queue& rhs);



#endif
