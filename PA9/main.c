//读取文件./news.txt的内容，统计出现次数前5的字母，并且按出现频率从高到低输出。如果频率一样，按照字母表顺序确定先后（且小写字母优先于大写字母）。
//compare函数这样来写，先比较两个结构体的count，如果count不同，按照count从大到小排序，如果count相同，按照字母表顺序排序，若字母为大小写的关系，小写字母优先于大写字母。

//要求利用读入文件、字符数组存储来实现
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Node {
    char ch;
    int count;
} Node;
//比较函数
int compare(const void *a, const void *b) {
    Node *p = (Node *)a;
    Node *q = (Node *)b;
    if (p->count != q->count) {
        return q->count - p->count;
    } else if ( p -> count  == q -> count ) {
       if (p -> ch - q->ch == 'a'- 'A'){
            return -1;
       } else if (p -> ch - q->ch == 'A'- 'a'){
            return 1;
       } else {
            if ( p -> ch >= 'A' && p -> ch <= 'Z'){
                p -> ch += 'a' - 'A';
            } if ( q -> ch >= 'A' && q -> ch <= 'Z'){
                q -> ch += 'a' - 'A';
            }
            return p -> ch - q -> ch;
       }
    }   
}

int main() {
    FILE *fp = fopen("./news.txt", "r");
    if (fp == NULL) {
        perror("文件打开失败\n");
        return 0;
    }
    //打开文件，读取内容到字符串中
    //char str[1000000];
    char str[100000];
    char ch;
    int len = 0;
    while ((ch = fgetc(fp)) != EOF) {
        str[len++] = ch;
    }//读取文件内容到str中,一个一个读入
    fclose(fp);
    //关闭文件，统计字母出现次数
    str[len] = '\0';//手动加上结尾\0
    Node arr[52];//为每一个字母建立一个结构体，记录字母和出现次数
    //初始化结构体
    for (int i = 0; i < 26; i++) {
        arr[i].ch = 'a' + i;
        arr[i].count = 0;
    }
    for (int i = 26; i < 52; i++) {
        arr[i].ch = 'A' + i - 26;
        arr[i].count = 0;
    }
    //统计字母出现次数
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            arr[str[i] - 'a'].count++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            arr[str[i] - 'A' + 26].count++;
        }
    }
    qsort(arr, 52, sizeof(Node), compare);
    for (int i = 0; i < 5; i++) {
        printf("%c\n", arr[i].ch);
    }
    return 0;
}


