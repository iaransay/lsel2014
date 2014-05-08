#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "observer.h"

typedef void (*actuator_notify_func_t)(observer_t*, observable_t*);

typedef struct actuator_t {
  observer_t observer;
  int id;
} actuator_t;

/*
 * Virtual class, no constructor
 */
void actuator_init (actuator_t* this, int id, actuator_notify_func_t notify);

#endif

/*
  Local variables:
    mode: c
    c-file-style: stroustrup
  End:
*/
