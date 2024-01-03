#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
	//TODO - Implementation
	head = nullptr;
	length = 0;
	//header,init head and length with 0
}////Θ(1)


void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	Node* newNode = new Node;
	newNode->key = c;
	newNode->value = v;
	newNode->next = nullptr;
	//create a new node
	if (head == nullptr) {
		head = newNode;
	//check for empty
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
		//adds it to the end of the list
	}
	length++;
	//lenght increased

}//O(n)


bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	Node* currentNode = head;
	Node* previousNode = nullptr;
	while (currentNode != nullptr && currentNode->key < c) {
		previousNode = currentNode;
		currentNode = currentNode->next;
		//loop until c
	}
	if (currentNode != nullptr && currentNode->key == c && currentNode->value == v) {
		if (previousNode == nullptr) {
			head = currentNode->next;
		}
		else {
			previousNode->next = currentNode->next;
		}
		//delete the node mathching c and v
		delete currentNode;
		length--;
		return true;
	}

	// not found ret F
	return false;
}//O(n)


vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation
	vector<TValue> values;
	Node* currentNode = head;
	while (currentNode != nullptr && currentNode->key <= c) {
		if (currentNode->key == c) {
			values.push_back(currentNode->value);
		}
		currentNode = currentNode->next;
	}
	return values;
}//O(n)



int MultiMap::size() const {
	//TODO - Implementation
	return length;
}//Θ(1)



bool MultiMap::isEmpty() const {
	if (length == 0) {
		return true;
	}
	return false;
}//Θ(1)


MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	//TODO - Implementation
	//destructor
	Node* current = head;
	while (current != nullptr) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}
}//O(n)

