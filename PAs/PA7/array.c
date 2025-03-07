# include <stdio.h>
# include <stdlib.h>
# include <string.h>


void scanfa2dimensionArray(int ***a2dimensionArray,int n){
    *a2dimensionArray = (int**)malloc(n*sizeof(int*)); // Remove duplicate declaration
    for(int i = 0; i < n; i++){
        (*a2dimensionArray)[i] = (int*)malloc(n*sizeof(int));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&(*a2dimensionArray)[i][j]); // Fix syntax error
        }
    }
}
//这里要特别注意，函数只能传递变量的值，不能够直接改变变量的值，所以要用指针传递变量的地址，然后通过地址改变变量的值，这里虽然**a2dimensionArray是一个指针，但是它指向的是一个指针的指针，所以要用***a2dimensionArray来传递它的地址，然后通过地址改变它的值
// void scanfa2dimensionArray(int **a2dimensionArray,int n){
//     a2dimensionArray = (int**)malloc(n*sizeof(int*)); // Remove duplicate declaration
//     for(int i = 0; i < n; i++){
//         (a2dimensionArray)[i] = (int*)malloc(n*sizeof(int));
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             scanf("%d", &a2dimensionArray[i][j]); // Fix syntax error
//         }
//     }
// }

int **transposea2dimensionArray(int **a2dimensionArray,int n){
    int **transposeArray = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        transposeArray[i] = (int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            transposeArray[i][j] = a2dimensionArray[j][i];
        }
    }
    return transposeArray;
}

int **sumof2_2dimensionArray(int **a2dimensionArray1,int **a2dimensionArray2,int n){
    int **sumArray = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        sumArray[i] = (int*)malloc(n*sizeof(int));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sumArray[i][j] = a2dimensionArray1[i][j] + a2dimensionArray2[i][j];
        }
    }
    return sumArray;
}

void printofresultArray(int **resultArray,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", resultArray[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int **our2dimensionArray;
    int n_1;
    scanf("%d",&n_1);
    //scanfa2dimensionArray(&our2dimensionArray,n_1);
    scanfa2dimensionArray(&our2dimensionArray,n_1);
    //printofresultArray(our2dimensionArray,n_1);
    printofresultArray(sumof2_2dimensionArray(transposea2dimensionArray(our2dimensionArray,n_1),our2dimensionArray,n_1),n_1);
    free(our2dimensionArray);
    return 0;
}

