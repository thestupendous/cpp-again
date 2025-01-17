// both read and write and does not overwrite file
#include <iostream>
#include <fstream>
#include <vector>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/cereal.hpp>

// Define a structure for the data to be stored
struct Record {
    int id;
    std::string name;

    template<class Archive>
    void serialize(Archive & archive)
    {
        archive( CEREAL_NVP(id), CEREAL_NVP(name) );
    }
};

// Function to append a new record to the JSON file
void appendRecord(const Record& newRecord, const std::string& filename) {
    std::vector<Record> records;

    // Open the file for reading first to load existing records
    std::ifstream is(filename);
    if (is.good()) {
        {
            cereal::JSONInputArchive iarchive(is);
            iarchive(cereal::make_nvp("records", records));
        }
    }
    // Close the file after reading
    is.close();

    // Append the new record
    records.push_back(newRecord);

    // Now, write all records including the new one back to the file
    std::ofstream os(filename);
    {
        cereal::JSONOutputArchive oarchive(os);
        oarchive(cereal::make_nvp("records", records));
    }
    os.close();
}

// Function to read all records from the JSON file
std::vector<Record> readRecords(const std::string& filename) {
    std::vector<Record> records;
    
    std::ifstream is(filename);
    if (is.good()) {
        {
            cereal::JSONInputArchive iarchive(is);
            iarchive(cereal::make_nvp("records", records));
        }
    }
    is.close();

    return records;
}

int main() {
    // Example usage for appending
    Record newRecord = {1, "John Doe"};
    appendRecord(newRecord, "database.json");

    // Example usage for reading
    std::vector<Record> fetchedRecords = readRecords("database.json");
    for (const auto& record : fetchedRecords) {
        std::cout << "ID: " << record.id << ", Name: " << record.name << std::endl;
    }
    
    return 0;
}

/*
ai-ki-shakti
11:44 PM, 13-01-2025
You're right. Let's expand this to include basic read functionality to make it more of a DBMS. Here's an updated version with both appendRecord and readRecords functions:

cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/cereal.hpp>

// Define a structure for the data to be stored
struct Record {
    int id;
    std::string name;

    template<class Archive>
    void serialize(Archive & archive)
    {
        archive( CEREAL_NVP(id), CEREAL_NVP(name) );
    }
};

// Function to append a new record to the JSON file
void appendRecord(const Record& newRecord, const std::string& filename) {
    std::vector<Record> records;

    // Open the file for reading first to load existing records
    std::ifstream is(filename);
    if (is.good()) {
        {
            cereal::JSONInputArchive iarchive(is);
            iarchive(cereal::make_nvp("records", records));
        }
    }
    // Close the file after reading
    is.close();

    // Append the new record
    records.push_back(newRecord);

    // Now, write all records including the new one back to the file
    std::ofstream os(filename);
    {
        cereal::JSONOutputArchive oarchive(os);
        oarchive(cereal::make_nvp("records", records));
    }
    os.close();
}

// Function to read all records from the JSON file
std::vector<Record> readRecords(const std::string& filename) {
    std::vector<Record> records;
    
    std::ifstream is(filename);
    if (is.good()) {
        {
            cereal::JSONInputArchive iarchive(is);
            iarchive(cereal::make_nvp("records", records));
        }
    }
    is.close();

    return records;
}

int main() {
    // Example usage for appending
    Record newRecord = {1, "John Doe"};
    appendRecord(newRecord, "database.json");

    // Example usage for reading
    std::vector<Record> fetchedRecords = readRecords("database.json");
    for (const auto& record : fetchedRecords) {
        std::cout << "ID: " << record.id << ", Name: " << record.name << std::endl;
    }
    
    return 0;
}


Explanation:

    appendRecord: This function remains unchanged from the previous example. It reads existing records, appends the new one, and writes everything back to the file.
    readRecords: This new function reads all records from the JSON file. If the file doesn't exist or is empty, it will return an empty vector.
    Main Function: Demonstrates how to use both appendRecord and readRecords. After appending a record, it reads all records from the file and prints them out.


This setup provides basic CRUD operations where:

    Create is done by appendRecord
    Read is handled by readRecords
    Update and Delete would require additional functions, which you might want to implement if needed for a more complete DBMS.


Remember, this is still quite simplistic. For a full-fledged DBMS, you'd need to add functionality for updating records, deleting records, indexing, querying, etc., along with error handling, data integrity checks, and possibly multi-threading for concurrent access.

*/