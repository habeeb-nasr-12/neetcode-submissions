class Solution {
public:
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z') ||
               (c >= 'a' && c <= 'z') ||
               (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = (int)s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left]))
                left++;
            while (right > left && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};