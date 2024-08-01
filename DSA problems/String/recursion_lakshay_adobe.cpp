#include <iostream>
using namespace std;
#include <limits.h>
#include <vector>

int minEle(vector <int>& arr, int sum){
  //base case
  if(sum==0) return 0;
  if(sum<0) return INT_MAX;

  //recursive condition
  int mini= INT_MAX;
  for(int i=0; i<arr.size(); i++){
    int ans = minEle(arr, sum-arr[i]);
    if(ans!=INT_MAX)
    mini = min(mini, ans+1);
  }
  return mini;
}

int main() {
  vector <int> arr{2,3};
  int sum = 5;

  int elements = minEle(arr, sum);
  cout<<"min no of elements  : "<<elements<<endl;
  return 0;
}