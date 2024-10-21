#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "expValidation.h"
#include "Stack.h"

using namespace std;

int main() {
    int Choice;
    ifstream file("Expressions.txt"); 
    if (!file)
    {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    string expressions[10];
    int count = 0;

    // Read expressions from the file
    while (count < 10 && getline(file, expressions[count])) 
    {
        count++;
    }
    file.close();

    // Display the expressions
    cout << "Available expressions:\n";
    for (int i = 0; i < count; ++i) 
    {
        cout << i + 1 << ": " << expressions[i] << endl;
    }

    do {
        // Ask the user to select a line number
        int lineNumber;
        cout << "\nSelect a line number to check its expression: ";
        cin >> lineNumber;

        if (lineNumber < 1 || lineNumber > count)
        {
            cout << "\nInvalid line number." << endl;
            return 1;
        }

        string selectedExpression = expressions[lineNumber - 1];

        expValidation validator;
        bool isValid;
        string exprType;

        // To Determine if the expression is infix or postfix based on parentheses
        if (selectedExpression.find('(') != string::npos || selectedExpression.find(')') != string::npos)
        {
            isValid = validator.isValidInfix(selectedExpression);
            exprType = "infix";
        }
        else {
            isValid = validator.isValidPostfix(selectedExpression);
            exprType = "postfix";
        }

        // Output the result
        if (isValid) 
        {
            cout << "\nThe " << exprType << " expression is valid." << endl;
        }
        else {
            cout << "\nThe " << exprType << " expression is invalid." << endl;
        }

        cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* " << endl;
        cout << "Press 1 to continue and select again or 0 to exit: ";
        cin >> Choice;
    } while (Choice == 1);

    return 0;
}
