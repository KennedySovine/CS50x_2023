#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

string text;

double s;
double w;
double l;

void count_letters(string input);
void count_words(string input);
void count_sentences(string input);
int index();



int main(void){

    text = get_string("Text: ");

    //printf("%i letter(s)\n", count_letters(text));
    //printf("%i word(s)\n", count_words(text));
    //printf("%i sentence(s)\n", count_sentences(text));
    count_letters(text);
    count_words(text);
    count_sentences(text);

    if(index()<16 && index()>=1){
        printf("Grade %i\n", index());
    }
    else if(index()>=16){
        printf("Grade 16+\n");
    }
    else{
        printf("Before Grade 1\n");
    }
}

void count_letters (string input){
    int count=0;
    for (int i = 0; i<strlen(input); i++){
        if (isalnum(input[i])){
            count++;
        }
    }
    l = count;
}

void count_words(string input){
    int count = 1;
    for (int i = 0; i <strlen(input); i++){
        if(isspace(input[i])){
            count++;
        }
    }
    w = count;

}

void count_sentences(string input){
    int count=0;
    for (int i = 0; i< strlen(input); i++){
        if (input[i] == '?' || input[i] == '.' || input[i] == '!'){
            count++;
        }
    }
    s = count;
}

int index (){
    float i = (0.0588*(l/(w/100)));
    i = i - (0.296*(s/(w/100)));
    i = round(i - 15.8);
    return (i);
}
