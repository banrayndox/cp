#include <iostream>
using namespace std;

void print(int array[], int n){
    for(int i=0; i<n; i++){
        cout << array[i] << "";
    }
    cout << endl;
}
void change(int array[], int n, int i){
    if(n==i){
        print(array,5);
     return;
    }
    array[i] = i+1;
    change(array,5,i+1);
    array[i] = array[i]-2;
    if(i==0) print(array,5);
}

int main(){
 int array[5]={0};   
    change(array,5,0);
    return 0;
}
