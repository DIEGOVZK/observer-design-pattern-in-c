#include "unity.h"
#include "wordCounter.h"

const char *sentence;
const char *sentence2;
const char *sentence3;
const char *sentence4;
const char *sentence5;

void setUp(void)
{
    sentence = "This is a test sentence.";
    sentence2 = "     ";
    sentence3 = "1234567890";
    sentence4 = NULL;
}

void tearDown(void)
{
}

void test_countTotalWords(void)
{
    TEST_ASSERT_EQUAL_INT(5, countTotalWords(sentence));
}

void test_countEvenLengthWords(void)
{
    TEST_ASSERT_EQUAL_INT(2, countEvenLengthWords(sentence));
}

void test_countCapitalStartWords(void)
{
    TEST_ASSERT_EQUAL_INT(1, countCapitalStartWords(sentence));
}

void test_countTotalWords_adverse(void) {
    TEST_ASSERT_EQUAL_INT(0, countTotalWords(sentence4));
}

void test_countEvenLengthWords_adverse(void) {
    TEST_ASSERT_EQUAL_INT(0, countEvenLengthWords(sentence2));
}

void test_countCapitalStartWords_adverse(void) {
    TEST_ASSERT_EQUAL_INT(0, countCapitalStartWords(sentence3));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_countTotalWords);
    RUN_TEST(test_countEvenLengthWords);
    RUN_TEST(test_countCapitalStartWords);
    RUN_TEST(test_countTotalWords_adverse);
    RUN_TEST(test_countEvenLengthWords_adverse);
    RUN_TEST(test_countCapitalStartWords_adverse);
    return UNITY_END();
}