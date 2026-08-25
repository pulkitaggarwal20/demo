#include <stdio.h> //Gaming Arcade Game
#include <stdlib.h> //Learning Git and Github
#include <time.h>

// Function declarations
void numberGuessing(int *score);
void rockPaperScissors(int *score);
void detectiveMystery(int *score);

int main() {

    int choice;
    int score = 0;

    // Used for generating different random numbers each run
    srand(time(0));

    while (1) {

        printf("\n====================================\n");
        printf("          🎮 C-QUEST ARCADE\n");
        printf("====================================\n");
        printf("Current Score: %d\n", score);
        printf("------------------------------------\n");
        printf("1. Number Guessing\n");
        printf("2. Rock Paper Scissors\n");
        printf("3. Detective Mystery\n");
        printf("4. View Score\n");
        printf("5. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                numberGuessing(&score);
                break;

            case 2:
                rockPaperScissors(&score);
                break;

            case 3:
                detectiveMystery(&score);
                break;

            case 4:
                printf("\nYour current score is: %d\n", score);
                break;

            case 5:
                printf("\nThanks for playing C-QUEST! 🎮\n");
                printf("Final Score: %d\n", score);
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}


// ==========================================
//        NUMBER GUESSING GAME
// ==========================================

void numberGuessing(int *score) {

    int secretNumber;
    int guess;
    int attempts = 0;

    secretNumber = rand() % 50 + 1;

    printf("\n====================================\n");
    printf("        NUMBER GUESSING GAME\n");
    printf("====================================\n");
    printf("I have selected a number between 1 and 50.\n");
    printf("Try to guess it!\n\n");

    do {

        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        }
        else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        }
        else {
            printf("\n🎉 Correct!\n");
            printf("You guessed it in %d attempts.\n", attempts);

            if (attempts <= 5) {
                printf("Excellent! +10 points\n");
                *score += 10;
            }
            else if (attempts <= 10) {
                printf("Good job! +5 points\n");
                *score += 5;
            }
            else {
                printf("You got it! +2 points\n");
                *score += 2;
            }
        }

    } while (guess != secretNumber);
}


// ==========================================
//       ROCK PAPER SCISSORS
// ==========================================

void rockPaperScissors(int *score) {

    int player;
    int computer;

    printf("\n====================================\n");
    printf("       ROCK PAPER SCISSORS\n");
    printf("====================================\n");

    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");

    printf("\nEnter your choice: ");
    scanf("%d", &player);

    if (player < 1 || player > 3) {
        printf("Invalid choice!\n");
        return;
    }

    computer = rand() % 3 + 1;

    printf("\nComputer chose: ");

    if (computer == 1)
        printf("Rock\n");
    else if (computer == 2)
        printf("Paper\n");
    else
        printf("Scissors\n");


    if (player == computer) {

        printf("It's a draw!\n");

    }
    else if (
        (player == 1 && computer == 3) ||
        (player == 2 && computer == 1) ||
        (player == 3 && computer == 2)
    ) {

        printf("🎉 You win!\n");
        *score += 5;

    }
    else {

        printf("Computer wins!\n");

    }
}


// ==========================================
//          DETECTIVE MYSTERY
// ==========================================

void detectiveMystery(int *score) {

    int choice;
    int clues = 0;

    printf("\n====================================\n");
    printf("          🕵️ DETECTIVE MYSTERY\n");
    printf("====================================\n");

    printf("\nCASE #001: THE MISSING LAPTOP\n");
    printf("------------------------------------\n");

    printf("\nA laptop has disappeared from the college computer lab.\n");
    printf("Three people were present in the building:\n");

    printf("\n1. The Lab Assistant\n");
    printf("2. The Security Guard\n");
    printf("3. The Student Researcher\n");

    printf("\nYou need to investigate the case.\n");

    // First investigation
    printf("\nWhere do you want to investigate first?\n");
    printf("1. Computer Lab\n");
    printf("2. Security Room\n");
    printf("3. Research Room\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {

        printf("\nYou examine the computer lab.\n");
        printf("You find a broken USB drive near the desk.\n");
        printf("🔎 CLUE FOUND!\n");
        clues++;

    }
    else if (choice == 2) {

        printf("\nYou check the security room.\n");
        printf("The camera shows someone entering the lab at 7:42 PM.\n");
        printf("🔎 CLUE FOUND!\n");
        clues++;

    }
    else if (choice == 3) {

        printf("\nYou search the research room.\n");
        printf("You find nothing suspicious.\n");

    }
    else {

        printf("\nInvalid choice.\n");
        return;
    }


    // Second investigation
    printf("\nYou have another opportunity to investigate.\n");

    printf("\n1. Question the Lab Assistant\n");
    printf("2. Question the Security Guard\n");
    printf("3. Question the Student Researcher\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {

        printf("\nLab Assistant: \"I left the lab at 7:30 PM.\"\n");

        if (clues > 0) {
            printf("The security footage shows someone entering at 7:42 PM.\n");
            printf("The assistant's statement seems suspicious.\n");
            clues++;
        }

    }
    else if (choice == 2) {

        printf("\nSecurity Guard: \"I was monitoring the cameras all evening.\"\n");
        printf("His statement seems consistent with the footage.\n");

    }
    else if (choice == 3) {

        printf("\nStudent Researcher: \"I was working in the research room.\"\n");
        printf("You notice the student has a USB drive.\n");
        printf("🔎 CLUE FOUND!\n");
        clues++;

    }
    else {

        printf("\nInvalid choice.\n");
        return;
    }


    // Final accusation
    printf("\n====================================\n");
    printf("             FINAL ACCUSATION\n");
    printf("====================================\n");

    printf("\nWho do you think stole the laptop?\n");

    printf("1. Lab Assistant\n");
    printf("2. Security Guard\n");
    printf("3. Student Researcher\n");

    printf("\nEnter your accusation: ");
    scanf("%d", &choice);


    /*
       The actual culprit is the Lab Assistant.
       The clues should help the player reach this conclusion.
    */

    if (choice == 1) {

        printf("\n🎉 CASE SOLVED!\n");
        printf("Excellent detective work!\n");
        printf("The Lab Assistant was responsible for the theft.\n");

        if (clues >= 2) {
            printf("You found enough clues to prove your theory.\n");
            printf("+15 points!\n");
            *score += 15;
        }
        else {
            printf("You got the culprit right, but you needed more evidence.\n");
            printf("+10 points!\n");
            *score += 10;
        }

    }
    else {

        printf("\n❌ WRONG ACCUSATION!\n");
        printf("The real culprit was the Lab Assistant.\n");
        printf("Better luck next time, detective.\n");

    }
}