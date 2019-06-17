#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char **readWords(int n) {
    char **words = (char **) calloc(n, sizeof(char *));
    if (words == NULL)
        exit(1);

    for (int i = 0; i < n; ++i) {
        if ( ( words[i] = calloc ( 21, sizeof ( char ) ) ) == NULL )
            exit(1);

        scanf("%s", words[i]);
        char *temp = (char *) realloc(words[i], strlen(words[i]) + 1);
        if (temp == NULL)
            exit (1);
        else
            words[i] = temp;
    }

    return words;
}

int isComplexNumber(char *string) {
    const char format[] = "%d%*[+-]j%d";
    int re, im;

    if (sscanf(string, format, &re, &im) == 2)
        return 1;
    else
        return 0;
}

double absoluteValue(char *complexNumber) {
    const char format[] = "%d%*[+-]j%d";
    int re, im;

    sscanf(complexNumber, format, &re, &im);

    return sqrt(re*re + im*im);
}

int main() {
    int n;

    printf("n? ");
    scanf ("%d", &n);

    printf("Numbers [format: Re%cjIm]:\n", 241);
    char **words = readWords(n);
    printf("Numbers' absolute value:\n");
    for (int i = 0; i < n; ++i) {
        if (isComplexNumber(words[i]) == 1)
            printf ("%0.2lf\n", absoluteValue(words[i]));
        else
            printf ("NaCN\n");
    }

    for (int i = 0; i < n; ++i)
        free (words[i]);
    free (words);
    
    return 0;
}