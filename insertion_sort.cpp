#include<iostream>
using namespace std;

void show(int* arr, int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int* arr, int n){
	for(int i = 1; i < n ; i++){
		int k = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > k){
			arr[j+1] = arr[j];
			j--;
		}
		j++;
		arr[j] = k;
		show(arr, n);
	}
}

int main(){
	int arr[] = {12,9,4,99,120,1,3,10};
	int arr1[] = {5,3,6,0,1,9,1,2};
	show(arr1, 8);
	insertionSort(arr1, 8);
}
