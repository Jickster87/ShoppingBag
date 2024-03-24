#include "ShoppingBag.h"
#include "ShoppingBagIterator.h"


ShoppingBag::ShoppingBag(int arrayCapacity) {
	if (arrayCapacity == 0) {
		throw exception();
	}
	this->arrayCapacity = arrayCapacity;
	this->sizeBag = 0;
	this->elements = new TElem[arrayCapacity];
}

ShoppingBag::~ShoppingBag() {
	delete[] this->elements;
}

bool ShoppingBag::add(TValue v) {
	if (this->sizeBag == this->arrayCapacity) {
		throw exception();
	}
	this->elements[this->sizeBag].first = v;
	this->sizeBag++;
	return true;
	
}

// this removes one of the occurences ? need another func to remove all occurences of TVal
bool ShoppingBag::remove(TValue v) {
	if (isEmpty()) {
		//bag is empty
		return false;
	}

	int index = 0;
	while (index < this->sizeBag)
	{
		if (this->elements[index].first == v) {
			//switch the element you want to remove with last in array
			this->elements[index] = this->elements[this->sizeBag - 1];
			//with the element switched and at the end of the array just delete last array spot
			this->sizeBag--;
			return true;
		}
		index++;
	}
	//element not in the list
	return false;
}

bool ShoppingBag::remove_all(TValue v) {

	if (isEmpty()) {
		//bag is empty
		return false;
	}

	int index = 0;
	bool removed_anything = false; // don't know if this trick is any good ???

	while (index < this->sizeBag) {
		if (this->elements[index].first == v) {
			this->elements[index] = this->elements[this->sizeBag - 1];
			this->sizeBag--;
			removed_anything = true;
		}
		else {
			index++;
		}
	}
	return removed_anything; // ???
}

ValuePair ShoppingBag::search(TValue v) const {
	ValuePair result;
	result.first = NULL_TVALUE; //search this value and
	result.second = 0; //count frequency with this
	int index = 0;
	while (index < this->sizeBag)
	{
		if (this->elements[index].first == v) {
			result.first = v;
			result.second++;
		}
		index++;
	}
	return result;
}

int ShoppingBag::size() const {
	return this->sizeBag;
}

bool ShoppingBag::isEmpty() const {
	return this->sizeBag == 0;
}

bool ShoppingBag::isFull() const {
	return this->sizeBag == this->arrayCapacity;
}

ShoppingBagIterator ShoppingBag::iterator() const {
	return ShoppingBagIterator(*this);
}