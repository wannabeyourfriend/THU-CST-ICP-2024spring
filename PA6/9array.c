//题目描述：
//九宫格。输入 1-9 这 9 个数字的一种任意排序，构成3*3二维数组。如果每行、每列以及对角线之和都相等，则打印1。否则打印0。
# include <stdio.h>
# include <stdlib.h>

void scanftwoDimenssionArray (int array[3][3]){
    for (int i = 0; i < 3; i++){
        for(int j = 0; j <3; j++){
            scanf("%d", &array[i][j]);
        }
    }
}

int addofElementsinARow (int array[3][3], int i){
    int sum = 0;
    for (int j = 0; j < 3; j++){
        sum += array[i][j];
    }
    return sum;
}

int addofElementsinAColumn (int array[3][3], int j){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += array[i][j];
    }
    return sum;
}

int addofElementsinADiagonal (int array[3][3]){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += array[i][i];
    }
    return sum;
}

int addofElementsinAnotherDiagonal (int array[3][3]){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += array[i][2-i];
    }
    return sum;
}

int main(){
    int array_1[3][3] = {0};
    scanftwoDimenssionArray(array_1);
    int sum = addofElementsinARow(array_1, 0);
    if ( sum == addofElementsinARow(array_1, 1) && sum == addofElementsinARow(array_1, 2) && sum == addofElementsinAColumn(array_1, 0) && sum == addofElementsinAColumn(array_1, 1) && sum == addofElementsinAColumn(array_1, 2) && sum == addofElementsinADiagonal(array_1) && sum == addofElementsinAnotherDiagonal(array_1)){
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}