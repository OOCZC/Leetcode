class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int i = 0;
        int len = s.length();
        while(s[i] == 'M' && i < len){
            ans += 1000;
            i++;
        }
        if(s.substr(i, 2) == "CM" && i < len){
            ans += 900;
            i += 2;
        }
        if(s[i] == 'D' && i < len){
            ans += 500;
            i++;
        }
        if(s.substr(i, 2) == "CD" && i < len){
            ans += 400;
            i += 2;
        }
        while(s[i] == 'C' && i < len){
            ans += 100;
            i++;
        }
        if(s.substr(i, 2) == "XC" && i < len){
            ans += 90;
            i += 2;
        }
        if(s[i] == 'L' && i < len){
            ans += 50;
            i++;
        }
        if(s.substr(i, 2) == "XL" && i < len){
            ans += 40;
            i += 2;
        }
        while(s[i] == 'X' && i < len){
            ans += 10;
            i++;
        }
        if(s.substr(i, 2) == "IX" && i < len){
            ans += 9;
            i += 2;
        }
        if(s[i] == 'V' && i < len){
            ans += 5;
            i++;
        }
        if(s.substr(i, 2) == "IV" && i < len){
            ans += 4;
            i += 2;
        }
        while(s[i] == 'I' && i < len){
            ans += 1;
            i++;
        }
        return ans;
    }
};
