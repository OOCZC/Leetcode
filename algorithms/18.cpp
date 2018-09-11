class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        int s1, s2, s3, s4;
        for (int i = 0; i < nums.size(); ++ i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); ++ j) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                findTarget(nums, ans, i, j, target - nums[i] - nums[j]);
            }
        }
        return ans;
    }
    void findTarget(const vector<int> &nums, vector<vector<int>> &ans,
                                   int i, int j, int target) {
        int left = i > j ? i + 1: j + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target)
                ++ left;
            else if (nums[left] + nums[right] > target)
                -- right;
            else {
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[left]);
                v.push_back(nums[right]);
                ans.push_back(v);
                ++ left;
                while (left < right && nums[left] == nums[left - 1])
                    ++ left;
            }
        }
    }
};
