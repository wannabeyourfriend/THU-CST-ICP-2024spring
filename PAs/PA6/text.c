//先编写函数EncryptChat，按照下述规则将给定的字符c转化（加密）为新的字符：“A”转化为“B”，“B”转化为“C”，... “Z”转化为“a”，“a”转化为“b”，...，“z”转化为“A”。其它字符不加密。编写程序，加密给定字符串。
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int Encryptchat(char c){
    if (c >= 'A' && c < 'Z'){
        c = c + 1;
    } else if (c == 'Z'){
        c = 'a';
    } else if (c >= 'a' && c < 'z'){
        c = c + 1;
    } else if (c == 'z'){
        c = 'A';
    } else {
        c = c;
    }
    return c;
}

int main(){
    char str[51] = {0};
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++){
        printf("%c", Encryptchat(str[i]));
    }
    return 0;
}