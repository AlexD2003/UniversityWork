#include "MultiMapIterator.h"
#include "MultiMap.h"

//constructor
MultiMapIterator::MultiMapIterator(const MultiMap& c) : col(c), current(c.head) {}
//Θ(1)
bool MultiMapIterator::valid() const {
	//check if current node is not null
	return current != nullptr;
	return false;
}//Θ(1)

TElem MultiMapIterator::getCurrent() const {
	//return current value or throw exeption otherwise
	if (!valid()) {
		throw std::exception("Invalid iterator");
	}

	return TElem(current->key, current->value);
}//Θ(1)

void MultiMapIterator::next() {
	//moves to the next node
	if (!valid()) {
		throw std::exception("Invalid iterator");
	}

	current = current->next;
}//Θ(1)

void MultiMapIterator::first() {
	//sets current node to head of the list
	current = col.head;
}//Θ(1)

