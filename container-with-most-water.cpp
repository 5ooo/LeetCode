class Solution {
public:
    int maxArea(vector<int>& height) {

        int vSize = height.size();
        int curLen, maxLen = 0, curHeight, maxHeight = 0;
        long curArea = 0, maxArea = 0;

        for(int pre = 0, post = vSize - 1; pre < post;)
        {     
            curHeight = height[post] > height[pre] ? height[pre] : height[post];
            curLen = post - pre;

            curArea = curLen * curHeight;
            if(curArea > maxArea)
            {
                maxLen = curLen;
                maxHeight = curHeight;
                maxArea = curArea;
            }

            if(height[pre] < height[post])
                pre++;
            else
                post--;

        }

        return maxArea;
    }
};
