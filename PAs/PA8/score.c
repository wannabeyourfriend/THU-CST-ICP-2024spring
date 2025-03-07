//定义一个学生结构体类型student，包括4个字段，姓名、性别、年龄和成绩。然后在主函数中定义一个结构体数组（长度不超过1000) 输入每个元素的值，程序使用冒泡排序法将学生按照成绩从小到大的顺序排序，然后输出排序的结果。
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct{
    char *name;
    char *gender;
    int age;
    int score;
} Student_;

void bubblesort(Student_ students[], int length);
void printfStudents(Student_ students[], int length); // Add the missing function prototype

void bubblesort(Student_ students[], int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            if(students[j].score > students[j + 1].score){
                Student_ temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void printfStudents(Student_ students[], int length){
    for(int i = 0; i < length; i++){
        printf("%s %s %d %d\n", students[i].name, students[i].gender, students[i].age, students[i].score);
    }
}

int main(){
    int length;
    scanf("%d", &length);
    Student_ students[1000];
    for(int i = 0; i < length; i++){
        students[i].name = (char*)malloc( sizeof(char) * 20 );//要特别注意这里的逻辑，一定还要为name和gender分配内存空间，不然读入会报错，因为name和gender是指针类型，没有分配内存空间，所以会报错
        students[i].gender = (char*)malloc( sizeof(char) * 20);//如果不读入可能造成内存泄漏
        scanf("%s %s %d %d", students[i].name, students[i].gender, &students[i].age, &students[i].score);
    }
    bubblesort(students, length);
    printfStudents(students, length);
    for(int i = 0; i < length; i++){
        free(students[i].name);
        free(students[i].gender);   
    }
    return 0;
}
