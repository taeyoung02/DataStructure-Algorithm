#include<iostream>
#include<string>
using namespace std;
typedef struct node{
	int n;
	node* next;
}node;
int main() {
	node* head = new node;
	node* tail = new node;
	head = tail;
	int N, k, cnt = 0; cin >> N >> k;
	for (int i = 1; i <= N; i++) {
		node* NEW = new node;
		NEW->n = i;
		tail->next = NEW;
		tail = tail->next;
	}
	tail->next = head->next;
	cout << "<";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < k-1 ; j++)
			head = head->next;
		cout << head->next->n; if (i < N - 1)cout << ", ";
		head->next = head->next->next;
	}
	cout << ">";
}