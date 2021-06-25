class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
    
        int max_pd; 
        int min_pd; 

        max_pd = nums[0];
        min_pd = nums[0];

        int ret = nums[0];
        for (int i = 2; i <= nums.size(); i++)
        {   
            int pre_max_pd = max_pd;
            max_pd = max(nums[i - 1], max(nums[i - 1] * max_pd, nums[i - 1] * min_pd));
            min_pd = min(nums[i - 1], min(nums[i - 1] * pre_max_pd, nums[i - 1] * min_pd));
            ret = max(ret, max_pd);
        }   

        return ret;
    } 
};
