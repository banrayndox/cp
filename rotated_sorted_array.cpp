#include <iostream>
#include <vector>
using namespace std;
void finda(vector<int>array, int target){
    int low = 0;
    int max = array.size()-1;
    while(low<=max){
        int mid = low + (max-low) / 2;
        if(array[mid]==target){
            cout << "Found at: " << mid << endl;
           return ;
        }
        if(array[low]<=array[mid]){
            if(array[low]<=target && target<=array[mid]){
                max = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(array[mid]<=target && target<=array[max]){
                low = mid+1;
            }else{
                max = mid -1;
            }
        }
    }
    cout << "Not Found" << endl;
}
int main(){
    
vector<int>array = {5,6,7,8,9,10,1,2,3,4};    
int target = 3;
// int target = 6; 
finda(array, target);

    return 0;
}
