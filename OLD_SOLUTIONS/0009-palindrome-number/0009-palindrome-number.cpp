class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int reversed_n = 0;
        int original = x;

        while (x != 0) {
            int digit = x % 10;
            if (reversed_n > INT_MAX / 10 || (reversed_n == INT_MAX / 10 && digit > 7)) {
                return false;
            }

            reversed_n = reversed_n * 10 + digit;
            x /= 10;
        }

        return reversed_n == original;
    }
};