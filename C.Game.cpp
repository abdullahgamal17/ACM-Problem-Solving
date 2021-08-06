#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n , q;
    cin >> n >> q;
    vector <long long> container(n) , queries(q);
    for (long long i = 0; i < n; i++)
    {
        cin >> container[i];
    }
    for (long long i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    
    for (int i = 0; i < q; i++)
    {
        long long k = queries[i];
        long long start = 0 , end = n-1 , mid;
        bool isFound = 0;
        while(start <= end)
        {
            mid = (start + end)/2;
            if (container[mid] <= k &&container[mid+1] > k &&mid != n-1)
            {
                cout << container[mid+1] << endl;
                isFound = 1;
                break;
            }
            else if(k < container[0])
            {
                cout << container[0] << endl;
                isFound = 1;
                break;   
            }
            else if(container[mid] > k)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            
        }  
        if (!isFound)
        {
            cout << -1;
            cout << endl;
        }
        
    }
    

}