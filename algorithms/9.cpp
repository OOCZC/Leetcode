class Solution {
public:
    bool isPalindrome(int x) {
        char str[1000];
        sprintf(str, "%d", x);
        int str_len = strlen(str);
        for(int i = 0; i < str_len / 2; ++i){
            if(str[i] != str[str_len - i - 1]){
                return false;
            }
        }
        return true;
    }
};
