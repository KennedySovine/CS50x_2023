#include <cs50.h>
#include <stdio.h>

int main(void){

    int answer;
    answer = get_int("Height: ");
    while (answer > 8 || answer < 1){
        answer = get_int("Height: ");
    }

    int tags = 1;
    while (tags <= answer){
        for (int j = answer - tags; j > 0; j--){
            printf(" ");
        }
        for(int u = 0; u < tags; u++){
            printf("#");
        }
        tags++;
        printf("\n");
    }
}