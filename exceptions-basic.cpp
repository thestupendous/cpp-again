#include<iostream>
using std::cout;
int main(){

	cout<< "<<\n";

	try{
		//statements that throw exceptions
	cout<< "{{\n";
		throw 1;
	} catch (int x) {
		//handle exceptions of type int
		std::cerr << "Ek error aya hai, error code ye hai "<< x << '\n';
	cout<< "))\n";

	}

	cout << "Ab sab normal\n";
	throw 201;
	catch (int x) {
		//handle exceptions of type int
		std::cerr << "Ek Aur error aya hai, error code ye hai "<< x << '\n';
	cout<< "))\n";

	}




	//cout<< "((\n";

	return 0;
}
