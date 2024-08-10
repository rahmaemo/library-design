#pragma once
#include<iostream>
#include< string >
#include <vector>
#include<fstream>
using namespace std;
#include "customer.h"
class emplyee:public customer
{public:
	void writeToFile(const vector<string>& bookname, const string& filename);
	vector<string> readBooksFromFile(const string& filename);
	void display_books_from_file(const string& filename);
	void update(vector<string>* booksname, vector<double>* bookPrices);
	int employees(vector<string>* names, vector<string>* ids, vector<double>* salaries);
	void display_employees(vector<string>* names, vector<string>* ids, vector<double>* salaries);
	
	
};

