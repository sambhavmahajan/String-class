#ifndef STRINGH_H
#define STRINGH_H

#include <cstddef>
namespace customstring
{
	class string
	{
	private:
		char* value;
		size_t size;
	public:
		string();
		string(const char*);
		~string();
		size_t Size const();
	};
}
#endif