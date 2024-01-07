#include "stringH.h"

#include <iostream>

namespace customstring {
	size_t len(const char* s)
	{
		size_t i = 0;
		while (s[i] != '\0')
		{
			i++;
		}
		return i;
	}

	string::string() value(nullptr), size(0) {}
	string::string(const char* s) value(nullptr), size(len(s))
	{
		value = new char[size + 1];
		value[size] = '\0';
		for (size_t i = 0; i < size; i++)
		{
			value[i] = s[i];
		}
	}
	string::~string()
	{
		delete[] value;
	}
	size_t string::Size() const
	{
		return size;
	}
	const char* string::cStr() const
	{
		return value;
	}
	const char string::at(size_t index) const {
		return value[index];
	}
	string string::operator+(const string& a, const string& b) const
	{
		size_t l = a.Size() + b.Size();
		char s[l + 1];
		s[l] = '\0';
		size_t i;
		for (i = 0; i < a.Size(); i++)
		{
			s[i] = a.at(i);
		}
		for (size_t j = 1; j - 1 < b.size; j++)
		{
			s[i + j] = b.at(j - 1);
		}
		string r{ s };
		return r;
	}
	string string::operator+(const string& a, const char* b) const
	{
		size_t l = a.Size() + len(b);
		char s[l + 1];
		s[l] = '\0';
		size_t i;
		for (i = 0; i < a.Size(); i++)
		{
			s[i] = a.at(i);
		}
		for (size_t j = 1; j - 1 < b.size; j++)
		{
			s[i + j] = b[j - 1];
		}
		string r{ s };
		return r;
	}
	string string::operator+(const char* b,const string& a) const
	{
		size_t l = a.Size() + len(b);
		char s[l + 1];
		s[l] = '\0';
		size_t i;
		for (i = 0; i < a.Size(); i++)
		{
			s[i] = a.at(i);
		}
		for (size_t j = 1; j - 1 < b.size; j++)
		{
			s[i + j] = b[j - 1];
		}
		string r{ s };
		return r;
	}
	string rev(string& str)
	{
		char c[s.Size()+1];
		c[s.Size()] = '\0';
		for (int i = 0; i < s.Size(); i++)
		{
			c[i] = str.at(s.Size() - 1 - i);
		}
		string r{ str };
		return r;
	}

}