//max sum of non adjacent elements

#include <iostream>
using namespace std;
#include <vector>

int maxSum(vector <int>& v, int i, int sum){

  //base
  if(i>=v.size()) return sum;

  //recursive condn
  //exclude
  int exc = maxSum(v, i+1, sum);

  sum += v[i];

  //include
  int inc = maxSum(v, i+2, sum);

  

  sum = max(inc, exc);

  return sum;
}

int main(){
  vector <int> v{4, 2, 9, 5, 3, 16};
  int i=0;
  int sum = 0;
  int ans = maxSum(v, i, sum);
  cout<<"Max. sum of elements : "<< ans <<endl;

  return 0;
}