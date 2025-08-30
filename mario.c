#include <stdio.h>

int main() {
    int n;
    do {
        printf("Enter the no. n ");
        scanf("%d", &n);
    }
    while(n<=0) ;
        printf("Enter the no. n ");
        scanf("%d", &n);
    
    for(int i=0; i<n; i++) { // no of lines
        for(int j=0; j<n-i-1; j++) {  //spaces
            printf(" "); 
        }
        
        for (int k = 0; k <i+1; k++) {  // pattern print
            printf("#"); 
        }
        
           
        printf("\n"); 
    }
       
    
    return 0;
}
