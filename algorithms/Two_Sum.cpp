class Solution {
public:
/*  O(n*n)解法
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }
*/ 
// O(n)解法
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i){
	    map[nums[i]] = i;
	}
        for(int i = 0; i < nums.size(); ++i){
	    int temp = target - nums[i];
            if(map.count(temp) && i != map[temp]){
                ans.push_back(i);
                ans.push_back(map[temp]);
                return ans;
            }
        }
    }
};
