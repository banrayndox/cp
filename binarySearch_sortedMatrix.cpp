#include <iostream>
#include <vector>
using namespace std;

void binarySearch(vector<vector<int>> array, int n, int m, int target){
    for(int i=0; i<n; i++){
        int start = 0;
        int end = m-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target==array[i][mid]){
                cout << i << "," << mid << endl;
                return;
            }
            if(target>array[i][mid]){
                start = mid+1;
            }
            if(target<array[i][mid]){
                end = mid-1;
            }
        }
        
    }
     cout << "Not Found" << endl;
    
}
int main(){
    
    vector<vector<int>> array = { {10,20,30},
                                  {15,25,35},
                                  {27,29,37},
                                  {32,33,39,50} };
                            
    binarySearch(array, 4,4,33);                        
    
    
    
    return 0;
}
