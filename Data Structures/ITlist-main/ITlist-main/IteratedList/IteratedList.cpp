
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList() {
	head = nullptr;
	length = 0;
}

int IteratedList::size() const {
	return length;
}

bool IteratedList::isEmpty() const {
	if (length != 0)
		return true;
	else
	return false;
}

ListIterator IteratedList::first() const {
	return ListIterator(*this);
}

TElem IteratedList::getElement(ListIterator pos) const {
	if (pos.valid() != true) {
		throw std::exception("Invalid iterator!");
	}
	else {
		return pos.getCurrent();
	}
}

TElem IteratedList::remove(ListIterator& pos) {
	//TODO - Implementation
	return NULL_TELEM;
}

ListIterator IteratedList::search(TElem e) const{
	//TODO - Implementation
	return ListIterator(*this);	
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
	if (pos.valid() != true) {
		throw std::exception("Invalid iterator!");
	}
	else {
		TElem oldData = pos.getCurrent();
		Node* current = pos.current;
		current->data = e;
		return oldData;

	}
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    //TODO - Implementation
}

void IteratedList::addToEnd(TElem e) {
	Node* newNode = new Node{ e, nullptr };
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	length++;
}

IteratedList::~IteratedList() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	length = 0;
}

