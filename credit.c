#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int get_num_length(long n);
int *num_arr(long n, int clen);
int num_prods(int *p, int clen);
int num_sum(int *p, int clen);
string card_type(int *p, int clen);

int main(void)
{
    long cc_num = get_long("Number:  ");
    int len = get_num_length(cc_num);
    int cc_arr[len - 1];
    int *t = num_arr(cc_num, len);
    
    int dig_sum_prods = num_prods(t, len);
    int dig_sum = num_sum(t, len);
    
    int final_sum = dig_sum + dig_sum_prods;
    if (final_sum % 10 == 0)
    {
        string final = card_type(t, len);
        printf("%s\n", final);
    }
    else
    {
        printf("INVALID\n");
    }
    
}

// // This number accepted the user input number, which comes in the form of a long, and identifies the length of the number using the /10 tecnique. 
int get_num_length(long n) 
{
    int cc_length = 0;
    while (n > 0)
    {
        n = n / 10;
        cc_length++;
    }
    return cc_length;
}

// // The number is recieved in the form of a long, this function takes the long and the length of the string and iteratively isolates each digit from the long
// // using the %10 technique.
// // The function returns the position of the array in the computer's memory as a pointer 
int *num_arr(long n, int clen)
{
    int temp;
    int pos = 0;
    int cs[clen - 1];
    while (n > 0)
    {
        temp = n % 10;
        cs[pos] = temp;
        pos++;
        n = floor(n / 10);
    }
    int *p = cs;
    return p;
    
}

// // This function takes the location of the number array (p) and the length of the array (clen) 
// // The number array is coded into place backwards so, starting with position one in the array (which corresponds with the second to last number) the array 
// // counts up by two until it reaches position (length of array - 1). 
// // The function then uses %10 and /10 to seperate the digits from each number and adds them to 'count' which is returned as the sum of digits the product of 
// // every number mutliplied by two starting with the second to last number.

int num_prods(int *p, int clen)
{
    float count = 0;
    
    for (int j = 1; j <= clen - 1; j += 2) 
    {
        int n;
        n = p[j];
        if ((n * 2) / 10 > 0)
        {
            count += floor(n * 2 / 10);
            count += n * 2 % 10;
        }
        else
        {
            count += n * 2 % 10 ;
        }
    }
    return count;
}

int num_sum(int *p, int clen)
{
    float count = 0;
    
    for (int j = 0; j <= clen - 1; j += 2) 
    {
        int n;
        n = p[j];
        count += n;
    }
    return count;
}

// Type of card
string card_type(int *p, int clen)
{
    string type;
    // printf("Length: %i\n", clen);
    if (clen == 15)
    {
        if (p[clen - 1] == 3)
        {
            if (p[clen - 2] == 4 || p[clen - 2] == 7)
            {
                type = "AMEX";
            }
            else
            {
                type = "INVALID";
            }
        }
        else 
        {
            type = "INVALID";
        }
    }
    else if (clen == 13)
    {
        type = "VISA";
    }
    else if (clen == 16)
    {
        if (p[clen - 1] == 4)
        {
            type = "VISA";
        }
        else if (p[clen - 2] <= 5 && p[clen - 2] >= 1)
        {
            type = "MASTERCARD";
        }
        else
        {
            type = "INVALID";
        }
    }
    else 
    {
        type = "INVALID";
    }
    return type;
}
