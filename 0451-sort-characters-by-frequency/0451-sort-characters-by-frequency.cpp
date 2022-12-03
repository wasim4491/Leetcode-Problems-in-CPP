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
        vector<char> v1;
        vector<int> v2;
        for(auto i : mp){
            v1.push_back(i.first);
            v2.push_back(i.second);
        }
        
        for(int i=0;i<v2.size();i++){
            cout << v1[i] << " " << v2[i] <<endl;
        }
        int k = v2.size();
        for(int i=0;i<k;i++){
            for(int j=i;j<k;j++){
                if(v2[i] < v2[j]){
                    swap(v1[i], v1[j]);
                    swap(v2[i], v2[j]);
                }
            }
        }
        for(int i=0;i<v2.size();i++){
            cout << v1[i] << " " << v2[i] <<endl;
        }
        cout << endl;
        string res = "";
        for(int i=0;i<k;i++){
            while(v2[i]){
            res.push_back(v1[i]);
                v2[i]--;
            }
        }
        return res;
    }
};