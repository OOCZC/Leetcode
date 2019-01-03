import java.util.Stack;

class Solution {
    private Stack<Character> stack = new Stack<Character>();

    public boolean isValid(String s) {
        for (int i = 0; i < s.length(); ++i) {
            pair(s.charAt(i));
        }
        return stack.size() == 0 ? true : false;
    }

    public void pair(char ch) {
        if (stack.size() != 0 && pairCh(stack.peek(), ch))
            stack.pop();
        else
            stack.push(ch);
    }

    private boolean pairCh(char a, char b) {
        if (a == '{' && b == '}')
            return true;
        if (a == '(' && b == ')')
            return true;
        if (a == '[' && b == ']')
            return true;
        return false;
    }
}
