#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	first();//initialize on first
}

void SMIterator::first(){
    if (map.root == -1) {
		//empty tree <=>set curindex on -1
        currentIndex = -1;
        return;
    }

    currentIndex = map.root;
    while (map.elements[currentIndex].left != -1) {
        currentIndex = map.elements[currentIndex].left;
		//go left to find the smallest key
    }
}

void SMIterator::next(){
	if (!valid()) {
		throw std::exception("Invalid!");
	}

	if (map.elements[currentIndex].right != -1) {
		currentIndex = map.elements[currentIndex].right;
		while (map.elements[currentIndex].left != -1) {
			currentIndex = map.elements[currentIndex].left;
			//if there is a right subtree,move to the first left node of that subtree
		}
	}
	else {
		int parentNode = map.elements[currentIndex].parent;
		while (parentNode != -1 && currentIndex == map.elements[parentNode].right) {
			currentIndex = parentNode;
			parentNode = map.elements[parentNode].parent;
			//go up until u find the first ancestor that is a left child
		}
		currentIndex = parentNode;
	}
}

bool SMIterator::valid() const{
    return currentIndex != -1;
	return false;
}

TElem SMIterator::getCurrent() const{
	if (!valid()) {
		throw std::exception("Invalid!");
	}

	return std::make_pair(map.elements[currentIndex].key, map.elements[currentIndex].value);
}


