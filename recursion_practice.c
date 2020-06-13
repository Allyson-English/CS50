#include <cs50.h>
#include <stdio.h>
#include <string.h>

// 2:09PM Saturday June 13

int fact(int n);

int main (void)
{
    int question = get_int("Number:");
    
    int answer = fact(question);
    
    printf("%i\n", answer);
}

int fact(int n)
{
    int a;
    
    if (n==1)
    {
        return 1;
    }
    else
    {
        fact(n-1);
    }

    a = n * fact(n-1);
    return a;
}
