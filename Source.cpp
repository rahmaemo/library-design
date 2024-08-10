#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "book.h"
#include "customer.h"
#include"emplyee.h"
using namespace std;
void writeVectorToFile(const vector<string>& vec, const string& filename) {
	ofstream outfile(filename);
	if (!outfile) {
		cerr << "Error opening file: " << filename << endl;
		return;
	}
	for (const string& element : vec) {
		outfile << element << "\n";
	}
	outfile.close();
}
bool signIn( vector<string>& names,  vector<string>& ids, string& username,  string& id) {
	auto nameIt = find(names.begin(), names.end(), username);
	if (nameIt != names.end()) {
		size_t index = distance(names.begin(), nameIt);
		if (index < ids.size()) {
			if (ids[index] == id) {
				cout << "User found at index: " << index+1 << endl;
				cout << "Name: " << names[index] << ", ID: " << ids[index] << endl;
				return true; // User found
			}
		}
	}
	cout << "User not found." << endl;
	return false; // User not found
}
std::vector<std::string> readFileToVector(const std::string& fileName) {
	std::vector<std::string> fileContents;
	std::ifstream file(fileName);

	if (!file) {
		std::cerr << "Unable to open file: " << fileName << std::endl;
		return fileContents;
	}

	std::string line;
	while (std::getline(file, line)) {
		fileContents.push_back(line);
	}

	file.close();
	return fileContents;
}
void replaceElementInVector(vector<string>& vec, const string& elementToRemove, const string& elementToAdd) {
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i] == elementToRemove) {
			vec[i] = elementToAdd;
			return;
		}
	}
	cerr << "Element \"" << elementToRemove << "\" not found in vector." << endl;
}
void printVectorToFile(const vector<string>& vec, string& filename) {
	ofstream file(filename);
	
	if (file.is_open()) {
		for (const string& str : vec) {
			file << str << " ";
		}
		file.close();
		
	}
	else {
		cerr << "Unable to open file: " << filename << endl;
	}
}
int main() {
	vector<string> books = {
		 "fg_Harry Potter",
		 "cs_Lord of the Rings",
		 "ij_The Hobbit",
		 "fs_Game of Thrones",
		 "ig_To Kill a Mockingbird"
	};
	writeVectorToFile(books, "books");
	vector<string> Ids_book = { "567","895","562","568","123" };
	//vector<int>ids_book = { 567,895,562,568,123 };
	writeVectorToFile(Ids_book, " Ids_books");
	vector<string>cust_names = { "fady","shady","zein","omer","samy" };
	writeVectorToFile(cust_names, "cust_names.txt");
	vector<string>cust_pass = { "12345","12346","12347","12348","12349" };
	writeVectorToFile(cust_pass, "cust_pass.txt");
	vector<string>emplo_names = { "ali","seif","mazen","ahmed" };
	writeVectorToFile(emplo_names, "emplonames.txt");
	vector<string>emplo_Ids = { "123","124","125","126"};
	writeVectorToFile(emplo_Ids, "emploIds.txt");
	vector<double>emp_salary = { 2500,6300,5000,56 };
	vector<double>book_price = { 20.5 ,63,85,95,85 };
	cout << "Hallo Rahma in your project \n ";
	cout << " pls we want you to be happy while you use your project \n ";

	int choice;
	cout << "Enter the mode you want to enter: \n1- To sing in as customer\n2- As employee\n";
	cin >> choice;
	switch (choice) {
	case 1: {
		int i = 1;
		while (i != 3) {
			string name;
			cout << "Enter your name: \n";
			cin>> name;
			cout << "Enter your password:\n ";
			string pass;
			cin>> pass;
			//signIn(cust_names, cust_pass, name, pass);
			if (signIn(cust_names, cust_pass, name, pass)) { 
				cout << "Welcome, " << name << "!" << endl;
				customer obj;
				int choice;
				char continueChoice;

				do {
					cout << "1- Enter 1 to search for book\n";
					cout << "2- Enter 2 to update your password\n";
					cout << "3- Enter 3 to update your username\n";
					cout << "4_Enter 4 to delete your username";
					//cout << "5_ delet cust";
					cout << "Enter your choice: ";
					cin >> choice;

					switch (choice) {
					case 1: {
						obj.searchers(books, Ids_book);
						break;
					}
					case 2: {
						string newPass;
						cout << "Enter your new password: ";
						cin >> newPass;
						obj.updateID("custpass.txt", newPass);
						break;
					}
					case 3: {
						cin.ignore(); // Clear the newline character from the input buffer
						string newName;
						cout << "Enter your new name: ";
						getline(cin, newName);
						obj.updateName("custnames.txt", newName);
						break;
					}
					case 4: {
						int choise;
						cout << " Do you want to remove account by id or by name 1-BY id \n2-By Name\n";
						cin >> choise;
						switch (choise) {
						case 1: {
							obj.removeCustomerAndSaveToFileById(&cust_names, &cust_pass);
							break;
						}
						case 2: {
							obj.removeCustomerBynameAndSaveToFile(&cust_names, &cust_pass);
							break;
						}
						default:
							cout << " NON vaild ";
						}
						break;
					}
					default:
						cout << "Invalid choice. Please enter a valid option." << endl;
						break;
					}

					cout << "Do you want to continue? (Y/N): ";
					cin >> continueChoice;
				} while (continueChoice == 'Y' || continueChoice == 'y');
break;
			}
			else {
				cout << "Incorrect username or password." << endl;
				cout << "Do you want to try again? Enter 'y' for yes, or any other key to exit: ";
				char dir;
				cin >> dir;
				if (dir == 'y' || dir == 'Y') {
					cin.ignore(); 
					i++;
				}
				else {
					break; 
				}
			}
		}
		break;
	}
	case 2: {
		int i = 0;
		while (i != 3) {
			string name;
			cout << "Enter your name: ";
			cin>> name;
			cout << "Enter your password: ";
			string pass;
			cin>> pass;

			if (signIn(emplo_names, emplo_Ids, name, pass)) {
				cout << "Welcome, " << name << "!" << endl; {
					customer obj;
					int choice;
					char continueChoice;

					do {
						cout << "1- Enter 1 to search for booke\n";
						cout << "2- Enter 2 to search for emplyee and up date\n";
						cout << "3- Enter 3 to update book\n";
						cout << "4_Enter 4 to display emplyee \n";
						cout << "5_ ent book you want to remove\n";
						cout << "6_ent book that you add \n";
						cout << "Enter your choice:\n ";
						cin >> choice;
						emplyee obj;
						switch (choice) {
						case 1: {
							obj.searchers(books, Ids_book);

							break;
						}
						case 2: {
							obj.employees(&emplo_names, &emplo_Ids, &emp_salary);
							break;
						}
						case 3: {
						//	obj.update(&books, &book_price);
							cout << "Enter the BOOK name you want to replase \n";
							string bookre;
							cin.ignore();
							getline(cin, bookre);
							cout << " enter the new book";
							string book2;
							cin.ignore();
							getline(cin, book2);
							replaceElementInVector(books,bookre,book2);
							string fille = "books2.txt";
							printVectorToFile(books, fille);
							break;
						}
						case 4: {
							int choise;
							cout << " Do you want to display from fill  1- BOOKS \n2-EMPLyeees\n";
							cin >> choise;
							switch (choise) {
							case 1: {
								//readFileToVector("books.txt"); 
								std::string fileName = "books.txt";
								std::vector<std::string> fileContents = readFileToVector(fileName);
								for (const auto& line : fileContents) {
									std::cout << line << std::endl;
								}
								break;
							}
							case 2: {
								//readFileToVector("emplonames.txt");
								std::string fileName = "emplonames.txt";
								std::vector<std::string> fileContents = readFileToVector(fileName);
								for (const auto& line : fileContents) {
									std::cout << line << std::endl;
								}
								cout << endl;
								//readFileToVector("emploIds.txt");
								std::string fileid = "emploIds.txt";
								std::vector<std::string> fileContentss= readFileToVector(fileid);
								for (const auto& line : fileContents) {
									std::cout << line << std::endl;
								}
								break;
							}
							default:
								cout << " NON vaild ";
							}
							break;
						}

						case 5: {
							std::vector<int> fill(books.size(), 1);
							obj.removeBooksAndSaveToFile(& books,& book_price,& Ids_book,&fill);
							break;
						}
						case 6: {
							cout << "Ent your New book";
							string book;
							cin.ignore();
							getline(cin, book);
							string fil = "books.txt";

					cout << " do you want to add this book in 1_ FORa new fill \n or 2_insame fill or any key to brak";
							int cho;
							cin >> cho;
							if (cho == 1) {
								obj.addBook(fil, books, book);
							}
							else if(cho==2) {
								books.push_back(book);
								string fill = "books.txt";
								printVectorToFile(books, fill);
							}
							break;
						}
						default:
							cout << "Invalid choice. Please enter a valid option." << endl;
							break;
						}

						cout << "Do you want to continue? (Y/N): ";
						cin >> continueChoice;
					} while (continueChoice == 'Y' || continueChoice == 'y');
					break;
				}
				break; 
			}
			else {
				cout << "Incorrect username or password." << endl;
				cout << "Do you want to try again? Enter 'y' for yes, or any other key to exit: ";
				char dir;
				cin >> dir;
				if (dir == 'y' || dir == 'Y') {
					cin.ignore(); 
					i++;
				}
				else {
					break; 
				}
			}
		}
		break;
	}
	default:
		cout << "Invalid choice. Please enter 1 or 2." << endl;
	}
	return 0;



}