#include <iostream>
#include <vector>
#include <climits>
using std::cout, std::vector;
class Solution
{
public:
    int save(vector<int> &digits)
    {
        int num = 0;
        for (auto numi : digits)
        {
            num = num * 10 + numi;
        }
        return num;
    }
    int countDigits(int num)
    {
        size_t count = 0;
        while (num)
        {
            num /= 10;
            count++;
        }
        return count;
    }

    int reverse(int x)
    {
        bool negative = (x < 0) ? true : false;
        if (countDigits(x) < 10 || x%10==0)
        {
            // bas rev number
            int num = x;
            vector<int> digits;
            while (num)
            {
                digits.push_back(num % 10);
                num /= 10;
            }
            int num2 = save(digits);
            return num2;

        }
        else
        {
            // tenDigitsWork(x);
            int num = (negative)?-x:x;
            vector<int> digits;
            vector<int> digitsM = {2, 1, 4, 7, 4, 8, 3, 6, 4}; // last digit 7/8 chhod di
            //digits banaliye
            while (num)
            {
                digits.push_back(num % 10);
                num /= 10;
            }
            // cout<<"digits poori: size: " <<digits.size()<<'\n';
            // for(auto numi : digits) {
            //     cout<<numi<<' ';
            // }cout<<'\n';

            //digits check karliye
            bool bahar(false);
            for (unsigned int i(0); i < 9; i++)
            {
                if (digits[i] > digitsM[i])
                {
                    bahar = true; // matlab zero
                    // cout<<0<<'\n';
                    break;
                }
            }
            int cmp = (negative) ? 8 : 7;
            if (!bahar && digits[9] > cmp)
            {
                bahar = true;
            }

            if (bahar)
            {
                //cout << 0 << '\n';
                return 0;
            }
            else
            {
                return save(digits);
            }
            //cout << '\n';
        }

        cout<<"Kaise hua, kaise hua?\n";
        return x;
    }
};
int main()
{
    Solution s;
    // cout<<s.reverse(123)<<'\n';
    // cout<<s.reverse(-123)<<'\n';
    // cout<<s.reverse(120000)<<'\n';
    cout<<s.reverse(2147447412)<<'\n';

    return 0;
}