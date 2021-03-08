#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf LLONG_MAX
#define MAXN 100008

long long n, k, arr[MAXN], ans;

int main()
{

    ans=inf;
    cin>>n>>k;
    for(long long i=1; i<=n; i++)
        cin>>arr[i];
    for(long long beg=1; beg<=1+k; beg++)
    {
        long long cost=0, nxt=beg;
        while(nxt<=n)
        {
            cost+=arr[nxt];
            nxt=nxt+2*k+1;
        }
        nxt=nxt-2*k-1;
        if(nxt+k>=n)
            ans=min(cost,ans);
    }
    cout<<ans<<endl;
    return 0;
}
