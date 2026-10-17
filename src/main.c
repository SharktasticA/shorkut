/*
    ######################################################
    ##              SHORK UTILITY - SHORKUT             ##
    ######################################################
    ## A system uptime source for when /proc/uptime     ##
    ## isn't available                                  ##
    ######################################################
    ## Licence: GNU GENERAL PUBLIC LICENSE Version 3    ##
    ######################################################
    ## Kali (links.sharktastica.co.uk)                  ##
    ######################################################
*/



#include <stdio.h>
#include <time.h>



#ifndef CLOCK_BOOTTIME
#define CLOCK_BOOTTIME 7
#endif

#define VERSION "1.0-wip"



static int strcmp(const char *a, const char *b)
{
    while (*a && *a == *b)
    {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}

int main(int argc, char *argv[])
{   
    if (argc == 2 && (!strcmp(argv[1], "-v") ||
        !strcmp(argv[1], "--version")))
    {
        printf("SHORKUT %s\n", VERSION);
        return 0;
    }

    struct timespec t;
    if (clock_gettime(CLOCK_BOOTTIME, &t)) return 1;
    printf("%ld.%02ld 0.00\n", (long)t.tv_sec, t.tv_nsec / 10000000);
    return 0;
}
