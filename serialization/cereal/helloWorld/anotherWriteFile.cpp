#include <cereal/archives/binary.hpp>
#include <cereal/archives/xml.hpp>
#include <fstream>
#include <string>

class MeriClass
{
	

int main() {
#if 1
  /*-----------Saving to file--------------------------*/
  std::ofstream File{"SaveFile.bin"};
  cereal::BinaryOutputArchive OArchive(File);

  int SomeInt{42};
  std::string SomeString{"raam Raam"};
  float SomeFloat{4.92004};
  bool SomeBoolean{true};


  // Throws error for strings, for now
  OArchive(SomeInt, SomeFloat, SomeBoolean /*,SomeString*/);

  std::ofstream file( "out.xml" );
  cereal::XMLOutputArchive archive2( file ); // depending on the archive type, data may be
                                            // output to the stream as it is serialized, or
                                            // only on destruction
  archive2( SomeInt, SomeFloat, SomeBoolean);
  File.close();
#endif


#if 1
  /*-----------Loading from file-----------------------*/
  std::ifstream File2{"SaveFile.bin"};
  cereal::BinaryInputArchive IArchive(File2);

  int SomeIntRead;
  float SomeFloatRead;
  bool SomeBooleanRead;

  IArchive(SomeIntRead, SomeFloatRead, SomeBooleanRead);

  std::cout << "SomeInt: " << SomeIntRead;
  std::cout << "\nSomeFloat: " << SomeFloatRead;
  std::cout << "\nSomeBoolean: "
            << std::boolalpha << SomeBooleanRead;
  File2.close();
#endif
}
