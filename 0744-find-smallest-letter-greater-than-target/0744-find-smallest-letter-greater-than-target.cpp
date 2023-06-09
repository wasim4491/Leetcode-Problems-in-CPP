class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int l = 0, r = letters.size()-1,mid;
        while(l <= r){
            mid = (l+r)/2;
            if(mid-1 >= 0 && letters[mid - 1] <= target && letters[mid] > target){
                return letters[mid];
            }
            else if(letters[mid] <= target){
                l = mid + 1;
            }
            else if(letters[mid] > target){
                 r = mid - 1;
            }
        }
        return letters[0];
    }
};