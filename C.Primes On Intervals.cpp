#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <bool>
Sieve_Of_Eratosthenes(int max)
{
    vector <bool> isPrime(max,1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= max; i++)
    {
        if (isPrime[i])
        {
            for (int j = i*i; j <= max; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
}



int main()
{
    int a,b ,k; 
    cin >> a >> b >> k;
    int primes = 0;
    bool isFound = 0;
    int last;
    int i = a ;
    vector <bool> isPrime(b); 
    isPrime = Sieve_Of_Eratosthenes(b);
    while(primes < k + 1)
    {
        if (primes <= k)
        {
            if (isPrime[i])
            {
                primes++;
                last = i;
            }
        }
        // last + 1 - a=   l 
        if(primes > k)
        {
            int l = last - 1 - a;
            cout << l;
            isFound = 1;
            break;
        }
        i++;
    }
    if (!isFound)
    {
        cout << -1 ;
    }
    
}