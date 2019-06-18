class Solution {
    private LinkedList<String> anw;
    public List<String> generateParenthesis(int n) {
        anw = new LinkedList<String>();
        String currStr = "";
        addPare(0, 0, n, currStr);
        return anw;
    }

    private void addPare(int leftNum, int rightNum, int pareNum, String currStr) {
        if (leftNum == pareNum && rightNum == pareNum) {
            anw.add(currStr);
            return;
        }
        if (leftNum < pareNum) {
            addPare(leftNum + 1, rightNum, pareNum, currStr + '(');
        }
        if (rightNum < leftNum) {
            addPare(leftNum, rightNum + 1, pareNum, currStr + ')');
        }
    }
}
