#pragma once
#ifndef QUEUE_ARRAY_2019
#define QUEUEA_ARRAY_2019

#include <cstddef>

class QueueA {
public:
	QueueA() = default;
	QueueA(const QueueA&);
	QueueA& operator=(const QueueA&);
	~QueueA();
	void push(const float value);
	void pop();
	float& top();
	const float& top() const;
	bool is_empty() const;
private:
	std::ptrdiff_t capacity_;
	std::ptrdiff_t head_{ -1 };
	std::ptrdiff_t tail_{ -1 };
	float* data_{ nullptr };
};

#endif