#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[]){

    //checks length
    if (argc != 2){
        printf("Usage: ./caesar key");
        return 1;
    }
    else{
        //checks if it has letters
        string con = argv[1];
        for (int i = 0; i<strlen(con); i++){
            if (isalpha(con[i])){
                printf("Usage: ./caesar key");
                return 1;
            }
        }


        //no letters and correct size

        int key = atoi(argv[1]);

        string plain = get_string("plaintext: ");

        char cipher [strlen(plain)];

        //is alphabeticall
        for (int i = 0; i <= strlen(plain); i++){

            if(isalpha(plain[i])){

                if(isupper(plain[i])){
                    cipher[i] = (((plain[i] - 65 + key) % 26) + 65);
                }

                else{
                    if(islower(plain[i])){
                    cipher[i] = (((plain[i] - 97 + key) % 26) + 97);
                    }
                }
            }

            //non alphabetical
            else{
                cipher[i] = plain[i];
            }
        }

        printf("ciphertext: %s", cipher);
        printf("\n");

        }
    return 0;
}