#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> CreatePossibilities(vector <int> a)
{
    vector <int> Possibilities;

        for(int j = 0 ; j < a.size() ; j++)
        {
            Possibilities.push_back(a[j]+1);
            Possibilities.push_back(a[j]+2);
        }
    return Possibilities;
}

int main()
{
    vector <int> Tree = {1,2};
        int hours = 5;
        vector <int> node;
        int counter = 0;
        for(int j = 0 ; j < hours-1;j++)
        {
            Tree = CreatePossibilities(Tree);
            for(auto jj:Tree)
                {
                    if(hours == jj)
                    {
                    counter++;
                    }
                }
        }
        cout << counter;
    
}