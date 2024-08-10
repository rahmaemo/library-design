#pragma once
#include "book.h"
class customer :public book
{public:
	//void searchers(vector<string>bookname, vector<int>ids);
	protected:
		string  name;
		int id;
	public:
		void setname(string n);
		string getname();
		void setid(int i);
		int getid();
		void addtofile();
		void updateName(const string& filename, string& newNam);
		void updateID(const string& filename, string newID);
		void removeCustomerAndSaveToFileById(vector<string>* custNames, vector<string>* custIDs);
		void removeCustomerBynameAndSaveToFile(vector<string>* custNames, vector<string>* custIDs);
	};


