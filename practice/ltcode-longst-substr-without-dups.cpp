/*
	 //TODO Make algo first

	 for a string,  find the length of the longest 
	 substring without duplicate characters.

	 https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/
#include <cstdint>
#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

			uint_fast32_t bigst {0};

			if (s.size() == 0) return 0;
			if (s.size() == 1) return 1;

			char last { s[0] };
			map
			for (uint_fast32_t i {1} ; i < s.size() ; i++ ) {
				if ( checkDup() ) {
					// dup found
				} else {
					// keep doing
				}
			}

			
        
    }
};

int main() {
	Solution s;
	s.lengthOfLongestSubstring("pwwkew");

	return 0;
}
