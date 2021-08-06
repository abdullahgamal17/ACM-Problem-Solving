#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

/*
105. Div 3

time limit per test: 0.25 sec.
memory limit per test: 4096 KB

There is sequence 1, 12, 123, 1234, ..., 12345678910, ... . Given first N elements of that sequence. You must determine amount of numbers in it that are divisible by 3.


Input

Input contains N (1<=N<=231 - 1).


Output

Write answer to the output.

Sample Input

4
Sample Output

2
*/

/*
1 12 123 1234 12345 123456 1234567 12345678 123456789 1234567890 12345678901 123456789012 1234567890123  
1  2  3   4    5     6       7       8          9      10           11           12          13          
*/


#include <iostream>
using namespace std;
int main()
{
    unsigned int n ;
    cin >> n;
    unsigned long long result = (n*2)/3;
    cout << result;
}