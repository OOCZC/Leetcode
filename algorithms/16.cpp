class Solution {
public:
    int get2sum(int target, int pos, const vector<int>& nums) { // ignore nums[pos]
        int ans = -99999999;
        int i = pos + 1, j = nums.size() - 1;
        while(i < j){
            if (abs(target - ans) > abs(target - nums[i] - nums[j]))
                ans = nums[i] + nums[j];
            if (nums[i] + nums[j] == target) {
                return target + nums[pos];
            }
            else if (nums[i] + nums[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return ans + nums[pos];
    }

    int threeSumClosest(vector<int> &nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        //cout << "ans " << ans << endl;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int v = get2sum(target - nums[i], i, nums);
            if (abs(target - v) < abs(target - ans)) {
                ans = v;
                cout << ans << endl;
            }
        }
        return ans;
    }
};

/*
int main() {
    Solution s;
    vector<int> v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-4);
    cout << s.threeSumClosest(v,1);
    return 0;
}
*/
