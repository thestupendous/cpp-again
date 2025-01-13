#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <fstream>
#include <iostream>
#include <string>

class Meri
{
	std::string name;
	public:
	Meri():name(""){}
	Meri(const std::string& s):name(s){}
	void print()
	{
		std::cout << name << '\n';
	}
	template<class Archive>
	void serialize(Archive & archive)
	{
		archive(name); // serialize things by passing them to the archive
	}
};

	int main()
	{
		//data
		std::string myString = "Raam Raam";
		Meri obj("yoshimitsu");

		//serialize
		std::ofstream os("string.bin", std::ios::binary); // Open a file stream in binary mode to save the serialized data
		cereal::BinaryOutputArchive archive(os); // Create a binary output archive
		archive(obj); // Serialize the data
		os.close(); // Close the file stream


		//deserialize
		std::ifstream is("string.bin", std::ios::binary); // Open a file stream in binary mode to read the serialized data
		cereal::BinaryInputArchive archive2(is); // Create a binary input archive
		std::string deserializedString;
		Meri objRead;
		archive2(objRead); // Deserialize the data
		is.close(); // Close the file stream

		objRead.print();
		//std::cout << deserializedString << std::endl; // Output: Hello, world!

		return 0;
	}
