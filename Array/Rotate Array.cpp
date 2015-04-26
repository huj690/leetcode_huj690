/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint:
Could you do it in-place with O(1) extra space?
*/

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        if (n == 0 || k == 0) {
            return;
        }
        rotateHelper(nums, 0, n - 1);
        rotateHelper(nums, 0, k - 1);
        rotateHelper(nums, k, n - 1);
    }
private:
    void rotateHelper(int nums[], int left, int right) {
        int mid = (left + right) / 2;
        for (int i = left; i <= mid; i++) {
            swap(nums[i], nums[left + right - i]);
        }
        
    }
};



