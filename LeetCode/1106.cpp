#include <iostream>
using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        if (expression[0] == 'f')
            return false;
        if (expression[0] == 't')
            return true;

        // For !, & and | we need to handle sub-expressions
        string sub_str = expression.substr(2, expression.length() - 3); // Exclude the first char and last )

        if (expression[0] == '!')
        {
            return !parseBoolExpr(sub_str); // Not operator
        }

        int balancer = 0, s_i = 0;

        // For OR (|)
        if (expression[0] == '|')
        {
            for (int i = 0; i < sub_str.length(); i++)
            {
                if (sub_str[i] == '(')
                    balancer++;
                if (sub_str[i] == ')')
                    balancer--;

                if (balancer == 0 && (sub_str[i] == ',' || i == sub_str.length() - 1))
                {
                    // Parse each sub-expression
                    if (parseBoolExpr(sub_str.substr(s_i, i - s_i + 1)))
                    {
                        return true; // Short-circuit for OR
                    }
                    s_i = i + 1;
                }
            }
            return false; // If no true found
        }

        // For AND (&)
        if (expression[0] == '&')
        {
            for (int i = 0; i < sub_str.length(); i++)
            {
                if (sub_str[i] == '(')
                    balancer++;
                if (sub_str[i] == ')')
                    balancer--;

                if (balancer == 0 && (sub_str[i] == ',' || i == sub_str.length() - 1))
                {
                    // Parse each sub-expression
                    if (!parseBoolExpr(sub_str.substr(s_i, i - s_i + 1)))
                    {
                        return false; // Short-circuit for AND
                    }
                    s_i = i + 1;
                }
            }
            return true; // If no false found
        }

        return false; // Default case
    }
};

class Solution2

{
public:
    bool parseBoolExpr(string expression)
    {
        if (expression[0] == 'f')
            return false;
        if (expression[0] == 't')
            return true;

        // now it can either ! , &, or |

        // ) sign
        string sub_str = expression.substr(2, expression.length() - 3);

        cout << sub_str << endl;

        if (expression[0] == '!')
            return !parseBoolExpr(sub_str);

        int balancer = 0, s_i = 0;
        if (expression[0] == '|')
        {
            for (int i = 0; i < sub_str.length(); i++)
            {
                if (sub_str[i] == ')')
                    balancer += 1;
                else if (sub_str[i] == '(')
                    balancer -= 1;

                if (balancer == 0)
                {
                    if (parseBoolExpr(expression.substr(s_i, i - s_i + 1)))
                        return 1;
                    i += 1;
                    s_i += 2;
                }
            }
            return 0;
        }
        for (int i = 0; i < sub_str.length(); i++)
        {
            if (sub_str[i] == ')')
                balancer += 1;
            else if (sub_str[i] == '(')
                balancer -= 1;

            if (balancer == 0)
            {
                if (!parseBoolExpr(expression.substr(s_i, i - s_i + 1)))
                    return 0;
                i += 1;
                s_i += 2;
            }
        }
        return 1;
    }
};

/*


"|(&(t,f,t),!(t))"
false

 */

int main()
{

    Solution s;
    cout << s.parseBoolExpr("&(|(f))") << endl; // false
    return 0;
}