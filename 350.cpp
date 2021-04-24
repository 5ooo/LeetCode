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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ret;
        for (int i = 0, j = 0; i == nums1.size() || j == nums2.size();)
        {
            printf("%d", nums1[i]);
            if (nums1[i] == nums2[j])
            {
                ret.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        
        return ret;
    }

};


int main()
{
	Solution s;

	vector<int> a = {1, 2, 2, 1};	
	vector<int> b = {2, 2};	

	s.intersect(a, b);

	return 0;
}
