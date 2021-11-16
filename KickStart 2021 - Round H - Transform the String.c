#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int distance(char curr_s, char curr_fav);
int min(int i, int j);

int
main(int argc, char* argv[]){
    int t;
    scanf("%d", &t);
    
    //initialises number of cases
    for (int i=0; i<t; i++){
        int total=0;
        char s[100000];
        char f[100];
        
        scanf("%s", s);
        scanf("%s", f);
        
        //for each character of string
        for (int j=0; j<strlen(s); j++){
            int minmove = 30;
            char curr_s = s[j];
            
            //check against each character of fav string
            for (int k=0; k<strlen(f); k++){
                char curr_f = f[k];
                int d = distance (curr_s, curr_f);
                
                //for exact mathc, terminate immediately
                if (d == 0){
                    minmove = d;
                    break;
                }
                if (d < minmove){
                    minmove = d;
                }
            }
            total += minmove;
        }
        printf("Case #%d: %d\n", i+1, total);
    }
    return 0;
}

//for two characters, find their cyclic distance
int distance(char curr_s, char curr_fav){
    int m;
    if (curr_s == curr_fav){
        return 0;
    }
    if (curr_s < curr_fav){
        char temp = curr_s;
        curr_s = curr_fav;
        curr_fav = temp;
    }
    m = min(curr_s-curr_fav,curr_fav+26-curr_s);
    
    return m;
}

int min(int i, int j){
    if (i<j){
        return i;
    } else {
        return j;
    }
}
