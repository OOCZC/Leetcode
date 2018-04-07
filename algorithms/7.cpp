class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while(x % 10 == 0 && x){
            x = x / 10;
        }
        while(x){
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        if(ans > 2147483647 || ans < -2147483648){return 0;}
        cout<<ans<<endl;
        return ans;
    }
};
