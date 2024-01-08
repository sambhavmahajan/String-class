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
	string::string(const string& s) value(nullptr), size(len(s))
	{
		size = s.Size();
		value = new char[size + 1];
		value[size] = '\0';
		for (size_t i = 0; i < size; i++)
		{
			value[i] = s.at(i);
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
	string string::rev(string& str)
	{
		char c[str.Size() + 1];
		c[str.Size()] = '\0';
		for (int i = 0; i < str.Size(); i++)
		{
			c[i] = str.at(str.Size() - 1 - i);
		}
		string r{ str };
		return r;
	}
	void string::trim()
	{
		int i = 0;
		while (value[i] == ' ' || value[i] == '\t')
		{
			i++;
		}
		int j = size-1;
		while (value[j] == ' ' || value[j] == '\t')
		{
			j--;
		}
		int l = j - i + 1;
		char *s = new char[l + 1];
		s[l] = '\0';
		int t = 0;
		for (int k = i; k <= j; k++)
		{
			s[t++] = value[k];
		}
		delete[] value;
		value = s;
	}
	string string::subStr(int& start, int& length)
	{
		char arr[length + 1];
		arr[length] = '\0';
		for (int i = start; i < start + length; i++)
		{
			arr[i - start] = value[i];
			if (value[i] == '\0')
			{
				string t{ arr };
				return t;
			}
		}
		string r{ arr };
		return r;
	}
	string string::tolower(const string& str)
	{
		char s[str.Size() + 1];
		s[str.Size()] = '\0';
		for (int i = 0; i < str.Size(); i++)
		{
			s[i] = str.at(i);
			if (str.at(i) >= 'A' && str.at(i) <= 'Z')
			{
				s[i] += 32;
			}
		}
		string r{ s };
		return r;
	}
	string string::toupper(const string& str)
	{
		char s[str.Size() + 1];
		s[str.Size()] = '\0';
		for (int i = 0; i < str.Size(); i++)
		{
			s[i] = str.at(i);
			if (str.at(i) >= 'a' && str.at(i) <= 'z')
			{
				s[i] -= 32;
			}
		}
		string r{ s };
		return r;
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
		size_t blen = len(b);
		for (size_t j = 1; j - 1 < blen; j++)
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
		size_t blen = len(b);
		for (size_t j = 1; j - 1 < blen; j++)
		{
			s[i + j] = b[j - 1];
		}
		string r{ s };
		return r;
	}
	bool string::operator==(const string& s1, const string& s2) const
	{
		if (s1.Size() != s2.Size())
		{
			return false;
		}
		for (int i = 0; i < s1.Size(); i++)
		{
			if (s1.at(i) != s2.at(i)) {
				return false;
			}
		}
		return true;
	}
	bool string::operator==(const string& s1, const char* s2) const
	{
		size_t l = len(s2);
		if (s1.Size() != l)
		{
			return false;
		}
		for (int i = 0; i < l; i++)
		{
			if (s1.at(i) != s2[i]) {
				return false;
			}
		}
		return true;
	}
	bool string::operator==(const char* s1, const string& s2) const
	{
		size_t l = len(s1);
		if (s2.Size() != l)
		{
			return false;
		}
		for (int i = 0; i < l; i++)
		{
			if (s2.at(i) != s1[i]) {
				return false;
			}
		}
		return true;
	}
	string& string::operator=(const char* str) {
		size_t l = len(str);
		char* newStr = new char[l + 1];
		newStr[l] = '\0';
		delete[] value;
		for (int i = 0; i < l; i++) {
			newStr[i] = str[i];
		}
		return *this;
	}
	string& string::operator=(const string& str)
	{
		if (this != &str)
		{
			delete[] value;
			char* newStr = new char[str.Size() + 1];
			newStr[str.Size()] = '\0';
			for (int i = 0; i < str.Size(); i++) {
				newStr[i] = str.at(i);
			}
		}
		return *this;
	}
}