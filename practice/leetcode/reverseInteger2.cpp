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
    int rev(const int initialNum)
    {
        int num = initialNum;
        int reverse = 0;
        while (num)
        {
            reverse = 10 * reverse + num % 10;
            num /= 10;
        }
        return reverse;
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

        if (countDigits(x) < 10 || x % 10 == 0)
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
            int num = (negative) ? -x : x;

            int tenthDigit = num % 10000000000;
            if (tenthDigit > 2)
            {
                return 0;
            }
            else
            {
                num = num - tenthDigit*10000000000;
                int numMax = INT_MAX/10;
                int reverse = rev(num);
                int cmp = (negative)?8:7;
                
                if (!negative reverse > INT_MAX)
                {
                    return 0;
                }
                {
                    return 0;
                }
            }
        };
        int main()
        {
            Solution s;
            // cout<<s.reverse(123)<<'\n';
            // cout<<s.reverse(-123)<<'\n';
            // cout<<s.reverse(120000)<<'\n';
            cout << s.reverse(2147447412) << '\n';

            return 0;
        }