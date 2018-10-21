#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char compared_char[26];

void squeeze(char*, char*, char**);
int removeDuplicate(char);

int removeDuplicate(char str){

    int k = 0;
    for (k = 0; compared_char[k] != '\0'; k++){
        if (compared_char[k] == str)
        return 1;
    }
    compared_char[k] = str;
    return 0;
}

void squeeze(char* Str, char* subStr, char** result){

    static int l, match_found;
    int j = 0;

    for(int i = 0; subStr[i] != '\0'; i++){
        removeDuplicate(subStr[i]);
    }
    for(j = 0; Str[j] != '\0'; j++){
        match_found = 0;
        for(int i = 0; compared_char[i] != '\0'; i++){
            if (Str[j] == subStr[i]){
                match_found = 1;
                break;
            }
        }
        if (!(match_found)){
            (*result)[l++] =  Str[j];
        }
    }
}

int main()
{
    char* charString;
    char* subString;
    char* squeezedString;

    charString = malloc(sizeof(char)*50);
    subString = malloc(sizeof(char)*50);
    squeezedString = malloc(sizeof(char)*50);
    strcpy(charString, "I am here too!!!");
    strcpy(subString, "I am here.");
    squeeze(charString, subString, &squeezedString);
}
