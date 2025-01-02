//https://leetcode.com/problems/merge-strings-alternately/
#include <string>
#include <iostream>
using namespace std;


using ui = unsigned;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        ui len1(word1.length()),len2(word2.length());
        ui len = len1 + len2 +1;
        char res[len];
        res[len-1] = '\0';
        ui i1(0),i2(0), i(0);

        while ( i1<len1 || i2<len2 ) {
            if (i1<len1) {
                res[i] = word1[i1];
                i++,i1++;
            }
            if (i2<len2) {
                res[i] = word2[i2];
                i++,i2++;
            }
        }

        string result = res;
        return result;
  
    }
};

int main(){
    Solution sol;
    //cout<< sol.mergeAlternately("abc","pqr") << endl;
    //cout<< sol.mergeAlternately("ab","pqrst") << endl;
    string ans = sol.mergeAlternately("abcdefgh","pq");
    cout<< ans  << "]"<< endl;
    return 0;
}