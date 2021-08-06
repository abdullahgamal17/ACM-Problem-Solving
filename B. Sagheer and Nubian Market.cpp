/*
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
On his trip to Luxor and Aswan, Sagheer went to a Nubian market to buy some souvenirs for his friends and relatives. The market has some strange rules. It contains n different items numbered from 1 to n. The i-th item has base cost ai Egyptian pounds. If Sagheer buys k items with indices x1, x2, ..., xk, then the cost of item xj is axj + xj·k for 1 ≤ j ≤ k. In other words, the cost of an item is equal to its base cost in addition to its index multiplied by the factor k.

Sagheer wants to buy as many souvenirs as possible without paying more than S Egyptian pounds. Note that he cannot buy a souvenir more than once. If there are many ways to maximize the number of souvenirs, he will choose the way that will minimize the total cost. Can you help him with this task?

Input
The first line contains two long egers n and S (1 ≤ n ≤ 105 and 1 ≤ S ≤ 109) — the number of souvenirs in the market and Sagheer's budget.

The second line contains n space-separated long egers a1, a2, ..., an (1 ≤ ai ≤ 105) — the base costs of the souvenirs.

Output
On a single line, prlong  two long egers k, T — the maximum number of souvenirs Sagheer can buy and the minimum total cost to buy these k souvenirs.

Examples
inputCopy
3 11
2 3 5
outputCopy
2 11
inputCopy
4 100
1 2 5 6
outputCopy
4 54
inputCopy
1 7
7
outputCopy
0 0
Note
In the first example, he cannot take the three items because they will cost him [5, 9, 14] with total cost 28. If he decides to take only two items, then the costs will be [4, 7, 11]. So he can afford the first and second items.

In the second example, he can buy all items as they will cost him [5, 10, 17, 22].

In the third example, there is only one souvenir in the market which will cost him 8 pounds, so he cannot buy it.
*/

/* Input :
    First Line contains n items (n is number of items in the store) and S (sameers budget)
    Second Line contains n base prices for all souvenirs (base prices are called a)
    Note : the price of souvenir is calculated as a + (index * k) , k being number of souvenirs that will be bought
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long  number_of_souvenirs; // n
    long  s_budget;//s
    cin >> number_of_souvenirs >> s_budget;
    vector <long > base_prices(number_of_souvenirs);
    for (long  i = 0; i < number_of_souvenirs; i++)
    {
        cin >> base_prices[i];
    }
    long  start = 0;
    long  end = number_of_souvenirs-1;
    long  mid; // 
    long  furthest_number;
    while (start <= end)
    {
        mid = (start + end)/2;
        long limit = (number_of_souvenirs*(number_of_souvenirs + 1))/2;
        if (s_budget >= limit)
        {
            furthest_number = end;
            break; 
        }
        else if(s_budget < limit)
        {
            end = mid-1;
        }
    }
    long  k;
    long  sum = 0;
    bool done = 0;
    
    
        vector <long > attempts(furthest_number+1);
        vector <long > prices_attempts(furthest_number+1);
        for (long  i = furthest_number; i >= 0; i--)
        {
            sum = 0;
            k = i+1;
            vector <long > prices_to_buy(number_of_souvenirs);
            for (long  j = 0; j < number_of_souvenirs; j++)
            {
                long  mult = (k*(j+1));
                prices_to_buy[j] = base_prices[j] + mult;
            }
            //sort(prices_to_buy.begin() , prices_to_buy.end());
            long  pieces = 0;
            while (sum <= s_budget && pieces < i+1)
            {
                sum += prices_to_buy[pieces];
                pieces++;

            }
            attempts[furthest_number-i] = pieces;
            prices_attempts[furthest_number-i] = sum;
            
        }
        bool f = 0;
        int maxsouv;
        for (long  i = 0; i < furthest_number+1; i++)
        {
            if (prices_attempts[i] <= s_budget)
            {
                maxsouv = attempts[i];
                f = 1;
                break;
            }
        }
        long long price = 1000000000000000;
        for (int i = 0; i <= furthest_number; i++)
        {

            if (attempts[i] < maxsouv)
            {
                continue;
            }
            else if (attempts[i] == maxsouv)
            {
                if (prices_attempts[i] < price)
                {
                    price = prices_attempts[i];
                }
                
            }
        }
        
        if (f == 0)
        {
            cout << 0 << " " << 0;
        }
        else
        {
            cout << maxsouv << " " << price;
        } 
        
        
        
    
    
    
}