#include <stdio.h>

int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    printf("%d %d %d\n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf("%d %d %d\n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("%d %d %d\n", matriz[2][0], matriz[2][1], matriz[2][2]);
    
    return 0;
}
