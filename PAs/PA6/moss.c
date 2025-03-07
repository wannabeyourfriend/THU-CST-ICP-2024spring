# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAX_LEN 1000
# define MAX_MORSE_CODE_LEN 5

struct MorseCode{
    char MorseCode[ MAX_LEN ][ MAX_MORSE_CODE_LEN ];
    char English[ MAX_LEN ];
};

char* convertColumnToString(struct MorseCode *morseCode, int i) {
    char *result = (char*)malloc(100 * sizeof(char));  
    for (int j = 0; j < MAX_MORSE_CODE_LEN; j++) {
        result[j] = morseCode->MorseCode[i][j];
    }
    result[MAX_MORSE_CODE_LEN-1] = '\0'; 
    return result;
}
// char* convertColumnToString(struct MorseCode *morseCode, int i) {
//     char *result = (char*)malloc( MAX_MORSE_CODE_LEN* sizeof(char));  
//     static int j = 0;
//     for (int j = 0; j < MAX_MORSE_CODE_LEN; j++) {
//         result[j] = morseCode->MorseCode[i][j];
//     }
//     result[++j] = '\0'; 
//     return result;
// }
void scanMorseCode(struct MorseCode *morseCode) {
    char ch;
    int i = 0, j = 0;
  
    while (1) {
        ch = getchar();
        if (ch != '*' && ch != '-' && ch != '|') {
            break;
        }
        if (ch != '|') {
            morseCode->MorseCode[i][j] = ch;
            j++;
        } else {
            morseCode->MorseCode[i][j] = '\0';  
            i++;
            j = 0;  
        }
    }
    morseCode->MorseCode[i][j] = '\0';  
}

char *morseCodeMap[26] = {
    "*-", "-***", "-*-*", "-**", "*", "**-*", "--*", "****", "**", 
    "*---", "-*-", "*-**", "--", "-*", "---", "*--*", "--*-", "*-*", 
    "***", "-", "**-", "***-", "*--", "-**-", "-*--", "--**"
};

void translateMorseToEnglish(struct MorseCode *morseCode) {
    for (int i = 0; i < MAX_LEN; i++) {
        for (int j = 0; j < 26; j++) {
            if (strcmp(morseCodeMap[j], convertColumnToString(morseCode, i)) == 0 ){
                free ( convertColumnToString(morseCode, i) );
                morseCode->English[i] = 'a' + j;
                break;
            }
        }
    }
    morseCode->English[MAX_LEN] = '\0';  
}

int main(){
    struct MorseCode morseCode_2;
    memset(morseCode_2.MorseCode, 0, sizeof(morseCode_2.MorseCode));
    memset(morseCode_2.English, 0, sizeof(morseCode_2.English));
    scanMorseCode(&morseCode_2);
    translateMorseToEnglish(&morseCode_2);
    // free (result);
    printf("%s\n", morseCode_2.English);
    return 0;
}