#include <cereal/archives/xml.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <fstream>
#include <cstdio>
#include "MeriClass.cpp"
using std::cout;

int main()
{
  std::ofstream file1{"mainSaveFile.xml"}; // any stream can be used
  std::ofstream file1json{"mainSaveFile.json"}; // any stream can be used

  {
    cereal::XMLOutputArchive oarchiveBin(file1); // Create an output archive
    cereal::JSONOutputArchive oarchiveJson(file1json); // Create an output archive
//    cereal::XMLOutputArchive oarchiveXML(ss); // Create an output archive

    MeriClass m1(3,4,1000), m2(-123,-10,-40), m3;
    oarchiveBin(m1, m2, m3); // Write the data to the archive
    oarchiveJson(m1, m2, m3); // Write the data to the archive
//    oarchiveXML(m1, m2, m3); // Write the data to the archive
  } // archive goes out of scope, ensuring all contents are flushed
	file1.close();
	file1json.close();


#if 1	
  std::ifstream file2{"mainSaveFile.xml"};
  std::ifstream file2json{"mainSaveFile.json"};

  {
    cereal::XMLInputArchive iarchive(file2); // Create an input archive
    cereal::JSONInputArchive iarchiveJson(file2json); // Create an input archive

    MeriClass m4, m5, m6;
    iarchive(m4, m5, m6); // Read the data from the archive
    iarchiveJson(m4, m5, m6); // Read the data from the archive
	cout<<"printing retrieved objects from json\n";
	cout<<m4.x<<','<<m4.y<<','<<m4.z<<'\n';
	cout<<m5.x<<','<<m5.y<<','<<m5.z<<'\n';
	cout<<m6.x<<','<<m6.y<<','<<m6.z<<'\n';


  }
  file2.close();
  file2json.close();
#endif

}

