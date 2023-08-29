//quick sort
#include <iostream>
using namespace std;
#include <vector>

void quickSort(vector <int>& v, int i, int j){ 
  //base case 
  if(i>=j) return;

  int start = i, end = j;

  //ek case solve karo
  int pivot = i;

  while(1){
    while(v[i]<=v[pivot] && i<end) i++;
    while(v[j]>v[pivot]) j--;

    if(i>=j) break;
    swap(v[i], v[j]); 
  }

  swap(v[pivot], v[j]);


  //recursive fn ->left
  quickSort(v, start, j-1);

  //recursive fn ->right
  quickSort(v, j+1, end);
}

int main(){
  vector <int> v{4, 1, 2, 1, 1, 2, 4};
  int start =0; 
  int end = v.size()-1;
  quickSort(v, start, end);
  cout<<"The sorted array : "<<endl;
  for(auto i: v) cout<<i<<" ";

  return 0;
}