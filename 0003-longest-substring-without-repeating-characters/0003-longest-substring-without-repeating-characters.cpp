class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int count = 0, ans = 0;
        unordered_map<char,int> mp;
        while(i < n){
            if(mp.find(s[i]) == mp.end()){
                count++;
                mp.insert({s[i],i});
                i++;
            }
            else{
                ans = max(ans, count);
                count = 0;
                i = mp[s[i]]+1;
                mp.clear();
            }
        }
        ans = max(ans, count);
        return ans;
    }
};