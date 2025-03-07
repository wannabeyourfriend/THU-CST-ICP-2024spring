//为库设计新函数 DiPack，删除输入字符串中所有的重复元素。要求写成函数，函数内部使用指针操作。
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char* DiPack(char *str){
    char *markPointer = str;
    char *checkPointer = str;
    char *newStr = (char*)malloc(strlen(str)*sizeof(char));
    char* result = newStr;
    *newStr = '\0';
    for(int i = 0; i < strlen(str); i++){
        markPointer = str + i;
        for(int  j = 0; j < strlen(str) ; j++){
        checkPointer = str + j;        
            if ( *markPointer == *checkPointer && i != j){
                break;
            }else {
                if ( j == strlen(str) - 1){
                    *newStr = *markPointer;
                    newStr++;
                    *newStr = '\0';
                }
            }
        }
    }
    return result;
}

int main(){
    char *s1 = (char*)malloc(100*sizeof(char));
    scanf("%s",s1);
    printf("%s\n",DiPack(s1));
    free(s1);
    return 0;
}