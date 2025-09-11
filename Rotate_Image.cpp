#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(int matrix[][3]){
int array[3][3];    
// Transpose the matrix
for(int j=0; j<3; j++){
    for(int i=0; i<3; i++){
        array[j][i] = matrix[i][j];
    }
}    

// reverse row 
for(int i=0; i<3; i++){
    for(int j=0; j<3/2; j++){
        int temp = array[i][j];
        array[i][j] = array[i][2-j];
        array[i][2-j] = temp;
    }
}
    
// print the matrix
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cout << array[i][j] << " ";
    }
    cout << endl;
}
   
}

void better_rotate(int matrix[][3]){
    int array[3][3]; 
// not yet done
    
}

int main(){
    int matrix[3][3]  = { {1,2,3},
                          {4,5,6},
                          {7,8,9} };
    // better_rotate(matrix);    
    rotate(matrix);
    
    
    
    return 0;
}
