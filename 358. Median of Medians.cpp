/*
Time limit per test: 0.25 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard



Vasya learned definition of median of three numbers. He says, "Median of three numbers is the number located in the middle when numbers are ordered in non-descending order". Subtle Pete gave him much more difficult task. Vasya has to find median of each of three triples and then find the median of three numbers he found. Please help Vasya with the task.

Input
The input file contains three lines. Each line contains three integers. Each number is not less than -1000 and is not greater than 1000.

Output
Print one number - median of three medians.

Example(s)
sample input
sample output
6 4 5 
7 9 8 
1 2 3
5

sample input
sample output
1 2 2 
4 3 2 
2 3 4
3

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Median_Of_Three_Medians()
{
    vector <int> ThreeNumbers;
    vector <vector <int>> ThreeNumbers_set;
    for (int i = 0; i < 3; i++)
    {
        ThreeNumbers.clear();
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            ThreeNumbers.push_back(x);
        }
        ThreeNumbers_set.push_back(ThreeNumbers);
    }
    ThreeNumbers.clear();
    for (int i = 0; i < 3; i++)
    {
        sort(ThreeNumbers_set[i].begin(),ThreeNumbers_set[i].end());
        ThreeNumbers.push_back(ThreeNumbers_set[i][1]) ;
    }
    sort(ThreeNumbers.begin(),ThreeNumbers.end());
    return ThreeNumbers[1];
}

int main()
{
    cout << Median_Of_Three_Medians();
}