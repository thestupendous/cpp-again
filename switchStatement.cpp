//didn't know this, The condition in a switch must evaluate to an integral type
#include  "standardHeader.h"

void printDigitName(int x)
{
	switch (x) // x is evaluated to produce value 5
	{
		case 1:
			std::cout << "One";
			return;
		case 2:
			std::cout << "Two";
			return;
		case 3:
			std::cout << "Three";
			return;
		default: // which does not match to any case labels
			std::cout << "Unknown"; // so execution starts here
			return; // and then we return to the caller
	}


} 
bool isVowel(char c);


int main()
{
	printDigitName(5);
	std::cout << '\n';

	//switch fall through
	switch (2)
	{
		case 1: // Does not match
			std::cout << 1 << '\n'; // Skipped
			[[ fallthrough ]]; // intentional fallthrough -- note the semicolon to indicate the null statement
		case 2: // Match!
			std::cout << 2 << '\n'; // Execution begins here
									// modern compiler throws error
			[[ fallthrough ]]; // intentional fallthrough -- note the semicolon to indicate the null statement
		case 3:
			std::cout << 3 << '\n'; // This is also executed
			[[ fallthrough ]]; // intentional fallthrough -- note the semicolon to indicate the null statement
		case 4:
			std::cout << 4 << '\n'; // This is also executed
			[[ fallthrough ]]; // intentional fallthrough -- note the semicolon to indicate the null statement
		default:
			std::cout << 5 << '\n'; // This is also executed
	}


	//avoid fallthrough warnings
	cout << ((isVowel('a') ) ? ("yes, vowel") : ("no, not vowel")) << '\n';
	return 0;
}

bool isVowel(char c)
{
	//avoid fallthrough warnings
    switch (c)
    {
    case 'a': // if c is 'a'
    case 'e': // or if c is 'e'
    case 'i': // or if c is 'i'
    case 'o': // or if c is 'o'
    case 'u': // or if c is 'u'
    case 'A': // or if c is 'A'
    case 'E': // or if c is 'E'
    case 'I': // or if c is 'I'
    case 'O': // or if c is 'O'
    case 'U': // or if c is 'U'
        return true;
    default:
        return false;
    }
}
