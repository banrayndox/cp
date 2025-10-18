#include <iostream>
#include <cmath>
using namespace std;
int main(){
    while(1){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if( a==0 && b==0 && c==0 && d==0 ) break;
        int result = 40*3*9;
        result+= ( (a-b+40) % 40 )* 9;
        result+= ( ((c-b+40) % 40 ) *9 );
        result+= ( (c-d+40) % 40 ) * 9;
        
        cout << result << endl;
    }
    
    
    
    return 0;
}
