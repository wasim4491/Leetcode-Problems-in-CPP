class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(s[i] == st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        int l = 0, r = res.length()-1;
        while(l < r){
            swap(res[l++],res[r--]);
        }
        return res;
    }
};