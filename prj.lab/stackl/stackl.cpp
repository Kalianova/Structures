#include <stackl/stackl.h>
#include <stdexcept>

StackL::StackL(const StackL& stackl){
	if (!stackl.is_empty()) {
		head_ = new Node(stackl.head_->val);
		Node* from = stackl.head_->next;
		Node* to = head_;
		while (from != nullptr) {
			to->next = new Node(from->val);
			from = from->next;
			to = to->next;
		}
	}
}

StackL& StackL::operator=(const StackL& stackl) {

	if (this != &stackl) {
		while (!is_empty()) {
			pop();
		}
		if (!stackl.is_empty()) {
			head_ = new Node(stackl.head_->val);
			Node* from = stackl.head_->next;
			Node* to = head_;
			while (from != nullptr) {
				to->next = new Node(from->val);
				from = from->next;
				to = to->next;
			}
		}
	}
	return* this;
}

StackL::~StackL() {
	while (!is_empty()) {
		pop();
	}
	delete head_;
}

void StackL::push(const float value) {
	head_ = new Node(head_, value);
}

void StackL::pop() {
	if (!is_empty()) {
		Node* deleted = head_;
		head_ = head_->next;
		delete deleted;
	}
}

float& StackL::top() {
	if (is_empty()) {
		throw std::logic_error("Stack is empty");
	}
	return head_->val;
}

const float& StackL::top() const {
	if (is_empty()) {
		throw std::logic_error("Stack is empty");
	}
	return head_->val;
}

bool StackL::is_empty() const {
	return nullptr == head_;
}

