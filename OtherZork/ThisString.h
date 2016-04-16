
#include <string.h>
#include <stdio.h>
#include "DynArray.h"

#ifndef THISSTRING_H
#define THISSTRING_H

typedef unsigned int uint;

class String {
private:
	char* string;

public:
	uint capacity;
public:
	String(unsigned int mem);
	String(char* c_str1);
	String(String &str);
	String();
	virtual ~String();

public:
	int size();
	const int length();
	bool empty() const;
	void clear();
	char* c_str();

	const Vector<String> & String::Tokenize(Vector<String> & tokens){
		
		String newbuffer(length());
		int i = 0, j = 0;
		do{
			for (i, j=0; (string[i] != ' '); i++,j++){
				if (string[i] == '\n') break;
				newbuffer.string[j] = string[i];
			}
			newbuffer.string[j] = '\0';
			tokens.push_back(newbuffer);
			newbuffer.string[0] = '\0';
			i++;
		} while (string[i] != '\0');
		return tokens;
	}

	/*void String::ReverseTokenize(Vector<String> & tokens){
		uint size = 0; uint j = 0; uint count = 0;
		for (uint i = 0; i < tokens.num_elements; i++){
			size = size + strlen(tokens.buffer[i].string);
		}
		if (capacity < size){
			delete[] this->string;
			capacity = size + 1;
			string = new char[capacity];
		}
		for (uint i = 0; count < tokens.num_elements; count++){
		for (j = 0; tokens.buffer[count].string[j] != '\0'; ++i, ++j){
			string[i] = tokens.buffer[count].string[j];
		}
		string[i] = ' ';
		++i;
	}
			
	}*/

	bool String::operator==(const char* c_str) const {
		return strcmp(this->string, c_str) == 0;
	}

	bool String::operator==(const String& str) const {
		return strcmp(this->string, str.string) == 0;
	}

	const String& String::operator=(const String& str) {
		if (this->capacity < str.capacity) {
			delete[] this->string;
			capacity = strlen(str.string) + 1;
			string = new char[capacity];
		}
		strcpy_s(string, str.capacity, str.string);
		return *this;
	}

	const String& String::operator=(const char* c_str) {
		if (this->capacity != strlen(c_str) + 1) {
			delete[] this->string;
			capacity = strlen(c_str) + 1;
			string = new char[capacity];
		}
		strcpy_s(string, capacity, c_str);
		return *this;
	}
	void String::print(){
		printf("%s\n", string);
	}
};

#endif