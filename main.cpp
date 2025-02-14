#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);
#define endl '\n'
using namespace std;

int game(int &counter_guesses) {
    int distance = 0, how_close = 0, limit = 1, guess = -1;

    cout << "Welcome to the number guessing game!\nChoose a limit: ";
    cin >> limit;
    if (limit < 1) {
        cout << "Invalid input! Please enter a limit greater than 1" << endl;
        return -1;
    }
    int random_number = rand();
    random_number = (random_number)? (random_number % limit) : 0;
    // cout << random_number << endl;
    cout << "Enter a number [0 - " << limit << "): " << endl;

    do {
        cin >> guess;
        counter_guesses++;
        if (guess == random_number) {
            break;
        }
        distance = abs(guess - random_number);
        how_close = (limit / 10)?  (limit / 10):2;

        if (guess > random_number) {
            if (distance > limit / 2) {
                cout << "Way too high!" << endl;
            }
            else 
                cout << "Too high..." << endl;
        }
        else if (guess < random_number) {
            if (distance > limit / 2) {
                cout << "Way too low!" << endl;
            }
            else 
                cout << "Too low..." << endl;
        }

        if (distance <= how_close) {
            cout << "But you're getting close! :3" << endl;
        }
    } while (guess != random_number);
    return 0;
}

bool keep_playing(const char user_input) {
    switch (user_input) {
        case 'y': {
            return true;
            break;
        }
        case 'n': {
            return false;
            break;
        }
        default: cout << "Invalid answer :p!";
        }
    return false;
}

int main(void) {
    FAST_IO;
    srand(time(0));
    
    cout.clear();
    
    int counter_guesses = 0, fastest_guess = 10000;
    char user_input;
    bool is_playing = true;
    
    do {
        cin.clear();
        game(counter_guesses);
        cin.clear();
        cout << "You guessed the number in " << counter_guesses << " tries! :3\n"<< "Play Again? [y/n]" << endl;
        cin >> user_input;
        if (counter_guesses < fastest_guess) {
            fastest_guess = counter_guesses;
        }
        is_playing = keep_playing(user_input);
        if (is_playing == true) {
            cout << "Your current best is: " << fastest_guess << " guesses.\nGood luck!" << endl; 
            main();
        }
        else if (is_playing == false) {
            cout << "Your fastest guess was in " << fastest_guess << " guesses" <<"\nBye bye :3\n" << endl; 
            exit(0);
        }
    } while (is_playing);
    cout << "Bye bye :3" << endl; 
    
    return 0;
}
