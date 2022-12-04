class Node{
    public:
    char pk;
    int count;
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = 1;
            }
            else{
                mp[s[i]]++;
            }
        }
        vector<Node> v3;
        for(auto i : mp){
            Node* obj = new Node();
            obj->pk = i.first;
            obj->count = i.second;
            v3.push_back(*obj);
        }
        
        sort(v3.begin(),v3.end(), [ ]( const Node& lhs, const Node& rhs )
                {
                   return lhs.count > rhs.count;
                });
        int k = v3.size();
        string res = "";
        for(int i=0;i<k;i++){
            while(v3[i].count){
            res.push_back(v3[i].pk);
                v3[i].count--;
            }
        }
        return res;
    }
};