#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int n,q;
    cin >> n >> q;
    vector <int> container(n), queries(q);
    
    //Input phase
    //----------------------------
    for (int i = 0; i < n; i++)
    {
        cin >> container[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }
    //----------------------------
    
    //Check State
    //----------------------------
    int state = 0; // states : 0 is ascending , 1 is descending , 2 iscombined ascending then descending
    if (container[0] < container[1])//checks for ascending state
    {
        state = 0;
    }
    else if (container[0] > container[1])//checks for descending state
    {
        state = 1;
    }
    int break_pos = -1;
    if (state == 0)
    {
        for (int i = 0; i < n-1; i++)
        {
            if (container[i] > container[i+1])
            {
                break_pos = i;
                state = 2;
                break;
            }
        }
    }
    //----------------------------
    
    //Binary Search for all in query
    //----------------------------
    for (int i = 0; i < q; i++)
    {
        int k = queries[i];
        bool isFound = 0;
        if (state == 0)
        {
            int start = 0 , end = n-1 , mid;
            while(start <= end)
            {
                mid = (start+end)/2;
                if (container[mid] == k)
                {
                    cout << "Yes " << mid+1;
                    isFound = 1;
                    break;
                }
                else if(container[mid] > k)
                {
                    end = mid -1 ;
                }
                else if(container[mid] < k)
                {
                    start = mid + 1;
                }
                
            }
            if (isFound == 0)
            {
                cout << "No";
            }
            cout << endl;
            
        }
        
        else if(state == 1)
        {
            int start = 0 , end = n-1 , mid;
            while(start <= end)
            {
                mid = (start+end)/2;
                if (container[mid] == k)
                {
                    cout << "Yes " << mid+1;
                    isFound = 1;
                    break;
                }
                else if(container[mid] > k)
                {
                    
                    start = mid + 1;
                }
                else if(container[mid] < k)
                {
                    end = mid -1 ;
                }
                
            }
            if (isFound == 0)
            {
                cout << "No";
            }
            
            
                cout << endl;
                
            
            
            
        }
        
        else if(state == 2)
        {
            int start , end  , mid;
            start = 0 , end = break_pos; 
            
            while(start <= end )
                {
                    mid = (start+end)/2;
                    if (container[mid] == k)
                    {
                        cout << "Yes " << mid+1;
                        isFound = 1;
                        break;
                    }
                    else if(container[mid] > k)
                    {
                        end = mid -1 ;
                    }
                    else if(container[mid] < k)
                    {
                        start = mid + 1;
                    }
                    
                }
            
            start = break_pos+1 , end = n - 1 ;

            while(start <= end )
                {
                    mid = (start+end)/2;
                    if (container[mid] == k)
                    {
                        cout << "Yes " << mid+1;
                        isFound = 1;
                        break;
                    }
                    else if(container[mid] > k)
                    {
                        
                        start = mid + 1;
                    }
                    else if(container[mid] < k)
                    {
                        end = mid -1 ;
                    }
                    
                }
            if (isFound == 0)
            {
                cout << "No";
            }
            cout << endl;
        }    
    }
    //----------------------------
    
    
}