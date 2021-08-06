#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;
    queue <int> q;
    while (t--)
    {
        int x, id;
        cin >> x;
        if (x==1)
        {
            cin >> id;
            q.push(id);
        }
        
        if(x==2)
        {
            cin >> id;
            int comp = q.front();
            q.pop();
            if (id==comp)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            
        }
        
    }
    
}