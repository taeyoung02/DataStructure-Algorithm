#include <iostream>
#include<string.h>
#include<math.h>

void radix(int arr[], int k, int size) {
	int* count = new int[10*sizeof(int)];
	int* res = new int[size*sizeof(int)];
	for (int j = 0; j < k; j++) {
		memset(count, 0, 10 * sizeof(int));
		int p = (int)pow(10, j);
		for (int i = 0; i <size; i++) {
			count[(int)(arr[i] / p) % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			count[i] = count[i] + count[i - 1];
		}
		for (int i = size - 1; i >= 0; i--) {
			res[--count[(int)(arr[i] / p) % 10]] = arr[i];
		}
		memcpy(arr, res, size*sizeof(int));
	}
	delete[] count;
	delete[] res;
}

int main() {
	int arr[] = { 210,30,2,1,28,33,12,211,35,234,43,42,13,234,115 };
	radix(arr, 3, 15);
	for (int i : arr)
	std::cout << i << " ";
}