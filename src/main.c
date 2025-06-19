#include <stdio.h>

#include "nco.h"

#define NSAMPLES 100000

int main(void)
{
    Nco nco = Nco_create();
    for (int i = 0; i < NSAMPLES; ++i) {
        printf("%d\t%d\n", Nco_getReal(nco), Nco_getImag(nco));
        Nco_tick(nco);
    }
    return 0;
}

