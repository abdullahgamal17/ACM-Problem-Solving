#include <vector>
#include <iostream>
#include <cmath>


using namespace std;

void Pharoah_Binary_Search(long long n)
{
    long long x = 1;
    long long upper_limit , lower_limit;
    while (n >= (x*(x+1)/2))
        {
            lower_limit = x;
            x+=1000000000;
            upper_limit = x;
        }
        if (n < (upper_limit*(upper_limit+1)/2))
        {
            long long start = lower_limit , end = upper_limit , mid;
            
            while (start <= end)
            {
                mid = (start + end)/2;
                long long left_limit = (mid * (mid+1) /2);
                long long rigth_limit = ((mid+1) * (mid+2) /2);
                if (n == 1)
                {
                    cout << 1 ;
                    break;
                }
                else if(n == 2 || n == 3)
                {
                    cout << 2  ;
                    break;
                }
                else if(n == 4 || n == 5 || n == 6)
                {
                    cout << 3 ;
                    break;
                }
                
                else if (left_limit < n && n <= rigth_limit)
                {
                    cout << mid + 1 ;
                    break;
                }
                else if (left_limit >= n && rigth_limit >= n)
                {
                    end = mid -1 ;
                }
                else
                {
                    start = mid + 1;
                }
                
            }
            
        }
}

int main()
{
    long long n ;
    long long t;
    cin >> t;
    n = 1;
    long long  x = 1;
    while(t--)
    {
        cin >> n;
        Pharoah_Binary_Search(n);
        cout << endl;
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}