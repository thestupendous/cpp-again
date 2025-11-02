#include<fstream>
using std::ofstream;
int main() {
	ofstream outFile{"3kb-file.txt"};
	for(auto i{0};i<1024;i++) {
		outFile << "0";
	}
	for(auto i{0};i<1024;i++) {
		outFile << "0";
	}
	for(auto i{0};i<1024;i++) {
		outFile << "0";
	}
	outFile.close();
	return 0;
}
