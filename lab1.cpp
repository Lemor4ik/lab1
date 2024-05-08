#include <iostream>
#include <vector>

using namespace std;

class Expression
{
private:
    vector<int> numbers;
    vector<char> operations;
    int count;

public:
    Expression(vector<int> nums, int c, vector<char> ops)
    {
        numbers = nums;
        count = c;
        operations = ops;
    }

    int calculate()
    {
        int result = numbers[0];
        for (int i = 1; i < count; i++)
        {
            if (operations[i - 1] == '+')
            {
                result += numbers[i];
            }
            else if (operations[i - 1] == '-')
            {
                result -= numbers[i];
            }
            else if (operations[i - 1] == '*')
            {
                result *= numbers[i];
            }
            else if (operations[i - 1] == '/')
            {
                result /= numbers[i];
            }
        }
        return result;
    }

    void printParameters()
    {
        for (int i = 0; i < count; i++)
        {
            cout << numbers[i] << " ";
            if (i < count - 1)
            {
                cout << operations[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    vector<vector<int>> allNumbers{ {5, 3, 2}, {10, 2, 3, 6}, {20, 4, 2} };
    vector<vector<char>> allOperations{ {'+', '*'}, {'-', '+', '*'}, {'/', '+'} };
    vector<int> counts{ 3, 4, 3 };

    vector<Expression> expressions;

    for (int i = 0; i < allNumbers.size(); i++)
    {
        Expression exp(allNumbers[i], counts[i], allOperations[i]);
        expressions.push_back(exp);
    }

    for (int i = expressions.size() - 1; i >= 0; i--)
    {
        expressions[i].printParameters();
        cout << "Result: " << expressions[i].calculate() << endl;
    }

    return 0;
}