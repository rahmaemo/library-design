#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "library.h"
using namespace std;
class book
{
private:
vector<string> books;     
string newBook;
string  filename;
public:
	book();
	void writeBooksToFile(const string& filename, const vector<string>& books);
	void addBook(const string& filename, vector<string>& books, string& newBook);
	void removeBooksAndSaveToFile(vector<string>* booksname, vector<double>* bookPrices, vector<string>* IDSBOOKS, std::vector<int>* fill);
	void searchers(vector<string> bookname, vector<string> ids);

};

