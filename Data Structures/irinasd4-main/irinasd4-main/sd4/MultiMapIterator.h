#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& col;
	//TODO - Representation
	int currentPosition;
	const MultiMap& multiMap;

public:
	//DO NOT CHANGE THIS PART
	MultiMapIterator(const MultiMap& c);
	TElem getCurrent()const;
	bool valid() const;
	void next();
	void first();
};

