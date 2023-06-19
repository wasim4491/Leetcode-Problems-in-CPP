class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int count = 0;
        for(int i=0;i<gain.size();i++){
            count += gain[i];
            maxi = max(maxi, count);
        }
        return maxi;
    }
};