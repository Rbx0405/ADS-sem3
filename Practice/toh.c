#include <stdio.h>
#include <stdlib.h>

void towerOfHanoiHelper(int n, char from_rod, char to_rod, char aux_rod);
void towerOfHanoi(int n) { towerOfHanoiHelper(n, 'A', 'C', 'B'); }
void towerOfHanoiHelper(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from tower [%c] to [%c]\n", from_rod, to_rod);
        return;
    }
    towerOfHanoiHelper(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from tower [%c] to [%c]\n", n, from_rod, to_rod);
    towerOfHanoiHelper(n - 1, aux_rod, to_rod, from_rod);
}
int main()
{
    int n;
    printf("no of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n);
    return 0;
}
