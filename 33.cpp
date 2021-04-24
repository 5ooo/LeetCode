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
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) 
        {
	    	int mid = (left + right) / 2;

		    if (nums[mid] == target)
			    return mid;
		
		    if (nums[mid] >= nums[left])//left in order
            {
                if (target >= nums[left] && target < nums[mid])
			        right = mid - 1;
                else
                    left = mid + 1;
            }
	    	else 
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
	    }
        return -1;
    }
};

int main()
{
	Solution s;

	return 0;
}
