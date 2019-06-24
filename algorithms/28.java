class Solution {
    // no find return -1
    // needle is "" return 0
    public int strStr(String haystack, String needle) {
        if(haystack == null || needle == null)
            return -1;
        if(needle.length() == 0)
            return 0;

        if(haystack.length() < needle.length())
            return -1;
        for(int i = 0; i < haystack.length(); ++i) {
            for(int j = 0; j < needle.length(); ++j) {
                if(i + j >= haystack.length())
                    return -1;
                if(haystack.charAt(i + j) != needle.charAt(j))
                    break;

                if(j == needle.length() - 1)
                    return i;
            }
        }
        return -1;
    }
}
