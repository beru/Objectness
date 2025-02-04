#pragma once

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int gettimeofday(struct timeval *tv, struct timezone *tz);

#include <time.h>
#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
struct timeval {
    long tv_sec;
    long tv_usec;
};
#endif /* _TIMEVAL_DEFINED */

#ifdef __cplusplus
}
#endif /* __cplusplus */
