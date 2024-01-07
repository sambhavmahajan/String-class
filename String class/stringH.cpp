#include "stringH.h"

#include <iostream>

namespace customstring {
	string::string() value(nullptr), size(0) {}
	string::string(const char* s)
	{
		string();
		while (s[size] != '\0')
		{
			size++;
		}
		value = new char[size + 1];
		value[size] = '\0';
		for (size_t i = 0; i < size; i++)
		{
			value[size] = s[i];
		}
	}
	string::~string()
	{
		delete[] value;
	}
}