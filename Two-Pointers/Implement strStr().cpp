/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        
        if (haystack.empty()) {
            return -1;
        }
        
        int gap = haystack.length() - needle.length();
        for (int i = 0; i <= gap; i++) {
            if (haystack[i] != needle[0]) {
                continue;
            }
            int j = 1;
            for (; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needle.length()) { //hint;
                return i;
            }
        }
        return -1;
    }
};
