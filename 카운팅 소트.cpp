#include <iostream>
#define MAX_SIZE 1000
#define MAX_NUM 10000 
int main() {
	int arr[] = { 0,0,2,1,8,3,2,0,5,4,3,2,3,4,5 };
	int count[9] = { 0 };
	int res[sizeof(arr) / sizeof(int)] = { 0 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		count[arr[i]]++;
	/*for (int i = sizeof(arr) / sizeof(int)-1; i >= 0; i--) {
		res[--count[arr[i]]]=arr[i];
		
	}
	for (int i : res)
		std::cout << i << " ";
*/
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < count[i]; j++)
			std::cout << i << " ";
}