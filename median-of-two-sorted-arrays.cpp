class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int size = size1 + size2;
        int is_odd = size % 2;
        int midIdx = size / 2, idx1 = 0, idx2 = 0;
        int min1 = 0, min2 = 0;
        int tmp[2] = { 0 };

        if(size1 == 0 && size2 == 0)
            return 0;
        else if(size1 != 0 && size2 == 0)
        {
            if(is_odd)
                return (double)nums1[midIdx];
            else
                return (double)((nums1[midIdx - 1] + nums1[midIdx]) / 2.0);
        }
        else if(size1 == 0 && size2 != 0)    
        {
            if(is_odd)
                return (double)nums2[midIdx];
            else
                return (double)((nums2[midIdx - 1] + nums2[midIdx]) / 2.0);
        }


        if(is_odd)
        {
            while((idx1 + idx2) <= midIdx)
            {
                if(idx1 < size1 && idx2 < size2)
                {
                    if(nums1[idx1] <= nums2[idx2])
                    {
                        idx1++;
                    }
                    else
                    {
                        idx2++;
                    }
                }
                else if(idx1 == size1)
                {
                    if(nums1[idx1 - 1] < nums2[idx2])
                    {
                        idx2 = midIdx - idx1 + 1;
                    }      
                    else
                    {
                        idx2++;
                    }
                }
                else if(idx2 == size2)
                {
                    if(nums2[idx2 - 1] < nums1[idx1])
                    {
                        idx1 = midIdx - idx2 + 1;
                    }  
                    else
                    {
                        idx1++;
                    }
                }
            }

            return (double)nums2[idx2 - 1] > (double)nums1[idx1 - 1] ? (double)nums2[idx2 - 1] : (double)nums1[idx1 - 1];
        }
        else
        {
            while((idx1 + idx2) <= midIdx)
            {
                if(idx1 < size1 && idx2 < size2)
                {
                    if(nums1[idx1] <= nums2[idx2])
                    {
                        tmp[0] = tmp[1];
                        tmp[1] = nums1[idx1];
                        idx1++;
                    }
                    else
                    {
                        tmp[0] = tmp[1];
                        tmp[1] = nums2[idx2];
                        idx2++;
                    }
                }
                else if(idx1 == size1)
                {
                    if(nums1[idx1 - 1] <= nums2[idx2])
                    {
                        tmp[0] = tmp[1];
                        tmp[1] = nums2[idx2];
                        idx2++;
                    }
                }
                else if(idx2 == size2)
                {
                    if(nums2[idx2 - 1] <= nums1[idx1])
                    {
                        tmp[0] = tmp[1];
                        tmp[1] = nums1[idx1];
                        idx1++;
                    }
                }
            }

            return (double)((tmp[0] + tmp[1]) / 2.0);
        }
    }
};
