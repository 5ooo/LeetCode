class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int nSize = nums.size();
        if (nSize < 3)
            return -1; 

        sort(nums.begin(), nums.end());

        int nMinDValue = -1, nTmpDValue, nSum, nTmpSum;
        int i, j, k;    
        for (i = 0; i < nSize - 2; i++)
        {   
            j = i + 1;
            k = nSize - 1;

            while(j < k)
            {   
                nTmpSum = nums[i] + nums[j] + nums[k];
                nTmpDValue = nTmpSum - target;

                if (nTmpDValue > 0)
                    k--;
                else if (nTmpDValue < 0)
                    j++;
                else
                    return target;
                
                if (nMinDValue > abs(nTmpDValue) || nMinDValue == -1)
                {   
                    nMinDValue = abs(nTmpDValue);
                    nSum = nTmpSum;
                }  
            }   
        }   

        return nSum;
    } 
};
