#ifndef STRINGH_H
#define STRINGH_H

#include <cstddef>
namespace customstring
{
	size_t len(char*);

	class string
	{
	private:
		char* value;
		size_t size;
	public:
		string();
		string(const char*);
		string(const string&);
		~string();

		size_t Size() const;
		const char* cStr() const;
		const char at(size_t) const;
		static string rev(string&);
		void trim();
		string subStr(int&, int&);
		static string tolower(const string&);
		static string toupper(const string&);
		bool modify(int index, char val);

		friend string operator+(const string&, const string&);
		friend string operator+(const string&, const char*);
		friend string operator+(const char*, const string&);
		friend bool operator==(const string&, const string&);
		friend bool operator==(const string&, const char*);
		friend bool operator==(const char*, const string&);
		string& operator=(const char*);
		string& operator=(const string&);
	};
}
#endif