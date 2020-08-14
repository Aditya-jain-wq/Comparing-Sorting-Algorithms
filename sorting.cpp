#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define show(x) cout<<#x<<" "<<x<<"\n"
#define COUNT_SORTS 6
typedef vector<int>::iterator iter;

long long bubble_sort(iter begin, iter end){
	vector<int> numbers(begin, end);
	int n = numbers.size();
	auto start = chrono::high_resolution_clock::now();
	
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n-1-i; j++)
			if(numbers[j] > numbers[j+1])
				swap(numbers[j], numbers[j+1]);

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


long long insertion_sort(iter begin, iter end){
	vector<int> numbers(begin, end);
	int n = numbers.size();
	auto start = chrono::high_resolution_clock::now();

	for(int i = 1; i < n; i++)
		for(int j = i; j > 0 && numbers[j-1] > numbers[j]; j--)
			swap(numbers[j-1], numbers[j]);

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


long long selection_sort(iter begin, iter end){
	vector<int> numbers(begin, end);
	int n = numbers.size();
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

long long merge_sort(iter begin, iter end){
	vector<int> numbers(begin, end);
	int n = numbers.size();
	auto start = chrono::high_resolution_clock::now();

	mergeSort(numbers, 0, n-1);

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


int partition(vector<int> &numbers,int l,int h)
{
	int element=numbers[l];
	int i=l;
	int j=h;
	swap(numbers[i],numbers[j]);
	do
	{
		swap(numbers[i],numbers[j]);
		do{i++;}while(numbers[i]<=element);
		do{j--;}while(numbers[j]>element);
	}
	while(i<j);

	swap(numbers[l],numbers[j]);
	return j;
}

void quickSort(vector<int> &numbers,int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=partition(numbers,l,h);
		quickSort(numbers,l,mid);
		quickSort(numbers,mid+1,h);
	}
}

long long quick_sort(iter begin, iter end){
	vector<int> numbers(begin, end);
	int n = numbers.size();
	auto start = chrono::high_resolution_clock::now();

	quickSort(numbers, 0, n);

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}


void heapify(vector<int> &numbers, int n, int i){
	int larger = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if(left < n && numbers[left]>numbers[larger])
		larger = left;
	if(right < n && numbers[right]>numbers[larger])
		larger = right;
	if(larger != i){
		swap(numbers[larger], numbers[i]);
		heapify(numbers, n, larger);
	}
}

long long heap_sort(iter begin, iter end){
	vector<int> numbers(begin, end);
	int n = numbers.size();
	auto start = chrono::high_resolution_clock::now();

	for(int i = n/2 - 1; i >= 0; i--)
		heapify(numbers, n, i);

	for(int i = n-1; i > 0; i--){
		swap(numbers[i], numbers[0]);
		heapify(numbers, i, 0);
	}

	auto elapsed = chrono::high_resolution_clock::now() - start;
	return chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
}

int main(){   

	cout<<"We'll sort your integer array in different methods and tell you the fastes for your specific data"<<nl
	<<"Option available are : ";

	cout<<"Bubble Sort(Theta(n^2))"<<nl;
	cout<<"Insertion Sort(O(n^2))"<<nl;
	cout<<"Selection Sort(good if swap is expensive compared to above(O(n^2)))"<<nl;
	cout<<"Merge Sort(O(n logn))"<<nl;
	cout<<"Quick Sort"<<nl;
	cout<<"Heap Sort"<<nl;
	cout<<"Heap Sort"<<nl;
	// cout<<"inBuilt (includes time to call function)"<<nl<<nl;

	cout<<"Number of elements in your array? (<"<<INT_MAX<<") ";
	int n;
	cin>>n;
	cout<<n<<" number(s)?"<<nl;
	vector<int> numbers(n);
	for(int i = 0; i < n; i++)
		cin>>numbers[i];
	if(n == 1){
		cout<<"only one element so every algo is best"<<nl;
		return 0;
	}

	// function pointer array containing all implemented sorts
	long long (*sortingAlgo[COUNT_SORTS])(iter, iter); 
	sortingAlgo[0] = bubble_sort;
	sortingAlgo[1] = insertion_sort;
	sortingAlgo[2] = selection_sort;
	sortingAlgo[3] = merge_sort;
	sortingAlgo[4] = quick_sort;
	sortingAlgo[5] = heap_sort;

	//calculating time for each sort
	long long timeTaken[COUNT_SORTS];
	for(int i = 0; i < COUNT_SORTS; i++)
		timeTaken[i] = sortingAlgo[i](numbers.begin(), numbers.end());

	for(long long time : timeTaken)
		cout<<time<<" ";
	
	
	return 0;
}