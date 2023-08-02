class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> mapi;
        unordered_map<int, bool> mapj;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(mapi.find(i) == mapi.end()){
                        mapi[i] = true;
                    }
                    if(mapj.find(j) == mapj.end()){
                        mapj[j] = true;
                    }
                }
            }
        }
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(mapi[i] == true || mapj[j] == true){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};