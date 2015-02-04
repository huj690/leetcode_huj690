class Solution {
public:
    int sqrt(int x) {
        if (x < 2) {
            return x;
        }
        int low = 1, high = x / 2;
        while (low <= high) { //取不取等要看情况
            int mid = (low + high) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low < x / low ? low : low - 1; // return的时候也要多注意
    }
};
