class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind1 = 0, ind2 = 0;
        while(ind1 < s.length() && ind2 < t.length()){
            if(s[ind1] == t[ind2]){
                ind1++;
            }
            ind2++;
        }
        if(ind1 == s.length()){
            return true;
        }
        return false;
    }
};