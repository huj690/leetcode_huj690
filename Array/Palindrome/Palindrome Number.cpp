/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

//取头取尾
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int d = 1;
        while (x / d >= 10) {
            d *= 10;
        }
		while (x > 0) {
		    int q = x / d;
		    int r = x % 10;
		    if (q != r) {
		        return false;
		    }
		    x = x % d / 10;
		    d /= 100;
		}
		return true;
    }
};

//取一半 造一半
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
		int cnt = 0, copy_x = x;
		while (copy_x != 0) {
			cnt++;
			copy_x /= 10;
		}

        int y = 0;
		int mid = cnt / 2;
        while (mid--) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return cnt % 2 == 0 ? x == y : x / 10 == y;
    }
};
