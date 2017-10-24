

#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void test_debug()
{
    debug("I have brown hair."); 
    debug("I am %d years old.", 37);
}

void test_log_err()
{
    log_err("I believe everything is broken"); 
    log_err("There are %d problems in %s.", 0, "space");

}


int main(int argc, char** argv)
{
    test_debug();
    test_log_err();
    printf("%d\n", UINT32_MAX);
}


