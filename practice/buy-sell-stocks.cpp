/*
test cases
{7, 10, 1, 3, 6, 9, 2} -> 8
prices = [100, 180, 260, 310, 40, 535, 695] -> 655
prices = [1000000, 999999, 999998, 999997] -> 0
prices = [50, 200, 150, 180, 90, 500, 600, 450, 700, 1000, 800, 900, 950, 1200] -> 1150
prices = [200, 150, 180, 350, 500, 600, 420, 700, 400, 750, 900, 1000, 1100] -> 950
prices = [700, 600, 800, 1500, 200, 400, 650, 500, 1200, 1500, 1000, 850, 900] -> 1300

*/

#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

int maxProfit(vector<int> prices) {
    // check sorted backwards
    bool backSorted { true };
    for (int i {1} ; i < prices.size(); i++ ) {
        if (prices[i-1]<prices[i]) {
            // it means it's not back sorted
            backSorted = false;
            break;
        }
    }
    if (backSorted) return 0;
    
    // check sorted
    bool sorted { true };
    for (int i {1} ; i < prices.size(); i++ ) {
        if (prices[i-1]>prices[i]) {
            // it means it's not sorted
            sorted = false;
            break;
        }
    }
    if ( sorted && prices[0] != prices[ prices.size()- 1 ] ) 
        return prices[ prices.size()- 1 ] - prices[0];
     
    int resultMinStockDay{-1},resultMaxStockDay{-1};
    int minStock { 999999 };  // TODO set to int max
    int minStockIndex { -1 };
    int result {0},thisProfit {0};
    for (int i {0} ; i < prices.size(); i++ ) {
        if (prices[i] < minStock) {
            minStock = prices[i];
            minStockIndex = i;
        }
        thisProfit = prices[i]-minStock ;
        if (thisProfit > result) {
            resultMinStockDay = minStockIndex;
            resultMaxStockDay = i;
            result = thisProfit;
        }
        cout << "i: " << i << ",  profit: " << thisProfit <<'\n';
    }
    
    cout << "min: " << resultMinStockDay << '\n';
    cout << "max: " << resultMaxStockDay << '\n';
    
    
    return prices[resultMaxStockDay] - prices[resultMinStockDay];
    
}

int main()
{

    vector<int> prices {50, 200, 150, 180, 90, 500, 600, 450, 700, 1000, 800, 900, 950, 1200};
    cout << maxProfit(prices) << '\n';
    return 0;
}