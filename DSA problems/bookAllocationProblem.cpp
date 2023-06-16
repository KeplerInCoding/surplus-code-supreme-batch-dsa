bool isPossible(int A[], int max, int M, int N){
    int sum = 0;
    int count = 1;
    for(int i=0; i<N; i++){
        if(A[i] > max) return false;
        
        if(sum + A[i] > max){
            count++;
            sum = A[i];
            if(count > M) return false;
        }
        
        else sum = sum + A[i];
    }
    return true;
}
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int start = 0;
        int end = accumulate(A, A+N, 0);
        int ans = -1;
        if(N<M) return -1;
        while(end>=start){
            int mid = (start + end)>>1;
            if(isPossible(A, mid, M, N)){
                end = mid - 1;
                ans= mid;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};
