#include <stackl/stackl.h>
#include <stdexcept>

StackL::StackL(const StackL& stackl){
	head_ = stackl.head_;
}
StackL& StackL::operator=(const StackL& stackl) {
	head_ = stackl.head_;
	return* this;
}
StackL::~StackL() {
	while (!is_empty()) {
		pop();
	}
	delete head_;
}
void StackL::push(const float value) {
	head_ = new Node{ value, head_ };
}
void StackL::pop() {
	if (is_empty()) {
		Node* deleted = head_;
		head_ = head_->next;
		delete deleted;
	}
}
float& StackL::top() {
	if (is_empty) {
		throw std::logic_error("Stack is empty");
	}
	return head_->val;
}
const float& StackL::top() const {
	if (is_empty) {
		throw std::logic_error("Stack is empty");
	}
	return head_->val;
}
bool StackL::is_empty() const {
	return nullptr == head_;
}

