#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int valid_key(string arg[]);

int main(int argc, string argv[])
{
    int code_number;
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        code_number = valid_key(argv);
        if (code_number == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            string original_message = get_string("plaintext: ");
            int len_message = strlen(original_message);
            int array_code[len_message];
            
            if (code_number > 27)
            {
                code_number = code_number % 26;
            }
            
            for (int i = 0; i < len_message; i++)
            {
                int original_ord = original_message[i];
                
                if (original_ord >= 65 && original_ord <= 90)
                {
                    int new_ord = original_ord + code_number;
                    
                    if (new_ord > 90)
                    {
                        int overflow = new_ord - 90;
                        new_ord = 64 + overflow;
                    }
                    
                    array_code[i] = new_ord;
                }
                else if (original_ord >= 97 && original_ord <= 122)
                {
                    int new_ord = original_ord + code_number;
                    
                    if (new_ord > 122)
                    {
                        int overflow = new_ord - 122;
                        new_ord = 96 + overflow;
                    }
                    
                    array_code[i] = new_ord;            
                }
                else
                {
                    array_code[i] = original_ord;
                    
                }
            }
            
            printf("ciphertext: ");
            for (int i = 0; i < len_message; i++)
            {
                printf("%c", array_code[i]);
            }
            printf("\n");
        }
        return 0;
    }
}

// check for valid key (function defined below, note that return value switches and is not intuitive!!)

int valid_key(string arg[])
{
    int final_key; 
    
    for (int i = strlen(arg[1]) - 1; i >= 0; i--)
    {
        if (arg[1][i] >= 48 && arg[1][i] <= 57)
        {
            final_key = atoi(&arg[1][i]);
        }
        else
        {
            return 0;
        }
    }
    return final_key;
}  
