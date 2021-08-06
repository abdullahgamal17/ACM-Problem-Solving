#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
Time limit per test: 1 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard



It is not easy to prepare a problem for a programming contest. Petya and Vasya decided that problem "A+B" needs at least n distinct solutions to be written. It doesn't matter how many solutions each of them will write, they need to write at least n solutions in total. We know that Petya needs t1 units of time to write a solution, and Vasya needs t2 units of time. They start to work simultaneously at time 0. Thus, for example, Petya finishes writing his first solution at time t1, his second solution at 2 · t1 and so on.

Petya and Vasya are working by the same algorithm. Each time Petya (Vasya) finishes writing a solution, he checks on how many solutions have already been written up to the current time moment t. Ready solutions are the solutions that have been fully written by this time. The solutions that were fully finished exactly at time t are also considered ready. If the number of such solutions is strictly less than n, then Petya (Vasya) starts writing the next solution. If a member of the jury began working on a problem, he doesn't stop working under any circumstances, and he will surely finish it.

Petya and Vasya realize that if they act on this algorithm, they will not necessarily write exactly n solutions in total. Maybe they'll write more solutions.

Considering that Petya and Vasya work non-stop, find, how many solutions they wrote in total and the moment when the latest solution was finished. The latest solution is one which was finished last.

Input
The only input line contains three integers n, t1 and t2 (1 ≤ n, t1, t2 ≤ 5000).

Output
Print two integers — m and f, where m is the number of written solutions, and f is the moment when the last solution was finished.

Example(s)
sample input
sample output
5 2 3
5 6

sample input
sample output
5 2 4
6 8

sample input
sample output
3 30 50
4 100



Note
In the first sample Petya finished his solutions at time 2, 4 and 6, and Vasya — at time 3 and 6. They finished writing their last solutions simultaneously, at time 6, and at this exact moment they already had the total of 5 written solutions and stopped working.

*/

// Petya needs t1 time to find a solution , Vasya needs t2 time to find a solution , both simultaniously should form at least n solutions and output f which is the last moment where n or more solutions were made
bool isWorking(int totalsolved , int n)
{
    bool isWorking;
    if(n > totalsolved)
    {
        isWorking = 1; // still working
    }
    else
    {
        isWorking = 0; // not working
    }
    return isWorking;
}

int DoWork(int t1 , int timecount)
{
    int totalsolved = 0;
    if(timecount%t1 == 0)
    {
        totalsolved = 1;
    }
    return totalsolved;
}
void ProblemMaker()
{
    int n , t1 , t2,f,totalsolved = 0,timecount = 0;
    cin >> n >> t1 >> t2;
    bool t1isworking = 1 , t2isworking = 1;
    int totalsolvedaftert1= 0,totalsolvedaftert2=0;
    while(t1isworking == 1 || t2isworking == 1)
    {
        timecount++;
        if(timecount%t1 == 0)
        {
            
            if(t1isworking)
            {
                totalsolved += DoWork(t1,timecount);
                totalsolvedaftert1 = totalsolved;
                f = timecount;
            }
            
        }
        
        if(timecount % t2 == 0)
        {
            
            if(t2isworking)
            {
                totalsolved += DoWork(t2,timecount);
                totalsolvedaftert2 = totalsolved;
                f = timecount;
            }
            
            
        }
        t2isworking = isWorking(totalsolvedaftert2,n);
        t1isworking = isWorking(totalsolvedaftert1,n);
        if(timecount%t1 == 0 && timecount%t2 == 0 && totalsolved >= n)
        {
            break;
        }  
    }
  
    cout << totalsolved << " " << f;
    
}
int main ()
{
    ProblemMaker();
} 
//Accepted   
