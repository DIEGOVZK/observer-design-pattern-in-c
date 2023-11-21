#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Observer Interface
typedef struct {
    void (*update)(const char* event);
} Observer;

// Subject (Observable) Interface
typedef struct {
    void (*attach)(Observer* observer);
    void (*detach)(Observer* observer);
    void (*notify)(const char* event);
} Subject;

int main ()
{
    
}