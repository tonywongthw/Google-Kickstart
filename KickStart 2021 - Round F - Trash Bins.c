#include<stdio.h>
#include<stdlib.h>

int nextbin(int j, char s[], int n);
int min(int i, int j);

int
main(int argv, char* argc){
    int t;
    scanf("%d",&t);
    
    // for each test case
    for (int i = 0; i<t; i++){
        int n;
        char s[500000];
        
        scanf("%d", &n);
        scanf("%s", s);
        
        // keep index of first bin and second bin (if any)
        int bin_first=nextbin(0,s,n);
        int bin_second=nextbin(bin_first+1,s,n);
        long long int d_total = 0;
        
        //loop through the whole string
        for (int j=0; j<n; j++){
            //if there is a bin in index j, update index of the first bin to index j
            //also update index of the second bin after index j
            if (s[j]=='1'){
                bin_first=j;
                bin_second=nextbin(bin_first+1,s,n);
                continue;
            }
            // find the distance between index j and the cloeset bin
            d_total += min(abs(j-bin_first), abs(bin_second-j));
        }
        printf("Case #%d: %lld\n", i+1, d_total);
    }
}

//find the next bin in the string. if there is none, return 2*n+1 (meaning infinity)
int nextbin(int j, char s[], int n){
    for (int i = 0; i<n; i++){
        if ((j+i)<n && s[j+i]=='1'){
            return (j+i);
        }
    }
    return (2*n+1);
}

int min(int i, int j){
    if (i<j){
        return i;
    } else {
        return j;
    }
}
