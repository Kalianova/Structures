#include <stacka/stacka.h>
#include <stdexcept>

StackA::StackA(const StackA& stacka)
:size_(stacka.size_),capacity_(stacka.capacity_)
{
	capacity_ = stacka.capacity_;
	size_ = stacka.size_;
	data_ = new float[capacity_];
	std::copy(stacka.data_, stacka.data_ + size_, data_);
}

StackA& StackA::operator=(const StackA& stacka) {

	if (this != &stacka) {
		delete[] data_;
		capacity_ = stacka.capacity_;
		size_ = stacka.size_;
		data_ = new float[capacity_];
		std::copy(stacka.data_, stacka.data_ + size_, data_);
	}

	return* this;
}

StackA::~StackA() {
	delete[] data_;
}

void StackA::push(const float value) {
	if (capacity_ == size_) {
		float* newData = new float[capacity_ * 2];
		for (size_t i = 0; i < size_; i++) {
			newData[i] = data_[i];
		}
		delete[] data_;
		data_ = newData;
		capacity_ = capacity_ * 2;
	}
	if (capacity_ == 0) {
		capacity_ = 1;
		data_ = new float[capacity_];
	}
	data_[size_] = value;
	size_++;
}

void StackA::pop() {
	if (!is_empty()) {
		size_--;
	}
}

float& StackA::top() {
	if (is_empty()) {
		throw std::logic_error("Stack is empty");
	}
	return data_[size_ - 1];
}

const float& StackA::top() const {
	if (is_empty()) {
		throw std::logic_error("Stack is empty");
	}
	return data_[size_ - 1];
}

bool StackA::is_empty() const {
	return size_ == 0;
}

