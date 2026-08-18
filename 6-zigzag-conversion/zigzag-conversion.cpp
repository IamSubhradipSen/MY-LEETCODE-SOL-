class Solution {
public:
    string convert(string s, int numRows) {
     if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        vector<string> rows(min(numRows, int(s.length())));
        
        int currentRow = 0;
        bool goingDown = false;

        // Iterate through each character in the string
        for (char c : s) {
            rows[currentRow] += c;
            
            // If we are at the top row or the bottom row, change direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to the next row depending on the current direction
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all the rows into a single result string
        string result = "";
        for (const string& row : rows) {
            result += row;
        }

        return result ;  
    }
};