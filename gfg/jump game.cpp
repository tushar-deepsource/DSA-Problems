// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int fun(int i,int A[],int N)
  {
      if(i >= N-1)
      return 1;
      if(A[i] == 0)
      return 0;
      int t = A[i];
      while(t--)
      {
          if(fun(i+A[i],A,N))
          return 1;
          
          A[i]--;
      }
      return 0;
  }
    int canReach(int A[], int N) {
        return fun(0,A,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
