class Solution {
public:
    string longestPalindrome(string s) {
     if (s.length() < 2) {
            return s;
        }

        int start = 0;
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes (center is a single character)
            int len1 = expandAroundCenter(s, i, i);
            
            // Check for even-length palindromes (center is between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Take the max length found from both center types
            int len = max(len1, len2);
            
            // If we found a longer palindrome, update the starting index and max length
            if (len > max_len) {
                start = i - (len - 1) / 2;
                max_len = len;
            }
        }

        return s.substr(start, max_len);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        // Expand outwards as long as the characters match and stay within bounds
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the valid palindrome
        // (right - left - 1 because the loop breaks one step after the palindrome ends)
        return right - left - 1;   
    }
};