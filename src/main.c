#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordCounter.h"
#include "observer.h"

int main()
{
    ConcreteObserver observer1 = {.base = {.update = update}};
    ConcreteObserver observer2 = {.base = {.update = update}};

    ConcreteSubject subject = {.base = {.attach = attach, .detach = detach, .notify = notify},
                               .observerCount = 0};

    subject.base.attach(&subject.base, &observer1.base);
    subject.base.attach(&subject.base, &observer2.base);

    // A text snippet from the Bee Movie Script
    const char *sentence = "According to all known laws of aviation, there is no way a bee should be able to fly.\
                            Its wings are too small to get its fat little body off the ground.\
                            The bee, of course, flies anyway because bees don't care what humans think is impossible.\
                            Yellow, black. Yellow, black. Yellow, black. Yellow, black.\
                            Ooh, black and yellow!\
                            Let's shake it up a little.\
                            Barry! Breakfast is ready!\
                            Coming!\
                            Hang on a second.\
                            ...\
                            ...\
                            A little. Special day, graduation.\
                            Never thought I'd make it.\
                            Three days grade school, three days high school.\
                            Those were awkward.\
                            Three days college. I'm glad I took a day and hitchhiked around The Hive.\
                            You did come back different.\
                            Hi, Barry. Artie, growing a mustache? Looks good.\
                            Hear about Frankie?\
                            Yeah.\
                            ...";

    countWords(&subject.base, sentence);

    subject.base.detach(&subject.base, &observer1.base);
    subject.base.detach(&subject.base, &observer2.base);

    // Note that two observers are notified, 
    // so the output is printed twice

    return 0;
}