#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

using ll = long long;

int main(){
	ifstream fin("guess.in");
	ofstream fout("guess.out");

	int n; fin>>n;
	vector<string> arr[n];
	
	for(int x=0; x<n; x++){
		string animal; fin>>animal;
		arr[x].push_back(animal);
		int chars; fin>>chars;
		for(int y=0; y<chars; y++){
			string s; fin>>s;
			arr[x].push_back(s);
		}
	}

	int ans = 1;
	
	for(int x=0; x<n; x++){
		for(int y=x+1; y<n; y++){
			int shared = 0;
			for(int z=1; z<arr[x].size(); z++){
				for(int w=1; w<arr[y].size(); w++){
					if(arr[x][z]==arr[y][w]){
						++shared;
						break;
					}
				}
			}
			ans = max(ans,shared+1);
		}
	}
	fout<<ans<<endl;
}
