/* 逆波兰计算器 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define STACK_INIT_SIZE 20
#define STACK_ADD 10
#define MAXBUFFER 10

typedef double ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int StackSize;
}sqStack;

//栈的初始化
void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc( sizeof(ElemType) * STACK_INIT_SIZE);
    if(!s->base){
        exit(0);
    }
    s->top = s->base;
    s->StackSize = STACK_INIT_SIZE;
}
void Push_back(sqStack *s, ElemType e)
{
    if(s->top - s->base >= s->StackSize){
        s->base = (ElemType *)realloc(s->base, (s->StackSize + STACK_ADD) * sizeof(ElemType));
        if(!s->base){
            exit(0);
        }
        s->top = s->base + s->StackSize;
        s->StackSize = s->StackSize + STACK_ADD;
    }
    *(s->top) = e;
    s->top++;
}
void Pop_back(sqStack *s, ElemType *e)
{
    if(s->top == s->base) return;
    *e = *--(s->top);
}
int main()
{
    sqStack s;
    InitStack(&s);
    char c;
    char str[MAXBUFFER];
    int i=0;
    double d, e;
    printf("请按逆波兰表达式输入数据，数据与运算符之间用空格隔开，键入Enter结束\n");
    scanf("%c",&c);
    while(c != '\n'){
        while(isdigit(c) || c == '.'){  //过滤数字
            str[i++] = c;
            str[i] = '\0';
            if(i>=10){
                printf("ERROR: 输入的单个数据过大! \n");
                return -1;
            }
            scanf("%c",&c);
            if(c == ' '){
                d = atof(str);
                Push_back(&s, d);
                i = 0;
                break;
            }
        }
        switch (c) {
            case '+':
                Pop_back(&s, &d);
                Pop_back(&s, &e);
                Push_back(&s, d+e);
                break;
            case '-':
                Pop_back(&s, &d);
                Pop_back(&s, &e);
                Push_back(&s, e-d);
                break;
            case '*':
                Pop_back(&s, &d);
                Pop_back(&s, &e);
                Push_back(&s, d*e);
                break;
            case '/':
                Pop_back(&s, &d);
                Pop_back(&s, &e);
                if(e){
                    Push_back(&s, d/e);
                }else{
                    printf("ERROR: 除数为0! \n");
                    return -1;
                }
                break;
                
            default:
                break;
        }
        scanf("%c",&c);
    }
    Pop_back(&s, &d);
    printf("最终计算结果为: %g\n",d);
    return 0;
}
