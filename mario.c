#include <cs50.h>
#include <stdio.h>
#include <string.h>

void mario(int n);
int get_pos(void);

int main(void)
{

    int n = get_pos();
    mario(n);
}

void mario(int n)
{
// for each row until number n is reached
    for (int i = 1; i < n + 1; i++)
    {
// print blank spaces such that one less than height n is printed for first row and one less space is printed each row after that
        for (int h = n - i; h > 0; h--)
        {
            printf(" ");
        }
///then print hashtags such that one hashtag is printed for the first row and one additional hashtag printed for each row after that 
        for (int j = i; j > 0; j--)
        {
            printf("#");
        }
///print two blank spaces on each line for all lines through height n
        printf("  ");
/// repeat hashtag loop to print corresponding pyramid on opposite side 
        for (int j = i; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_pos(void)
{
    int n;
    do 
    {
        (n = get_int("Height:  "));
    }
    while (8 < n || n < 1);
    return n;
}
