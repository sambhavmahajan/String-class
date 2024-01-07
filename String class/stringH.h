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
		~string();

		size_t Size () const;
		const char* cStr() const;
		const char at(size_t) const;

		string operator+(const string&,const string&) const;

	};
}
#endif