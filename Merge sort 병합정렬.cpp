#include<iostream>
using namespace std;
const int SIZE = 20;
int tmp[SIZE];
void merge(int data[], int p, int q, int r) {
	int i = p; int j = q + 1; int k = p;
	
	while (i <= q && j <= r) {
		if (data[i] < data[j])
			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}
	while (i <= q)
		tmp[k++] = data[i++];
	while (j <= r)
		tmp[k++] = data[j++];
	for (int i = p; i <= r; i++)
		data[i] = tmp[i];
}
void mergesort(int data[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergesort(data, p, q);
		mergesort(data, q + 1, r);
		merge(data, p, q, r);
	}
}
int main() {
	int data[SIZE];
	for (int i = 0; i < SIZE; i++)
		cin >> data[i];
	mergesort(data, 0, SIZE-1);
	for (int a : data)
		cout << a << " ";
}