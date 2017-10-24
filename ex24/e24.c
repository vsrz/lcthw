
#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 1000

typedef enum EyeColor {
    BLUE, GREEN, BROWN, BLACK, OTHER, COUNT
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first[MAX_DATA];
    char last[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char **argv)
{
    Person you = { .age = 0 };
    int i = 0;
    char *in = NULL;

    printf ("What's your first name? ");
    // in = fgets(you.first, MAX_DATA - 1, stdin);
    in = gets(you.first);
    check(in != NULL, "Failed to read first name.");

    printf("What's your last name? ");
    in = fgets(you.last, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read last name. ");

    printf("How old are you? ");
    int rc = fscanf(stdin, "%d", &you.age);
    check(rc > 0, "You have to enter a number.");

    printf("What color are your eyes:\n");
    for (i = 0; i < COUNT; i++) {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes);
    check(rc > 0, "You have to enter a number.");

    you.eyes = eyes - 1;
    check(you.eyes < COUNT && you.eyes >= 0, "Do it right, that's not an option.");

    printf("How much in your wallet? ");
    rc = fscanf(stdin, "%f", &you.income);
    check(rc > 0, "Enter a floating point number");
    printf("------ RESULTS ------\n");

    printf("First name: %s\nLast name: %s\nAge: %d\nEyes: %s\nMoney: %f\n", 
            you.first, you.last, you.age, EYE_COLOR_NAMES[you.eyes], you.income);

    return 0;

}

