#include <iostream>
#include <iomanip>
#include <cmath>
// Write a program named student_scores.cpp that reads students’ test scores in the range 0–200 as integer user input.
// It should then determine the number of students having scores in each of the following ranges: 0–24, 25–49, 50–74, 75–99, 100–124, 125–149, 150–174, and 175–200.
// Output the score ranges and the number of students as a table.
// Your program should also output the mean, variance and standard deviation.

// halfway between the lowest and highest
double midpoint(int lower, int upper) {
    return (lower + upper) / 2.0;
}

// f * x = frequency times midpoint
double fx(int f, double x) {
    return f * x;
}

// (x - mean)^2 = squared distance from the midpoint to the mean
double x_xbar_sqrd(double x, double mean) {
    return (x - mean) * (x - mean);
}

// f * (x - mean)^2
double f_x_xbar_sqrd(int f, double x, double mean) {
    return f * x_xbar_sqrd(x, mean);
}

// Prints one row of the table
void printRow(int lower, int upper, int f, double mean) {
    double x = midpoint(lower, upper);
    std::cout << std::setw(4) << lower << " - " << std::setw(7) << upper
              << std::setw(16) << x
              << std::setw(16) << f
              << std::setw(12) << fx(f, x)
              << std::setw(14) << x_xbar_sqrd(x, mean)
              << std::setw(14) << f_x_xbar_sqrd(f, x, mean) << std::endl;
}

int main() {
    int n;     // number of students
    int score; // user entered score

    // How many scores fall in each group
    int count24 = 0, count49 = 0, count74 = 0, count99 = 0, count124 = 0, count149 = 0, count174 = 0, count200 = 0;

    std::cout << "How many students? ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "No scores to be entered." << std::endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Score for student " << i + 1 << ": ";
        std::cin >> score;

        if (score < 0 || score > 200) {
            std::cout << "Wrong input. Enter a score in range 0-200." << std::endl;
            i--; // go back and ask for this student again
            continue;
        }

        if (score <= 24) {
            count24++;
        } else if (score <= 49) {
            count49++;
        } else if (score <= 74) {
            count74++;
        } else if (score <= 99) {
            count99++;
        } else if (score <= 124) {
            count124++;
        } else if (score <= 149) {
            count149++;
        } else if (score <= 174) {
            count174++;
        } else {
            count200++;
        }
    }

    // Total f is just the number of students
    int totalF = n;

    // Total fx: add up fx for every group
    double totalFx = fx(count24, midpoint(0, 24))
                   + fx(count49, midpoint(25, 49))
                   + fx(count74, midpoint(50, 74))
                   + fx(count99, midpoint(75, 99))
                   + fx(count124, midpoint(100, 124))
                   + fx(count149, midpoint(125, 149))
                   + fx(count174, midpoint(150, 174))
                   + fx(count200, midpoint(175, 200));

    // Mean x_bar = total fx / total f
    double mean = totalFx / totalF;

    // Total f(x - mean)^2: add it up for every group
    double totalFxx = f_x_xbar_sqrd(count24, midpoint(0, 24), mean)
                    + f_x_xbar_sqrd(count49, midpoint(25, 49), mean)
                    + f_x_xbar_sqrd(count74, midpoint(50, 74), mean)
                    + f_x_xbar_sqrd(count99, midpoint(75, 99), mean)
                    + f_x_xbar_sqrd(count124, midpoint(100, 124), mean)
                    + f_x_xbar_sqrd(count149, midpoint(125, 149), mean)
                    + f_x_xbar_sqrd(count174, midpoint(150, 174), mean)
                    + f_x_xbar_sqrd(count200, midpoint(175, 200), mean);

    // Print the table header
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left
              << std::setw(14) << "Group Score"
              << std::setw(16) << "Mid Point (x)"
              << std::setw(16) << "Frequency (f)"
              << std::setw(12) << "fx"
              << std::setw(14) << "(x-xbar)^2"
              << std::setw(14) << "f(x-xbar)^2" << std::endl;
    std::cout << std::setfill('-') << std::setw(86) << "" << std::setfill(' ') << std::endl;

    // One row per group
    printRow(0, 24, count24, mean);
    printRow(25, 49, count49, mean);
    printRow(50, 74, count74, mean);
    printRow(75, 99, count99, mean);
    printRow(100, 124, count124, mean);
    printRow(125, 149, count149, mean);
    printRow(150, 174, count174, mean);
    printRow(175, 200, count200, mean);

    // Totals row
    std::cout << std::setfill('-') << std::setw(86) << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(30) << "Total"
              << std::setw(16) << totalF
              << std::setw(12) << totalFx
              << std::setw(14) << ""
              << std::setw(14) << totalFxx << std::endl;

    // Variance = total f(x - mean)^2  / total f
    double variance = totalFxx / totalF;
    double stdDev = sqrt(variance);

    std::cout << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Variance: " << variance << std::endl;
    std::cout << "Standard deviation: " << stdDev << std::endl;

    return 0;
}
