#include <queuel/queuel.h>
#include <stdexcept>

QueueL::QueueL(const QueueL& queuel) {
	if (!queuel.is_empty()) {
	    head_ = new Node(queuel.head_->val);
		Node* to = head_;
		Node* from = queuel.head_;
		while (from->next != nullptr) {
			from = from->next;
			to->next = new Node(from->val);
			to = to->next;
		}
		tail_ = to;
	}
}

QueueL& QueueL::operator=(const QueueL& queuel) {
	if (this != &queuel) {
		if (!queuel.is_empty()) {
			while (!is_empty()) {
				pop();
			}
			head_ = new Node(queuel.head_->val);
			Node* to = head_;
			Node* from = queuel.head_;
			while (from->next != nullptr) {
				from = from->next;
				to->next = new Node(from->val);
				to = to->next;
			}
			tail_ = to;
		}
	}
	return *this;
}

QueueL::~QueueL(){
	while (!is_empty())	{
		pop();
	}
}

void QueueL::push(const float value) {
	if (is_empty()) {
		head_ = new Node(value);
		tail_ = head_;
	}
	else {
		tail_->next = new Node(value);
		tail_ = tail_->next;
	}
}

void QueueL::pop() {
	if (!is_empty()) {
		Node* deleted = head_;
		head_ = head_->next;
		delete deleted;
	}
	if (head_ == nullptr) {
		tail_ = nullptr;
	}
}

float& QueueL::top() {
	if (is_empty()) {
		throw std::logic_error("Queuel is empty");
	}
	return head_->val;
}

const float& QueueL::top() const {
	if (is_empty()) {
		throw std::logic_error("Queuel is empty");
	}
	return head_->val;
}

bool QueueL::is_empty() const {
	return head_ == nullptr;
}
