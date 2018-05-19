class Solution {
public:
    int getArea(int i, int j, int width){
        return min(i, j) * width;
    }
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxArea = 0;
        while(i != j){
            maxArea = max(maxArea, getArea(height[i], height[j], j - i));
            height[i] > height[j]? j--: i++;
        }
        return maxArea;
    }
};
