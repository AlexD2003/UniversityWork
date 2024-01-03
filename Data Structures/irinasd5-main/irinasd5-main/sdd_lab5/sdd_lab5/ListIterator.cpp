#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	//set iterator to the first elem	
	first();
}

void ListIterator::first(){
	int min = list.nodes[list.root].info;//initialize min
	int current = list.root;//start from root
	//go to the most left leaf
	while (current != -1)
	{
		if (list.nodes[current].info < min)
			min = list.nodes[current].info;//update min
		current = list.nodes[current].left;//go left
	}
	current = list.root;//reset to current node
	while (current != -1)
	{
		if (list.nodes[current].info < min)
			min = list.nodes[current].info;//update min value
		current = list.nodes[current].right;//go right
	}
}

void ListIterator::next(){
	//move iterator to next element
	current = list.nodes[current].right;//go right
	if (current == -1)
	{
		int parent = list.nodes[current].parent;//get parent
		while (parent != -1 && list.nodes[parent].right == current)
		{
			current = parent;//move up parent node
			parent = list.nodes[current].parent;//update parent	
		}
		current = parent;// set the current node to the found ancestor node
	}
	else
	{
		if (list.nodes[current].left != -1)
			current = list.nodes[current].left;//go left
		else
			current = list.nodes[current].right;//go right
	}

}

bool ListIterator::valid() const {
	// Check if the iterator is valid
	return 1;
}



