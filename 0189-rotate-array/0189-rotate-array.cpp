class Solution {
public:
    void reverse(vector<int> &arr, int l,int r){
       // int l =0, r = n-1;
        while(l < r){
            swap(arr[l++],arr[r--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums,0,n-1);
        reverse(nums,k,n-1);
        reverse(nums,0,k-1);
    }
};