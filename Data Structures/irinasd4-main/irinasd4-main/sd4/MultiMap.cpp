#include "MultiMap.h"
#include "MultiMapIterator.h"

MultiMap::MultiMap() {
    //constructor
    capacity = 8;
    hashtable = new Node[capacity]();
    size = 0;
}

MultiMap::~MultiMap() {
    //destructor,deletes hashtable
    delete[] hashtable;
}

int MultiMap::hash(TKey key) const {
    return abs(key) % capacity;
}

int MultiMap::getNextPosition(int position, int i) const {
    return (position + i * i) % capacity;
}

void MultiMap::resize() {
    //resize of multimap
    int oldCapacity = capacity;
    Node* oldHashtable = hashtable;

    capacity *= 2;
    hashtable = new Node[capacity]();

    for (int i = 0; i < oldCapacity; i++) {
        if (oldHashtable[i].valid) {
            int position = hash(oldHashtable[i].element.first);
            int j = 0;
            while (hashtable[getNextPosition(position, j)].valid) {
                j++;
            }
            hashtable[getNextPosition(position, j)] = oldHashtable[i];
        }
    }

    delete[] oldHashtable;//delete old hashtable
}

void MultiMap::add(TKey key, TValue value) {
    if (size >= capacity / 2) {
        resize();
    }

    int position = hash(key);
    int i = 0;
    while (hashtable[getNextPosition(position, i)].valid) {
        if (hashtable[getNextPosition(position, i)].element == std::make_pair(key, value)) {
            return;  // already exists
        }
        i++;
    }

    hashtable[getNextPosition(position, i)].element = std::make_pair(key, value);
    hashtable[getNextPosition(position, i)].valid = true;
    size++;
}

bool MultiMap::remove(TKey key, TValue value) {
    //remove based on key and value
    int position = hash(key);
    int i = 0;
    while (hashtable[getNextPosition(position, i)].valid) {
        if (hashtable[getNextPosition(position, i)].element == std::make_pair(key, value)) {
            hashtable[getNextPosition(position, i)].valid = false;
            size--;
            return true;  // removed successfully
        }
        i++;
    }

    return false;  // not found
}

int MultiMap::getSize() const {
    //ret size
    return size;
}

bool MultiMap::isEmpty() const {
    //size=0 =>empty
    return size == 0;
}

MultiMapIterator MultiMap::iterator() const {
    return MultiMapIterator(*this);
}