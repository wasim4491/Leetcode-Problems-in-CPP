class Solution {
public:
    vector<int> countBits(int n) {
        int counter = 0;
        int num = 0;
        int temp;
        vector<int> ans;
        while(num <= n){
            temp = num;
            counter = 0;
            while(temp){
                if(temp & 1 == 1){
                    counter++;
                }
                temp = temp >> 1;
            }
            ans.push_back(counter);
            num++;
        }
        return ans;
    }
};