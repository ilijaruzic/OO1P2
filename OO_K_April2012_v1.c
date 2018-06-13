#include <stdio.h>
#define MAX 100

int main() {
	int a[MAX], b[MAX], pom[MAX];
	int i, j, n, rot, jednaki, t;
	
	while (1) {
		printf("Unesite duzinu nizova: ");
		scanf("%d", &n);
		
		if (n <= 0 || n > MAX) break;
		
		printf("Unesite prvi niz: ");
		for(i = 0; i < n; i++) 
			scanf("%d", &a[i]);
			
		printf("Unesite drugi niz: ");
		for(i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			pom[i] = b[i];
		}
		
		rot = 0; 
		for(i = 0; i < n; i++) {
			jednaki = 1;
			for(j = 0; j < n; j++)
				if(a[j] != pom[j]) {
					jednaki = 0;
					break;
				}
				
			if(jednaki) break;
			rot++;
			
			t = pom[n-1];
			for (j = n-1; j > 0; j--) 
				pom[j] = pom[j-1];
			pom[0] = t;
		}
		
		printf("Niz A: ");
		for(i = 0; i < n; i++) 
			printf("%d ", a[i]);
			
		printf("\nNiz B: ");
		for(i = 0; i < n; i++) 
			printf("%d ", b[i]);
			
		if(jednaki)
			printf("\nNiz A se dobija rotacijom niza B za %d mesta udesno!\n", rot);
		else
			printf("\nNiz A se ne moze dobiti rotacijom niza B!\n");
	}
}