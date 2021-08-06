#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <char> DistinctLetters(string a)
{
    sort(a.begin(),a.end());
    vector <char> x;
    for(int i = 0 ; i < a.length() ; i++)
    {
        x.push_back(a[i]);
    }
    x.erase(unique(x.begin(),x.end()),x.end());
    return x;
}

vector <int> FindLetterFrequency(string a , vector <char> x)
{
    vector <int> Freq;
    for(auto i:x)
    {
        int counter = 0;
        for(auto j : a)
        {
            if(i == j)
            {
                counter++;
            }
        }
        Freq.push_back(counter);
    }
    return Freq;
}

bool isPalindrome(string a , vector <int> x)
{
    bool test = 1;
    if(a.length() % 2 == 0)
    {
        for(auto i:x)
        {
            if(i%2 == 1)
            {
                test = 0;
            }
        }
    }
    else
    {
        if(a.length() % 2 == 1)
        {
            int counter;
            for(auto z:x)
            {
                if(z%2 == 1)
                {
                    counter++;
                }
                if(counter > 1 )
                {
                    test = 0;
                }
            }
        }   
    
    }
    return test;
}

int CutAmount(string a,vector <int> x)
{
    int res ;
    bool palindrome = isPalindrome(a,x);
    if(palindrome != 1)
    {
        int counter = 0;
        if(a.length() % 2 == 0)
    {
        for(auto i:x)
        {
            if(i%2 == 1)
            {
                counter++;
            }
        }
        res = counter-1;
    }
        if(a.length() % 2 == 1)
        {
            
            for(auto z:x)
            {
                if(z%2 == 1)
                {
                    counter++;
                }
            }
            res = counter - 1;
        }
    }
    return res;
}
int main()
{
    string mainstring , playwithstring;
    cin >> mainstring;
    int result = 0;
    for(int i = mainstring.length() ; i > 0;i--)
    {
        playwithstring += mainstring.substr(0,i);
        vector <char> x = DistinctLetters(mainstring);
        vector <int> xx = FindLetterFrequency(playwithstring,x);
        int a = CutAmount(playwithstring,xx);
        result += a;
    }
    cout << result;
     
    
}