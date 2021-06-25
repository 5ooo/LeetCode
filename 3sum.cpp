class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int first, second, third;
        int sum;
        int numsSize = nums.size();
        bool existed = false;
        vector<vector<int> > res;

        if(numsSize < 3)
            return res;

        sort(nums.begin(), nums.end());

        for(first = 0; first < numsSize - 2; first++)
        {
            if(nums[first] > 0)
                break;

            if(first > 0 && nums[first] == nums[first - 1])
                continue;

            second = first + 1;
            third = numsSize - 1;

            while(second < third)
            {
                if((sum = nums[first] + nums[second] + nums[third]) == 0)
                {
                    vector<int> tmp;
                    tmp.push_back(nums[first]);
                    tmp.push_back(nums[second]);
                    tmp.push_back(nums[third]);
                    res.push_back(tmp);
                    do
                    {
                        second++;
                    }
                    while(second < third && nums[second - 1] == nums[second]);
                    do
                    {
                        third--;
                    }
                    while(second < third && nums[third + 1] == nums[third]); 
                }
                else if(sum > 0)
                    third--;
                else 
                    second++;
            }
        }

        return res;
    }
};
