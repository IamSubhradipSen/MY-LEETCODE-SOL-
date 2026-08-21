class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle closing brackets
            else {
                // If stack is empty, there is no matching opening bracket
                if (st.empty()) return false;
                
                char top = st.top();
                
                // Check if the top of the stack matches the current closing bracket
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // Match found, remove from stack
                } else {
                    return false; // Mismatched bracket
                }
            }
        }
        
        // If stack is empty, all brackets were matched correctly
        return st.empty();
    }
};