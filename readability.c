#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

float count_of_letters(string chrctrs);
float count_of_words(string chrctrs);
float count_of_sentances(string chrctrs);
float score(float lets, float wrds, float sents);

int main(void)
{
    string user_input = get_string("Text: \n");
    
    // count characters in user input
    float letters = count_of_letters(user_input);
    
    //count words in user input
    float words = count_of_words(user_input);
    
    //count sentances in user input
    float sentances = count_of_sentances(user_input);
    
    
    int answer = round(score(letters, words, sentances));
    
    if (answer>= 16)
    {
        printf("Grade 16+\n");
    }
    else if (answer < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", answer);
    }
}

float count_of_letters(string chrctrs)
{
    float letter_count = 0;
    
    for (int i=0, s = strlen(chrctrs); i< s; i++)
    {
        float temp = chrctrs[i];
        
        if (temp >= 65 && temp <= 90)
        {
            letter_count++;
        }
        else if (temp >= 97 && temp <= 122)
        {
            letter_count++;
        }
        
    }
    
    return letter_count;
}

float count_of_words(string chrctrs)
{
    float word_count = 1;
    
    for (int i=0, s = strlen(chrctrs); i< s; i++)
    {
        int temp = chrctrs[i];
        
        if (temp == 32)
        {
            word_count++;
        }
        
    }
    
    return word_count;
}

float count_of_sentances(string chrctrs)
{
    float sent_count = 0;
    
    for (int i=0, s = strlen(chrctrs); i< s; i++)
    {
        int temp = chrctrs[i];
        
        if (temp == 33 || temp == 46 || temp == 63)
        {
            sent_count++;
        }
        
    }
    
    return sent_count;
}

float score(float lets, float wrds, float sents)
{
    float index;
    
    float L = (lets/wrds)*100;
    float S = (sents/wrds)*100;
    
    index = 0.0588 * L - 0.296 * S - 15.8;
    
    return index;
}
