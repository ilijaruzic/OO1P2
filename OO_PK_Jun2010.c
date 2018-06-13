#include <stdio.h>
#include <ctype.h>
#define N 6

int main() {
	char broj[N+1], c;
	int n = 0, vred, i, j;
	
	while(((c = getchar()) != '\n') && (n < N)) {
		if (!(isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) continue;
		broj[n++] = c;
	}
	
	broj[n] = '\0';
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++)
			if(broj[i] = broj[j]) {
				c = broj[i];
				broj[i] = broj[j];
				broj[j] = c;
			}
			
	sscanf(broj, "%x", &vred);
	printf("Minimalna vrednost: %d %s", vred, broj);
}