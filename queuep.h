
#pragma once
#ifndef QUEUEP_QUEUEP_H_051022
#define QUEUEP_QUEUEP_H_051022
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
struct Queue {
private:
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
public:
	~Queue()
	{
		while (head)
			head = std::move(head->next);
	}
	Queue() :head() {};
	Queue(const Queue& copy) = default;
	void push(const int value)
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
			while (prev->next!=nullptr && value <= prev->next->data)
			{
				prev = (prev->next).get();
			}
			std::unique_ptr<Node> new_value = std::make_unique<Node>();
			new_value->data = value;
			new_value->next = std::move(prev->next);
			prev->next = std::move(new_value);
		}
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
	Queue& Queue::operator=(const Queue& rhs) {
		*this = rhs;
		return *this;
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

