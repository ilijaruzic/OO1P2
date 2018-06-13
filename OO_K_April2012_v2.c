#include <stdio.h>
#define MAX 100

int main() {
	int a[MAX], b[MAX];
	int i, j, k, n, rot, dobijaSeRotacijom, brMesta;
	
	while (1) {
		printf("Unesite duzinu nizova: ");
		scanf("%d", &n);
		
		if (n <= 0 || n > MAX) break;
		
		printf("Unesite prvi niz: ");
		for(i = 0; i < n; i++) 
			scanf("%d", &a[i]);
			
		printf("Unesite drugi niz: ");
		for(i = 0; i < n; i++)
			scanf("%d", &b[i]);
			
		dobijaSeRotacijom = 0;
		for (i = 0; i < n; i++) {
			rot = 1;
			for (j = 0, k = i; j < n; j++, k = (k + 1) % n)
				if (a[k] != b[j]) {
					rot = 0;
					break;
				}
			
			if(rot) {
				dobijaSeRotacijom = 1;
				brMesta = i;
				break;
			}
		}
		
		printf("Niz A: ");
		for(i = 0; i < n; i++) 
			printf("%d ", a[i]);
			
		printf("\nNiz B: ");
		for(i = 0; i < n; i++) 
			printf("%d ", b[i]);
			
		if(dobijaSeRotacijom)
			printf("\nNiz A se dobija rotacijom niza B za %d mesta udesno!\n", brMesta);
		else
			printf("\nNiz A se ne moze dobiti rotacijom niza B!\n");
	}
}