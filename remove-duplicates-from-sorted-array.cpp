class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;

        int pre = 0;
        int cur = 1;
        
        for (; cur < nums.size(); cur++)
        {
            if (nums[pre] == nums[cur])
                continue;
           
            pre++;
            nums[pre] = nums[cur];
        }
        
        return pre + 1;
    } 
};
