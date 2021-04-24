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
    vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0)
			return digits;

		int i;
		for (i = digits.size() - 1; i >= 0; i--)
		{
			digits[i] += 1;
			if (digits[i] == 10)
				digits[i] = 0;
			else
				return digits;
		}

		if (digits[0] == 0)
		{
			vector<int> ret(digits.size() + 1, 0);
			ret[0] = 1;
			return ret;
		}
		else
			return digits;
    }


};


int main()
{
	Solution s;

	return 0;
}
