#pragma once
#ifndef QUEUE_ARRAY_2019
#define QUEUEA_ARRAY_2019

#include <cstddef>

class QueueL {
public:
	QueueL() = default;
	QueueL(const QueueL&);
	QueueL& operator=(const QueueL&);
	~QueueL();
	void push(const float value);
	void pop();
	float& top();
	const float& top() const;
	bool is_empty() const;
private:
	struct Node {
		float val{ 0.0 };
		Node* next{ nullptr };
		Node(const float Value = 0.0) :val(Value) {}
		Node(Node* Next, const float Value = 0.0) :val(Value), next(Next) {}
	};
	Node* tail_{ nullptr };
	Node* head_{ nullptr };
};

#endif