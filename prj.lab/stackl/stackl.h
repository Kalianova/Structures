#ifndef STACK_LIST_H_2019
#define STACK_LIST_H_2019

#pragma once


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
};


#endif