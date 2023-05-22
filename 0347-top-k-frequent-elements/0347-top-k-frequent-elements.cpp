bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }

class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ansmap;
        for(int i=0; i<nums.size(); i++){
            ansmap[nums[i]]++;
        }
        
        vector<pair<int,int>> res;
        for(auto i : ansmap){
            res.push_back({i.first, i.second});
        }
        sort(res.begin(), res.end(), cmp);
        
        vector<int> result;
        
        for(int i=0;i<k;i++){
            result.push_back(res[i].first);
        }
        return result;
    }
};