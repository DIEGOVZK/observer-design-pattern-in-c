#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "iobserver.h"

struct Subject;  // Forward declaration

/**
 * @brief Subject (Observable) Interface
 * @param attach Function to attach an Observer to this Subject. Takes a pointer to the Subject and the Observer to attach.
 * @param detach Function to detach an Observer from this Subject. Takes a pointer to the Subject and the Observer to detach.
 * @param notify Function to notify all attached Observers of an event. Takes the event as a string.
 */
typedef struct
{
    void (*attach)(struct Subject *subject, Observer *observer);
    void (*detach)(struct Subject *subject, Observer *observer);
    void (*notify)(const char *event);
} Subject;

/**
 * @brief Concrete implementation of the Subject interface.
 * @param base The base Subject interface this struct is built on.
 * @param observers An array of pointers to the observers attached to this subject.
 * @param observerCount The number of observers currently attached to this subject.
 */
typedef struct
{
    Subject base;
    int observerCount;
    Observer *observers[10];
} ConcreteSubject;

#endif //ISUBJECT_H