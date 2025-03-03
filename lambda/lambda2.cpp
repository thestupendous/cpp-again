// lambda syntax
// [ captures ] ( params ) specs requires (optional) { body }
#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>

bool containsSantara( std::string_view str ) {
	return str.find("santara") != std::string_view::npos;
}

int main() {
	using std::cout;
	constexpr std::array < std::string_view, 4 > ar {
		"apple", "banana",
		"santara", "anaar"
	};

	// without lambda/closure
	// auto found { std::find_if ( ar.begin(), ar.end(), containsSantara ) };

	// without lambda/closure
	auto found { std::find_if ( ar.begin(),
			ar.end(),
			[] (std::string_view st)
			{
				return st.find("santara") != std::string_view::npos;
			}
			) };

	
	if ( found == ar.end() )
	{
		cout << "Santara hath nai aya!\n";
	} else {
		cout << "Santara mil gaya! " << *found << '\n';
	}

	return 0;
}


