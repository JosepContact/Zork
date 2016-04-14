
#ifndef DYNARRAY_H
#define DYNARRAY_H


#define BLOCK 10
template<class TYPE>

class Vector{
public:
	TYPE *buffer;
	unsigned int capacity = BLOCK;
	unsigned int num_elements = 0;
public:
	Vector(){
		buffer = new TYPE[capacity];
	}

	Vector(const Vector& v){
		num_elements = v.num_elements;
		capacity = v.capacity;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = v.buffer[i];
		}
	}
	Vector(const TYPE& v){
		num_elements = 1;
		capacity = 2;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = v;
		}
	}
	void push_back(const TYPE value){

		if (num_elements == capacity){
			TYPE* newbuffer = new TYPE[capacity + 1];

			for (int i = 0; i < num_elements; i++){
				newbuffer[i] = buffer[i];
			}
			delete[] buffer;
			capacity++;
			buffer = newbuffer;
		}

		buffer[num_elements] = value;
		num_elements++;

	}
	void push_front(const TYPE value){

		if (num_elements == capacity){
			capacity++;
		}

		TYPE* newbuffer = new TYPE[capacity];

		for (int i = 0; i < num_elements; i++){
			newbuffer[i + 1] = buffer[i];
		}
		newbuffer[0] = value;
		delete[] buffer;
		buffer = newbuffer;
		num_elements++;


	}
	TYPE operator[](int value)const{
		return buffer[value];

	}
};

#endif