#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void mult();
void add();
void type();
int cType;
string card;
int cMult;
int cAdd;
int

int main (void){
    card = get_string("Number: ");
    printf("\n");
    mult();
    add();
    int total = cMult + cAdd;
    type();

}

void mult(){
    cMult = 1;
    int i = sizeof(card);
    while(i >= 0) {
        char s = card[i];
        int temp = atoi(s);
        cMult = cMult + (temp * 2);
        i -= 2;
    }
}

void add(){
    cAdd = 0;
    int i = sizeof(card) - 1;
    while (i >= 0){
        char s = card[i];
        int temp = atoi(s);
        cAdd += card[i];
        i -= 2;
    }
}

void type(){
    string s = card;
    int start = atoi(s);
    while (sizeof(start) != 2){
        start /= 10;
    }
    if ((start == 34 || start == 37) && sizeof(card) == 15){
        printf("AMEX\n");
    }
    else if (start == 4 && (sizeof(card) == 13 || sizeof(card) == 16)){
        printf("VISA\n");
    }
    else if ((start == 51 || start == 52 || start == 53 || start == 54 || start == 55) && sizeof(card) == 16){
        printf("MASTERCARD\n");
    }
    else{
        printf("INVALID\n");
    }
}