#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <string>

std::string generatePassword() {
    // Seed for random number generation
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Define character sets
    const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string specialChars = "!@#$%^&*()-_=+[]{}|;:'<>,.?/";

    // Select a random length between 7 and 13 characters
    int length = std::rand() % 7 + 7;

    // Initialize password with a random lowercase character
    std::string password(1, lowercaseChars[std::rand() % lowercaseChars.length()]);

    // Add at least one uppercase character, one special character, and one number
    password += uppercaseChars[std::rand() % uppercaseChars.length()];
    password += specialChars[std::rand() % specialChars.length()];
    password += std::to_string(std::rand() % 10);

    // Add random characters to meet the specified length
    for (int i = 4; i < length; ++i) {
        // Combine all character sets
        const std::string allChars = lowercaseChars + uppercaseChars + specialChars + "0123456789";
        password += allChars[std::rand() % allChars.length()];
    }

    // Shuffle the password characters
    std::random_shuffle(password.begin(), password.end());

    return password;
}

int main() {
    // Generate and print a random password
    std::string password = generatePassword();
    std::cout << "Random Password: " << password << std::endl;

    return 0;
}
