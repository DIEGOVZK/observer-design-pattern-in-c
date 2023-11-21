#include "observer.h"
#include <stdio.h>

void notify(Subject *subject, const char *event)
{
    ConcreteSubject *concreteSubject = (ConcreteSubject *)subject;

    for (int i = 0; i < concreteSubject->observerCount; ++i)
    {
        concreteSubject->observers[i]->update(event);
    }
}

void update(const char *event)
{
    printf("Observer received event: %s\n", event);
}

void attach(Subject *subject, Observer *observer)
{
    ConcreteSubject *concreteSubject = (ConcreteSubject *)subject;

    if (concreteSubject->observerCount < 10)
    {
        concreteSubject->observers[concreteSubject->observerCount++] = observer;
    }
}

void detach(Subject *subject, Observer *observer)
{
    ConcreteSubject *concreteSubject = (ConcreteSubject *)subject;

    for (int i = 0; i < concreteSubject->observerCount; ++i)
    {
        if (concreteSubject->observers[i] == observer)
        {
            // Remove observer by shifting elements
            for (int j = i; j < concreteSubject->observerCount - 1; ++j)
            {
                concreteSubject->observers[j] = concreteSubject->observers[j + 1];
            }
            concreteSubject->observerCount--;
            break;
        }
    }
}