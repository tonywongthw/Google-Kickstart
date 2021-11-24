#include<stdio.h>
#include<string.h>

#define MAX 10000

void sort_char_array(char s[], int n);
void char_swap(char *p1, char *p2);
void store_char(char s[], int n, int size, int index[][size]);
void arrange(char s1[], int n, int size, int index[][size],char s3[]);
int check_index(char c, int size, int index[][size]);

int main(int argv, char* arg[]){
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i<t; i++){
        char s[MAX+1];
        scanf("%s", s);
        int n = strlen(s);
        
        int index[26][MAX];
        
        // initialises 2d index array to store index of each character in string
        for (int j = 0; j<26; j++){
            for (int k = 0; k<MAX; k++){
                index[j][k]=-1;
            }
        }
        
        // store index of character in the 2d array
        store_char(s,n, MAX, index);
        
        sort_char_array(s, n);
        
        // find the max number of repetition of a character
        char c=s[0];
        int l = 1;
        int count = 1;
        int max=1;
        
        while (l<n){
            if (s[l]==c){
                count++;
                if (count>max){
                    max=count;
                }
            } else {
                c=s[l];
                count=1;
            }
            l++;
        }
        
        // if max > n/2, cannot create anagram
        if (max>n/2){
            printf("Case #%d: IMPOSSIBLE\n", i+1);
        } else {
            // otherwise, create the anagram
            char s3[MAX+1];
            arrange(s, n, MAX, index, s3);
            printf("Case #%d: %s\n", i+1, s3);
        }
    }
    return 0;
}

// store index of character in the 2d array
void
store_char(char s[], int n, int size, int index[][size]){
    for (int i=0; i<n; i++){
        int j = s[i]-'a';
        int k = 0;
        
        while (index[j][k]!=-1){
            k++;
        }
        index[j][k]=i;
    }
}

void
sort_char_array(char s[], int n) {
	int i, j;
	for (i=1; i<n; i++) {
		for (j=i-1; j>=0 && s[j+1]<s[j]; j--) {
			char_swap(&s[j], &s[j+1]);
		}
	}
}

void
char_swap(char *p1, char *p2) {
	char tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// arrange the anagram
void
arrange(char s1[], int n, int size, int index[][size], char s3[]) {
    char s2[MAX+1];
    
    int i = 0;
    
    //sort the string, and exchange the first and second half
    while (i<n/2){
        s2[i]=s1[i+n/2];
        i++;
    }
    
    if (n%2==1){
        s2[i] = s1[n-1];
        i++;
    }
    
    while (i<n && (n%2==1)){
        s2[i]=s1[i-n/2-1];
        i++;
    }
    
    while (i<n && (n%2==0)){
        s2[i]=s1[i-n/2];
        i++;
    }
    
    //create anagram s3, by matching each character in s2 to the corresponding
    //original position of the character in s1
    for (int j=0; j<n; j++){
        // get the original position of the character in s1
        int i = check_index(s1[j], MAX, index);
        // put characher in s2 in that position
        s3[i] = s2[j];
    }
    s3[n]='\0';
}

//check the original position of the character in s1
int check_index(char c, int size, int index[][size]){
    int ans, i=0;
    
    while (index[c-'a'][i]==-1){
        i++;
    }
    
    //obatin the index as ans
    ans = index[c-'a'][i];
    //afer using, remove that index in the 2d array index
    index[c-'a'][i]=-1;
    
    return ans;
}
