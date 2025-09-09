#include <iostream>
#include <vector>
using namespace std;
int maxProfit(int prices[], int pricesSize){
    int buy=prices[0];
    int profit=0;
    for(int i=1; i<pricesSize; i++){
        int currProfit = prices[i]-buy;
        if(currProfit > profit) profit = currProfit;    
        if(prices[i] < buy) buy = prices[i];
}
return  profit;
}
int main(){
    int array[5] = {7,1,5,3,6};
    int result = maxProfit(array,5);
    cout << result << endl;
   return 0; 
}
