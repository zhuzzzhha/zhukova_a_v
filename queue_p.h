
#pragma once
#ifndef QUEUEP_QUEUEP_H_051022
#define QUEUEP_QUEUEP_H_051022
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
struct QueueP {
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
	~QueueP()
	{
		while (head)
			head = std::move(head->next);
	}
	QueueP() :head() {};
	QueueP(QueueP&&) noexcept = default;
	QueueP(const QueueP& copy) = default;
	void push(const int& value);
	void pop() noexcept;
	const int& top() const;
	bool operator==(const QueueP& rhs) const;
	QueueP& operator=(const QueueP& rhs)=default;
	QueueP& operator=(QueueP&& other) = default;
	
};



#endif
