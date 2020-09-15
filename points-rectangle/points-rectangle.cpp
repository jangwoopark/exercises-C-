#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

int main() {
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        pii A[n];
        int xmin = 100000, ymin = 100000, xmax = -100000, ymax = -100000;
        for(int i = 0; i < n; i++){
            cin>>A[i].first>>A[i].second;
            if(xmin > A[i].first ){
                xmin = A[i].first ;
            }
            if(xmax < A[i].first ){
                xmax = A[i].first;
            }
            if(ymin > A[i].second)
                ymin = A[i].second;
            if(ymax < A[i].second)
                ymax = A[i].second;
            
        }
        bool b = true;
        for(int i = 0; i < n; i++){
            if(A[i].first < xmin || A[i].first > xmax || A[i].second < ymin || A[i].second > ymax)
                b = false;
            if(A[i].first == xmin || A[i].first == xmax || A[i].second == ymin || A[i].second == ymax)
                string s;
            else
                b = false;
            
        }
        if(b )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
