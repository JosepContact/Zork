#include "thisstring.h"
#include <assert.h>

String::String(unsigned int mem) {
	string = new char[mem + 1];
	string[mem] = '\0';
}

String::String(){
	string = nullptr;
}

String::String(char* c_str) {
	assert(c_str != nullptr);
	this->capacity = strlen(c_str) + 1;
	this->string = new char[capacity];
	strcpy_s(this->string, capacity, c_str);
}

String::String(String& str){
	assert(str.string != nullptr);
	capacity = strlen(str.string) + 1;
	string = new char[capacity];
	strcpy_s(this->string, capacity, str.string);
}

int String::size() {
	return sizeof(string) / sizeof(string[0]);
}

const int String::length() {
	return strlen(this->string);
}

bool String::empty() const {
	return string[0] == '\0';
}

void String::clear() {
	delete[] string;
}

char* String::c_str() {
	return string;
}

String::~String() {
	delete[] string;
};