bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 1;
            }
            else{
                map[nums[i]]++;
            }
        }
        
        vector<pair<int, int>> result;
        for(auto it : map){
            result.push_back({it.first, it.second});
        }
        
        sort(result.begin(), result.end(), cmp);
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(result[i].first);
        }
        
        return ans;
    }
};