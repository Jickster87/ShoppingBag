#pragma once
#include "ShoppingBag.h"

class ShoppingBagIterator {

	friend class ShoppingBag;
	
	private:
		const ShoppingBag& bag;
		int currentPosition = 0; // do i need this ?
		ShoppingBagIterator(const ShoppingBag& b);

	public:
		void first();
		void next();
		TElem getCurrent();
		bool valid() const;
			
};