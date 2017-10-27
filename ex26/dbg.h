
#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef DEBUG
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%s:%d: " M "\n", \
            __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, \
    "[ERROR] (%s:%s:%d errno: %s) " M "\n", __FILE__, __FUNCTION__, __LINE__, \
    clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, \
    "[WARN] (%s:%s:%d errno: %s) " M "\n", \
    __FILE__, __FUNCTION__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, \
    "[INFO] (%s:%s:%d:%s errno: %s) " M "\n", \
    __FILE__, __FUNCTION__,  __LINE__, clean_errno(), ##__VA_ARGS__)

#define check(A, M, ...) if (!(A)) { \
        log_err(M, ##__VA_ARGS__); errno=0; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); \
        errno=0; }
#else
#define debug(M, ...)
#define clean_errno()

#define log_err(M, ...)
#define log_warn(M, ...)
#define log_info(M, ...)
#define check(A, M, ...)
#define check_mem(A)
#define check_debug(A, M, ...) 

#endif

#endif
