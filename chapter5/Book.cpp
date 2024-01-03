#include "Book.h"
#include <istream>
#include <ostream>
#include <iostream>

bool operator<(const Book b1, const Book b2)
{
	return b1.author.compare(b2.author) < 0 ? true : (b1.name.compare(b2.name) < 0 ? true : b1.code < b2.code ? true : false);
}
bool  operator>(const Book b1, const Book b2)
{
	return !(b1 < b2) && !(b1 == b2);
}
bool  operator<=(const Book b1, const Book b2)
{
	return !(b1 > b2);
}
bool  operator>=(const Book b1, const Book b2)
{
	return !(b1 < b2);
}
bool  operator==(const Book b1, const Book b2) 
{
	return b1.author.compare(b2.author) != 0 ? false : (b1.name.compare(b2.name) != 0 ? false : b1.code != b2.code ? false : true);
}
bool  operator!=(const Book b1, const Book b2)
{
	return !(b1 == b2);
}
std::ostream& operator <<(std::ostream& lhs, const Book b)
{
	lhs << "Book code: " << b.code << ".  Book author: "<< b.author<<".  Book name: "<<b.name<<"."<<endl;
	return lhs;
}
std::istream& operator>>(std::istream& lhs, Book& b)
{
	cout << "Enter the book code, author name, book name. " << endl;
	lhs >> b.code >> b.author >> b.name ;
	return lhs;
}
