#pragma once
#include <utility>
#include <exception>

using namespace std;

//typedef int TKey;
typedef int TValue;
typedef int TFreq;
typedef std::pair<TValue, TFreq> TElem;
typedef std::pair<TValue, TValue> ValuePair;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TValue, TFreq>(-111111, -111111)
class ShoppingBagIterator;

class ShoppingBag {

	friend class ShoppingBagIterator;

	private:
		TElem* elements; //why pointer?
		int arrayCapacity;
		int sizeBag;

	public:
		//constructor
		ShoppingBag(int arrayCapacity);
		
		//destructor
		~ShoppingBag();

		//add something to the bag
		bool add(TValue v);
			
		//remove something from the bag
		bool remove(TValue v);
		//remove all occurences of TVal from the bag
		bool remove_all(TValue v);

		//search for value and show frequency
		ValuePair search(TValue v) const;

		//what is the bag Size
		int size() const;

		//is the bag Empty
		bool isEmpty() const;
		
		//is the bag Full
		bool isFull() const;

		//iterator
		ShoppingBagIterator iterator() const;	
};