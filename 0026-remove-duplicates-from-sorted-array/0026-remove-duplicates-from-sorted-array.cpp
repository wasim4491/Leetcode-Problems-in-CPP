class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return 1;
        }
        vector<int> res;
        res.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(arr[i] != arr[i-1]){
                res.push_back(arr[i]);
            }
        }
        // int k = res.size();
        // if(arr[n-1] != res[k-1]){
        //     res.push_back(arr[n-1]);
        // }
        for(int i=0;i<res.size();i++){
            arr[i] = res[i];
        }
        return res.size();
    }
};