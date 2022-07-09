#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,c0,c1,h;
	    cin>>n>>c0>>c1>>h;
	    string s;
	    cin>>s;
	    int num0=0;
	    int num1=0;
	    for(auto x:s) x=='1'?num1++:num0++;
	    int ans = c0*num0+c1*num1;
	    if(((num0+num1)*c1+h*num0)<ans) ans = (num0+num1)*c1+h*num0;
	    if(((num0+num1)*c0+h*num1)<ans) ans = (num0+num1)*c0+h*num1;
	    cout<<ans<<endl;
	}
	
	return 0;
}
