#include <bits/stdc++.h>
using namespace std;

int distance(int x1,int y1,int x2,int y2){
    return pow(x2-x1,2)+pow(y2-y1,2);
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // freopen("triangles.in", "r", stdin);
    // freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
	vector<int> xcord;
	vector<int> ycord;
	for(int i=0;i<n;i++){
	    int x;cin>>x;
	    xcord.push_back(x);
	}
	for(int i=0;i<n;i++){
	    int y;cin>>y;
	    ycord.push_back(y);
	}
	int maxdis = 0;
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        if(i!=j){
	            int dis = distance(xcord[i],ycord[i],xcord[j],ycord[j]);
	            maxdis = max(dis,maxdis);
	        }
	    }
	}
	cout<<maxdis<<endl;
}
