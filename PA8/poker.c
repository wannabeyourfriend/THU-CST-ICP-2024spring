# include <stdio.h>
# include <string.h>
# include <stdlib.h>
typedef struct {
    char num;
    char color;
}Pocker;

void bubblesort1(Pocker pockers_[],Pocker pockers[], int length){
    for (int i = 0; i < length ; i++){
        for (int j = 0; j < length - i- 1; j++){
            if (pockers_[j].num > pockers_[j + 1].num){
                Pocker temp = pockers[j];
                pockers[j] = pockers[j + 1];
                pockers[j + 1] = temp;
                temp = pockers_[j];
                pockers_[j] = pockers_[j + 1];
                pockers_[j + 1] = temp;
            }
        }
    }
}

void bubblesort2(Pocker pockers_[],Pocker pockers[], int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            if (pockers_[j].num == pockers_[j + 1].num){
                if (pockers[j].color > pockers[j + 1].color){
                    Pocker temp = pockers[j];
                    pockers[j] = pockers[j + 1];
                    pockers[j + 1] = temp; 
                    temp = pockers_[j];
                    pockers_[j] = pockers_[j + 1];
                    pockers_[j + 1] = temp;
                }
            }
        }
    }
}

int main(){
    char* allthe5pockers;
    char* allthe5pockers_;
    char* inputarray;

    inputarray  = (char*)malloc(sizeof(char) * 16);
    allthe5pockers_ = (char*)malloc(sizeof(char) * 20);
    allthe5pockers = (char*)malloc(sizeof(char) * 20);

    Pocker pockers[5] = {0};  
    Pocker pockers_[5] = {0};    

    scanf("%s", inputarray);
    int index = 0;
    for (int i = 0; i < 16; i++){
        if (inputarray[i] != '1' ){
            allthe5pockers[index++] = inputarray[i];
        }else if ( inputarray[i] == '1'){
            allthe5pockers[index++] = '9'+1;
            i++;
        }
    }

    for (int i = 0; i < 16; i++){
        allthe5pockers_[i] = allthe5pockers[i];
    }

    for (int i = 0; i < 16; i++ ){
        if (allthe5pockers[i] == 'J'){
            allthe5pockers_[i] = 59;
        }
        if (allthe5pockers[i] == 'Q'){
            allthe5pockers_[i] = '9'+3;
        }
        if (allthe5pockers[i] == 'K'){
            allthe5pockers_[i] = '9'+4;
        }
        if (allthe5pockers[i] == 'A'){
            allthe5pockers_[i] = '9'+5;
        }

        if (allthe5pockers[i] == 'd'){
            allthe5pockers_[i] = 1;
        }
        if (allthe5pockers[i] == 'c'){
            allthe5pockers_[i] = 2;
        }
        if (allthe5pockers[i] == 'h'){
            allthe5pockers_[i] = 3;
        }
        if (allthe5pockers[i] == 's'){
            allthe5pockers_[i] = 4;
        }
    }
    for (int i = 0 ; i < 5; i++){
        pockers[i].num = allthe5pockers[i * 2];
        pockers[i].color = allthe5pockers[i * 2 + 1];
    }
    for (int i = 0 ; i < 5; i++){
        pockers_[i].num = allthe5pockers_[i * 2];
        pockers_[i].color = allthe5pockers_[i * 2 + 1];
    }
    bubblesort1(pockers_,pockers, 5);
    bubblesort2(pockers_,pockers, 5);
    for (int i = 0; i < 5; i++){
        if ( pockers[i].num != '9'+1){
            printf("%c", pockers[i].num);
        }
        if ( pockers[i].num == '9'+1){
            printf("10");
        }
        printf("%c ", pockers[i].color);
    }
    return 0;
}