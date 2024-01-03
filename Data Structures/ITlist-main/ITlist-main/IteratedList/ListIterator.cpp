#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

//constructor
ListIterator::ListIterator(const IteratedList& list) : list(list),current(list.head) {}

void ListIterator::first() {
	current = list.head;
}

void ListIterator::next() {
	if (!valid()) {
		throw std::exception("Invalid iterator!");
	}
	current = current->next;
}

bool ListIterator::valid() const {
	if (current == nullptr)
		return false;
	else
	return  true;
}

TElem ListIterator::getCurrent() const {
	if (!valid()) {
		throw std::exception("Invalid iterator!");
	}
	return current->data;
}



