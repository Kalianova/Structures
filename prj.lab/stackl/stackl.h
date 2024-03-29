#ifndef STACK_LIST_H_2019
#define STACK_LIST_H_2019

#pragma once
#include<memory>

class StackL {
public:
	StackL() = default;
	StackL(const StackL&);
	StackL& operator=(const StackL&);
	~StackL();
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
	Node* head_{ nullptr };
};

#endif