#include<iostream>
#include<math.h>
using namespace std;
int N, col[15];
bool cdt(int level) {
	for (int i = 1; i < level; i++)
		if ((col[i] == col[level]) || (abs(col[level] - col[i]) == level - i))return 0;
	return 1;
}
bool queen(int level) {
	if (level == N) {
		for (int i : col)
			cout << i << endl;
		return 1;
	}
	for (int i = 1; i <= N; i++) {
		col[level + 1] = i;
		if (cdt(level + 1))
			if(queen(level + 1))
				return 1;
	}
	return 0;
}
int main() {
	cin >> N;
	queen(0);
}