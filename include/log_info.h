#ifndef _LOG_INFO_H_
#define _LOG_INFO_H_

#include "config.h"

#define LOG_ARGS                                        \
    __FILE__, __PRETTY_FUNCTION__, __LINE__

#ifdef ERR_REPORTS

    #define Print_error(error)                         \
        _Print_error (LOG_ARGS, (error));

#else

    #define Print_error(error)) 

#endif
int Open_logs_file ();

int _Print_error (const char *file_name, const char *func_name, int line, int error);

const char* Process_error(int error);

int Close_logs_file ();

#endif