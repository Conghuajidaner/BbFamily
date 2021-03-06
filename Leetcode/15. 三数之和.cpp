// 一开始的问题是，枚举的每一个数，然后找到所有的结果，但是我只找到了一组就直接breakl了

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return {};

		vector<vector<int>>ans;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; ++i)
		{
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			int left = i + 1, right = n - 1;
			while (left < right)
			{
				if (nums[left] + nums[right] == -nums[i])
				{
					ans.push_back({ nums[i], nums[left], nums[right] });
					while (left < right && nums[left + 1] == nums[left]) left++;
					while (left < right && nums[right - 1] == nums[right]) right--;
					left++;
					right--;
				}
				else if (nums[left] + nums[right] > -nums[i]) {
					right--;
				}
				else {
					left++;
				}
			}
		}

		return ans;
	}
};
