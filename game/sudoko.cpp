#include <bits/stdc++.h>
using namespace std;
int main(){
int array[9][9];
// input
for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
        cin >> array[i][j];
    }
}

// processing


// row
for(int i=0; i<9; i++){
bool digit[10] = {false};    
    for(int j=0; j<9; j++){
        digit[array[j][i]] = true;    
    }
for(int i=1; i<=9; i++){
    if(digit[i]==false) {
        cout << "No\n";
        return 0;
    }
}
}

// column
for(int i=0; i<9; i++){
bool digit[10] = {false};    
    for(int j=0; j<9; j++){
        digit[array[i][j]] = true;    
    }
for(int i=1; i<=9; i++){
    if(digit[i]==false) {
        cout << "No\n";
        return 0;
    }
}
}

//divide
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        
    bool digit[10] = {false};
    for(int k=0; k<3; k++){
        for(int l=0; l<3; l++){
            digit[array[(i*3)+k][(j*3)+l]] = true;
        }
    }
    
    for(int i=1; i<=9; i++){
    if(digit[i]==false) {
        cout << "No\n";
        return 0;
    }
        
        
    }
}    
}
// output
cout << "Yes\n";

    return 0;
}
