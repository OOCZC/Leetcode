// dp[i][j] == 1 表示字符串i-j为回文。

/*
   dp[i][j] = true,  i == j
   dp[i][j] = true,  i == j - 1 && str[i] == str[j]
   dp[i][j] = true,  i < j - 1  && str[i] == str[j] && dp[i+1][j-1]
   方向从左至右，从下至上
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int maxNum = 0, left = 0, right = 0;
        int dp[1005][1005];
        memset(dp,0,sizeof(dp));
        for(int j = 0; j < s.length(); ++j){
            for(int i = j; i >= 0; --i){
                if(i == j){
                    dp[i][j] = 1;
                    if(1 > maxNum){
                        maxNum = max(maxNum, 1);
                        left = i;
                        right = j;
                    }
                }
                else if(i == j - 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 1;
                        if(2 > maxNum){
                            maxNum = max(maxNum, 2);
                            left = i;
                            right = j;
                        }
                    }
                }
                else if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = 1;
                        if(j - i + 1 > maxNum){
                            maxNum = max(maxNum, j - i + 1);
                            left = i;
                            right = j;
                        }
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};
