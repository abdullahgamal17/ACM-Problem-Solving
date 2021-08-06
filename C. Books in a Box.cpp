#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int x;
    cin >> x;
    stack <int> box;
    while (x--)
    {
        int ch ;
        cin >> ch;
        if (ch == 1)
        {
            int id;
            cin >> id;
            box.push(id);
        }
        else if(ch == 2)
        {
            if (!box.empty())
            {
                box.pop();
            }
            
            
        }
        else
        {
            if (!box.empty())
            {
                cout << box.top() << endl;
            }
            
            
        }
        
    }
    
}