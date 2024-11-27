#include <iostream>
 #include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Using srand() to make the game more predictable
    // without this, on every execution the pattern of 
    //generated number will be same 
      srand(time(0));

    // Generate a random number between 1 and 100
    // rand() generates random numbers but it 
    //starts from 0 so we add 1.
      int random_Number = rand() % 100 + 1;
     int guess_by_user;

       cout << "Guess the number (between 1 and 100): ";

    // Loop until the user guesses the correct number
    while (true) {
         cin >> guess_by_user;

          if (guess_by_user < random_Number) {
            cout << "Too low. Try again: ";
            } else if (guess_by_user > random_Number) {
            cout << "Too high. Try again: ";
           } else {
            cout << "Congratulations! You guessed the number!" << endl;
            break;
            }
    }

    return 0;
}
