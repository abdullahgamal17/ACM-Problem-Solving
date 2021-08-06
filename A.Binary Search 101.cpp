#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    long long a , b , k;
    cin >> a >> b >> k;
    long long start = a , end = b , mid;
    long long steps = 0;
    while (start <= end)
    {
        
        mid = (start + end)/2;
        if ( mid == k)
        {
            steps++;
            break;
        }
        else if(mid > k)
        {
            steps++;
            end = mid - 1;
        }
        else
        {
            steps++;
            start = mid +1;
        }
    }

    cout << steps;
    
}
