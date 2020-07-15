#ifndef STACK_ARRAY_H_2019
#define STACK_ARRAY_H_2019

#pragma once
#include<memory>

class StackA {
public:
	StackA() = default;
	StackA(const StackA&);
	StackA& operator=(const StackA&);
	~StackA();
	void push(const float value);
	void pop();
	float& top();
	const float& top() const;
	bool is_empty() const;
private:
	ptrdiff_t size_{ 0 };
	ptrdiff_t capacity_{ 0 };
	float* data_{ nullptr };
};

#endif