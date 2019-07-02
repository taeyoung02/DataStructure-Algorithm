#include<iostream>
#include<vector>

using namespace std;
int main() {
	int n, m;
	vector<pair<int,int>>arr[4];
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
 		cin >> u >> v>>w;
		arr[u].push_back(make_pair(v,w));
		arr[v].push_back(make_pair(u,w));
	}
	for (int i = 1; i <= n; i++) {
		cout << "arr[" << i << "] : ";
		for (auto &a : arr[i])
		{
			cout << a.first << ","<<a.second<<" ";
		}cout << endl;
	}
}