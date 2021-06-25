class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        
        deque<int> q;
        
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && q.back() < nums[i])
                q.pop_back();
                   
            q.push_back(nums[i]);
        }
        
        for (int i = 0, j = k; j < nums.size(); i++, j++)
        {
            ret.push_back(int(q.front()));
            
            if (!q.empty() && q.front() == nums[i])
                q.pop_front();
            
            while (!q.empty() && q.back() < nums[j])
                q.pop_back();
                   
            q.push_back(nums[j]);
        }
        
        ret.push_back(q.front());
        
        return ret;
    }
};
