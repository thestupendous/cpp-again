#include <iostream>
#include <map>
#include <cereal/archives/json.hpp>
#include <cereal/types/map.hpp>  // Include for std::map support
#include <fstream>

// Function to serialize the std::map
template <class Archive>
void serialize(Archive & archive, std::map<int, std::string> & m) {
    archive(cereal::make_nvp("my_map", m));  // Serialize the map with a name ("my_map")
}

int main() {
    // Create a sample map
    std::map<int, std::string> my_map = {
        {1, "apple"},
        {2, "banana"},
        {3, "cherry"}
    };

    // Serialize to a JSON file
    {
        std::ofstream os("map_output.json"); // Open a file to write the serialized data
        cereal::JSONOutputArchive archive(os); // Create a JSON output archive
        archive(my_map); // Serialize the map
    }

    // Deserialize from the JSON file
    std::map<int, std::string> loaded_map;
    {
        std::ifstream is("map_output.json"); // Open the file for reading
        cereal::JSONInputArchive archive(is); // Create a JSON input archive
        archive(loaded_map); // Deserialize into the map
    }

    // Print out the deserialized map
    std::cout << "Deserialized map:" << std::endl;
    for (const auto &entry : loaded_map) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    return 0;
}
