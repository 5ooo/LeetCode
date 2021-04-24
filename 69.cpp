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
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        
        int left = 0; 
        int right = x;
        
        while (left < right)
        {
            int mid = (left + right) / 2;
            
            if (x / mid >= mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        return right - 1;
    }
};


int main()
{
	Solution s;

	return 0;
}
