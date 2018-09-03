class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits.length() == 0)
            return v;
        dfsLetter(v, digits, 0);
        return v;
    }
    void dfsLetter(vector<string> &v, string digits, int index) {
        if (digits.length() == index) {
            string s(str_letter, digits.length());
            v.push_back(s);
            return;
        }
        int num = digits[index] - '0' - 2;
        for (int i = 0; letter[num][i] != 0; ++ i) {
            str_letter[index] = letter[num][i];
            dfsLetter(v, digits, index + 1);
        }
    }
private:
    char letter[8][5] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char str_letter[1000];
};
