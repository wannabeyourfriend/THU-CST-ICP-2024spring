//自己实现一个比较字符串大小的函数，也即实现 strcmp 函数。函数 int myStrcmp(char *s1, char *s2) 按照ASCII顺序比较字符串 s1, s2，若s1与s2相等返回0， s1 > s2 返回 1，s1 < s2 返回 -1
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int myStrcmp (char *s1, char *s2){
    int i = 0;
    int result = 0;
    int state = 0;
    while ( s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] > s2[i]){
            result = 1;
            state = 1;
            break;
        }else if (s1[i] < s2[i] ){
            result = -1;
            state = 1;
            break;
        }
        i++;
    }
    if (!state){ 
        if (s1[i] == '\0' && s2[i] == '\0') {
            result = 0;
        }else if ( s1[i] == '\0') {
            result = -1;
        }else {
            result = 1;
        }
    }
    return result;
}

int main(){
    char * s1 = (char *)malloc(100 * sizeof(char));
    char * s2 = (char *)malloc(100 * sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);
    printf("%d\n", myStrcmp(s1, s2));
    free (s1);
    free (s2);
    return 0;
}