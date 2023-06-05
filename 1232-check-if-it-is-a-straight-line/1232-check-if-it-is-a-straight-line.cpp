class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int m1 = coordinates[1][1] - coordinates[0][1];
        int m2 = coordinates[1][0] - coordinates[0][0];
        double c;
        if(m2 == 0){
            c = -((double)m1) * (double)coordinates[0][0];
            for(int i=0; i<coordinates.size();i++){
                if(c != - ((double)m1) * (double)coordinates[i][0]){
                    return false;
                }
            }     
        }
        else if(m1 == 0){
            int c = coordinates[0][1] ;
            for(int i=0; i<coordinates.size();i++){
                if(c != coordinates[i][1]){
                    return false;
                }
            }     
        }
        else{
            double c = (double)coordinates[0][1] - ((double)m1/m2) * (double)coordinates[0][0];
            for(int i=0; i<coordinates.size();i++){
                if(c != (double)coordinates[i][1] - ((double)m1/m2) * (double)coordinates[i][0]){
                    return false;
                }
            }     
        }
        return true;
    }
};