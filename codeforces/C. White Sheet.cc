#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersect(vector<int> s1, vector<int> s2) {
	int x1 = s1[0], y1 = s1[1], x2 = s1[2], y2 = s1[3], x3 = s2[0], y3 = s2[1], x4 = s2[2], y4 = s2[3];
	
	// no overlap
	if (x1 >= x4 || x2 <= x3 || y1 >= y4 || y2 <= y3) {
		return {0, 0, 0, 0};
	} else {
		// coords of overlapping portion (finding intersections)
		return {max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4)};
	}
}

long long area(vector<int> s) {
	int x1 = s[0], y1 = s[1], x2 = s[2], y2 = s[3];
	long long length = y2 - y1;
	long long width = x2 - x1;
	return length * width;
}

int main() {
	vector<int> white(4);
	vector<int> black1(4);
	vector<int> black2(4);
	for (int i = 0; i < 4; i++) cin >> white[i];
	for (int i = 0; i < 4; i++) cin >> black1[i];
	for (int i = 0; i < 4; i++) cin >> black2[i];
	
	long long remaining = area(white) - area(intersect(white, black1)) - area(intersect(white, black2)) + area(intersect(white, intersect(black1, black2)));
	cout<<((remaining > 0)?"YES":"NO")<< "\n";
}
