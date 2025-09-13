#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    if(a.size()!=b.size()) {
        cout << "false" << endl;
        return 0;
    }
    if(a==b) {
        cout << "true" << endl;
        return 0;
    }
    int count = 0;
    int misIndex[2];
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]){
            if(count==2) {
                cout << "false" << endl;
                return 0;
            }
            misIndex[count++] = i;
        }
    }
    
    if(count==2) {
       if(a[misIndex[0]]==b[misIndex[1]] && a[misIndex[1]]==b[misIndex[0]]) {
           cout << "true" << endl;
           
       }else{
           cout << "false" << endl;
       }
    }else{
        cout << "false" << endl;
    }
    
    
    
}
