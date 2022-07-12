	#include <bits/stdc++.h>
	using namespace std;
	using ll = long long;

	int main() {
			freopen("shell.in","r",stdin);
		freopen("shell.out","w",stdout);
			int N;
			cin >> N;
			vector<int> v(3), ans(3);
			v[0] = 0;
			v[1] = 1;
			v[2] = 2;
			for(int i = 0; i < N; i++) {
					int a, b, g;
					cin >> a >> b >> g;
					a--; b--; g--;
					swap(v[a], v[b]);
					ans[v[g]]++;
			}
			cout << max({ans[0], ans[1], ans[2]}) << endl;
	}
