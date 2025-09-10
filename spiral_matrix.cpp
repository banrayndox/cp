#include <iostream>
using namespace std;
void res(int matrix[][4],int n,int m){
    int start_row = 0;
    int end_row = n-1;
    int start_col = 0;
    int end_col = m-1;
    while(start_row<=end_row && start_col <= end_col){
     for(int i=start_col; i<=end_col; i++){
         cout << matrix[start_row][i] << " ";
     }
     start_row++;
     
     for(int i=start_row; i<=end_row; i++){
         cout << matrix[i][end_col] << " ";
     }
     end_col--;
    if(start_row<=end_row){   
     for(int i=end_col; i>=start_col; i--){
         cout << matrix[end_row][i] << " ";
     }
     end_row--;}
     if(start_col<=end_col){
     for(int i=end_row; i>=start_row; i--){
         cout << matrix[i][start_col] << " ";
     }
     start_col++;
     }

    }
    
}
int main(){
    int matrix[4][4] = { {1,2,3,4},
                         {5,6,7,8},
                         {9,10,11,12},
                         {13,14,15,16} };
    int n = 4, m = 4;
    res(matrix,n,m);
}
