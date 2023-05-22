bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }

class Solution {
public:
    
    // struct boolcmpoperator{
    //     bool cmp(int i, int j, unordered_map<int,int> ansmap){
    //         if(ansmap[i] > ansmap[j]){
    //             return true;
    //         }
    //         return false;
    //     }
    // };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ansmap;
        for(int i=0; i<nums.size(); i++){
            // if(ansmap.find(nums[i]) == ansmap.end()){
            //     ansmap[nums[i]] = 1;
            // }
            // else{
            //     ansmap[nums[i]]++;
            // }
            ansmap[nums[i]]++;
        }
        
        vector<pair<int,int>> res;
        for(auto i : ansmap){
            //cout << i.first << endl;
            res.push_back({i.first, i.second});
        }
        // for(int i=0;i<res.size();i++){
        //     cout << res[i].first << " " << res[i].second << endl;
        // }
        sort(res.begin(), res.end(), cmp);
        
        vector<int> result;
        
        for(int i=0;i<k;i++){
            result.push_back(res[i].first);
        }
        return result;
    }
};