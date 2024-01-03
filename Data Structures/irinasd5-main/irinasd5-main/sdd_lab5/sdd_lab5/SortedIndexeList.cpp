#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
	//constructor that initializes the list
	capacity = 100;
	nodes = new node[capacity];
	len = 0;
	root = -1;
	relation = r;
}

int SortedIndexedList::size() const {
	//returns len of the list for size
	return len;
}

bool SortedIndexedList::isEmpty() const {
	//len=0 => list.empty
	return len == 0;
}

TComp SortedIndexedList::getElement(int i) const{
	//return element at given index
	return nodes[i].info;
}

TComp SortedIndexedList::remove(int i) {
	//remove element at given index i
	if (i < 0 || i >= len)
		throw exception("not in range");
	int current = root;
	int parent = -1;
	//find index
	while (current != -1)
	{
		if (current == i)
			break;
		parent = current;
		if (relation(nodes[current].info, nodes[i].info))
			current = nodes[current].right;
		else
			current = nodes[current].left;
	}
	if (current == -1)//node not found in list
		throw exception();
	if (nodes[current].left == -1 && nodes[current].right == -1)
		throw exception();//node has no children
	return NULL_TCOMP;
}

int SortedIndexedList::search(TComp e) const {
	//search for index
	int current = root;
	while (current != -1)
	{
		if (nodes[current].info == e)
			return current;//element found
		if (relation(nodes[current].info, e))
			current = nodes[current].right;//go right
		else
			current = nodes[current].left;//go left
	}
	return 0;
}

void SortedIndexedList::add(TComp e) {
	//function to add e into list
	if (len == capacity - 2)//resize algorithm
	{
		capacity *= 2;
		node* newNodes = new node[capacity];//new memory allocation for e
		for (int i = 0; i < len; i++)
			newNodes[i] = nodes[i];//copy elements into new array
		delete[] nodes;//dealocate memory
		nodes = newNodes;//copy into old dealocated array
	}
	//empty(add at first position)
	if (root == -1)
	{
		nodes[0].info = e;
		len = 1;
		return;
	}
	int current = root;
	int parent = -1;
	//find pos for insertion
	while (current != -1)
	{
		parent = current;
		if (relation(nodes[current].info, e))
			current = nodes[current].right;//go right
		else
			current = nodes[current].left;//go left
	}
	//find available index
	for (int i = 0; i < capacity; i++)
	{
		if (nodes[i].info == -1)
		{
			nodes[i].info = e;//add element at index
			nodes[i].parent = parent;
			if (relation(nodes[parent].info, e))
				nodes[parent].right = i;//update right child
			else
				nodes[parent].left = i;//update left child
			len++;
			return;
		}
	}
}

ListIterator SortedIndexedList::iterator(){
	//iterator
	return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
	//deletes all nodes
	delete[] nodes;
}
