// 
// A code breaking game as a console application. At the beginning of the game, it randomly generates a secret 4 digit code.
// Each digit is unique. For example, 0123, 9548, and 3217 are valid codes, but 1102, 4445, and 7313 are not.
//
// Once the number has been generated, the player has 10 chances to guess the code. After each guess, the game should report how many digits
// guessed correctly, and how many had the right number, but in the wrong place. For example, with a secret code of 0123, a guess of 0451
// has one digit correct (the 0), and one digit with the right number in the wrong place (the 1).
// 
// After the player has either correctly broken the code or run out of guesses, the player has the option to play again.
//
// If the player enters a code that isn't valid, the game will prompt them to try again but do NOT count invalid guess as one of the attempts.
//
// Good luck!

#include <iostream>
#include <string>
#include <random>
#include <limits>
#include <algorithm>

    /* Generate Secret Pin*/
std::string generate_Random_pin()
{
    std::string pin = "0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(pin.begin(), pin.end(), gen);
    pin.resize(4);
    return pin;
}

/* Compare pins for correctness*/
void compare_pin(const std::string& secret_pin, const std::string& guess)
{
    int correctDigitsRightPlace = 0;
    int correctDigitsWrongPlace = 0;

    for (int i = 0; i < secretPin.size(); ++i) {
        if (secretPin[i] == guess[i]) {
            ++correctDigitsRightPlace;
        } else if (secretPin.find(guess[i]) != std::string::npos) {
            ++correctDigitsWrongPlace;
        }
    }
    std::cout << correctDigitsRightPlace << " digits in the correct place, and " << correctDigitsWrongPlace << " digits in the wrong place." << std::endl;
}

/* Check if the input has all unique digits */
bool hasUniqueDigits(const std::string& guess) {
    return std::all_of(guess.begin(), guess.end(), ::isdigit) && guess.size() == 4 && std::adjacent_find(guess.begin(), guess.end()) == guess.end();
}

/* Validate User Input*/
bool validate_input(const std::string& guess) {
    return std::all_of(guess.begin(), guess.end(), ::isdigit) && guess.size() == 4 && guess_unique_digits(guess);
}

/* Get User Guesses*/
void run(const std::string secret_pin)
{
   int guesses = 0;
    const int maxAttempts = 10;

    while (guesses < maxAttempts) {
        std::cout << "\nYou have " << maxAttempts - guesses << " tries remaining. Please enter your guess: ";
        std::string guess;
        std::cin >> guess;

        if (hasUniqueDigits(guess)) {
            if (guess == secretPin) {
                std::cout << "\n\n~~ CONGRATULATIONS! YOU CRACKED THE CODE! ~~" << std::endl;
                return;
            } else {
                std::cout << "Result: ";
                comparePin(secretPin, guess);
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a 4-digit PIN with unique digits." << std::endl;
        }
        guesses++;
    }
    std::cout << "\nSorry! You lost! The correct PIN was " << secretPin << std::endl;
}

/* Main */
int main()
{
    char keep_playing = 'Y';
    while (keep_playing == 'Y' || keep_playing == 'y') {
        system("cls");
        std::string secretPin = generate_Random_pin();
        std::cout << "~CODE BREAKER~" << std::endl;
        std::cout << "~DO YOUR BEST TO GUESS THE PIN~" << std::endl;
        std::cout << "~YOU CAN GUESS ANY COMBINATION OF NUMBERS 0-9 ~" << std::endl;
        run(secret_pin);

        std::cout << "Would you like to play again? (Y/N): ";
        std::cin >> keepPlaying;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    }
    return 0;
}
