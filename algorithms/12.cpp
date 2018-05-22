class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        for(int i = 0; i < num / 1000; ++i){
            ans += "M";
        }
        num = num % 1000;
        if(num >= 900){
            ans += "CM";
            num -= 900;
        }
        if(num >= 500){
            ans += "D";
            num -= 500;
        }
        if(num >= 400){
            ans += "CD";
            num -= 400;
        }
        for(int i = 0; i < num / 100; ++i){
            ans += "C";
        }
        num = num % 100;
        if(num >= 90){
            ans += "XC";
            num -= 90;
        }
        if(num >= 50){
            ans += "L";
            num -= 50;
        }
        if(num >= 40){
            ans += "XL";
            num -= 40;
        }
        for(int i = 0; i < num / 10; ++i){
            ans += "X";
        }
        num = num % 10;
        if(num >= 9){
            ans += "IX";
            num -= 9;
        }
        if(num >= 5){
            ans += "V";
            num -= 5;
        }
        if(num >= 4){
            ans += "IV";
            num -= 4;
        }
        for(int i = 0; i < num; ++i){
            ans += "I";
        }
        return ans;
    }
};
