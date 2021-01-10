#include <stdio.h>

int main() {
	int n = 10,c=1,temp=0,temp2;
	for (int i = 1;i<=n;i++){
	    if ((i%2) !=0){ //for odd rows
	        for (int j = 1;j<=2*i-1;j++){
	            if ((j%2)!=0){
	                printf("%d",c);
	                c++;
	            }
	            else printf("-");
	        }
	    }
	    else {//for even rows, i.e 3*2, 10*9*8*7 , etc
            temp = (i*i/2)+i/2;
	        for (int j = 1;j<=2*i-1;j++){
	            if ((j%2)!=0){
	             printf("%d",temp);
	             temp--;
	            }
	            else printf("-");
	        }
			c = c + i;
	        }
	        printf("\n");
	        }
}