#include "emplyee.h"
using namespace std;
void emplyee:: display_books_from_file(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error: Unable to open file for reading." << endl;
		return;
	}

	vector<string> booksname;
	vector<double> bookPrices;

	string bookName;
	double price;
	while (file >> bookName >> price) {
		booksname.push_back(bookName);
		bookPrices.push_back(price);
	}

	file.close();

	cout << "Books available in the library:" << endl;
	for (size_t i = 0; i < booksname.size(); ++i) {
		cout << "**********" << endl;
		cout << "Book name: " << booksname[i] << endl;
		cout << "Price: " << bookPrices[i] << endl;
		cout << "**********" << endl;
	}
}
void emplyee::update(vector<string>* booksname, vector<double>* bookPrices)
{
	char choice;
	do {
		string book;
		cout << "Enter the name of the book you want to edit:" << endl;
		cin.ignore();
		getline(cin, book);

		auto it = find(booksname->begin(), booksname->end(), book);
		if (it != booksname->end()) {
			// Calculate index of the book
			int index = distance(booksname->begin(), it);
			double price = (*bookPrices)[index];

			// Update the price
			double newPrice;
			cout << "Enter the new price: ";
			cin >> newPrice;
			(*bookPrices)[index] = newPrice;

			cout << "Price of book '" << book << "' before update: " << price << endl;
			cout << "Price updated to: " << newPrice << endl;
		}
		else {
			cout << "Book not found." << endl;
		}

		cout << "Do you want to update another book? (y/n): \n OR Press any button to exit  ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}
void emplyee::writeToFile(const vector<string>& bookname, const string& filename)
{
	ofstream outFile(filename);
	if (outFile.is_open()) {
		for (const string& book : bookname) {
			outFile << book << endl;
		}
		outFile.close();
	}
	else {
		cerr << "Error: Unable to open file for writing." << endl;
	}
}
vector<string> emplyee::readBooksFromFile(const string& filename)
{
	return vector<string>();
}
int emplyee::employees(vector<string>* names, vector<string>* ids, vector<double>* salaries)
{

		char choice;
		do {
			string name, id;
			cout << "Enter the employee's name: \n";
			cin >> name;
			cout << "Enter the employee's ID:\n ";
			cin >> id;

			auto idIt = find(ids->begin(), ids->end(), id);

			if (idIt != ids->end()) {
				size_t index = distance(ids->begin(), idIt);
				if ((*names)[index] == name) {
					cout << name << " with ID " << id << " is an existing employee." << endl;
					cout << "Current salary: " << (*salaries)[index] << endl;

					cout << "Do you want to update \n" << name << "'s salary? (y/n):\n ";
					cin >> choice;
					if (choice == 'y' || choice == 'Y') {
						cout << "Enter the new salary:\n ";
						cin >> (*salaries)[index];
						cout << "Salary updated for " << name << endl;
					}
					else if (choice == 'n' || choice == 'N')
						cout << "Not adding employee." << endl;
					else
						cout << "Ent Availed char";
				}
				else {
					cout << "The entered name does not match the name associated with ID  " << id << "." << endl;
				}
			}
			else {
				cout << "This employee does not exist." << endl;
				cout << "Do you want to add\n " << name << "? (y/n): ";
				cin >> choice;
				if (choice == 'y' || choice == 'Y') {
					names->push_back(name);
					ids->push_back(id);
					double newSalary;
					cout << "Enter the new employee's salary: \n";
					cin >> newSalary;
					salaries->push_back(newSalary);
					writeToFile(*names, "employee_data.txt"); // Corrected function call
					cout << "New employee " << name << " with ID " << id << " and salary " << newSalary << " added." << endl;
				}
				else if (choice == 'n' || choice == 'N')
					cout << "Not adding employee.\n" << endl;
				else
					cout << "Ent Availed char\n";

			}

			cout << "Do you want to check/update another employee? (y/n): OR ANY thing if you want to Leaves ";
			cin >> choice;
		} while (choice == 'y' || choice == 'Y');

		return 0;
	}
void emplyee::display_employees(vector<string>* names, vector<string>* ids, vector<double>* salaries)
{
	cout << "The employees in the library \n";
	int x = 1;
	for (size_t i = 0; i < names->size(); ++i) {

		cout << "**********" << endl;
		cout << "*** Employee " << x << " ***" << endl;
		cout << "employee name: " << (*names)[i] << endl;
		cout << "his Rank " << (*salaries)[i] << endl;
		//cout << "**********" << endl;
		cout << "His ID " << (*ids)[i] << endl;
		cout << "**********" << endl;
		x++;
	}
}
