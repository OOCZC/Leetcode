class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a[100000], a_num = 0;
        int i = 0, j = 0, x, y;
        while(i < nums1.size() || j < nums2.size()){
            x = i < nums1.size() ? nums1[i] : 99999999;
            y = j < nums2.size() ? nums2[j] : 99999999;
            a[a_num] = x > y ? (j++, y) : (i++, x);
            a_num ++;
        }
        int all_size = nums1.size() + nums2.size();
        if(all_size % 2){
            return a[all_size / 2];
        }
        else{
            return (a[all_size / 2] + a[all_size / 2 - 1]) / 2.0;
        }
    }
};
