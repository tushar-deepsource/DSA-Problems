// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int N){
        // code here
        long long ls[N+1];
        ls[0]=ls[1]=ls[2]=ls[3]=1;
        for(int i=4;i<=N;i++)
            ls[i] = ls[i-4]+ls[i-1];
        return ls[N];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
