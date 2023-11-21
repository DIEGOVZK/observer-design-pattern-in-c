#ifndef OBSERVER_H
#define OBSERVER_H

#include "iobserver.h"
#include "isubject.h"

/**
 * @brief Notifies the observers of a subject.
 * @param subject The subject that will notify the observers.
 * @param event The event that will be sent to the observers.
 */
void notify(Subject *subject, const char *event);

/**
 * @brief Updates the observer with an event.
 * @param event The event that will be sent to the observer.
 */
void update(const char *event);

/**
 * @brief Attaches an observer to a subject.
 * @param subject The subject that will attach the observer.
 * @param observer The observer that will be attached to the subject.
 */
void attach(Subject *subject, Observer *observer);

/**
 * @brief Detaches an observer from a subject.
 * @param subject The subject that will detach the observer.
 * @param observer The observer that will be detached from the subject.
 */
void detach(Subject *subject, Observer *observer);

#endif // OBSERVER_H