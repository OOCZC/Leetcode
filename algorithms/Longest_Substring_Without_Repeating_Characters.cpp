class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0;
        unordered_map<char, int> map; # hash implement
        for( j = 0; j < s.length(); ++j){
            if(map.count(s[j])){
                i = max(i, map[s[j]] + 1);
            }
            map[s[j]] = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
