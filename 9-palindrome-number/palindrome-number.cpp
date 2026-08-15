class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        // Reverse the number until the original number is less than or equal to the reversed half
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
       
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
