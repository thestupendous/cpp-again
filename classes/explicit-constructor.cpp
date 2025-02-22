/*
	 The explicit keyword
	 We can use the explicit keyword to tell the compiler that a constructor should not be used as a converting constructor.

   Making a constructor explicit has two notable consequences:

    An explicit constructor cannot be used to do copy initialization or copy list initialization.
    An explicit constructor cannot be used to do implicit conversions (since this uses copy initialization or copy list initialization).
		
*/



#include <iostream>
class Rupees
{
	private:
		uint64_t rupees;

	public:
		explicit Rupees(uint64_t r)
			: rupees{r}
		{}

    uint64_t getRupees() const { return rupees; }
};

void print(Rupees r) {
	std::cout << "Rs " << r.getRupees();
}

int main() {
	print(56); //compilation error because Rupees(int) is explicit

	return 0;
}

