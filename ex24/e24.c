
#include <stdlib.h>
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
    char *ch;
    myscanf("%c", ch, 4);
    Person you = { .age = 0 };
    int i = 0;
    char *in = NULL;

    printf ("What's your first name? ");
    in = fgets(you.first, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read first name.");

    printf("What's your last name? ");
    in = fgets(you.last, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read last name. ");

    printf("How old are you? ");
    char buf[MAX_DATA];
    in = fgets(buf, MAX_DATA - 1, stdin);
    int rc = atoi(buf);
    check(rc > 0, "You have to enter a number.");
    you.age = rc;

    printf("What color are your eyes:\n");
    for (i = 0; i < COUNT; i++) {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    in = fgets(buf, MAX_DATA - 1, stdin);
    rc = atoi(buf);
    check(rc > 0, "You have to enter a number.");
    eyes = rc;

    you.eyes = eyes - 1;
    check(you.eyes < COUNT && you.eyes >= 0, "Do it right, that's not an option.");

    printf("How much in your wallet? ");
    // rc = fscanf(stdin, "%f", &you.income);
    in = fgets(buf, MAX_DATA - 1, stdin);
    float rcf = atof(buf);
    check(rcf > 0.f, "Enter a floating point number");
    printf("------ RESULTS ------\n");
    you.income = rcf;

    printf("First name: %s\nLast name: %s\nAge: %d\nEyes: %s\nMoney: %f\n", 
            you.first, you.last, you.age, EYE_COLOR_NAMES[you.eyes], you.income);

    return 0;

}

