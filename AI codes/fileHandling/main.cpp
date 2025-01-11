/*Creating a simple Database Management System (DBMS) using files in C++ can be a great 
way to understand file handling and basic database operations. 
Below is a concise example that demonstrates how to create, read, update, 
and delete records in a file-based DBMS.

Example: Simple File-Based DBMS in C++*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Record {
    int id;
    string name;
    int age;
};

void addRecord(const string& filename, const Record& record) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << record.id << " " << record.name << " " << record.age << endl;
        file.close();
        cout << "Record added successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

void displayRecords(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        Record record;
        while (file >> record.id >> record.name >> record.age) {
            cout << "ID: " << record.id << ", Name: " << record.name << ", Age: " << record.age << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void updateRecord(const string& filename, int id, const Record& newRecord) {
    ifstream file(filename);
    ofstream tempFile("temp.txt");
    bool found = false;

    if (file.is_open() && tempFile.is_open()) {
        Record record;
        while (file >> record.id >> record.name >> record.age) {
            if (record.id == id) {
                tempFile << newRecord.id << " " << newRecord.name << " " << newRecord.age << endl;
                found = true;
            } else {
                tempFile << record.id << " " << record.name << " " << record.age << endl;
            }
        }
        file.close();
        tempFile.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        if (found) {
            cout << "Record updated successfully." << endl;
        } else {
            cout << "Record not found." << endl;
        }
    } else {
        cout << "Unable to open file." << endl;
    }
}

void deleteRecord(const string& filename, int id) {
    ifstream file(filename);
    ofstream tempFile("temp.txt");
    bool found = false;

    if (file.is_open() && tempFile.is_open()) {
        Record record;
        while (file >> record.id >> record.name >> record.age) {
            if (record.id != id) {
                tempFile << record.id << " " << record.name << " " << record.age << endl;
            } else {
                found = true;
            }
        }
        file.close();
        tempFile.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        if (found) {
            cout << "Record deleted successfully." << endl;
        } else {
            cout << "Record not found." << endl;
        }
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    string filename = "database.txt";
    Record record1 = {1, "Alice", 30};
    Record record2 = {2, "Bob", 25};

    addRecord(filename, record1);
    addRecord(filename, record2);

    cout << "Displaying all records:" << endl;
    displayRecords(filename);

    Record updatedRecord = {2, "Bob", 26};
    updateRecord(filename, 2, updatedRecord);

    cout << "Displaying all records after update:" << endl;
    displayRecords(filename);

    deleteRecord(filename, 1);

    cout << "Displaying all records after deletion:" << endl;
    displayRecords(filename);

    return 0;
}

/*
Explanation:
Add Record: Appends a new record to the file.
Display Records: Reads and displays all records from the file.
Update Record: Updates a specific record by creating a temporary file and renaming it.
Delete Record: Deletes a specific record by creating a temporary file and renaming it.

This example provides a basic structure for a file-based DBMS. You can expand it by adding more functionalities like searching records, handling errors more gracefully, and improving the user interface.
*/