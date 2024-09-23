#ifndef expValidation_H
#define expValidation_H

#include <string>
#include <sstream>
#include <cctype>
#include "Stack.h"
using namespace std;

class expValidation {
public:
    // Validate infix expression
    bool isValidInfix(const string& expression) {
        Stack<char> stack;
        char prevChar = ' ';
        bool wasOperator = true;      // To track if the last character was an operator

        for (char ch : expression) {
            if (ch == '(') {
                stack.push(ch);
                wasOperator = false;
            }
            else if (ch == ')') {
                if (stack.isEmpty() || wasOperator) return false;
                stack.pop();
            }
            else if (!isspace(ch) && !isdigit(ch) && !isOperator(ch)) {
                return false; // Invalid character
            }

            if (isOperator(ch)) {
                if (wasOperator) return false; // Two operators in a row
                wasOperator = true;
            }
            else {
                wasOperator = false; // Reset since we have a number or a parenthesis
            }
            prevChar = ch;
        }
        return stack.isEmpty() && !wasOperator; // Check for unbalanced parentheses or trailing operators
    }

    // Validate postfix expression
    bool isValidPostfix(const string& expression) {
        Stack<int> stack;
        istringstream tokens(expression);
        string token;

        while (tokens >> token) {
            if (isOperator(token[0]) && token.size() == 1) {
                if (stack.size() < 2) return false; // Not enough operands
                stack.pop(); // Pop two operands
                stack.push(0); // Push result (dummy value)
            }
            else if (isdigit(token[0])) {
                stack.push(stoi(token)); // Push operand
            }
            else {
                return false; // Invalid character
            }
        }
        return stack.size() == 1; // Should be one result left
    }

private:
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
};

#endif // EXPRESSIONVALIDATOR_H
