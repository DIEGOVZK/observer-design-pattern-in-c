#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include "observer.h"

/**
 * @brief Counts the number of words in a sentence and notifies the observers.
 * @param subject The subject that will notify the observers.
 * @param sentence The sentence in which to count the words.
 */
void countWords(Subject *subject, const char *sentence);

#endif //WORD_COUNTER_H