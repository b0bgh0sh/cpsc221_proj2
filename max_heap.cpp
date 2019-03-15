/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions: 


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
		text_item x = top();
		data[0] = data[--numItems];
		swap_down(0);
		// Fix this so it correctly deletes
		// and maintains the heap-order property
		// required for a max-heap
		
		// returning something so it compiles:
		return x;
	}
}

void max_heap::swap_down(int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int index = i;
	if (left < numItems && data[left].freq > data[index].freq)
        index = left;
    if (right < numItems && data[right].freq > data[index].freq)
        index = right;
    if (index != i) {
        text_item temp = data[i];
		data[i] = data[index];
		data[index] = temp;
        swap_down(index);
    }
		
	// Fix this so it correctly swaps
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {
		
		
		// Fix this so it correctly inserts
		// and maintains the heap-order property
		// required for a max-heap
		if (numItems == 0) {
        data[0] = item;
        numItems++;
		}
		else {
			data[numItems] = item;
			swap_up(numItems);
			numItems++;
			}
	}
}

void max_heap::swap_up(int i) {
	int parent = (i-1)/2;
	if((i!=0) && (data[parent].freq < data[i].freq)){
		text_item temp = data[i];
		data[i] = data[parent];
		data[parent] = temp;
		swap_up(parent);
	}
		
	// Fix this so it correctly swaps
}
