class Solution {
public:
    bool checkunique(string arr){
        bool alphabet[256] = {false};
        for(char c : arr){
            if(alphabet[c]){
                return false;
            }
            else{
                alphabet[c] = true;
            }
        }
        return true;
    }
    void helper(vector<string>& arr, int &ind, string &temp, int &curlen, int &maxlen){
        //cout << ind << " " << curlen << " "<< maxlen << endl;
        if(!checkunique(temp)){
            return;
        }
        if(maxlen < curlen){
            maxlen = curlen;
        }
        if(ind >= arr.size()){
            return;
        }
        
        temp = temp + arr[ind];
        curlen = curlen + arr[ind].length();
        ind++;
        helper(arr, ind, temp, curlen, maxlen);
        ind--;
        curlen = curlen - arr[ind].length();
        temp = temp.substr(0, temp.length() - arr[ind].length());
        
        ind++;
        helper(arr, ind, temp, curlen, maxlen);
        ind--;
    }
    int maxLength(vector<string>& arr) {
        int ind = 0;
        string temp = "";
        int curlen = 0;
        int maxlen = 0;
        helper(arr, ind, temp, curlen, maxlen);
        return maxlen;
    }
};