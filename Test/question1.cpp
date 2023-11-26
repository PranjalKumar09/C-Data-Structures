#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int amount, amount1, n, last_committed = 1;
vector<int> transactions;
vector<int> answers;

// Function to perform operations
void operation(const string &str, int op_no)
{
    stringstream ss(str);
    string word;
    vector<string> words;

    // Tokenize the input string
    while (ss >> word)
        words.push_back(word);

    if (words.size() == 2)
    {
        int money = stoi(words[1]);

        if (words[0] == "credit")
        {
            amount += money;
            transactions.push_back(money);
        }
        else if (words[0] == "debit")
        {
            amount -= money;
            transactions.push_back(-money);
        }
        else if (words[0] == "rollback")
        {
            int start_idx = static_cast<int>(transactions.size()) - money;
            if (start_idx < 0)
            {
                cerr << "Error: Rollback exceeds transaction history size.\n";
                return;
            }
            for (int i = start_idx; i < static_cast<int>(transactions.size()); i++)
            {
                amount -= transactions[i];
            }
            transactions.resize(start_idx);
        }
        else if (words[0] == "abort")
        {
            if (0 <= money - last_committed)
            {
                amount -= transactions[money-last_committed];
            }
        }
    }
    else if (words.size() == 1)
    {
        if (words[0] == "read")
        {
            answers.push_back(amount);
        }
        else if (words[0] == "commit")
        {
            transactions.clear();
            last_committed = op_no;
            amount1 = amount; // Update the last committed amount
        }
    }
}

int main()
{
    cin >> amount >> n;

    amount1 = amount; // Initialize the last committed amount
    cin.ignore();     // Ignore the newline after reading integers

    for (int i = 1; i <= n; i++)
    {
        string str;
        getline(cin, str);
        operation(str, i);
    }
    for (int i = 0; i < answers.size(); i++)
        cout << answers[i] << endl;
    return 0;
}

/*
90

8

Operation 1 - Read, prints the account balance i.e., 90

Operation 2 - Credit 10, Result: Balance increases by 10. New balance: 100

Operation 3 - Debit 12, Result: Balance decreases by 12. New balance: 88

Operation 4 - Debit 8, Result: Balance decreases by 8. New balance: 80

Operation 5 - Credit 7, Result: Balance increases by 7. New balance: 87

Operation 6 - Abort 1, this means undoing the changes made by the 1st transaction (the credit of 10). So, the account balance will become 77

Operation 7 - Commit, this commits all previous changes made. Account balance will be updated as 77

Operation 8 - Read, prints the account balance i.e., 77
77
*/
