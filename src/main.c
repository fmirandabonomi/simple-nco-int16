/**********************************************************************************************************************
Copyright (c) 2025, Fernando Alberto Miranda Bonomi <fmirandabonomi@herrera.unt.edu.ar>
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the “Software”), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
**********************************************************************************************************************/

#include "nco.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    enum { DEFAULT_SAMPLES = 10 };
    if (argc == 2 && !strcmp("getSamples", argv[1])) {
        Nco nco = Nco_create(1, DEFAULT_SAMPLES);
        ComplexSample buf[DEFAULT_SAMPLES];
        Nco_getSamples(nco, buf, DEFAULT_SAMPLES);
        for (int i = 0; i < DEFAULT_SAMPLES; ++i)
            printf("%hd\t%hd\n", buf[i].real, buf[i].imag);
    } else {
        int nsamp = DEFAULT_SAMPLES;
        if (argc == 2) {
            int x = atoi(argv[1]);
            if (x > 0) nsamp = x;
        }
        Nco nco = Nco_create(30 * 17, 3000);
        for (int i = 0; i < nsamp; ++i) {
            printf("%hd\t%hd\n", Nco_getReal(nco), Nco_getImag(nco));
            Nco_tick(nco);
        }
    }
    return 0;
}
