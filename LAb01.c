 #include <stdio.h>
#include <string.h>
int patternMatching(char T[], char P[]) {
    int S = strlen(T);
    int R = strlen(P);
    int K = 0;
    int MAX = S - R + 1;
  while (K < MAX) {
        int L;
        for (L = 0; L < R; L++) {
            if (P[L] != T[K + L]) {
                break;
            }
        }
        if (L == R) {
            return K + 1;  // Return 1-based index
        }
        K++;
    }    return 0;
}
int main() {
    char T[100], P[100]; // Assuming the strings are not longer than 100 characters.
    printf("Enter the main string (T): ");
    scanf("%s", T);
    printf("Enter the pattern string (P): ");
    scanf("%s", P);
    int index = patternMatching(T, P);
   if (index == 0) {
        printf("Pattern not found in the main string.\n");
    } else {
        printf("Pattern found at position: %d\n", index);
    }
   return 0;
}
