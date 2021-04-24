#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        if (nums.size() < 3)
            return -1;

        sort(nums.begin(), nums.end());

        int nMinDValue = -1, nTmpDValue, nSum, nTmpSum;
	    int i, j, k;    
		for (i = 0; i < nums.size() - 2; i++)
		{
            j = i + 1;
            k = nums.size() - 1;

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

                if (nMinDValue == -1 || nMinDValue > abs(nTmpDValue))
                {
                    nMinDValue = abs(nTmpDValue);
                    nSum = nTmpSum;
                }
            }
		}

        return nSum;
    }
};

int main()
{
#if 0
    //[-1, 2, 1, -4]
	vTest.push_back(-1);	
	vTest.push_back(2);	
	vTest.push_back(1);	
	vTest.push_back(-4);	
#endif
    vector<int> vTest{1, 2, 5, 10, 11};
    

	Solution s;

	printf("%d\n", s.threeSumClosest(vTest, 12));

	return 0;
}
