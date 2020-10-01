#include <stdio.h>

int main() {
    int N, M, K;
    scanf("%d%d", & N, & M);
    if (N > M)
        K = N;
    else
        K = M;
    int arr1[N + 1], arr2[M + 1], arr3[K + 1];
    for (int i = 0; i <= N; i++) {
        scanf("%d", & arr1[i]);
    }
    for (int i = 0; i <= M; i++) {
        scanf("%d", & arr2[i]);
    }
    for (int i = K; i >= 0; i--) {
        if (M - K + i < 0)
            arr3[i] = arr1[N - K + i];
        else if (N - K + i < 0)
            arr3[i] = arr2[M - K + i];
        else
            arr3[i] = arr1[N - K + i] + arr2[M - K + i];
    }
    for (int i = 0; i <= K; i++) {
        printf("%d ", arr3[i]);
    }
}
