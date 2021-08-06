#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map <string,int> league;
    set <string> teams;
    while(n--)
    {
        string c;
        char w;
        cin >> c >> w;
        teams.insert(c);

        if (w=='W')
        {
            league[c] += 3; 
        }
        else if(w=='D')
        {
            league[c] += 1;
        }
        else
        {
            league[c] += 0;
        }
        
    }
    auto x = teams.begin();
    cout << teams.size() << endl;
    for (; x != teams.end(); x++)
    {
        string team = *x ;
        cout << team << " " << league[team] << endl;
    }
    
    {
        
    } 
}