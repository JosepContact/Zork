#include <string.h>
#include <stdio.h>

#ifndef THISSTRING_H
#define THISSTRING_H

typedef unsigned int uint;

class String{
public:
	char * string;
	uint memory;
	uint space;
public:
	char * String::returns(){
		return string;
	}
	char * String::get_word(int &nword){
		char * word;
		uint i = 0, j = 0;
		switch (nword){
		case 1:
			break;
		case 2:
			while (string[i] != ' '){
				i++;
			}
			word = new char[memory - i];
			i++;
			for (; i <= (memory-3) ; i++, j++){
				word[j] = string[i];
			}
			word[j] = '\0';
			return word;
			break;
		}
	}
	String::String(){
		space = 3;
		memory = space + 1;
		string = new char;
	}
	String::String(const char * string){
		space = strlen(string);
		memory = space + 1;
		this->string = new char[memory];
		strcpy_s(this->string, memory, string);
	}
	uint String::length() const {
		return strlen(string);
	}
	void String::operator=(const String & string){
		int len = string.length();
		if (len > length()){
			delete[] this->string;
			space = len;
			memory = len + 1;
			this->string = new char[memory];
			strcpy_s(this->string, memory, string.string);
		}
		else strcpy_s(this->string, len + 1, string.string);
	}
	void String::operator=(const char*string){
		int len = strlen(string);
		if (len > length()){
			delete[] this->string;
			space = len;
			memory = len + 1;
			this->string = new char[memory];
			strcpy_s(this->string, memory, string);
		}
		else strcpy_s(this->string, len + 1, string);
	}
	
	bool String::operator==(char * string) const {
		return (strcmp(this->string, string) == 0);
	}
	String::~String(){
		delete[] string;
	}
};




#endif

