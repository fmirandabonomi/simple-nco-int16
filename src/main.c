#include <stdio.h>

#include "nco.h"

#define NSAMPLES 10000

int main(void)
{
    Nco nco = Nco_create();
    for (int i = 0; i < NSAMPLES; ++i) {
        printf("%hd\t%hd\n", Nco_getReal(nco), Nco_getImag(nco));
        Nco_tick(nco);
    }
    return 0;
}

