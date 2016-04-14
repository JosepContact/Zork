/*
String::Tokenize(" ", Vector<String>& tokens);
Tokenize transforms the string written by the player into a vector of words that has no " ". This way you can return the word in each position like [0] or [1];
*/

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
	int GetnArgs();

	const Vector<String> & String::Tokenize(Vector<String>& tokens){
		//transform the string stored in string into a vector string


	}
	bool String::operator==(const char* c_str) const {
		return strcmp(this->string, c_str) == 0;
	}

	bool String::operator==(const String& str) const {
		return strcmp(this->string, str.string) == 0;
	}

	const String& String::operator=(const String& str) {
		if (this->capacity != str.capacity) {
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