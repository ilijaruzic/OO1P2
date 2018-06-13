#include <stdio.h>
#define MAX 50

int main() {
	int niz_indeksi[MAX], niz_poeni[MAX] = {0};
	int i, j, n; 
	int indeks, poeni, godina, suma, broj;
	
	printf("Broj studenata? "); 
	scanf("%d", &n);
	
	if(n <= 0 || n > MAX) {
		printf("Nekorektan broj studenata.\n");
		return;
	}
	
	printf("Indeksi (ggggbbbb)? ");
	for(i = 0; i < n; i++) 
		scanf("%d", &niz_indeksi[i]);
	
	while(1) {
		printf("Indeks poeni? ");
		scanf("%d %d", &indeks, &poeni);
		
		for(j = 0; j < n; j++)
			if(niz_indeksi[j] == indeks) 
				break;
		
		if(j == n) 
			break;
			
		niz_poeni[j] += poeni;
	}
	
	printf("Godina upisa? "); 
	scanf("%d", &godina);
	
	suma = broj = 0;
	for(i = 0; i < n; i++)
		if(niz_indeksi[i]/10000 == godina){
			suma+=niz_poeni[i];
			broj++;
		}
		
	if(broj>0)
		printf("Prosecan broj poena za generaciju %d iznosi %lf", godina, (double)suma/broj);
	else
		printf("Nema podataka o generaciji %d.\n", godina);
}