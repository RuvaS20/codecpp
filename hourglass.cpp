#include <iostream>

int main() {
    // top half
    for (int i = 0; i < 6; i++) {

        // spaces increase by one each row
        for (int space = 0; space < i; space++) {
            std::cout << " ";
        }

        // stars decrease by one each row
        for (int j = 0; j < 6 - i; j++) {
            std::cout << "* "; // with space next to the star
        }

        std::cout << std::endl;
    }

    // bottom half is same rows as the top, but counting i backwards
    for (int i = 5; i >= 0; i--) {

        for (int s = 0; s < i; s++) {
            std::cout << " ";
        }

        for (int j = 0; j < 6 - i; j++) {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }

    return 0;
}
