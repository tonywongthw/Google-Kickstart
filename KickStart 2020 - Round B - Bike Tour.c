#include <stdio.h>

int main(int argv, char* argc[]){
    int t;
    scanf("%d", &t);
    
    for (int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        
        //initialises the array and stores the inputs
        int arr[n];
        for (int k=0; k<n; k++){
            int input;
            scanf("%d", &input);
            arr[k] = input;
        }
        
      //for each point, check if it is a peak
        int count=0;
        for (int j=1; j<n-1; j++){
            if (arr[j] > arr[j-1] && arr[j] > arr[j+1]){
                count++;
            }
        }
        printf("Case #%d: %d\n", i+1, count);
    }
}
