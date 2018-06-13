#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 100

int main() {
	float x[N], y[N];
	int i, j, n;
	
	srand(time(NULL));
	
	while (1) {
		printf("\nUnesite broj tacaka: ");
		scanf("%d", &n);
		
		if(n <= 0 || n > N) break;
		
		for(i = 0; i < n; i++) {
			x[i] = rand() / (float)RAND_MAX;
			y[i] = rand() / (float)RAND_MAX;
		}
		
		for(i = j = 0; i < n; i++)
			if(x[i] * x[i] + y[i] * y[i] <= 1) {
				x[j] = x[i];
				y[j] = y[i];
				j++;
			}
		n = j;
	}
	
	printf("\nTacke koje pripadaju krugu:\n");
	for(i = 0; i < n; i++)
		printf("(%f, %f) ", x[i], y[i]);
}