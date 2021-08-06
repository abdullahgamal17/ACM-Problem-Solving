#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
    int n_piles;
    cin >> n_piles;
    int sum = 0;
    vector <pair<int,int>> indices(n_piles);
    int x;
    cin >> x;
    int start_i , end_i=x; 
    indices[0] = {1,x};
    for (int i = 0; i < n_piles-1; i++)
    {
        start_i = end_i+1;
        cin >> x;
        end_i = start_i + x - 1;
        indices[i+1] = {start_i,end_i};
    }
    int m ;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int start = 0 , end = n_piles-1 , mid;
        int test;
        cin >> test;
        while (start <= end)
        {
            mid = (start + end)/2;
            if (indices[mid].first <= test && test <= indices[mid].second)
            {
                cout << mid + 1 << endl;
                break;
            }
            else if(indices[mid].first < test && indices[mid].second < test)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }    
    }
     
}