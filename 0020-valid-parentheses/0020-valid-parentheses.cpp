class Solution {
public:
    bool isValid(std::string parentheses) {
        std::stack<char> stack;
        std::unordered_map<char, char> dict = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        for (int i = 0; i < parentheses.length(); i++) {
            if (dict.find(parentheses[i]) != dict.end()) {
                stack.push(parentheses[i]);
            } else if (!stack.empty() && parentheses[i] == dict[stack.top()]) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();
    }
};