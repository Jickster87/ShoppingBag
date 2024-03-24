#include "ShoppingBag.h"
#include "ShoppingBagIterator.h"
#include <exception>
using namespace std;

ShoppingBagIterator::ShoppingBagIterator(const ShoppingBag& b) : bag(b) {
	this->currentPosition = 0;
}

void ShoppingBagIterator::first() {
	this->currentPosition = 0;
}

void ShoppingBagIterator::next() {
	if (this->currentPosition == this->bag.sizeBag) {
		throw exception();
	}
	this->currentPosition++;
}

TElem ShoppingBagIterator::getCurrent() {
	if (this->currentPosition == this->bag.sizeBag) {
		throw exception();
	}
	return this->bag.elements[this->currentPosition];
}

bool ShoppingBagIterator::valid() const {
	return this->currentPosition < this->bag.sizeBag;
}