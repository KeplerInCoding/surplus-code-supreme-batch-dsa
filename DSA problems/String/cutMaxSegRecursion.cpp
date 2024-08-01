#include <iostream>
#include <vector>
#include <limits.h>
// #include <algorithm>
using namespace std;

int maxSeg(vector <int>& v, int length){
  //base case 
  if(length==0) return 0;

  if(length<0) return INT_MIN;

  //recursive condn

  int maxi = INT_MIN;

  for(int i=0; i<v.size(); i++){
    int ans = maxSeg(v, length-v[i]);
    if(ans!=INT_MIN) {
      maxi = max(ans+1, maxi);
    }
  }

  return maxi;

}

int main(){
  vector <int> v{5,2,2};

  int length = 7;
  int maxi = maxSeg(v, length);
  if(maxi<0) maxi =0;
  cout<<"Max. segments : "<<maxi<<endl;

  return 0;
}