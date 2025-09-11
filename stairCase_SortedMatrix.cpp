#include <iostream>
#include <vector>
using namespace std;

void stairCaseSearch(vector<vector<int>> array, int n, int m, int target){
    int i=0;
    int j=m-1;
while(i<n && j>=0){
    if(target == array[i][j]){
        cout << i << " " << j << endl;
        return;
    }
    else if(target < array[i][j]){
        j--;
    }else{
        i++;
    }
    
}
cout << "Not Found" << endl;

}
int main(){
    
    vector<vector<int>> array = { {10,20,30},
                                  {15,25,35},
                                  {27,29,37},
                                  {32,33,39} };
                            
    stairCaseSearch(array, 4,3,33);                        
    
    
    
    return 0;
}
