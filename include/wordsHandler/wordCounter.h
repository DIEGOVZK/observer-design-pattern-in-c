#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include "observer.h"

/**
 * @brief Counts the number of words in a sentence.
 * @param sentence The sentence in which to count the words.
 * @return The number of words in the sentence.
 */
int countTotalWords(const char *sentence);

/**
 * @brief Counts the number of words in a sentence that have an even length.
 * @param sentence The sentence in which to count the words.
 * @return The number of words in the sentence that have an even length.
 */
int countEvenLengthWords(const char *sentence);

/**
 * @brief Counts the number of words in a sentence that start with a capital letter.
 * @param sentence The sentence in which to count the words.
 * @return The number of words in the sentence that start with a capital letter.
 */
int countCapitalStartWords(const char *sentence);

/**
 * @brief Counts the number of words in a sentence and notifies the observers.
 * @param subject The subject that will notify the observers.
 * @param sentence The sentence in which to count the words.
 */
void countWords(Subject *subject, const char *sentence);

#endif //WORD_COUNTER_H