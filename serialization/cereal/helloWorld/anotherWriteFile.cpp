#include <cereal/archives/binary.hpp>
#include <cereal/archives/xml.hpp>
#include <fstream>

int main() {
  std::ofstream File{"SaveFile"};
  cereal::BinaryOutputArchive OArchive(File);

  int SomeInt{42};
  float SomeFloat{3.14f};
  bool SomeBoolean{true};

  OArchive(SomeInt, SomeFloat, SomeBoolean);

  std::ofstream file( "out.xml" );
  cereal::XMLOutputArchive archive2( file ); // depending on the archive type, data may be
                                            // output to the stream as it is serialized, or
                                            // only on destruction
  archive2( SomeInt, SomeFloat, SomeBoolean);
}
