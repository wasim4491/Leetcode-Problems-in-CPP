class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        
        for(int i=0; i<str.size(); i++){
            string temp = str[i];
            sort(str[i].begin(), str[i].end());
            map[str[i]].push_back(temp);
        }
        
        for(auto it : map){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};