#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int x , counter = 0;
    cin >> x;
    int res = 0;
    while(counter < x)
    {
            counter++;
            int test = __gcd(counter, x);
            if (  test == 1)
            { 
                res++;
            }
    }
    cout << res;
}