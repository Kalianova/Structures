#include <queuea/queuea.h>
#include <stdexcept>

QueueA::QueueA(const QueueA& queuea) {
	if (!queuea.is_empty()) {
		head_ = 0;
		if (queuea.head_ <= queuea.tail_) {
			capacity_ = queuea.tail_ - queuea.head_ + 1;
			data_ = new float[capacity_] {0.0f};
			tail_ = capacity_ - 1;
			std::copy(queuea.data_ + queuea.head_, queuea.data_ + queuea.tail_ + 1, data_);
		}
		else {
			capacity_ = queuea.capacity_ - queuea.head_ + queuea.tail_ + 1;
			data_ = new float[capacity_] {0.0f};
			tail_ = capacity_ - 1;
			std::copy(queuea.data_ + queuea.head_, queuea.data_ + queuea.capacity_ + 1, data_);
			std::copy(queuea.data_, queuea.data_ + queuea.tail_ + 1, data_ + queuea.capacity_ - queuea.head_);
		}
	}
}

QueueA& QueueA::operator=(const QueueA& queuea) {
	if (this != &queuea) {
		delete[] data_;
		if (!queuea.is_empty()) {
			head_ = 0;
			*this = QueueA(queuea);
		}
		else {
			head_ = -1;
			tail_ = -1;
		}
	}
	return *this;
}

QueueA::~QueueA(){
	delete[] data_;
}

void QueueA::push(const float value) {
	if (is_empty()) {
		if (capacity_ = 0) {
			capacity_ = 2;
			data_ = new float[capacity_] {0.0f};
		}
		head_ = 0;
		tail_ = 0;
	}
	else {
		std::ptrdiff_t new_tail_ = (tail_ + 1) % capacity_;
		if (new_tail_ == head_) {
			std::ptrdiff_t new_capacity_ = capacity_ * 2;
			float* new_data_ = new float[capacity_];
			if (head_ <= tail_) {
				std::copy(data_ + head_, data_ + tail_ + 1, new_data_);
			}
			else {
				std::copy(data_ + head_, data_ + capacity_ + 1, new_data_);
				std::copy(data_, data_ + tail_ + 1, new_data_ + capacity_ - head_);
			}
			std::swap(data_, new_data_);
			delete[] new_data_;
			capacity_ = new_capacity_;
			new_tail_++;
		}
		tail_ = new_tail_;
	}
	data_[tail_] = value;
}

void QueueA::pop() {
	if (!is_empty()) {
		if (head_ != tail_) {
			head_--;
		}
		else {
			head_ = -1;
			tail_ = -1;
		}
	}
}

float& QueueA::top() {
	if (is_empty()) {
		throw std::logic_error("Queuea is empty");
	}
	return data_[head_];
}

const float& QueueA::top() const {
	if (is_empty()) {
		throw std::logic_error("Queuea is empty");
	}
	return data_[head_];
}

bool QueueA::is_empty() const {
	return head_ < 0;
}