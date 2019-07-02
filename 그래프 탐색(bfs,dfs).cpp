#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
vector < vector<int>>arr;
bool check[1001];
void dfs(int x) {
	check[x] = true;
	cout << x << " ";
	for (int i = 0; i < arr[x].size(); i++) {//x의 간선을 탐색
		int y = arr[x][i]; 
		if (check[y] == false) // x와 연결된 정점 y가 탐색안되어있으면
			dfs(y); // y를 탐색
	}//이렇게 꼬리를물고 깊이우선탐색을 시행
}
void bfs(int x) {
	check[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int x = q.front(); q.pop(); // q의 맨앞을 꺼냄
		cout << x << " ";
		for (int i = 0; i < arr[x].size(); i++) {//꺼낸 정점의 간선을 탐색
			int y = arr[x][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y); //x와 연결된 아직 탐색되지않은 정점을 큐에 넣음
			}
		}//이렇게 하나의 정점에 연결된 정점을 모두 탐색후 다음 정점으로 넘어감
	}
}
int main() {
	int n, m, start; cin >> n >> m>> start;
	arr.resize(n + 1);//1차원 행렬이 n+1개
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v); 
		arr[v].push_back(u); //대각선기준으로 일치하므로
	}
	for (int i = 1; i <= n; i++)
		sort(arr[i].begin(), arr[i].end()); //작은순서부터 탐색하므로
	dfs(start);
	cout << endl;
	memset(check, 0, 1001);
	bfs(start);
}