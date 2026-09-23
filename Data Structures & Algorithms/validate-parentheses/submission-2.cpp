class Solution
{
public:
    bool Vaild(char c, char s)
    {
        if (c == ']' && s == '[')
            return true;
        if (c == '}' && s == '{')
            return true;
        if (c == ')' && s == '(')
            return true;
        return false;
    }

    bool isValid(string s)
    {
        if (s.empty())
            return true;

        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
                stk.push(s[i]);
            else if (!stk.empty() && Vaild(s[i], stk.top()))
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
        return stk.empty();
    }
};
