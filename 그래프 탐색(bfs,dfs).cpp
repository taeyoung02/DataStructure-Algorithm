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
	for (int i = 0; i < arr[x].size(); i++) {//x�� ������ Ž��
		int y = arr[x][i]; 
		if (check[y] == false) // x�� ����� ���� y�� Ž���ȵǾ�������
			dfs(y); // y�� Ž��
	}//�̷��� ���������� ���̿켱Ž���� ����
}
void bfs(int x) {
	check[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int x = q.front(); q.pop(); // q�� �Ǿ��� ����
		cout << x << " ";
		for (int i = 0; i < arr[x].size(); i++) {//���� ������ ������ Ž��
			int y = arr[x][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y); //x�� ����� ���� Ž���������� ������ ť�� ����
			}
		}//�̷��� �ϳ��� ������ ����� ������ ��� Ž���� ���� �������� �Ѿ
	}
}
int main() {
	int n, m, start; cin >> n >> m>> start;
	arr.resize(n + 1);//1���� ����� n+1��
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v); 
		arr[v].push_back(u); //�밢���������� ��ġ�ϹǷ�
	}
	for (int i = 1; i <= n; i++)
		sort(arr[i].begin(), arr[i].end()); //������������ Ž���ϹǷ�
	dfs(start);
	cout << endl;
	memset(check, 0, 1001);
	bfs(start);
}