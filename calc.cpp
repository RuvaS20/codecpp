#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    /*Calculator using switch statements*/
    char selection; // define the selection variable
    float val1, val2, result; // define the variables for the calculation and final result

    // menu selection prompt
    std::cout << "Please select an operation:\n";
    std::cout << "(+) Addition\n(-) Subtraction\n(*) Multiplication\n(/) Division\n(%) Reminder\n";

    // get the user's selection
    std::cout << "Enter your choice (+, -, *, /, %): ";
    std::cin >> selection;

    // get the two values from the user
    std::cout << "Enter the first value: ";
    std::cin >> val1;
    std::cout << "Enter the second value: ";
    std::cin >> val2;

    float temp = val1; // define a temporary variable to hold the modulus result

    std::cout << std::setprecision(5) << std::fixed; // set the precision for the output

    // using switch cases to perform the calcuation on the numbers
    switch(selection) {
        case '+': // addition
            result = val1 + val2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '-': // subtraction
            result = val1 - val2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '*': // multiplication
            result = val1 * val2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '/': // division
            if (val2 != 0) {
                result = val1 / val2;
                std::cout << "Result: " << result << std::endl;
            } else {
                std::cout << "Nope, you can't divide by zero." << std::endl;
            }
            break;
        case '%': // modulus
            // using fmod function from cmath library to calculate the modulus of two floating point numbers
            // Time complexity: O(1) since it is a single operation using the lbrary
            // the answer is the a float as well
            // if (val2 != 0) {
            //     temp = fmod(val1, val2);
            //     std::cout << "Result: " << temp << std::endl;
            // } else {
            //     std::cout << "Nope, you can't divide by zero." << std::endl;
            // }

            // using a while loop to calculate the modulus of two floating point numbers
            // Time complexity: O(n) where n is the number of times val2 can be subtracted from val1
            
            if (val2 != 0) {
                while (temp >= val2) {
                    temp -= val2;
                }
                std::cout << "Result: " << temp << std::endl;
            } else {
                std::cout << "Nope, you can't divide by zero." << std::endl;
            }

            break;

        // notes
        // Time complexity: O(1) for addition, subtraction, multiplication, and division
        // Time complexity: O(n) for modulus where n is the number of times val2 can be subtracted from val1
        // Surely fmod() has to somehow calculate the remainder. Maybe internally it repeatedly subtracts? - No:
        // Big-O isn't about whether code contains loops. It's about whether the amount of work grows with the input size.
        // There are only a finite number of possible float values. So even if the implementation did something internally, the maximum amount of work is bounded.
        // this is also why % is usually considered O(1) since the operating system can perform the operation in a single instruction, directly on the hardware.
        // using the raw % will not work with float because its behavior is strictly defined for integer types at both the language and hardware levels
        default:
            std::cout << "Invalid selection. Please choose one of +, -, *, / or %." << std::endl;
    }

    return 0;
}