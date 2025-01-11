class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i <= reach; i++) {
            if (reach >= n-1) return true;
            reach = max(reach, i + nums[i]);
        }
        return false;
    }
};

