#pragma once

//contains the expvalidation class
    class expValidation {
    public:
                                                        // To Validate infix expression
        bool isValidInfix(const string& expression) {
            Stack<char> stack;
            char prevChar = ' ';
            bool wasOperator = true; 
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
                    return false; 
                }

                if (isOperator(ch)) {
                    if (wasOperator) return false; 
                    wasOperator = true;
                }
                else {
                    wasOperator = false; 
                }
                prevChar = ch;
            }
            return stack.isEmpty() && !wasOperator; // Check for unbalanced parentheses or trailing operators
        }

                          // To Validate postfix expression
        bool isValidPostfix(const string& expression) {
            Stack<int> stack;
            istringstream tokens(expression);
            string token;

            while (tokens >> token) {
                if (isOperator(token[0]) && token.size() == 1) {
                    if (stack.size() < 2) return false; // Not enough operands
                    stack.pop(); 
                    stack.push(0); 
                }
                else if (isdigit(token[0])) {
                    stack.push(stoi(token)); 
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

