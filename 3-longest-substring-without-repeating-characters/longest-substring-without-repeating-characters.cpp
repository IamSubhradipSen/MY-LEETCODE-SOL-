class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // It stores the last seen index of each character. Initialized to -1.
        vector<int> char_index(128, -1);
        
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];
            
            if (char_index[current_char] >= left) {
                left = char_index[current_char] + 1;
            }
            
            // Record/update the most recent index of the current character
            char_index[current_char] = right;
            
            // Update the maximum length found so far
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len ;
    }
};