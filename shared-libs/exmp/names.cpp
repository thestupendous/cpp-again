#include<string>
std::string name(int ind) {
	switch (ind) {
		case 1:
			return "apple";
		case 2:
			return "seb";
		case 3:
			return "halwa";
		case 4:
			return "potato";
		default:
			return "a";
	}
	return "b";
}
