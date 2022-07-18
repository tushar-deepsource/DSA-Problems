#include <bits/stdc++.h>
using namespace std;

int distance(int x1,int y1,int x2,int y2){
    return pow(x2-x1,2)+pow(y2-y1,2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("triangles.in", "r", stdin);
    // freopen("triangles.out", "w", stdout);
    int k,n;
    cin >> k >> n;
	vector<vector<int>> arr;
	for(int i=0;i<k;i++){
	    vector<int> temp;
	    for(int j=0;j<n;j++){
	        int cow;cin>>cow;
	        temp.push_back(cow);
	    }
	    arr.push_back(temp);
	}
	int consistent=0;
	for(int i=1;i<n+1;i++){
	    for(int j=1;j<n+1;j++){
	        if(i!=j){
	            bool flag = true;
                for (int q = 0; q < k; q++) {
    				for (int l = 0; l < n; l++) {
    					if (arr[q][l] == i) break;
    					if (arr[q][l] == j) {
    						flag = false;
    						break;
    					}
    				}
			}
			if (flag) consistent++;
	        }
	    }
	}
	cout<<consistent<<endl;
}

