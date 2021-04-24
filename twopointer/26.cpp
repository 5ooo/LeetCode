#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;
        
        int cur_val = nums[0];
        
        for (auto i = nums.begin() + 1; i < nums.end(); )
        {
            if (cur_val == *i)
            {
                nums.erase(i);
                continue;
            }
            
            cur_val = *i;
            i++;
        }
        
        return nums.size();
    }
};

int main()
{
	int test[] = {0, 0, 1, 1, 2, 2, 3, 3, 4};

    vector<int> test_v(test, test+9);

	Solution s;

	s.removeDuplicates(test_v);

	return 0;
}
