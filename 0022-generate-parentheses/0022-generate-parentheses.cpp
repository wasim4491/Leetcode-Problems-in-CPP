class Solution {
public:
    void genpar(int n, string &s, int a, int b, vector<string> &ans){
        if(b > a){
            return ;
        }
        else if((b+a) == 2*n && a == b){
            ans.push_back(s);
            return;
        }
        else if((b+a) == 2*n && a!=b){
            return;
        }
        s.push_back('(');
        a++;
        genpar(n,s,a,b,ans);
        s.pop_back();
        a--;
        s.push_back(')');
        b++;
        genpar(n,s,a,b,ans);
        s.pop_back();
        b--;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        int a =0, b =0;
        genpar(n,s,a,b,ans);
        return ans;
    }
};