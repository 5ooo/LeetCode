class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min_cap = 0;
        int max_cap = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (min_cap < weights[i])
                min_cap = weights[i];

            max_cap += weights[i];
        }

        while (min_cap < max_cap)
        {
            int cap = min_cap + (max_cap - min_cap) / 2;

            if (calcDays(weights, cap) > days)
            {
                min_cap = cap + 1;
            }
            else if (calcDays(weights, cap) <= days)
            {
                max_cap = cap;
            }
        }

        return min_cap;
    }

    int calcDays(vector<int>& weights, int cap) {
        int ret = 0;
        int tmp_cap = 0;

        for (int i = 0; i < weights.size();)
        {
            if (tmp_cap >= weights[i]) 
            {
                tmp_cap -= weights[i];
                i++;
            }
            else
            {
                tmp_cap = cap;
                ret++;
            }
        }

        return ret;
    }
};
