#include <iostream>
#include <vector>
using namespace std;
void binarySearch(vector<int>* array, int target){
    int left = 0;
    int right = array->size()-1;
    while(left<=right){
        int mid = left + (right-left) / 2;
        if(target == (*array)[mid]) {
            cout << "Value found at index: " << mid;
            return;
            
        }
        else if(target < (*array)[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
}
int main(){
    vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    int target = 3;
    binarySearch(&array, target);
}
