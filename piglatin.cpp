#include <iostream>
#include <string>

std::string VOWELS="aeiou";

std::string pigLatinReturn(std::string str) {
    int str_len = str.length(); // for the length
    int i = 0; // for the index

    std::string strBefore;
    std::string strAfter;


    // Collect letters before the first vowel
    while (i < str_len) {

        // Stop if we find a vowel
        if (VOWELS.find(str[i]) != std::string::npos) {
            break;
        }

        // otherwise just be appending
        strBefore += str[i];
        i++;
    }

    // Get everything from the first vowel onwards
    strAfter = str.substr(i);

    return strAfter + strBefore + "ay";
}

void pigLatinReference(std::string &str) {
     int str_len = str.length(); // for the length
    int i = 0; // for the index

    std::string strBefore;
    std::string strAfter;


    // Collect letters before the first vowel
    while (i < str_len) {

        // Stop if we find a vowel
        if (VOWELS.find(str[i]) != std::string::npos) {
            break;
        }

        // otherwise just be appending
        strBefore += str[i];
        i++;
    }

    // Get everything from the first vowel onwards
    strAfter = str.substr(i);

    // Get everything from the first vowel onwards
    strAfter = str.substr(i);

    str = strAfter + strBefore + "ay";
}


int main() {

    std::string name = "julie";
    std::string str1 = pigLatinReturn(name);
    std::cout << str1 << std::endl;   // prints "uliejay"
    pigLatinReference(name);
    std::cout << name << std::endl;   // prints "uliejay"

    return 0;
}