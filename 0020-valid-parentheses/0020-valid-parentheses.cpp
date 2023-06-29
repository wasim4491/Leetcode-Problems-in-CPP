class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(!st.empty() && s[i] == ']'){
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(!st.empty() && s[i] == '}'){
                if(st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};