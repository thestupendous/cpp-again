/*
Converting JSON to YAML in C++ involves reading a JSON file, parsing it, 
 and then writing the equivalent YAML file. Below is a simple 
 example using the `jsoncpp` library for JSON and `yaml-cpp` 
 library for YAML. Ensure you have both libraries installed.
*/
#include <fstream>
#include <iostream>
#include <json/json.h>
#include <yaml-cpp/yaml.h>

void convertJsonToYaml(const std::string &jsonFilePath, const std::string &yamlFilePath) {
    // Open the JSON file
    std::ifstream jsonFile(jsonFilePath);
    Json::Value jsonData;
    jsonFile >> jsonData;
    jsonFile.close();

    // Convert JSON to YAML
    YAML::Emitter yamlOut;
    yamlOut << YAML::convert<Json::Value>::encode(jsonData);

    // Write the YAML data to file
    std::ofstream yamlFile(yamlFilePath);
    yamlFile << yamlOut.c_str();
    yamlFile.close();
}

int main() {
    std::string jsonFilePath = "example.json";
    std::string yamlFilePath = "example.yaml";

    try {
        convertJsonToYaml(jsonFilePath, yamlFilePath);
        std::cout << "Conversion from JSON to YAML successful!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

