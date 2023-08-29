class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int zeropen = 0;
        int time = 0;
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y'){
                zeropen++;
            }
        }
        int minpen = zeropen;
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y'){
                zeropen--;
            }
            if(customers[i] == 'N'){
                zeropen++;
            }
            if(minpen > zeropen){
                minpen = zeropen;
                time = i+1;
            }
        }
        return time;
    }
};