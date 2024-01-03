#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;
//constructor
SortedMap::SortedMap(Relation r) {
	capacity = 10;
	elements = new Node[capacity];
	count = 0;
	root = -1;
	relation = r;
	firstEmpty = 0;
}//Θ(1)

void SortedMap::resizeDynamicArray() {
	//resize algorithm
	Node* newElements = new Node[2 * capacity];
	for (int i = 0; i < capacity; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
	capacity *= 2;
}//O(n),Θ(n)

TValue SortedMap::add(TKey key, TValue value) {
	if (count == capacity)
		resizeDynamicArray();
	//resize if at capacity
	if (root == -1) {
		//if empty,create a new node as root
		elements[firstEmpty].key = key;
		elements[firstEmpty].value = value;
		elements[firstEmpty].left = elements[firstEmpty].right = elements[firstEmpty].parent = -1;
		root = firstEmpty;
		count++;
		firstEmpty++;
		return NULL_TVALUE;
	}
	else {
		int currentNode = root;
		int parentNode = -1;
		//search for the key in the tree
		while (currentNode != -1 && elements[currentNode].key != key) {
			parentNode = currentNode;
			if (relation(key, elements[currentNode].key))
				currentNode = elements[currentNode].left;
			else
				currentNode = elements[currentNode].right;
		}
		//if the key already exists,update and return old
		if (currentNode != -1) {
			TValue oldValue = elements[currentNode].value;
			elements[currentNode].value = value;
			return oldValue;
		}
		else {
			//if key doesnt exists,create a new node and insert into tree
			elements[firstEmpty].key = key;
			elements[firstEmpty].value = value;
			elements[firstEmpty].left = elements[firstEmpty].right = -1;
			elements[firstEmpty].parent = parentNode;

			if (relation(key, elements[parentNode].key))
				elements[parentNode].left = firstEmpty;
			else
				elements[parentNode].right = firstEmpty;
			count++;
			firstEmpty++;
			return NULL_TVALUE;
		}
	}
}
//O(n)//degenerate tree(when every parent node has 1 child node),Θ(logn)
TValue SortedMap::search(TKey key) const {
	int currentNode = root;
	//search for key in tree
	while (currentNode != -1 && elements[currentNode].key != key) {
		if (relation(key, elements[currentNode].key))
			currentNode = elements[currentNode].left;
		else
			currentNode = elements[currentNode].right;
	}

	//if found return it,null otherwise
	if (currentNode != -1)
		return elements[currentNode].value;
	else
		return NULL_TVALUE;
}
//O(logn),Θ(logn)
TValue SortedMap::remove(TKey key) {
	int currentNode = root;
	int parentNode = -1;
	//search for the key in the tree
	while (currentNode != -1 && elements[currentNode].key != key) {
		parentNode = currentNode;
		if (relation(key, elements[currentNode].key))
			currentNode = elements[currentNode].left;
		else
			currentNode = elements[currentNode].right;
	}
	//ret null if not found
	if (currentNode == -1)
		return NULL_TVALUE;
	TValue removedValue = elements[currentNode].value;
	//remove the node from the tree based on its children
	if (elements[currentNode].left == -1 && elements[currentNode].right == -1) {
		//case:No children
		if (parentNode == -1)
			root = -1;
		else if (elements[parentNode].left == currentNode)
			elements[parentNode].left = -1;
		else
			elements[parentNode].right = -1;
	}
	else if (elements[currentNode].left == -1) {
		//case:Only right child
		int childNode = elements[currentNode].right;
		if (parentNode == -1)
			root = childNode;
		else if (elements[parentNode].left == currentNode)
			elements[parentNode].left = childNode;
		else
			elements[parentNode].right = childNode;
		//update the parent ref of the child node
		elements[childNode].parent = parentNode;
	}
	else if (elements[currentNode].right == -1) {
		//case:Only left child
		int childNode = elements[currentNode].left;
		if (parentNode == -1)
			root = childNode;
		else if (elements[parentNode].left == currentNode)
			elements[parentNode].left = childNode;
		else
			elements[parentNode].right = childNode;
		//update the parent reference of the child node
		elements[childNode].parent = parentNode;
	}
	else {
		//case:Both children
		int successorNode = elements[currentNode].right;
		int successorParentNode = currentNode;
		//find smallest key in the right subtree
		while (elements[successorNode].left != -1) {
			successorParentNode = successorNode;
			successorNode = elements[successorNode].left;
		}
		if (successorParentNode != currentNode) {
			elements[successorParentNode].left = elements[successorNode].right;
			if (elements[successorNode].right != -1)
				elements[elements[successorNode].right].parent = successorParentNode;
		}
		else {
			elements[currentNode].right = elements[successorNode].right;
			if (elements[successorNode].right != -1)
				elements[elements[successorNode].right].parent = currentNode;
		}
		//replace node key and value with successor key and value
		elements[currentNode].key = elements[successorNode].key;
		elements[currentNode].value = elements[successorNode].value;
	}
	//reset
	elements[currentNode].key = NULL_TPAIR.first;
	elements[currentNode].value = NULL_TPAIR.second;
	elements[currentNode].left = elements[currentNode].right = -1;
	elements[currentNode].parent = -1;
	//decrease size
	count--;
	return removedValue;
}

int SortedMap::size() const {
	//return count
	return count;
	return 0;
}
//Θ(1)
bool SortedMap::isEmpty() const {
	return count == 0;
	return false;
}//Θ(1)

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}//Θ(1)

SortedMap::~SortedMap() {
	delete[] elements;
}
