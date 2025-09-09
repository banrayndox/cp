// #include <iostream>
// using namespace std;
// void binToDec(int bin){
//     int n = bin;
//     int dec = 0;
//     int power = 1;
//     while(n>0){
//         int last = n%10;
//         dec += last * power;
//         power = power * 2;
//         n = n/10;

//     }
//     cout << dec << endl;
// }

// int main() {
// binToDec(101);
//     return 0;
// }

// #include <iostream>
// #include <cmath>
// using namespace std;
// void binToDec(int bin){
//     int n = bin;
//     int dec = 0;
//     int power = 0;
//     while(n>0){
//         int last = n%10;
//         dec += last * pow(2,power);
//         power++;
//         n/=10;
//     }
//     cout << dec << endl;
// }
// int main(){
// binToDec(101);
    
//     return 0;
// }



#include <iostream>
using namespace std;
void decToBin(int dec){
    int n = dec;
    int power = 1; // 10^0
    int bin = 0;
    while(n>0){
        int rem = n%2;
        bin += rem*power;
        n/=2;
        power *= 10;
    }
    cout << bin << endl;
}
int main() {
decToBin(5);
    return 0;
}




















