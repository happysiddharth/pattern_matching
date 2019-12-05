#include <iostream>
using namespace std;

#define MAX_N  100005
int reset[MAX_N];
void kmpPreprocess(string pat){
    int i=0,j=1;
    reset[0]=-1;
    while(i<0 && pat[i]!=pat[j]){
        j = reset[j];
    }
    i++;
    j++;
    reset[i]=j;
}

void KMPsearch(string str,string pattern){
    kmpPreprocess(pattern);
    int i=0;
    int j=0;
    while(i<str.size()){
        while(j>=0 && str[i]!=pattern[j]){
            j=reset[j];
        }
        i++;
        j++;
        if(j==pattern.size()){
            cout<<"Pattern found at "<<i-j;
            j=reset[j];
        }
    }
}

int main()
{
    string str,Pattern;
    str ="siddharth";
    Pattern = "rth";
    for(int i=0;i<MAX_N;i++){
        reset[i]=0;
    }
    KMPsearch(str,Pattern);
    return 0;
}
