
#ifndef SYSCALL_ERROR
#define SYSCALL_ERROR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


#define SYSCALL_EXIT_EQ( name, r, sc, ve, str ) \
    if((r = (sc)) == ve){                       \
        perror(#name);                          \
        int errno_copy = errno;                 \
        print_error(str);                       \
        exit(errno_copy);                       \
    }

#define SYSCALL_EXIT_NEQ( name, r, sc, ve, str ) \
    if((r = (sc)) != ve){                       \
        perror(#name);                          \
        int errno_copy = errno;                 \
        print_error(str);                       \
        exit(errno_copy);                       \
    }


#define SYSCALL_RETURN_EQ( name, r, sc, ve, str ) \
    if((r = (sc)) == ve){                       \
        perror(#name);                          \
        int errno_copy = errno;                 \
        print_error(str);                       \
        errno = errno_copy;                     \
        return r;                               \
    }


#define SYSCALL_RETURN_NEQ( name, r, sc, ve, str ) \
    if((r = (sc)) != ve){                       \
        perror(#name);                          \
        int errno_copy = errno;                 \
        print_error(str);                       \
        errno = errno_copy;                     \
        return r;                               \
    }


#define SYSCALL_RETURN_VAL_EQ( name, r, sc, ve, vr, str ) \
    if((r = (sc)) == ve){                       \
        perror(#name);                          \
        int errno_copy = errno;                 \
        print_error(str);                       \
        errno = errno_copy;                     \
        return vr;                              \
    }


#define SYSCALL_RETURN_VAL_NEQ( name, r, sc, ve, vr, str ) \
    if((r = (sc)) != ve){                       \
        perror(#name);                          \
        int errno_copy = errno;                 \
        print_error(str);                       \
        errno = errno_copy;                     \
        return vr;                              \
}


#define SYSCALL_PRINT_EQ( name, r, sc, ve, str ) \
    if((r = (sc)) == ve){                       \
        perror(#name);                          \
        int errno_copy = errno;                 \
        print_error(str);                       \
        errno = errno_copy;                     \
    }


#define SYSCALL_PRINT_NEQ( name, r, sc, ve, str ) \
    if((r = (sc)) != ve){                       \
        perror(#name);                          \
        int errno_copy = errno;                 \
        print_error(str);                       \
        errno = errno_copy;                     \
    }

/**
* Brief utility procedure for printing errors
*
* @params str : string containing the number to extract
* @params ... : any other arguments to the print errors function
*/
static inline void print_error( const char* str ){
    const char err[] = "ERROR: ";
    //va_list argp;
    char* p = (char *) malloc(strlen(str) + strlen(err) + EXTRA_LEN_PRINT_ERROR);
    if(!p){
        perror("malloc");
        fprintf(stderr, "FATAL ERROR: in function 'print_error' \n");
        return;
    }
    strcpy(p, err);
    strcpy(p + strlen(err), str);
    //va_start(argp, str);
    //vfprintf(stderr, p, argp);
    //va_end(argp);
    free(p);
}

#endif /* SYSCALL_ERROR */
