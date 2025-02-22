//reverse a sentence using recursion
//bohot ghatiya approach -> to use recursion for handling string

#include<iostream>
#include<string>
using namespace std;

string reverse(string sen) {
int k;
	if (sen.find(' ') == std::string::npos ) return sen ;
	//pehla word nikal
	int spaceI = sen.find(' ');
	string pehla { sen.substr(0,spaceI) };
  string revPehla { reverse(pehla) };

	//baki string nikal
	string baaki { sen.substr(spaceI+1) };
  string revBaaki { reverse(baaki) };

	// nayi ulti string banake return
	return revBaaki + ' ' + revPehla;
}

int main() {

	string a { "youtuber ke dimag me" };
	
	cout << '[' << reverse(a) << ']' << '\n';

	return 0;
}

