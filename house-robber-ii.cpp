class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 1)
            return nums[0];

        return max(robRange(nums, 0, nums.size() - 2), //抢第一间，不抢最后一间
                   robRange(nums, 1, nums.size() - 1)); //不抢第一间，抢最后一间
    }

    int robRange(vector<int>& nums, int start, int end) {

        int dp_i = 0;   //第i间房子最多能抢的钱
        int dp_i_1 = 0; //第i+1间房子最多能抢的钱
        int dp_i_2 = 0; //第i+2间房子最多能抢的钱

        for (int i = end; i >= start; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i;
    }
};
