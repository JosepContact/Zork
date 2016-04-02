#include <string.h>
#include <stdio.h>

#ifndef MY_STRING_H
#define MY_STRING_H

typedef unsigned int uint;

class String{
public:
	char * string;
public:
	String::String(char * string){
		int len = length(string);
		this->string = new char[len + 1];
		strcpy_s(this->string, len + 1,  string);
	}
	uint String::length() const {
		return strlen(string);
	}
	uint String::length(const char * string) const {
		return strlen(string);
	}
	void String::operator=(const char*string){
		int len = length(string);
		if (len > length(this->string)){
			delete[] this->string;
			this->string = new char[len + 1];
			strcpy_s(this->string, len + 1, string);
		}
		else strcpy_s(this->string, len + 1, string);
	}
	bool String::operator==(char * string) const {
		return (strcmp(this->string, string) == 0);
	}
	String::~String(){
		delete[] this->string;
	}
};




#endif