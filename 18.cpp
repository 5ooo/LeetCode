#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

		vector<vector<int>> vRet;

        if (nums.size() < 4)
            return vRet;

        sort(nums.begin(), nums.end());

		for (int n = 0; n < nums.size() - 3; n++)
		{
			int nTarget = target - nums[n];

	    	int i, j, k;    
			for (i = n + 1; i < nums.size() - 2; i++)
			{
            	j = i + 1;
            	k = nums.size() - 1;

            	while(j < k)
            	{
                	int nTmpSum = nums[i] + nums[j] + nums[k];

                	if (nTmpSum > nTarget)
                    	k--;
                	else if (nTmpSum < nTarget)
                    	j++;
                	else
					{
						vRet.push_back({nums[n], nums[i], nums[j], nums[k]});
						k--;
						j++;
					}
            	}
			}
		}

        sort(vRet.begin(), vRet.end());
        vRet.erase(unique(vRet.begin(), vRet.end()), vRet.end());

        return vRet;
    }
};

int main()
{
    vector<int> vTest{1, 0, -1, 0, -2, 2};

	Solution s;

	s.fourSum(vTest, 0);
#if 0
	for(int i = 0; i < ret.size(); i++)
    {
        printf("%s\n", ret[i].c_str());
    }
#endif
	return 0;
}
