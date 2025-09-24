#include <bits/stdc++.h>
using namespace std;

// ======================
// 1️⃣ LCS (Iterative simple way without DP)
// ======================
// Idea: try all lengths of subsequences manually using bitmask (for small strings)
int LCSIterative(string X, string Y){
    int m = X.size(), n = Y.size();
    int maxLen = 0;
    // all subsequences of X
    for(int mask=1; mask<(1<<m); mask++){
        string subX="";
        for(int i=0;i<m;i++) if(mask & (1<<i)) subX += X[i];
        // check if subX is subsequence of Y
        int idx=0;
        for(int j=0;j<n && idx<subX.size();j++){
            if(subX[idx]==Y[j]) idx++;
        }
        if(idx==subX.size()) maxLen = max(maxLen, (int)subX.size());
    }
    return maxLen;
}

// ======================
// 2️⃣ Longest Common Substring (check all substrings)
// ======================
int LCSubstringIterative(string X, string Y){
    int m = X.size(), n = Y.size();
    int maxLen = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int k=0;
            while(i+k<m && j+k<n && X[i+k]==Y[j+k]) k++;
            maxLen = max(maxLen,k);
        }
    }
    return maxLen;
}

// ======================
// 3️⃣ Min Insertions & Deletions (use iterative LCS)
// ======================
pair<int,int> minInsertDeleteIterative(string X, string Y){
    int lcsLen = LCSIterative(X,Y);
    int deletions = X.size() - lcsLen;
    int insertions = Y.size() - lcsLen;
    return {insertions, deletions};
}

// ======================
// 4️⃣ Longest Palindromic Subsequence (Iterative using subsequences check)
// ======================
bool isPalindromeIterative(string s){
    int i=0, j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

int LPSSimpleIterative(string s){
    int n = s.size();
    int maxLen = 0;
    for(int mask=1; mask<(1<<n); mask++){
        string sub="";
        for(int i=0;i<n;i++) if(mask & (1<<i)) sub += s[i];
        if(isPalindromeIterative(sub))
            maxLen = max(maxLen,(int)sub.size());
    }
    return maxLen;
}

// ======================
// 5️⃣ Min Insertions to make Palindrome
// ======================
int minInsertPalindromeIterative(string s){
    return s.size() - LPSSimpleIterative(s);
}

// ======================
// 6️⃣ Check if X is subsequence of Y (iterative 2-pointer)
// ======================
bool isSubsequenceIterative(string X, string Y){
    int i=0,j=0;
    while(i<X.size() && j<Y.size()){
        if(X[i]==Y[j]) i++;
        j++;
    }
    return i==X.size();
}

// ======================
// 7️⃣ Count of Distinct Subsequences (iterative using set)
// ======================
int countDistinctSubseqIterative(string s){
    int n = s.size();
    set<string> subseqs;
    // loop over all subsequences using bitmask
    for(int mask=0; mask<(1<<n); mask++){
        string sub="";
        for(int i=0;i<n;i++){
            if(mask & (1<<i)) sub += s[i];
        }
        subseqs.insert(sub);
    }
    return subseqs.size();
}

// ======================
// Main function
// ======================
int main(){
    string X="abc", Y="ace";
    string s="abca";

    cout << "1. LCS length: " << LCSIterative(X,Y) << endl;
    cout << "2. Longest Common Substring length: " << LCSubstringIterative(X,Y) << endl;

    auto [ins, del] = minInsertDeleteIterative(X,Y);
    cout << "3. Min insertions: " << ins << ", Min deletions: " << del << endl;

    cout << "4. Longest Palindromic Subsequence length: " << LPSSimpleIterative(s) << endl;
    cout << "5. Min insertions to make palindrome: " << minInsertPalindromeIterative(s) << endl;

    cout << "6. is 'ace' subsequence of 'abc'? " << (isSubsequenceIterative("ace","abc")?"Yes":"No") << endl;

    cout << "7. Count of distinct subsequences of 'abc': " << countDistinctSubseqIterative("abc") << endl;
}
