class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int count = 0;
        int maxi = INT_MIN;
        
        unordered_map<char,int> map;
        
        int l = 0, r = 0;
        int n = s.length();
        while(l < n && r < n){
            if(map.find(s[r]) != map.end() && map[s[r]] >= l){
                l = map[s[r]] + 1;
            }
            map[s[r]] = r;
            maxi = max(maxi, r-l+1);
            r++;
            
        }
        return maxi;
    }
};