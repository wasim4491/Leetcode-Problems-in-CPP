class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = INT_MIN;
        int l = 0, r = n - 1;
        while(l < r){
            int a = r - l;
            int b = min(height[r], height[l]);
            area = max(area, a*b);
            if(height[l] > height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return area;
    }
};