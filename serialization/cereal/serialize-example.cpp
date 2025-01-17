//appends but does not read
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

int main() {
    // Example usage
    Record newRecord = {1, "John Doe"};
    appendRecord(newRecord, "database.json");
    
    return 0;
}