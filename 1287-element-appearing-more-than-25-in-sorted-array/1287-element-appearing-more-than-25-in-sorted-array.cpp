class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        n = n/4 + 1;
        int count = 1;
        for(int i=0; i<arr.size()-1;i++){
            cout << count << " " << arr[i] << endl;
            if(arr[i] != arr[i+1]){
                if(count >= n){
                    return arr[i];
                }
                count = 1;
            }
            else{
                count++;
            }
        }
        return arr[arr.size() - 1];
    }
};