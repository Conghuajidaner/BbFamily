class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int len = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 1; i < len; ++ i)
        {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        return min(arr.back(), len);
    }
};
