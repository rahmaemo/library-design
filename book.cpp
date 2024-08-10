#include "book.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
using namespace std;

book::book()
{

}

void book::writeBooksToFile(const string& filename, const vector<string>& books)
{    ofstream outputFile(filename, ios::trunc);
    if (!outputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    for (size_t i = 0; i < books.size(); ++i) {
        outputFile << (i + 1) << ". " << books[i] << endl;
    }
    outputFile.close();

}

void book::addBook(const string& filename, vector<string>& books, string& newBook)
{
    books.push_back(newBook);

    ofstream outputFile(filename, ios::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    outputFile << books.size() << ". " << newBook << endl;

    outputFile.close();

}

void book::removeBooksAndSaveToFile(vector<string>* booksname, vector<double>* bookPrices, vector<string>* IDSBOOKS, std::vector<int>* fill)
{
    std::ofstream outputFile("books.txt"); // Open the file for writing

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return;
    }
    std::vector<std::string> removedBooks; // Vector to store removed books

    char removeAnother;
    cout << "Enter y to continue or any other key to exit: ";
    cin >> removeAnother;
    while (removeAnother == 'y' || removeAnother == 'Y') {
        std::string book;
        std::cout << "Enter the name of the book you want to remove: ";
		cin.ignore();
		getline(cin, book);

        auto it = std::find(booksname->begin(), booksname->end(), book);
        if (it != booksname->end()) {
            int index = it - booksname->begin();
            double price = (*bookPrices)[index];
            string bookID = (*IDSBOOKS)[index];

            removedBooks.push_back("Removed book: " + book + ", Price: " + std::to_string(price) + ", ID: " + bookID );

            std::cout << "Are you sure you want to remove '" << book << "' that has price " << price << " and ID " << bookID << "?" << std::endl;
            std::cout << "1- Yes, remove the book" << std::endl;
            std::cout << "2- No, keep the book and exit" << std::endl;
            // std::cout << "3- No, keep the book and remove another book" << std::endl;
            std::cout << "3- Delete all" << std::endl;
            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1:
                (*fill)[index] = 0; // Set the corresponding fill element to 0 indicating removed
                booksname->erase(it);
                bookPrices->erase(bookPrices->begin() + index);
                IDSBOOKS->erase(IDSBOOKS->begin() + index);
                std::cout << "Book '" << book << "' has been successfully removed." << std::endl;
                break;
            case 2:
                std::cout << "No changes made. The book '" << book << "' has been kept." << std::endl;
                removeAnother = 0;
                break;

            case 3:
                std::cout << "Are you sure you want to delete all books?\n1- Yes\n2- No" << std::endl;
                int dis;
                std::cin >> dis;
                if (dis == 1) {
                    std::fill(fill->begin(), fill->end(), 0); // Set all elements in fill vector to 0
                    booksname->clear();
                    bookPrices->clear();
                    IDSBOOKS->clear();
                    std::cout << "All books have been deleted." << std::endl;
                }
                else if (dis == 2) {
                    std::cout << "No changes made." << std::endl;
                }
                else {
                    std::cout << "Invalid choice." << std::endl;
                }
                break;
            default:
                std::cout << "Invalid choice. Please enter 1, 2, 3, or 4." << std::endl;
                break;
            }
        }
        else {
            std::cout << "Book not found." << std::endl;
            removeAnother = 0;
        }
        cout << "Enter y to continue or any other key to exit: ";
        cin >> removeAnother;
    }

    outputFile << "Remaining Books:\n";
    for (const auto& book : *booksname) {
        outputFile << book << std::endl;
    }

    for (const auto& removedBook : removedBooks) {
        outputFile << removedBook << std::endl;
    }

    outputFile.close(); // Close the file when done
    std::cout << "Changes saved to remaining_books.txt" << std::endl;

 
}
 void book::searchers(vector<string> bookname, vector<string> ids) 
{
	char yes;
	bool f = true;
	do {
		cout << "Enter 1 to search by  section" << endl;
		cout << "Enter 2 to search by author" << endl;
		cout << "Enter 3 to search by book name" << endl;
		cout << "Enter 4 to search by book id" << endl;
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1: {cout << "Enter the section of the book:" << endl;
			cout << "Enter 'F' or 'f' for Fantasy section." << endl;
			cout << "Enter 'C' or 'c' for Crime section." << endl;
			cout << "Enter 'I' or 'i' for Mystery section." << endl;
			char cha;
			cin >> cha;
			switch (cha)
			{
			case 'f':
			case 'F': {
				vector<string> excludedNames;
				char targetLetter = 'f';
				for (const string& name : bookname) {
					if (name[0] == targetLetter || name[0] == toupper(targetLetter)) {
						excludedNames.push_back(name);
					}
				}
				cout << "Books that belong to the Fantasy section:" << endl;
				for (const string& name : excludedNames) {
					cout << name << endl;
				}
				break;
			}

			case 'c':
			case 'C': {
				vector<string> excludedNames;
				char targetLetter = 'c';
				for (const string& name : bookname) {
					if (name[0] == targetLetter || name[0] == toupper(targetLetter)) {
						excludedNames.push_back(name);
					}
				}
				cout << "Books that belong to the Crime section:" << endl;
				for (const string& name : excludedNames) {
					cout << name << endl;
				}
				break;
			}
			case 'i':
			case 'I': {
				vector<string> excludedNames;
				char targetLetter = 'i'; // Assuming 'f' is the target letter for the Fantasy section
				for (const string& name : bookname) {
					if (name[0] == targetLetter || name[0] == toupper(targetLetter)) {
						excludedNames.push_back(name);
					}
				}
				cout << "Books that belong to the Mystery section:" << endl;
				for (const string& name : excludedNames) {
					cout << name << endl;
				}
				break;
			}
			default:
				cout << "Invalid choice" << endl;
				break;

			} break;
		}
		case 2: {
			cout << "Enter the author's name:" << endl;
			cout << "Enter 'G' or 'g' for George Orwell." << endl;
			cout << "Enter 'S' or 's' for Stephen King." << endl;
			cout << "Enter 'J' or 'j' for J.K. Rowling." << endl;
			char x;
			cin >> x;
			switch (x) {
			case 'g':
			case 'G': {
				vector<string> excludedNames;
				char targetLetter = 'g';
				for (const string& name : bookname) {
					if (name[1] == targetLetter || name[1] == toupper(targetLetter)) {
						excludedNames.push_back(name);
					}
				}
				cout << "Books that belong to the author George Orwell ' (" << targetLetter << ")':" << endl;
				for (const string& name : excludedNames) {
					cout << name << endl;
				}
				break;
			}
			case 's':
			case 'S': {
				vector<string> excludedNames;
				char targetLetter = 's';
				for (const string& name : bookname) {
					if (name[1] == targetLetter || name[1] == toupper(targetLetter)) {
						excludedNames.push_back(name);
					}
				}
				cout << "Books that belong to the author Stephen King. '(" << targetLetter << ")':" << endl;
				for (const string& name : excludedNames) {
					cout << name << endl;
				}
				break;
			}
			case 'j':
			case 'J': {
				vector<string> excludedNames;
				char targetLetter = 'j';
				for (const string& name : bookname) {
					if (name[1] == targetLetter || name[1] == toupper(targetLetter)) {
						excludedNames.push_back(name);
					}
				}
				cout << "Books that belong to the author J.K. Rowling '" << targetLetter << "':" << endl;
				for (const string& name : excludedNames) {
					cout << name << endl;
				}
				break;
			}
			default:
				cout << "Invalid choice" << endl;

				break;
			}
			break;
		}
		case 3: {
			cin.ignore(); // Clear the newline character from the buffer
			cout << "Enter the book name you want to search for: ";
			string book_name_from_user;
			getline(cin, book_name_from_user);
			vector<string> excludedNames;
			for (const string& book : bookname) {
				string subBookName = book.substr(3);
				excludedNames.push_back(subBookName);
			}
			bool found = false;
			for (const string& name : excludedNames) {
				if (name == book_name_from_user) {
					found = true;
					break;
				}
			}
			if (found) {
				cout << "Found('" << book_name_from_user << "') in the library." << endl;
			}
			else {
				cout << "Did not find (' " << book_name_from_user << "') in the library." << endl;
			}
			break;
		}
		case 4: {
			if (ids.empty()) {
				cout << "No book IDs available for search." << endl;
				break;
			}

			cout << "Enter the book ID you want to search for: ";
			string id;
			cin >> id;
			bool found = false;
			size_t index = 0;
			for (size_t i = 0; i < ids.size(); ++i) {
				if (ids[i] == id) {
					found = true;
					index = i;
					break;
				}
			}
			if (found) {
				cout << "Found book with ID " << id << ": " << bookname[index] << endl;
			}
			else {
				cout << "Did not find book with ID " << id << " in the vector." << endl;
			}
			break;
		}

		}
		cout << "Do you want to continue? (Y/y to continue, any other key to exit): ";
		cin >> yes;
		if (yes != 'y' && yes != 'Y') {
			f = false;
			break; // Break out of the loop if yes is not 'y' or 'Y'
		}
	} while (f);

}
void writeToFile(const vector<string>& bookname, const string& filename) {
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



