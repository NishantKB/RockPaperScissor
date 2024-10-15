#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char getComputerChoice() {
    srand(time(NULL));

    int randomValue = (rand() % 3) + 1;
    char compChoice;

    switch (randomValue) {
        case 1:
            compChoice = 'r';
            break;
        case 2:
            compChoice = 'p';
            break;
        case 3:
            compChoice = 's';
            break;
    }

    return compChoice;
}

char getUserChoice() {
    char userChoice;

    printf("Enter your choice (r for rock, p for paper, s for scissors): ");
    scanf(" %c", &userChoice);

    return tolower(userChoice);
}

char determineResult(char userChoice, char compChoice) {
    if (compChoice == userChoice) {
        return 'd';
    } else if ((userChoice == 'p' && compChoice == 'r') ||
               (userChoice == 'r' && compChoice == 's') ||
               (userChoice == 's' && compChoice == 'p')) {
        return 'w';
    } else {
        return 'l';
    }
}

int main() {
    char compChoice = getComputerChoice();
    char userChoice;

    while (1) {
        userChoice = getUserChoice();
        if (userChoice == 'r' || userChoice == 'p' || userChoice == 's') {
            break;
        }
    }

    char result = determineResult(userChoice, compChoice);

    switch (result) {
        case 'w':
            printf("Computer's choice: %c\n", compChoice);
            printf("Your choice: %c\n", userChoice);
            printf("You won\n");
            break;
        case 'l':
            printf("Computer's choice: %c\n", compChoice);
            printf("Your choice: %c\n", userChoice);
            printf("You lost\n");
            break;
        case 'd':
            printf("Computer's choice: %c\n", compChoice);
            printf("Your choice: %c\n", userChoice);
            printf("It's a draw\n");
            break;
    }

    return 0;
}
