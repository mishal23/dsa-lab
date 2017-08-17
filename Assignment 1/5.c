/*
    Problem Statement:- Design  and implement a recussive algorithm to solve the Tower of Hanoi problem for one or more disks.
*/
#include <stdio.h>
void towerofHanoi(int, char, char, char);
int main()
{
    int num;
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towerofHanoi(num, 'A', 'C', 'B');
    return 0;
}
void towerofHanoi(int num, char fromrod, char torod, char auxrod)
{
    if (num == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", fromrod, torod);
        return;
    }
    towerofHanoi(num - 1, fromrod, auxrod, torod);
    printf("Move disk %d from rod %c to rod %c\n", num, fromrod, torod);
    towerofHanoi(num - 1, auxrod, torod, fromrod);
}
