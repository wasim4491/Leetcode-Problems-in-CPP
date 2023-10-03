class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        int count = 0;
        for(auto it : map){
            int temp = it.second;
            if(temp > 1){
                count += (temp * (temp - 1))/2;
            }
        }
        return count;
    }
};