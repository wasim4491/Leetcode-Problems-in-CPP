class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int count = 0, ans = 0;
        for(int i=0;i<n;i++){
            count = 0;
            unordered_set<char> mp;
            for(int j=i;j<n;j++){
             //   cout << mp.find(s[j]) != mp.end() << endl;
                if(mp.find(s[j]) == mp.end() ){
                    mp.insert(s[j]);
                    count++;
                   // cout << count << endl;
                }
                else{
                    break;
                }
              //  cout << count << endl;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};