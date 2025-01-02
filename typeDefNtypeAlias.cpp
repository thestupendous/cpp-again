#include <string> // for std::string
#include <vector> // for std::vector
#include <utility> // for std::pair

using VectPairSI = std::vector<std::pair<std::string, int>>; // make VectPairSI an alias for this crazy type

bool hasDuplicates(VectPairSI pairlist) // use VectPairSI in a function parameter
{
    // some code here
    return false;
}


using TestScore = int;

TestScore gradeTest()
{
    //some code
    return 45;
}


int main()
{
     VectPairSI pairlist; // instantiate a VectPairSI variable


    // code maintenance
    TestScore gradeTest();
    return 0;
}