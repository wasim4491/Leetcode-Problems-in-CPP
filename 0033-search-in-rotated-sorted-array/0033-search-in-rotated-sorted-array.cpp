class Solution {
public:
    int pivot(vector<int> arr){
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int mid ;
        while(s < e){
            mid = s + (e-s)/2;
            if(arr[mid] >= arr[0]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
    int search(vector<int>& arr, int target) {
        int piv = pivot(arr);
        int n = arr.size();
        int s=0,e=n-1,mid;
        if(arr[piv] == target){
            return piv;
        }
        if(arr[piv] < target && target <= arr[e]){
            s = piv + 1;
        }
        else{
            e = piv - 1;
        }
        while(s <= e){
            mid = s + (e-s)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
    }
};