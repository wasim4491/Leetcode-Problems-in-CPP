class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m != n){
            return false;
        }
        
        unordered_map<char,int> map;
        
        for(int i=0; i<n; i++){
            if(map.find(s[i]) != map.end()){
                map[s[i]]++;
            }
            else{
                map[s[i]] = 1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(map.find(t[i]) != map.end()){
                map[t[i]]--;
            }
            else{
                return false;
            }
        }
        
        for(auto it : map){
            if(it.second != 0){
                return false;
            }
        }
        
        return true;
    }
};