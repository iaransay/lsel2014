#include "../../Interpreter/interp.h"
#include <stdlib.h>

void setup_logger(void)
{
   interp_addcmd("log", logger_cmd, "Print in a file.\n");
}

int logger_cmd(char* arg)
{
   logger_new(arg);
   return 0;
}

logger_t* logger_new(const char* filename)
{
   logger_t* logger = (logger_t*) malloc(sizeof(logger_t));
   logger_init(logger, filename);
   return logger;
}

void logger_init(logger_t* logger, const char* filename)
{
   observer_init((observer_t*) logger, logger_notify);
   (*logger).file = fopen(filename, "a");
}

void logger_notify(observer_t* observer, observable_t* observable)
{
   train_t* train = (train_t*) ((void*) observable - sizeof(observer_t));
   // train_t* train = (train_t*) model_get_observable("Diesel");
   fprintf((*observer).file, "Tren %d en sector %d\n", train->ID, train->telemetry->sector);
}
