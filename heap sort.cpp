#include<iostream>
#include<algorithm>
#define SIZE 20
using namespace std;
int root;
void heapify(int arr[], int j) {//자식노드가 부모노드보다 작게만듬
	if (j == 0)return;
		root = (j-1) / 2;
		if (arr[root] >= arr[j])  
			return;
		swap(arr[j], arr[root]);
		heapify(arr, root);
}
void buildheap(int arr[],int size) {//heap으로 만듬. 길이가 log(SIZE) -1 인 heap완성
	for (int i = size - 1; i > 0; i--)
		heapify(arr, i);
}
void heap(int arr[]){
	buildheap(arr,SIZE);
	for (int i = SIZE-1; i > 0; i--) {
		swap(arr[0], arr[i]);
		buildheap(arr,i);
	}
}
int main() {
	int arr[SIZE] = { 3,2,1,0,4,5,12,19,17,65,20,11,54,65,31,15,16,19,18,17};
	heap(arr);
	for (auto a : arr)
		cout << a << " ";
}