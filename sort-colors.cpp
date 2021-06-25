class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        for (int i = 0; i <= right;)
        {
            if (nums[i] == 0)
            {   
                if (left != i)
                {
                    nums[left] ^= nums[i];
                    nums[i] ^= nums[left];
                    nums[left] ^= nums[i];
                }
                
                i++;
                left++;
            }
            else if (nums[i] == 1)
            {   
                i++;
            }
            else
            {   
                if (right != i)
                {
                    nums[right] ^= nums[i];
                    nums[i] ^= nums[right];
                    nums[right] ^= nums[i];
                }
                
                right--;
            }
        }
    }


};
