#include <stdio.h>
#define MAX_SKUP 16

int main() {
	int skup1[MAX_SKUP], skup2[MAX_SKUP];
	int i, end = 1, jednaki, b;

	while(end) {
		for(i = 0; i < MAX_SKUP; i++)
			skup1[i] = skup2[i] = 0;
			
		printf("Unesite elemente prvog skupa: ");
		while(1) {
			scanf("%d", &b);
			if((b < 0) || (b >= MAX_SKUP)) break;
			skup1[b] = 1;
		}
		
		printf("Unesite elemente drugog skupa: ");
		while(1) {
			scanf("%d", &b);
			if((b < 0) || (b >= MAX_SKUP)) break;
			skup2[b] = 1;
		}
		
		jednaki = 1;
		for(i = 0; i < MAX_SKUP; i++)
			if(skup1[i] != skup2[i]) {
				jednaki = 0;
				break;
			}
			
		if(jednaki)
			printf("Skupovi su jednaki!\n");
		else
			printf("Skupovi nisu jednaki!\n");
		
		printf("0 za kraj, 1 za nastavak: ");
		scanf("%d", &end);
	}
}