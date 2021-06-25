class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;
                
        int ret = 0;

        vector<int> l_max(height.size(), 0); 
        vector<int> r_max(height.size(), 0); 

        l_max[0] = height[0];
        r_max[height.size() - 1] = height[height.size() - 1]; 

        for (int i = 1; i < height.size(); i++)
            l_max[i] = max(l_max[i - 1], height[i]);

        for (int i = height.size() - 2; i >= 0; i--)
            r_max[i] = max(r_max[i + 1], height[i]);

        for (int i = 0; i < height.size(); i++)
            ret += min(l_max[i], r_max[i]) - height[i];   

        return ret;
    } 
};
