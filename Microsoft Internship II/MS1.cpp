/*
MS-1
08/04/17 19:13:43
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

int main()
{
    unordered_map<int, int> rows;
    unordered_map<int, int> cols;
    unordered_map<int, int> dias;
    unordered_map<int, int> udias;
    
    int n;
    int x, y;
    int ans = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; ++i)
    {
        scanf("%d %d", &x, &y);
        if(rows.find(x)!=rows.end())
        {
            ans += rows[x];
            rows[x]++;
        }
        else
        {
            rows[x] = 1;
        }
        
        if(cols.find(y)!=cols.end())
        {
            ans += cols[y];
            cols[y]++;
        }
        else
        {
            cols[y] = 1;
        }
        
        if(dias.find(x+y)!=dias.end())
        {
            ans += dias[x+y];
            dias[x+y]++;
        }
        else
        {
            dias[x+y] = 1;
        }
        
        if(udias.find(y-x+n-1)!=udias.end())
        {
            ans += udias[y-x+n-1];
            udias[y-x+n-1]++;
        }
        else
        {
            udias[y-x+n-1] = 1;
        }
        
    }
        printf("%d\n", ans);

    return 0;
}
