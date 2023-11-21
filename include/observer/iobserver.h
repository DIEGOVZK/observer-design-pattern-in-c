#ifndef OBSERVER_IOBSERVER_H
#define OBSERVER_IOBSERVER_H

/**
 * @brief Observer Interface
 * @param update Function to update the Observer with an event. Takes the event as a string.
 */
typedef struct
{
    void (*update)(const char *event);
} Observer;

/**
 * @brief Concrete implementation of the Observer interface.
 * @param base The base Observer interface this struct is built on.
 */
typedef struct
{
    Observer base;
} ConcreteObserver;

#endif //OBSERVER_IOBSERVER_H