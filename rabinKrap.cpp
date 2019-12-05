#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define prime 119


ll createHashValue(string str,int n){
    ll result = 0;
    for(int i=0;i<n;i++){
        result+=(ll)(str[i]*(ll)(pow(prime,i)));
    }
    return result;
}

ll recalculateHash(string str,int oldIndex,int newIndex,ll oldhash ,int patternLength){
    ll newHash = oldhash - str[oldIndex];
    newHash/=prime;
    newHash = (ll)(str[newIndex]*(ll)(pow(prime,patternLength-1)));

    return newHash;
}

bool checkEqual(string str1,string str2,int start1,int end1,int start2,int end2){
    if(end1 - start1 != end2 - start2){
        return false;
    }
    while(start1<=end1 and start2<=end2){
        if(str1[start1]!=str2[start2]){
            return false;
        }
        start2++;
        start1++;
    }
    return true;
}


int main()
{
    string str,Pattern;
    str ="siddharth";
    Pattern = "ddh";
    ll PatternHash = createHashValue(Pattern,Pattern.length());
    ll strHash = createHashValue(str,Pattern.length());
    cout<<PatternHash<<endl<<strHash<<endl;
    cout<<"Pattern length "<<Pattern.length()<<endl;

    for(int i=0;i<=str.length();i++){
        if(PatternHash == strHash and checkEqual(str,Pattern,i,i+Pattern.length()-1,0,Pattern.length()-1)){
            cout<<i<<endl;
        return 0;
        }
        if(i<(str.length()-Pattern.length())){
            strHash = recalculateHash(str,i,i+Pattern.length(),strHash,Pattern.length());
           cout<<strHash<<"->";
        }
    }

    return 0;
}
