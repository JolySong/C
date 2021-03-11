#include <stdio.h>
#define size 3
int main()
{
    int board[size][size];
    int i,j;
    int numOfX;
    int numOfO;
    int result=-1;  //-1没人胜出，0表示 O 胜出，1表示 X 胜出；
    
    //读入矩阵；
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            scanf("%d",&board[i][j]);
        }
    }
        
    //检查行；
    for (i=0; i<size&&result==-1; i++) {
        numOfO=numOfX=0;
        for (j=0; j<size; j++) {
            if(board[i][j]==1){
                numOfX++;
            }else{
                numOfO++;
            }
        }
        if(numOfO==size){
            result=0;
        }else if(numOfX==size){
            result=1;
        }
    }
    //检查列；
    if(result == -1){
        for(j=0;j<size&&result==-1;j++){
            numOfX=numOfO=0;
            for (i=0; i<size; i++) {
                if(board[i][j]==1){
                    numOfX++;
                }else{
                    numOfO++;
                }
            }
            if(numOfO==size){
                result=0;
            }else if(numOfX==size){
                result=1;
            }
        }
    }
    //检查正对角线；
    numOfX=numOfO=0;
    for(i=0;i<size;i++){
        if(board[i][i]==1){
            numOfX++;
        }else{
            numOfO++;
        }
    }
    if(numOfO==size){
        numOfO=0;
    }else if(numOfX==size){
        numOfX=1;
    }
    //检查反对角线；
    numOfX=numOfO=0;
    for(i=0;i<size;i++){
        if(board[i][size-i-1]){
            numOfX++;
        }else{
            numOfO++;
        }
    }
    if(result==1) printf(" X win!\n");
    else if(result==0) printf(" O win!\n");
    else printf(" noun !\n");
    return 0;
}
