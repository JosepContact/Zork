#include "MyString.h"

char * String::get_word(int nword){
	char * word = new char[50];
	uint i = 0;
	uint j = 0;
	switch (nword){
	case 1:
		for (; i < (length()) || string[i] == ' '; i++){
			word[i] = string[i];
		}
		return word;
		break;
	case 2:
		for (; i < string[i] != ' '; i++);
		for (; i < string[i] != ' ' || string[i] == '\0'; i++, j++){
			word[j] = string[i];
		}
		return word;
		break;
	}
	return nullptr;
}