#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int main() {
	int godine, n, i, j, max; 
	int gradovi[MAX];
	double slucajan;
	
	srand(time(NULL));
	
	printf("Unesite broj gradova: ");
	scanf("%d", &n);
	
	if (n < 1 || n > MAX) {
		printf("ERR: Broj gradova je neodgovarajuci.\n");
		exit(1);
	}
	
	printf("Unesite broj godina: ");
	scanf("%d", &godine);
	
	if (godine < 1) {
		printf("ERR: Broj godina je neodgovarajuci.\n"); 
		exit(1);
	}
	
	printf("Unesite broj stanovnika za gradove:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &gradovi[i]);
		
		if (gradovi[i] < 2) {
			printf("ERR: Broj stanovnika grada je neodgovarajuci.\n"); 
			exit(1);
		}
	}
	
	for (i = 0; i < godine; i++) {
		for (j = 0; j < n; j++) {
			slucajan = rand() / (double)RAND_MAX * 2 - 1;
			gradovi[j] += gradovi[j] * slucajan / 100;
			
			if (gradovi[j] < 2) {
				printf("ERR: Broj stanovnika grada je neodgovarajuci.\n"); 
				exit(1);
			}
		}
		
		for (j = 0; j < n; j++)
			printf("%d ", gradovi[j]);
		
		printf("\n");
	}
	
	max = gradovi[0];
	for (i = 0; i < n; i++)
		if (max < gradovi[i])
			max = gradovi[i];
	printf("Grad sa najvecim brojem stanovnika je %d.\n", max);
}