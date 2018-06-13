#include <stdio.h>
#define MAX 100

int main() {
	int a[MAX], i, j, n;
	int isFirst = 1;
	
	while (1) {
		printf("Unesite duzinu niza: ");
		scanf("%d", &n);
		
		if (n <= 0 || n > MAX) break;
		
		printf("Unesite niz: ");
		for(i = 0; i < n; i++) {
			a[i] = 0;
			while(a[i] <= 0) 
				scanf("%d", &a[i]);
		}
			
		for (i = 0; i < n; ++i) {
			printf("\n%d = ", a[i]);
			for(j = sizeof(int)*8 - 1; j >= 0; j--)
				if(a[i] & 1 << j) {
					if(!isFirst) 
						printf(" + ");
					else 
						isFirst = 0;
					printf("2^%d", j);
				}
		}
		
		/* v2 za bitsko maskiranje i proveru
		unsigned int mask = 1 << (sizeof(int)*8-1);
		j = sizeof(int)*8-1; 
		for(; mask; mask >>=1, j--) 
			if(a[i] & mask) { 
				printf("%c 2^%d", isFirst ? ' ' : '+', j); 
				if(isFirst) 
					isFirst = 0; 
			}
		*/
		
		putchar('\n');
	}
}