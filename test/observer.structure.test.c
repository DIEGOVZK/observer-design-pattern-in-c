#include "unity.h"
#include "observer.h"

ConcreteObserver observer;

void setUp(void) {
    observer.base.update = (void (*)(const char *))update;
}

void tearDown(void) {
}

void test_update_function_not_null(void) {
    TEST_ASSERT_NOT_NULL(observer.base.update);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_update_function_not_null);
    return UNITY_END();
}