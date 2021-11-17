#include<stdio.h>
#include<string.h>

int nodog(char s[], int n);

int main(int argc, char* argv[]){
    int t;
    scanf("%d", &t);
  
    //for each test case
    for (int i = 0; i < t ; i++){
        int n, d, m;
        long long int c;
        char s[10000];
        
        // scan in test data
        scanf("%d %d %lli %d\n", &n, &d, &c, &m);
        scanf("%s", s);
        
        // check through the string
        for (int j = 0; j<n; j++){
            if(nodog(s,n)==1){
                break;
            }
            
            if (s[j]=='D'){
                if (d>0){
                    d--;
                    s[j] = 'P';
                    c+=m;                    
                } else {
                    break;
                }
            } else if (s[j]=='C'){
                if (c>0){
                    c--;
                    s[j] = 'P';
                } else {
                    break;
                }
            }
        }
        
        if(nodog(s,n)==1){
            printf("Case #%d: YES\n", i+1);
        } else {
            printf("Case #%d: NO\n", i+1);
        }
    }
    return 0;
}

//check if there are still dogs in queue
int nodog(char s[], int n){
    for (int i=0; i<n; i++){
        if (s[i]=='D'){
            return 0;
        }
    }
    return 1;
}
