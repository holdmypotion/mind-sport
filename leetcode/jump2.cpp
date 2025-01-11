class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int count = 1;
        int i = 0;

        while(i < n) {
          int reach = nums[i] + i;
          int reachIdx;

          if (reach >= n-1) return count;

          for (int j = i+1; j <= reach; j++) {
            int newReach = nums[j] + j;
            if (newReach >= reach) {
              reach = newReach;
              reachIdx = j;
            }
          }

          count++;
          i = j;
        }

        return count;
    }
};
