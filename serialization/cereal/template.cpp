#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <fstream>
#include <string>

int main()
{
	std::string myString = "Hello, world!";
#if 0
	//serialize
	std::ofstream os("string.bin", std::ios::binary); // Open a file stream in binary mode to save the serialized data
	cereal::BinaryOutputArchive archive(os); // Create a binary output archive
	archive(myString); // Serialize the string
	os.close(); // Close the file stream
				#endif


	//deserialize
	std::ifstream is("string.bin", std::ios::binary); // Open a file stream in binary mode to read the serialized data
	cereal::BinaryInputArchive archive2(is); // Create a binary input archive
	std::string deserializedString;
	archive2(deserializedString); // Deserialize the string
	is.close(); // Close the file stream

	std::cout << deserializedString << std::endl; // Output: Hello, world!

	return 0;
}
