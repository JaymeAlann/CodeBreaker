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

    /* Generate Secret Pin*/
std::string generate_Random_pin()
{
    std::string pin = "0123456789";
    srand(time(0));
    std::random_shuffle(pin.begin(), pin.end());
    pin.resize(4);
    return pin;
}

/* Compare pins for correctness*/
void compare_pin(const std::string& secret_pin, const std::string& guess)
{
    int correct_digits_right_place = 0;
    int correct_digits_wrong_place = 0;


    for (int i = 0; i < secret_pin.size(); i++) {
        if (secret_pin[i] == guess[i]) {
            correct_digits_right_place++;
            //std::cout << "You have (" << secret_pin[i] << ") in the correct Location." << std::endl;
        }
        else if (secret_pin.find(guess[i]) != std::string::npos) {
            correct_digits_wrong_place++;
            //std::cout << "You have (" << guess[i] << ") in the wrong Location." << std::endl;
        }
    }
    if (correct_digits_right_place == 0 && correct_digits_wrong_place == 0) {
        std::cout << "You have no digits in the correct Location." << std::endl;
    }
    else {
        std::cout << "You have " << correct_digits_right_place 
            << " in the correct place, and " << correct_digits_wrong_place << " in the wrong place!" << std::endl;
    }
}

/* Check if the input has all unique digits */
bool guess_unique_digits(const std::string& guess) {
    for (int i = 0; i <= guess.size() - 1; i++) {
        for (int j = i + 1; j <= guess.size(); j++) {
            if (guess[i] == guess[j]) {
                return false;
            }
        }
    }
}

/* Validate User Input*/
bool validate_input(const std::string& guess) {
    return std::all_of(guess.begin(), guess.end(), ::isdigit) && guess.size() == 4 && guess_unique_digits(guess);
}

/* Get User Guesses*/
void run(const std::string secret_pin)
{
    bool won = false;
    int guesses = 0;
    int trys = 10;
    while (guesses < 10)
    {
        std::cout << "\nYou have " << trys - guesses << " tries Remaining. Please Enter your pin: ";
        // Get User Input
        std::string guess;
        std::cin >> guess;

        // Validate User Input
        while (!validate_input(guess))
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid Input! Please Enter a 4 DIGIT Pin with UNIQUE digits: " << std::endl;
            std::cin >> guess;
        }

        // Compare User Input to Secret Pin
        if (guess == secret_pin)
        {
            std::cout << "\n\n~~ CONGRATULATIONS! YOU CRACKED THE CODE! ~~" << std::endl;
            won = true;
            break;
        }
        else {
            compare_pin(secret_pin, guess);
        }
        guesses++;
    }
    if (guesses == trys && !won) {
        std::cout << "\n Sorry! You lost! The correct pin was " << secret_pin << std::endl;
    }
}

/* Main */
int main()
{
    char keep_playing = 'Y';
    while (keep_playing == 'Y' || keep_playing == 'y') {
        system("cls");
        std::string secret_pin = generate_Random_pin();
        std::cout << "~CODE BREAKER~" << std::endl;
        std::cout << "~DO YOUR BEST TO GUESS THE PIN~" << std::endl;
        std::cout << "~YOU CAN GUESS ANY COMBINATION OF NUMBERS 0-9 ~" << std::endl;
        run(secret_pin);

        std::cout << "Would You like to play again!? (Y/N)" << std::endl;
        std::cin >> keep_playing;
    }
    return 0;
}