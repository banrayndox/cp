#include <iostream>
using namespace std;
#include <string>
#include <queue>
string output(string &temp){
    int len = temp.size();
    queue<char>cha;
    int freq[26] = {0};
    string result = "";
    for(char ch: temp){
        freq[ch-'a']++;
        cha.push(ch);
        while(!cha.empty() && freq[cha.front()-'a']>1){
            cha.pop();
        }
        if(!cha.empty()){
            result+=cha.front();
        }else{
            result+="#";
        }
    }
    return result;
}

int main(){
    string line = "hello rakib";
    cout << output(line) << endl;
    
    return 0;
}
