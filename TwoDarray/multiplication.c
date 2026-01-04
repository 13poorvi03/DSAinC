// wap to print the multiplication of two matrice given by the user 

#include<stdio.h>
int main(){
    // 1 2
    // 3 4
    // 5 6
    int a[3][2]={{1,2},{3,4},{5,6}};
    // 2 7 8 9
    // 3 5 6 4
    int b[2][4]={{2,7,8,9},{3,5,6,4}};
    int res[3][4];
    //multiplying 

    int cr=2; 

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            //i row of a[][] and j column of b[][]
            //(a[i][0],a[i][1],a[i][2])*(b[0][j],b[1][j],b[2][j])

            /////basically arr a mae i constant rhega and j  increase hota rhega and arr b mae j constant rhega aur i increase hota rhega
             
            res[i][j]=0;
            for(int k =0; k<cr; k++){
                res[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    //print

    // 8 17 20 17 
    // 18 41 48 43
    // 28 65 76 69
    
    for(int i=0 ; i<3; i++){
        for(int j=0; j<4; j++){
          printf(" %d ", res[i][j]);

        }
        printf("\n");
    }
    return 0;
}