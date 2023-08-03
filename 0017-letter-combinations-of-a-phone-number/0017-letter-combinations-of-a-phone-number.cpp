class Solution {
public:
    void helper(unordered_map<char, string> &map, vector<string> &ans, string digits, string temp, int ind){
        if(digits.length() == temp.length()){
            ans.push_back(temp);
            return;
        }
        if(ind >= digits.length()){
            return;
        }
            //pick element
        for(auto v : map[digits[ind]]){
            //pick element
            temp.push_back(v);
            helper(map, ans, digits, temp, ind+1);
            temp.pop_back();
                
            helper(map, ans, digits, temp, ind+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        string temp = "";
        helper(map, ans, digits, temp, 0);
        
        return ans;
    }
};