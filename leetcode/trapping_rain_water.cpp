class Solution {
public:
    int trap(vector<int>& height) {
        // Greedy approach: min(leftMaxHeight[i], rightMaxHeight[i]) - height[i] = water that can be stored at that position.
        int n = height.size();
        int i = 0, j = n-1, leftMax = height[0], rightMax = height[n-1];
        int sum = 0;

        while(i < j) {
            if (leftMax <= rightMax) {
                i++;
                leftMax = max(leftMax, height[i]);
                sum += (leftMax - height[i]); // -> as leftMax is smaller than rightMax hence it has to be rightMaxHeight[i]
            } else {
                j--;
                rightMax = max(rightMax, height[j]); // -> as rightMax is smaller than leftMax hence it has to be lefttMaxHeight[i]
                sum += (rightMax - height[j]);
            }
        }
        
        return sum;
    }
};
