#include <bits/stdc++.h>
using namespace std;

// ======================
// 1️⃣ Check if X is a subsequence of Y
// ======================
bool isSubsequence(string X, string Y){
    int i=0,j=0;
    while(i<X.size() && j<Y.size()){
        if(X[i]==Y[j]) i++;
        j++;
    }
    return i==X.size();
}

// ======================
// 2️⃣ Check if two strings are anagrams
// ======================
bool isAnagram(string X, string Y){
    if(X.size()!=Y.size()) return false;
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    return X==Y;
}

// ======================
// 3️⃣ Check if string contains only digits
// ======================
bool isNumber(string s){
    for(char c:s){
        if(!isdigit(c)) return false;
    }
    return true;
}

// ======================
// 4️⃣ Check if string is palindrome
// ======================
bool isPalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

// ======================
// 5️⃣ Check if string contains all unique characters
// ======================
bool isUniqueChars(string s){
    set<char> st;
    for(char c:s){
        if(st.count(c)) return false;
        st.insert(c);
    }
    return true;
}

// ======================
// 6️⃣ Check if one string can be rotated to get another
// ======================
bool isRotation(string s1, string s2){
    if(s1.size()!=s2.size()) return false;
    string temp = s1+s1;
    return temp.find(s2)!=string::npos;
}

// ======================
// 7️⃣ Check if pattern (with ? and *) matches text
// ======================
bool wildcardMatch(string text, string pattern){
    int n=text.size(), m=pattern.size();
    int i=0,j=0,star=-1, match=0;
    while(i<n){
        if(j<m && (pattern[j]=='?' || pattern[j]==text[i])){
            i++; j++;
        }
        else if(j<m && pattern[j]=='*'){
            star=j;
            match=i;
            j++;
        }
        else if(star!=-1){
            j=star+1;
            match++;
            i=match;
        }
        else return false;
    }
    while(j<m && pattern[j]=='*') j++;
    return j==m;
}

// ======================
// Main function: Test all
// ======================
int main(){
    string X="ace", Y="abcde";
    string num="12345", pal="radar", uniq="abcdef", s1="abcd", s2="cdab";

    cout<<"1. Is 'ace' subsequence of 'abcde'? "<<(isSubsequence(X,Y)?"Yes":"No")<<endl;
    cout<<"2. Are 'listen' and 'silent' anagrams? "<<(isAnagram("listen","silent")?"Yes":"No")<<endl;
    cout<<"3. Is '12345' a number? "<<(isNumber(num)?"Yes":"No")<<endl;
    cout<<"4. Is 'radar' palindrome? "<<(isPalindrome(pal)?"Yes":"No")<<endl;
    cout<<"5. Does 'abcdef' have all unique characters? "<<(isUniqueChars(uniq)?"Yes":"No")<<endl;
    cout<<"6. Can 'abcd' be rotated to get 'cdab'? "<<(isRotation(s1,s2)?"Yes":"No")<<endl;
    cout<<"7. Does text 'abcde' match pattern 'a*e'? "<<(wildcardMatch("abcde","a*e")?"Yes":"No")<<endl;
}
