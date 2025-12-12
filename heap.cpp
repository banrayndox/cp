#include <bits/stdc++.h>
using namespace std;
// STL priority queue / Heap with Self referential structure
class Heap{
    private:
    vector<int> array;
    public:
    void push(int x){
        array.push_back(x);
        int n = array.size()-1;
        int parent = (n-1)/2;
        while(n>0 && array[parent]<array[n]){
            swap(array[parent], array[n]);
            n = parent;
            parent = (n-1)/2;
        }
    }
    void heapify(int i){
        int l = i*2+1;
        int r = i*2+2;
        int largest = i;
        if(l<array.size() && array[largest] < array[l]){
            largest = l;
        }
        if(r<array.size() && array[largest] < array[r]){
            largest = r;
        }
        if(largest!=i){
            swap(array[largest], array[i]);
            heapify(largest);
        }
    }
    void pop(){
        if(array.empty()) return;
        array[0] = array[array.size()-1];
        array.pop_back();
        heapify(0);
    }
    int top(){
        if(array.size()==0) return -1;
        return array[0];
    }
    bool isEmpty(){
        if(array.size()==0) return true;
        return false;
    }
};
// Build Max Heap from an array and making it ascending order sorted

void heapify_for_max_heap(vector<int> &array, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && array[largest] < array[left]){
        largest = left;
    }
    if(right<n && array[largest]< array[right]){
        largest = right;
    }
    if(largest!=i){
        swap(array[largest], array[i]);
        heapify_for_max_heap(array,n,largest);
    }
}
void build_heap_from_array(vector<int> &array){
    int n = array.size();
    for(int i=n/2-1; i>=0; i--){
        heapify_for_max_heap(array,n,i);
    }
}
void sort_heap(vector<int> &array){
    build_heap_from_array(array);
    
      // Without sort
    cout << "UnSorted Max Heap: ";
    for(int x : array) cout << x << " ";
    cout << "\n";
    
    int n = array.size();
    for(int i=n-1; i>=1; i--){
        swap(array[0], array[i]);
        heapify_for_max_heap(array,i, 0);
    }

}

int main(){

     vector<int> array = {12, 3, 17, 8, 34, 1, 9};

    cout << "Original array: ";
    for(int x : array) cout << x << " ";
    cout << "\n";

    
    // Heap Sort
    sort_heap(array);

    cout << "Sorted array (ascending): ";
    for(int x : array) cout << x << " ";
    cout << "\n";
    
return 0;
}
