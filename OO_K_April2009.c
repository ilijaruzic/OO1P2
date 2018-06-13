#include <stdio.h>
#define MAX 20

int main() {
	int a[MAX], n, b, i, ind;
	
	n = 0;
	while(n<MAX) {
		printf("\nUnesite broj: ");
		scanf("%d", &b);
		
		if(b<0) break;
			
		for(i = ind = 0; i < n || a[i] < b; i++)
			if(a[i] == b)
				ind = 1;
		
		if(ind) continue;
			
		for(i = n-1; i >= 0 && a[i]<b; i--)
			a[i+1] = a[i];
		a[i+1] = b;
		
		n++;
	}
	
	printf("\nUneti niz: ");
	for(i = 0; i < n; i++) 
		printf("%d ", a[i]);
}
