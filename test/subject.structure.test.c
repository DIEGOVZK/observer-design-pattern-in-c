#include "unity.h"
#include "observer.h"

ConcreteSubject subject;

void setUp(void) {
    subject.base.attach = attach;
    subject.base.detach = detach;
    subject.base.notify = notify;
    subject.observerCount = 0;
}

void tearDown(void) {
}

void test_attach_function_not_null(void) {
    TEST_ASSERT_NOT_NULL(subject.base.attach);
}

void test_detach_function_not_null(void) {
    TEST_ASSERT_NOT_NULL(subject.base.detach);
}

void test_notify_function_not_null(void) {
    TEST_ASSERT_NOT_NULL(subject.base.notify);
}

void test_observer_count_zero(void) {
    TEST_ASSERT_EQUAL_INT(0, subject.observerCount);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_attach_function_not_null);
    RUN_TEST(test_detach_function_not_null);
    RUN_TEST(test_notify_function_not_null);
    RUN_TEST(test_observer_count_zero);
    return UNITY_END();
}