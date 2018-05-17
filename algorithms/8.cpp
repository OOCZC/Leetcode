class Solution {
public:
    int myAtoi(string str) {
        int sign_flag = 1; // pos
        int sign_num = 0;
        int begin_num = 0;
        double return_num = 0;
        for(int i = 0; i < str.length(); ++i){
            if(str[i] == ' '){
                if(begin_num)
                    break;
            }
            else if(str[i] == '+'){
                sign_num ++;
                if(begin_num)
                    break;
                if(sign_num > 1 || begin_num)
                    return 0;
                begin_num = 1;
            }
            else if(str[i] == '-'){
                sign_num ++;
                if(begin_num)
                    break;
                if(sign_num > 1|| begin_num){
                    return 0;
                }
                begin_num = 1;
                sign_flag = -1; // neg
            }
            else if(str[i] >= '0' && str[i] <= '9'){
                return_num *= 10;
                return_num += str[i] - '0';
                begin_num = 1;
                if(return_num > INT_MAX && sign_flag == 1)
                    return INT_MAX;
                if(return_num < INT_MIN && sign_flag == -1)
                    return INT_MIN;
            }
            else if(str[i] == '.'){
                break;
            }
            else if(begin_num)
                    break;
            else
                return 0;
                
        }
        
        return (int)return_num * sign_flag;
    }
};
