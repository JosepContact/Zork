#include <assert.h>
#include <stdio.h>
#ifndef DYNARRAY_H
#define DYNARRAY_H


#define BLOCK 10
typedef unsigned int uint;

template<class TYPE>

class Vector{
public:
	TYPE *buffer;
	unsigned int capacity = BLOCK;
	unsigned int num_elements = 0;
public:
	virtual ~Vector(){
		if (num_elements > 0){
		//	delete[] buffer;
		}
	}
public:

	Vector()
	{
		buffer = new TYPE[capacity];
	}

	Vector(const Vector& v)
	{
		num_elements = v.num_elements;
		capacity = v.capacity;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = v.buffer[i];
		}
	}
	Vector(uint size) : capacity(size)
	{
		buffer = new TYPE[size];
	}

	Vector(const TYPE& v)
	{
		num_elements = 1;
		capacity = 2;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = v;
		}
	}
	void push_back(const TYPE & value)
	{

		if (num_elements >= capacity)
		{
			TYPE* newbuffer = new TYPE[capacity];

			for (uint i = 0; i < num_elements; i++){
				newbuffer[i] = buffer[i];
			}
			delete[] buffer;
			capacity++;
			buffer = newbuffer;
			delete[] newbuffer;
			num_elements++;
		}

		buffer[num_elements] = value;
		num_elements++;

	}
	void push_front(const TYPE value)
	{

		if (num_elements == capacity){
			capacity++;
		}

		TYPE* newbuffer = new TYPE[capacity];

		for (int i = 0; i < num_elements; i++)
		{
			newbuffer[i + 1] = buffer[i];
		}
		newbuffer[0] = value;
		delete[] buffer;
		buffer = newbuffer;
		num_elements++;
	}
	TYPE & operator[](uint value)
	{
		assert(value<num_elements);
		return buffer[value];
	}
	const TYPE & operator[](uint value)const
	{
		assert(value<num_elements);
		return buffer[value];
	}

	bool pop_back(TYPE & data){
		if (num_elements > 0){
			data = buffer[--num_elements];
			return true;
		}
		else {
			return false;
		}
	}
	void clear_at(uint pos){
		for (; pos <= num_elements; pos++){
			buffer[pos] = buffer[pos + 1];
		}
		num_elements--;
	}
	
	void clear(){
	}
};
// ADD: EMPTY / CLEAN / SIZE - AMOUNT OF ELEMENTS -  / CAPACITY - SPACE - / AT - IS THE SAME WITHOUT ASSERT / 
#endif