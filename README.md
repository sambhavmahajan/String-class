# Custom String Library

This is a simple C++ library for handling custom string operations, including basic string manipulation and comparison. The library consists of two files: `stringH.h` (header file) and `stringH.cpp` (implementation file).

## Usage

To use this library in your C++ project, follow these steps:

1. Copy the `stringH.h` and `stringH.cpp` files into your project directory.

2. Include the `stringH.h` header file in your C++ code where you want to use the custom string functionalities:
   
    #include "stringH.h"

4. Compile your project with both `stringH.h` and `stringH.cpp` files.

## Features

### `customstring::string` Class

- Constructors:
  - `string()`: Default constructor.
  - `string(const char*)`: Constructor with a C-style string as input.
  - `string(const string&)`: Copy constructor.
  - `~string()`: Destructor.

- Member Functions:
  - `size_t Size() const`: Returns the size of the string.
  - `const char* cStr() const`: Returns a pointer to the C-style string.
  - `const char at(size_t) const`: Returns the character at the specified index.
  - `static string rev(string&)`: Reverses the string.
  - `void trim()`: Removes leading and trailing spaces.
  - `string subStr(int&, int&)`: Returns a substring based on the start and length.
  - `static string tolower(const string&)`: Converts the string to lowercase.
  - `static string toupper(const string&)`: Converts the string to uppercase.

- Overloaded Operators:
  - `string operator+(const string&, const string&) const`: Concatenates two strings.
  - `string operator+(const string&, const char*) const`: Concatenates a string and a C-style string.
  - `string operator+(const char*, const string&) const`: Concatenates a C-style string and a string.
  - `bool operator==(const string&, const string&) const`: Checks if two strings are equal.
  - `bool operator==(const string&, const char*) const`: Checks if a string is equal to a C-style string.
  - `bool operator==(const char*, const string&) const`: Checks if a C-style string is equal to a string.
