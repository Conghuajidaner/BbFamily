class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i = m - 1, j = m + n - 1; i >= 0 && j >= 0; i --, j --)
            nums1[j] = nums1[i];

        int idx1 = n, idx2 = 0, idx = 0;
        if (m != 0) {
            for (; idx1 < m + n && idx2 < n && idx < m + n; idx ++)
            {
                if (nums1[idx1] <= nums2[idx2])
                {   
                    nums1[idx] = nums1[idx1 ++];
                } else {
                    nums1[idx] = nums2[idx2 ++];
                }
            }
        }
        // cout << idx1 <<  " " << idx2 << " " << idx << endl;
        if(m != 0)
            while (idx < m + n && idx1 < m + n) nums1[idx ++] = nums1[idx1 ++];
        while (idx < m + n && idx2 < n) nums1[idx ++] = nums2[idx2 ++];
    }
};
