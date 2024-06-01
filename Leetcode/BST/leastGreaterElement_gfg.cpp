// Replace every element with the least greater element on its right
// Medium


//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Node{
        public:
        int val;
        Node* left;
        Node* right;
        
        Node(int val){
            this->val = val;
            left=nullptr;
            right=nullptr;
        }
    };
    
class Solution{
    public:
    
    Node* insert(Node* root, int val, int &successor) {
        if (root == nullptr) {
            return new Node(val);
        }
        if (val < root->val) {
            successor = root->val;
            root->left = insert(root->left, val, successor);
        } else {
            root->right = insert(root->right, val, successor);
        }
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        if (n == 0) return {};

        Node* root = nullptr;
        vector<int> result(n);

        for (int i = n - 1; i >= 0; i--) {
            int successor = -1;
            root = insert(root, arr[i], successor);
            result[i] = successor;
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends