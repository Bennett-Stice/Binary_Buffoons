//Pierre Minga
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expression) {
    // Stack to store operands
    stack<int> operands;

    // Using stringstream to separate expression elements
    stringstream ss(expression);
    string input;

    // Loop through each token in the expression
    while (ss >> input) {
        // If the first input is a digit, push it onto the stack
        if (isdigit(input[0])) {
            operands.push(stoi(input)); //converts the string input into an integer and pushes it onto the stack (operands). 
        } else {
            // If it's an operator, pop the top two operands from the stack
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            // Perform the operation based on the operator
            switch (input[0]) { // push the first operator onto the stack
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            } 
        }
    }

    // The result is the only element left in the stack
    return operands.top();
}

int main() {
    // Get the postfix expression from the user
    string expression;
    cout << "Enter postfix expression (operands and operators separated by space): ";
    getline(cin, expression);

    // Evaluate the expression
    int result = evaluatePostfix(expression);

    // Display the result
    cout << "Result: " << result << endl;

    return 0;
}
