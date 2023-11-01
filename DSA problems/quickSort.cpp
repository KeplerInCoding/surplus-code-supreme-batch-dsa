// //quick sort
// #include <iostream>
// using namespace std;
// #include <vector>

// void quickSort(vector <int>& v, int i, int j){ 
//   //base case 
//   if(i>=j) return;

//   int start = i, end = j;

//   //ek case solve karo
//   int pivot = i;

//   while(1){
//     while(v[i]<=v[pivot] && i<end) i++;
//     while(v[j]>v[pivot]) j--;

//     if(i>=j) break;
//     swap(v[i], v[j]); 
//   }
// 
//   swap(v[pivot], v[j]);


//   //recursive fn ->left
//   quickSort(v, start, j-1);

//   //recursive fn ->right
//   quickSort(v, j+1, end);
// }

// int main(){
//   vector <int> v{4, 1, 2, 1, 1, 2, 4};
//   int start =0; 
//   int end = v.size()-1;
//   quickSort(v, start, end);
//   cout<<"The sorted array : "<<endl;
//   for(auto i: v) cout<<i<<" ";

//   return 0;
// }





// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

int main()
{

	int arr[] = { 9, 3, 4, 2, 1, 8 };
	int n = 6;

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
