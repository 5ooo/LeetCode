class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, Compare> q;
        
        if (nums.size() < k)
            return -1;
        
        for (int i = 0; i < k; i++)
            q.push(nums[i]);
        
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        
        return q.top();
    }

    class Compare
    {
    public:
        bool operator() (int x, int y)
        {
            return x > y;
        }
    };
};
