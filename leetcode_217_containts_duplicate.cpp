#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void check(vector<int>array){
    int n = array.size();
    // sort(array.begin(),array.end());
    
    for(int i=0; i<n-1; i++){
        for(int j=0;j<n-i-1; j++){
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
    
    
    
    for(int i=1; i<array.size(); i++){
        if(array[i]==array[i-1]) {
            cout << "True" << endl;
            return;
        }
    }
    cout << "False" << endl;
}
int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    check(array);
    
    return 0;
}
