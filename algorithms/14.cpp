class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs.size() > 0 ? strs[0] : "";
        for(int i = 1; i < strs.size(); ++i){
            for(int j = 0; j < pre.length() && j < strs[i].length(); ++j){
                if(pre[j] != strs[i][j]){
                    pre = pre.substr(0, j);
                    break;
                }
            }
            pre = pre.length() > strs[i].length() ? strs[i] : pre;
        }
        return pre;
    }
};
