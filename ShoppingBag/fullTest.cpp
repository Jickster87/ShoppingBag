#include "fullTest.h"
#include "ShoppingBag.h"
#include "ShoppingBagIterator.h"

#include <assert.h>
#include <iostream>
#include <utility>

void fullTest() {
	ShoppingBag b(10);
	assert(b.isEmpty() == true);
	assert(b.size() == 0);
	assert(b.add(5)==true);
	assert(b.add(12)==true);
	assert(b.add(5) == true);
	assert(b.add(2) == true);
	assert(b.add(15) == true);
	assert(b.add(2) == true);
	assert(b.add(11) == true);
	assert(b.add(7) == true);
	assert(b.add(2) == true);
	assert(b.add(2) == true);
	std::pair<TValue, TValue> res = b.search(10);
	std::pair<TValue, TValue> ans1(5, 2);
	std::pair<TValue, TValue> ans2(2, 4);
	assert(((res == ans1) || (res == ans2)));
}