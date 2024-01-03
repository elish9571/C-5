#pragma once
#include <string>
using namespace std;

class Book
{
public:
	int code;
	string author;
	string name;


	Book(int code = 0, string author = "", string name = "") : code(code), author(author), name(name) {}
	friend bool  operator<(const Book b1, const Book b2);
	friend bool  operator>(const Book b1, const Book b2);
	friend bool  operator<=(const Book b1, const Book b2);
	friend bool  operator>=(const Book b1, const Book b2);
	friend bool  operator==(const Book b1, const Book b2);
	friend bool  operator!=(const Book b1, const Book b2);
	friend std::ostream& operator <<(std::ostream& lhs, const Book b);
	friend std::istream& operator>>(std::istream& lsh, Book& b);

};

