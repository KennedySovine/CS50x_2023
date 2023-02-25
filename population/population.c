#include <cs50.h>
#include <stdio.h>

int start;
int end;

int main(void)
{
    // TODO: Prompt for start size
    start = get_int("What is the starting size?\n");
    while (start<9){
        start = get_int("Enter a number greater than 9\n");
    }

    // TODO: Prompt for end size
    end = get_int("What is the ending size?\n");
    while (end<start){
        end = get_int("Enter a number greater than the starting amount\n");
    }

    // TODO: Calculate number of years until we reach threshold
    int current = start;
    int passed;
    int born;
    int years=0;
    do{
        passed = current/4;
        born = current/3;
        current += born;
        current -= passed;
        years++;
    }
    while (current<end);

    // TODO: Print number of years
    if (start!=end){
        printf ("Start size: %i\n", start);
        printf ("End size: %i\n", end);
        printf ("Years: %i\n", years);
    }
    else{
        printf ("Years: 0");
    }
}