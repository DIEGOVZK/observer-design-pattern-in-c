#include "unity.h"
#include "observer.h"

ConcreteObserver observer;
ConcreteSubject subject;

void setUp(void)
{
    observer.base.update = (void (*)(const char *))update;
    observer.base.update = update;
    subject.base.attach = attach;
    subject.base.detach = detach;
    subject.observerCount = 0;
}

void tearDown(void)
{
}

void test_update_function_not_null(void)
{
    TEST_ASSERT_NOT_NULL(observer.base.update);
}

void test_attach_function_increases_count(void)
{
    subject.base.attach((struct Subject *)&subject, &observer.base);
    TEST_ASSERT_EQUAL_INT(1, subject.observerCount);
}

void test_attach_function_adds_observer(void)
{
    subject.base.attach((struct Subject *)&subject, &observer.base);
    TEST_ASSERT_EQUAL_PTR(&observer.base, subject.observers[0]);
}

void test_detach_function(void)
{
    subject.base.attach((struct Subject *)&subject, &observer.base);
    subject.base.detach((struct Subject *)&subject, &observer.base);
    TEST_ASSERT_EQUAL_INT(0, subject.observerCount);
}

void test_update_function(void)
{
    observer.base.update("Test Event");
    // Since the update function prints to the console,
    // I can at least make sure it doesn't crash when called.
    TEST_ASSERT_TRUE(1);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_update_function_not_null);
    RUN_TEST(test_attach_function_increases_count);
    RUN_TEST(test_attach_function_adds_observer);
    RUN_TEST(test_detach_function);
    RUN_TEST(test_update_function);
    return UNITY_END();
}