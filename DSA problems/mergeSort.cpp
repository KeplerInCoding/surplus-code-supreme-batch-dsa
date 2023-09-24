// //merge sort
// #include <vector>
// #include <iostream>
// using namespace std;

// vector <int> mergeSort(vector <int>& v){

//   //base case
//   if(v.size()==1) return v;


//   //ek case solve karo baki recursion sambhal lega


//   //solving one case
//   int mid = v.size()/2;

//   vector <int> left(v.begin(), v.begin()+mid);
//   vector <int> right(v.begin()+mid, v.end());

//   //left = sorted v
//   left = mergeSort(left);

//   //right = sorted v
//   right = mergeSort(right);

//   //new v = merge left+right
//   int i = 0, j=0, k=0;
//   while(i<left.size() && j<right.size()){
//     if(left[i]<right[j]) v[k++] = left[i++];
//     else v[k++] = right[j++];
    
//   }

//   while(i<left.size()) v[k++] = left[i++];
//   while(j<right.size()) v[k++] = right[i++];

  
//   //return sorted v;
//   return v;

  
// }

// int main() {
//   vector <int> v{2,5,4,7,5,3,9,6,1};
//   vector <int> sorted = mergeSort(v);
//   cout<<"sorted vector : "<<endl;
//   for(auto i:sorted) cout<<i<<" ";
//   return 0;
// }




#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int> &v, vector <int> &ans, int start, int end, int mid){
  int i = start, j = mid + 1, k=start;
  while(i<=mid && j<=end){
    if(v[i]>v[j]){
      ans[k++]=v[j++];
    }
    else{
      ans[k++]=v[i++];
    }
  }
  while(i<=mid){
      ans[k++]=v[i++];

  }
  while(j<=end){
      ans[k++]=v[j++];

  }

  while(start<=end){
    v[start]=ans[start];
    start++;
  }
}

void mergeSort(vector <int> &v, vector <int> &ans, int start, int end){
  if(start>=end) return;

  int mid = (start+end)/2;
  mergeSort(v, ans, start, mid);
  mergeSort(v, ans, mid+1, end);
  merge(v, ans, start, end, mid);

}

int main() {
  vector <int> v = {7, 4, 5, 3, 2, 8, 1};
  vector <int> ans(v.size(), 0);
  mergeSort(v, ans, 0, v.size()-1);
  for(auto i:v) cout<<i<<" ";
  return 0;
}