#include <stdio.h>
#define N 100

int main() {
	unsigned char a[N];
	int i, j, n, odd;
	
	while(1) {
		printf("\nN? ");
		scanf("%d", &n);
		
		if (n <= 0 || n > N) break;
		
		printf("Unesite poruku:\n");
		for(i = 0; i < n; i++) 
			scanf("%d", &a[i]);
			
		for(i = 0; i < n; i++) {
			odd = 0;
			for(j = 0; j < 7; j++)
				odd += 1 & (a[i] >> j);
			a[i] |= odd % 2 ? 0x80 : 0;
		}
		
		printf("Poruka za slanje:\n");
		for(i = 0; i < n; i++) 
			printf("%u", a[i]);
	}
}