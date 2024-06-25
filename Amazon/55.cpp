// Amazon | Medium | 55. Jump Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        if (n == 1) {
            return true; 
        }

        for (int i = 0; i < n; i++) {
            if (i > farthest) {
                return false; 
            }
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) {
                return true; 
            }
        }
        return false;
    }
};
