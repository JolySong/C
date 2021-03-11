/*快速排序*/

#include<stdio.h>
#define SIZE 10

int a[SIZE] = {6,1,2,7,9,3,4,5,10,8};

void quicksort(int left, int right);

int main(void)
{
    
    int i;
    quicksort(0,SIZE-1);

    for (i = 0; i < SIZE; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void quicksort(int left, int right)
{
    int i,j,t,temp;
    if(left>right)
        return;

    temp= a[left];     //temp中存放的基准数
    i = left;
    j = right;
    while(i != j){
        //顺序很重要，要先从右往左找
        while(a[j] >= temp && i<j)
            j--;
        //再从左往右找
        while(a[i] <= temp && i<j)
            i++;

        //交换两个数在数组中的位置
        if(i<j){ //当哨兵i与j未相遇的时候
            t = a[i] ;
            a[i] = a[j];
            a[j] = t;
        }
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;

    quicksort(left , i-1);    //继续处理左边的，这是一个递归的过程
    quicksort(i+1, right);    //继续处理右边的，这是一个递归的过程
    return;
}
