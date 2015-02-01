/*
Palindrome Partitioning II Total Accepted: 22724 Total Submissions: 121512 My Submissions Question Solution 
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

/*
bool isPalindrome[i][j] : s[i->j] is a palindrome or not.
int dp[i] : s[0->i] need to be cutted to dp[i] parts.
init: if (s[0->i] is palindrome): dp[i] = 1;
      else : dp[i] = dp[i - 1] +1;
transfer equation: for (k = i..0): if (s[k->i] is palindrome) : dp[i] = min(dp[k - 1] + 1, dp[i]);
*/

class Solution {
public:
    int minCut(string s) {
        if (s.empty()) {
            return 0;
        }
        buildIsPalindrome(s);
        int *dp = new int[s.length()];
        dp[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (isPalindrome[0][i]) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
            for (int cut = i; cut >= 0; cut--) {
                if (isPalindrome[cut][i]) {
                    dp[i] = (dp[cut - 1] + 1) < dp[i] ? dp[cut - 1] + 1 : dp[i];
                }
            }
        }
		deletePalindrome(s);
        return dp[s.length() - 1] - 1;
    }
private:
    bool **isPalindrome;
    void buildIsPalindrome(string s) {
		isPalindrome = new bool*[s.length()];
        for (int i = 0; i < s.length(); i++) {
			isPalindrome[i] = new bool[s.length()];
            for (int j = 0; j < s.length(); j++) {
                if (i >= j) {
					isPalindrome[i][j] = true;
                } else {
                    isPalindrome[i][j] = false;
                }
			}
        }
        
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = s.length() - 1; j >= 0; j--) {
                if (i < j) {
                    isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
                }
            }
        } 
    } 
	void deletePalindrome(string s) {
		for (int i = 0; i < s.length(); i++) {
			delete [] isPalindrome[i];
		}
		delete [] isPalindrome;
	}
};
