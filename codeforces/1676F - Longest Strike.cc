#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
	while(t--){
    	int n, k;
    	cin >> n >> k;
    	int start = 0;
    	map<int, int> cnt;
    	for (int i = 0; i < n; i++) {
    	    int x;cin>>x;
    	    cnt[x]++;
    	}
    	vector<int> arr;
    	map<int, int>::iterator itr;
        for (itr = cnt.begin(); itr != cnt.end(); ++itr) { 
            if(itr->second>=k) arr.push_back(itr->first);
        }
        
        if(arr.empty()){
           cout<<-1<<endl;
           continue;
        }
        int l=arr[0], r=arr[0], diff=0, templ=arr[0];
        for(int i=1;i<arr.size();i++){
           if(arr[i]-arr[i-1]==1){
               if(arr[i]-templ > diff){
        			l = templ;
        			r = arr[i];
        			diff = arr[i]-templ;
        		}
           } else{
               templ=arr[i];
           }
        }
   cout<<l<<" "<<r<<endl;
	}	
}
