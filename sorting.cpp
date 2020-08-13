#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

long long bubble_sort(vector<int> numbers, int n){
	auto start = chrono::high_resolution_clock::now();
	
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n-1-i; j++)
			if(numbers[j] > numbers[j+1])
				swap(numbers[j], numbers[j+1]);

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


long long insertion_sort(vector<int> numbers, int n){
	auto start = chrono::high_resolution_clock::now();

	for(int i = 1; i < n; i++)
		for(int j = i; j > 0 && numbers[j-1] > numbers[j]; j--)
			swap(numbers[j-1], numbers[j]);

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


long long selection_sort(vector<int> numbers, int n){
	auto start = chrono::high_resolution_clock::now();

	int mini;
	for(int i = 0; i < n-1; i++){
		mini = i;
		for(int j = i+1; j < n; j++)
			if(numbers[j] < numbers[mini])
				mini = j;
		swap(numbers[i], numbers[mini]);
	}

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


void merge(vector<int> &numbers, int low, int mid, int high){
	int sorted[high - low + 1];
	int i = low, j = mid + 1, k = 0;
	while(i < mid+1 && j < high+1){
		if(numbers[i] <= numbers[j])
			sorted[k++] = numbers[i++];
		else
			sorted[k++] = numbers[j++];
	}
	while(i < mid+1) sorted[k++] = numbers[i++];
	while(j < high+1) sorted[k++] = numbers[j++];
	while(k--) numbers[high--] = sorted[k];
}

void mergeSort(vector<int> &numbers, int low, int high){
	if(low >= high) return;
	int mid = low + (high - low)/2;
	mergeSort(numbers, low, mid);
	mergeSort(numbers, mid+1, high);
	merge(numbers, low, mid, high);
}

long long merge_sort(vector<int> numbers, int n){
	auto start = chrono::high_resolution_clock::now();

	mergeSort(numbers, 0, n-1);

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


int partition(vector<int> &arr,int l,int h)
{
	int element=arr[l];
	int i=l;
	int j=h;
	swap(arr[i],arr[j]);
	do
	{
		swap(arr[i],arr[j]);
		do{i++;}while(arr[i]<=element);
		do{j--;}while(arr[j]>element);
	}
	while(i<j);

	swap(arr[l],arr[j]);
	return j;
}

void quickSort(vector<int> &arr,int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=partition(arr,l,h);
		cout<<nl;
		for(int i : arr)
			cout<<i<<" ";
		quickSort(arr,l,mid);
		quickSort(arr,mid+1,h);
	}
}

long long quick_sort(vector<int> numbers, int n){
	auto start = chrono::high_resolution_clock::now();

	quickSort(numbers, 0, n);
	cout<<nl;
	for(int i : numbers)
		cout<<i<<" ";

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


long long heap_sort(vector<int> numbers, int n){
	auto start = chrono::high_resolution_clock::now();

	for(int i = )

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}

int main(){   
	// fastio;

	cout<<"We'll sort your integer array in different methods and tell you the fastes for your specific data"<<nl
	<<"Option available are : ";

	cout<<"Bubble Sort(Theta(n^2))"<<nl;
	cout<<"Insertion Sort(O(n^2))"<<nl;
	cout<<"Selection Sort(good if swap is expensive compared to above(O(n^2)))"<<nl;
	cout<<"Merge Sort(O(n logn))"<<nl;
	cout<<"Quick Sort"<<nl;
	cout<<"Heap Sort"<<nl;
	cout<<"inBuilt (includes time to call function)"<<nl;

	cout<<"Number of elements in your array? (<"<<INT_MAX<<") ";
	int n;
	cin>>n;
	vector<int> numbers(n);
	for(int i = 0; i < n; i++)
		cin>>numbers[i];
	if(n == 1){
		cout<<"only one element so every algo is best"<<nl;
		return 0;
	}
	
	long long bubble = bubble_sort(numbers, n);
	long long insertion = insertion_sort(numbers, n);
	long long selection = selection_sort(numbers, n);
	long long merge = merge_sort(numbers, n);
	long long quick = quick_sort(numbers, n);
	long long heap = heap_sort(numbers, n);

	// auto start = chrono::high_resolution_clock::now();
	// sort(arr, arr+n);
	// auto elapsed = chrono::high_resolution_clock::now() - start;
	// long long ms = chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
	// cout<<ms<<"ms"<<nl;	
	
	return 0;
}