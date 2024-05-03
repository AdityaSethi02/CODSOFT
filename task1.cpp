#include <iostream>
#include <ctime>
using namespace std;

void guessNum()
{
    srand(time(0));
    int num = rand() % 10 + 1;

    int attempt = 0;
    int guess;

    while(true)
    {
        cout << "Guess a number between 1 and 10: ";
        cin >> guess;
        attempt++;

        if (guess == num)
        {
            cout << "Congratulations! You guessed the number " << num << " correctly in " << attempt << " attempts.";
            break;
        }

        else if (guess < num)
        {
            cout << "Too low! Try again.";
        }

        else
        {
            cout << "Too high! Try again.";
        }
    }
}

int main()
{
    guessNum();
    return 0;
}