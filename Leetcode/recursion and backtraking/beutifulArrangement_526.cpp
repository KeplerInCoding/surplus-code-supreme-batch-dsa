class Solution {
public:

    void perm(vector <int> &arr, int i, int &ans){
        //base case
        if(i==arr.size()){
            // for(int m = 0; m<arr.size(); m++){
            //     cout<<arr[m]<<" ";
            // }
            // cout<<endl;
            ans++;
            return;
        }

        //recursive condition
        for(int j = i; j<arr.size(); j++){
            swap(arr[i], arr[j]);
            if((arr[i]%(i+1))!=0 && ((i+1)%arr[i])!=0){
                swap(arr[i], arr[j]);
                continue;
            }
            perm(arr, i+1, ans);
            swap(arr[i], arr[j]);
        }
    }

    int countArrangement(int n) {
        if (n==1) return 1;
        int ans = 0;
        vector <int> arr;
        for(int i = 1; i<=n; i++){
            arr.push_back(i);
        }
        perm(arr, 0, ans);
        return ans;
    }
};