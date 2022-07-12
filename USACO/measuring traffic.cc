#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
//     ifstream fin("traffic.in");
// 	ofstream fout("traffic.out");
    int n;
    cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if (s=="none") arr[i][0]=0;
        else if (s=="on") arr[i][0]=1;
        else arr[i][0]=2;
        cin>>arr[i][1]>>arr[i][2];
    }
    int startindex=0,endindex=n-1;
    while(arr[startindex][0]!=0) startindex++;
    while(arr[endindex][0]!=0) endindex--;
    pair<int,int> start = make_pair(arr[startindex][1],arr[startindex][2]);
	pair<int,int> end = make_pair(arr[endindex][1],arr[endindex][2]);
    
    for(int x=startindex+1;x<n;x++){
        if(arr[x][0]==0){
            start.first=max(start.first,arr[x][1]);
            start.second=min(start.second,arr[x][2]);
        }else if(arr[x][0]==1){
            start.first+=arr[x][1];
            start.second+=arr[x][2];
        }else{
            start.first=max(0,start.first-arr[x][2]);
            start.second=max(0,start.second-arr[x][1]);
        }
    }
    for(int x=endindex-1;x>=0;x--){
        if(arr[x][0]==0){
            end.first=max(end.first,arr[x][1]);
            end.second=min(end.second,arr[x][2]);
        }else if(arr[x][0]==1){
            end.first=max(0,end.first-arr[x][2]);
            end.second=max(0,end.second-arr[x][1]);
        }else{
            end.first+=arr[x][1];
            end.second+=arr[x][2];
        }
    }
    std::cout << end.first << " " << end.second << std::endl;
    std::cout << start.first << " " << start.second << std::endl;
//     fout<<end.first<<" "<<end.second<<endl
// 	fout<<start.first<<" "<<start.second<<endl;
    return 0;
}
