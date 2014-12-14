/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
中心思想：逆序是没有next permutation的！
思路：排列数字末尾出现的末尾数字即使需要改变的部分
step1: 从右向左，依次判断逆序出现的位置（num[i] <= num[i - 1]），用upPost定位逆序出现之前的位置
      *若整个数组均为逆序，（upPost < 0）则反转成为正序
step2：从右向左，找到第一个比定位值大的数，交换（实现了next的意图）
step3：将之前找到的逆序部分反转回正

*注意reverse的用法，[left, right) !!!
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.empty()) {
            return;
        }
        int i = num.size() - 1;
        while (i > 0 && num[i] <= num[i - 1]) {
            i--;
        }
        int upPost = i - 1;
        if (upPost < 0) {
            reverse(num.begin(), num.end());
            return;
        }
        int j = num.size() - 1;
        while (num[j] <= num[upPost]) {
            j--;
        }
        swap(num[upPost], num[j]);
        reverse(num.begin() + i, num.end()); 
        return;
    }
};
