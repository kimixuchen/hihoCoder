/*
MS-2
08/04/17 19:23:31
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

long long getTime(long long jobs, long long bots)
{
    long long t = 0;
    if(jobs%bots != 0)
        t = 1;
    t += jobs/bots;
    
    return t;
}
int main()
{
    long long N, Q;
    cin>>N>>Q;
    
    long long jobs = N, bots = 1;
    
    long long t = 0;
    while(true)
    {
        long long tl = getTime(jobs, bots);
        if(tl>=2*Q)
        {
            t += Q;
            bots *= 2;
        }
        else
        {
            t += tl;
            break;
        }
        /**
        else
        {
            if(jobs>2*bots)
            {
                t += Q;
                bots *= 2;
            }
            else
            {
                t += 1;
                jobs -= bots;
            }
        }
        **/
    }
    cout<<t<<endl;

    return 0;
}
