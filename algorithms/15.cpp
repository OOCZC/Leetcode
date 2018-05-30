/*

3sum 通过固定一个数并遍历，转换为2sum问题。

这里使用unordered_map解决2sum会出现有重复答案的现象，再运用set去重则会超时。

这里使用先排序，再设置两个游标在两端，向中间移动的方式求2sum。

*/

class Solution {
public:
    vector<vector<int>> get2sum(int pos, vector<int>& nums){ // ignore nums[pos], think of -nums[pos] as a target
        vector<vector<int>> v;
        int target = - nums[pos];
        int i = pos + 1, j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] == target){
                vector<int> u;
                u.push_back(nums[pos]);
                u.push_back(nums[i]);
                u.push_back(nums[j]);
                v.push_back(u);
                while(nums[i] == nums[i + 1])
                    i++;
                while(nums[j] == nums[j - 1])
                    j--;
                i++; j--;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{
                j--;
            }

        }
        return v;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans, v;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            v = get2sum(i, nums);
            for(int j = 0; j< v.size(); ++j){
                ans.push_back(v[j]);
            }
        }
        return ans;
    }
};
