#pragma once
#ifndef QUEUE_ARRAY_2019
#define QUEUEA_ARRAY_2019

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
};

#endif