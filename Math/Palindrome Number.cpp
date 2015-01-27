/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
        int high = 1, copy_x = x;
        while (x >= 10) {
            high *= 10;
            x /= 10;
        }
        
        x = copy_x;
        int low = 1;
        while (low < high) {
            if (x / high % 10 == x / low % 10) {
                high /= 10;
                low *= 10;
            } else {
                return false;
            }
        }
        return true;
    }
};
