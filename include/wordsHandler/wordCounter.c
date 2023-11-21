#include "wordCounter.h"
#include <stdio.h>
#include <ctype.h>

void countWords(Subject *subject, const char *sentence)
{
    int totalWords = countTotalWords(sentence);
    int evenLengthWords = countEvenLengthWords(sentence);
    int capitalStartWords = countCapitalStartWords(sentence);

    // Notify observers
    char event[100];
    sprintf(event, "Total words: %d, Even length words: %d, Capital start words: %d",
            totalWords, evenLengthWords, capitalStartWords);
    notify(subject, event);
}

int countTotalWords(const char *sentence)
{
    int totalWords = 0;
    int isWord = 0;

    if (sentence == NULL)
    {
        return 0;
    }
    
    for (const char *ptr = sentence; *ptr; ++ptr)
    {
        if (isalpha((unsigned char)*ptr))
        {
            isWord = 1;
        }
        else if (isspace((unsigned char)*ptr) || *(ptr + 1) == '\0')
        {
            if (isWord)
            {
                totalWords++;
                isWord = 0;
            }
        }
    }
    return totalWords;
}

int countEvenLengthWords(const char *sentence)
{
    int evenLengthWords = 0;
    int wordLength = 0;
    int isWord = 0;
    for (const char *ptr = sentence; *ptr; ++ptr)
    {
        if (isalpha((unsigned char)*ptr))
        {
            wordLength++;
            isWord = 1;
        }
        else
        {
            if (isWord)
            {
                if (wordLength % 2 == 0)
                {
                    evenLengthWords++;
                }
                wordLength = 0;
                isWord = 0;
            }
        }
    }
    if (isWord && wordLength % 2 == 0)
    {
        evenLengthWords++;
    }
    return evenLengthWords;
}

int countCapitalStartWords(const char *sentence)
{
    int capitalStartWords = 0;
    int wordLength = 0;
    for (const char *ptr = sentence; *ptr; ++ptr)
    {
        if (isalpha((unsigned char)*ptr))
        {
            wordLength++;
            if (wordLength == 1)
            {
                if (isupper((unsigned char)*ptr))
                {
                    capitalStartWords++;
                }
            }
        }
        else
        {
            wordLength = 0;
        }
    }
    return capitalStartWords;
}