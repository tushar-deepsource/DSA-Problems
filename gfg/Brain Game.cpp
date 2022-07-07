// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	bool isPrime(int n)
	{
	    for(int i=2; i<=sqrt(n); i++)
	        if(n%i==0)
	            return false;
	   return true;
	}
	int primeFactor(int n){
	    int ans = 0;
        int num = n;
        for(int i=2; i<=num/2; i++){
            while(n%i == 0){
                ans++;
                n/= i;
            }
        }
        return ans;
    }
    bool brainGame(vector<int>nums) {
        int ans=0;
        for(int num:nums){
            if(!isPrime(num))ans=ans^(primeFactor(num)-1);
        }
        return ans!=0;
    }
    
    // why case 7 \n 13 5 3 9 7 12 1 gives A
    /* ANSWER->
    A turn – making 12 as 6
    B turn – making either 6 as 3 or 9 as 3
    A turn – making remaining that is if B makes 6 as 3, A will make 9 as 3 or vice versa.
    Now B have no choice left with so A wins.
    */
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends
