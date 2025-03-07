/*选用合适的数据结构，实现基于栈的括号匹配算法。

样例输入
(a(b)(c))
样例输出
1:3
2:1
3:2
说明：1:3表示第一个左括号和第三个右括号匹配。输出顺序由左括号的出现顺序决定。
*/
# include <stdio.h>
# include <stdlib.h>
# define MAX_PAIRS 1000

# ifndef _STACK_H_
# define _STACK_H_
struct Stack {
	char stack[MAX_PAIRS];
    int count[MAX_PAIRS];
    int top;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    struct Stack* count = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

void DestroyStack(struct Stack* stack) {
    free(stack);
}

void push(struct Stack* stack, char c, int count_) {
    stack->stack[++stack->top] = c;
    stack->count[stack->top] = count_;
}

char pop(struct Stack* stack) {
    return stack->stack[stack->top--];
}


int isPair(char a, char b) {
    return (a == '(' && b == ')');
}

# endif

int main(){
    struct Stack* stack_ = createStack();
    char* str = (char*)malloc(2*MAX_PAIRS * sizeof(char));
    scanf("%s", str);
    int count_ = 1;
    int index[MAX_PAIRS]  = {0};
    int index_right = 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '('){
            push(stack_, str[i], count_++);
        }
        else if (str[i] == ')'){
            if (isPair(stack_->stack[stack_->top], str[i])){
                index[stack_->count[stack_->top ]] = index_right++;
                pop(stack_);
            }
            }
        }
    for (int i = 1; i < count_; i++){
        printf("%d:%d\n", i, index[i]);
    }
    DestroyStack(stack_);
    free(str);
    return 0;
    }
