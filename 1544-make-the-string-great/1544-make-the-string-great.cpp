class Solution {
public:
    string makeGood(string s) {
        stack<char> ans;
        int n = s.length();
        ans.push(s[0]);
        for(int i=1;i<n;i++){
            if(ans.empty()){
                ans.push(s[i]);
                continue;
            }
            int k = abs(s[i] - ans.top());
            if(k == 32){
                ans.pop();
            }
            else{
                ans.push(s[i]);
            }
        }
        string res = "";
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }
        int l = 0, r = res.length()-1;
        while(l < r){
            swap(res[l++], res[r--]);
        }
        return res;
    }
};