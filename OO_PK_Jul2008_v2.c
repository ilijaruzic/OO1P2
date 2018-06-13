#include <stdio.h>
#define MAX_SKUP 16

int main(){
	unsigned short skup1 = 0, skup2 = 0;
	int end = 1, b;
	
	while(end) {
		printf("Unesite elemente prvog skupa: ");
		while(1) {
			scanf("%d", &b);
			if((b < 0) || (b >= MAX_SKUP)) break;
			skup1 |= 1 << b;
		}
		
		printf("Unesite elemente drugog skupa: ");
		while(1) {
			scanf("%d", &b);
			if((b < 0) || (b >= MAX_SKUP)) break;
			skup2 |= 1 << b;
		}
		
		if(skup1 == skup2)
			printf("Skupovi su jednaki!\n");
		else
			printf("Skupovi nisu jednaki!\n");
		
		printf("0 za kraj, 1 za nastavak: ");
		scanf("%d", &end);
	}
}