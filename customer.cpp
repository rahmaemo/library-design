#include "customer.h"

void customer::setname(string n)
{
	name = n;
}

string customer::getname()
{
	return name;
}

void customer::setid(int i)
{
	id = i;
}

int customer::getid()
{
	return id;
}
    void customer::addtofile() {
        string n;
        int i;

        cout << "Do you want to update your name, ID, or both?" << endl;
        cout << "1. Name" << endl;
        cout << "2. ID" << endl;
        cout << "3. Both" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter your new name: ";
            cin.ignore();
            getline(cin, n);
            setname(n);
            break;
        case 2:
            cout << "Enter your new ID: ";
            cin >> i;
            setid(i);
            break;
        case 3:
            cout << "Enter your new name: ";
            cin.ignore();
            getline(cin, n);
            setname(n);
            cout << "Enter your new ID: ";
            cin >> i;
            setid(i);
            break;
        default:
            cout << "Invalid choice." << endl;
            return;
        }

        // Open the file for writing in append mode
        ofstream customerFile("customer.txt", ios::out | ios::app);
        if (!customerFile.is_open()) {
            cout << "Failed to open customer file!" << endl;
            return;
        }

        // Write customer information to the file
        customerFile << name << "#" << id << "#" << endl;
        customerFile.close();
    }
    void customer::updateName(const string& filename, string& newNam)
    {
        ofstream customerFile(filename, ios::out);
        if (!customerFile.is_open()) {
            cout << "Failed to open customer file!" << endl;
            return;
        }

        customerFile << newNam << " " << endl;
        customerFile.close();

        cout << "Your name has been updated successfully." << endl;

        // Open the file for reading to display the updated data
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cout << "Failed to open customer file for reading!" << endl;
            return;
        }

        string updatedName;
        int id;
        inFile >> updatedName >> id;
        inFile.close();

        cout << "Updated Name: " << updatedName << ", ID: " << id << endl;
    }
    void customer::updateID(const string& filename, string newID)
    {
        ofstream customerFile(filename, ios::out);
        if (!customerFile.is_open()) {
            cout << "Failed to open customer file!" << endl;
            return;
        }

        customerFile << newID << " " << endl;
        customerFile.close();

        cout << "Your ID has been updated successfully." << endl;

       
    }

    void customer::removeCustomerAndSaveToFileById(vector<string>* custNames, vector<string>* custIDs)
    {
        cout << "Enter the ID of the customer you want to remove: ";
        string id;
        cin >> id;

        auto it = find(custIDs->begin(), custIDs->end(), id);
        if (it != custIDs->end()) {
            int index = distance(custIDs->begin(), it);
            custIDs->erase(it); 
            custNames->erase(custNames->begin() + index);
            cout << "Customer with ID " << id << " has been removed." << endl;
        }
        else {
            cout << "Customer with ID " << id << " not found." << endl;
        }
        ofstream outFile("customers.txt");
        if (!outFile.is_open()) {
            cerr << "Error: Unable to open file for writing." << endl;
            return;
        }
        for (size_t i = 0; i < custNames->size(); ++i) {
            outFile << (*custNames)[i] << " " << (*custIDs)[i] << endl;
        }
        outFile.close();
        cout << "Customer data saved to file." << endl;
    }

    void customer::removeCustomerBynameAndSaveToFile(vector<string>* custNames, vector<string>* custIDs)
    {
        cout << "Enter the name of the customer you want to remove: ";
        string name;
        getline(cin, name);

        auto it = find(custNames->begin(), custNames->end(), name);
        if (it != custNames->end()) {
            int index = distance(custNames->begin(), it);
            custNames->erase(it); 
            custIDs->erase(custIDs->begin() + index);
            cout << "Customer with name " << name << " has been removed." << endl;
        }
        else {
            cout << "Customer with name " << name << " not found." << endl;
        }
        ofstream outFile("customers.txt");
        if (!outFile.is_open()) {
            cerr << "Error: Unable to open file for writing." << endl;
            return;
        }
        for (size_t i = 0; i < custNames->size(); ++i) {
            outFile << (*custNames)[i] << " " << (*custIDs)[i] << endl;
        }
        outFile.close();
        cout << "Customer data saved to file." << endl;
    }
    
       

   
