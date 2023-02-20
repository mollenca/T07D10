#include <stdio.h>
#include <stdlib.h>

void output(int *a, int n);

int main() {
    int n, m;
    int **a = NULL;
    int A[100][100];
    int ch = 0;
    int ch1 = 0;
    int c;
    scanf("%d", &c);
    switch (c) {
        case 1:
            ch = scanf("%d%d", &n, &m);
            if (ch != 2 || (n > 100 || m > 100)) {
                printf("n/a");
                return 0;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ch1 = scanf("%d", &A[i][j]);
                    if (ch1 != 1 || (n > 100 || m > 100)) {
                        printf("n/a");
                        return 0;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                output(*(A + i), m);
                printf("\n");
            }
            break;
        case 2:
            ch = scanf("%d%d", &n, &m);
            if (ch != 2 || (n > 100 || m > 100)) {
                printf("n/a");
                break;
            }
            a = (int **)malloc(n * sizeof(int *));
            for (int i = 0; i < n; i++) {
                a[i] = (int *)malloc(m * sizeof(int));
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ch1 = scanf("%d", &A[i][j]);
                    if (ch1 != 1 || (n > 100 || m > 100)) {
                        printf("n/a");
                        return 0;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                output(*(A + i), m);
                printf("\n");
            }

            for (int i = 0; i < m; i++) {
                free(a[i]);
            }
            free(a);
            break;
        case 3:
            ch = scanf("%d%d", &n, &m);
            if (ch != 2 || (n > 100 || m > 100)) {
                printf("n/a");
                return 0;
            }

            a = (int **)malloc(m * sizeof(int));
            a[0] = (int *)malloc(m * n * sizeof(int));
            for (int i = 0; i < m; i++) {
                a[i] = a[0] + i * n;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ch1 = scanf("%d", &A[i][j]);
                    if (ch1 != 1 || (n > 100 || m > 100)) {
                        printf("n/a");
                        return 0;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                output(*(A + i), m);
                printf("\n");
            }

            free(a[0]);
            free(a);
            break;
        case 4:
            ch = scanf("%d%d", &n, &m);
            if (ch != 2 || (n > 100 || m > 100)) {
                printf("n/a");
                return 0;
            }

            a = (int **)malloc(m * sizeof(int *) + m * n * sizeof(int));
            a[0] = (int *)(a + m);
            for (int i = 0; i < m; i++) {
                a[i] = a[0] + i * n;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    scanf("%d", &A[i][j]);
                }
            }
            for (int i = 0; i < n; i++) {
                output(*(A + i), m);
                printf("\n");
            }

            free(a);
            break;
        default:
            printf("n/a");
            break;
    }
}

void output(int *a, int n) {
    if (n == 0) {
        return;
    }
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}