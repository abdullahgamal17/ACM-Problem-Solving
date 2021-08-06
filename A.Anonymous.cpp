#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1;
    getline(cin,s1);
    string s2;
    getline(cin , s2);
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());
    int s1l = s1.length() , s2l = s2.length();
    vector <char> s1p(s1l),s2p(s2l);
    for (int i = 0; i < s1l; i++)
    {
        s1p[i]= s1[i];
    }
    for (int i = 0; i < s2l; i++)
    {
        s2p[i] = s2[i];
    }
    
    while(!s2p.empty())
    {
        int pos = s2p.size()-1;
        char x = s2p[pos];
        auto i = s1p.begin();
        bool isFound = 0;
        for (; i != s1p.end();i++)
        {
            if (*i == x)
            {
                s1p.erase(i);
                s2p.pop_back();
                isFound = 1;
                break;
            }
        }
        if (!isFound)
        {
            cout << "NO" ;
            break;
        }
    }
    if (s2p.empty())
    {
        cout << "YES" ;
    }

    
}