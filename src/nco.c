#include "nco.h"

#include <stdlib.h>

struct Nco_s {
    int16_t real;
    int16_t imag;
};

// fs = 3e6/17
// fc = 30e3
// fc/fs = 17e-2
// wc=2*\pi*0.17
//
// round(2**16 * exp(-jwc)) -> 31562 -j57430

static const int32_t bReal = 31572L;
static const int32_t bImag = -57429L;

Nco Nco_create(void)
{
    Nco inst = malloc(sizeof(*inst));
    if (inst) *inst = (struct Nco_s){.real = INT16_MAX};
    return inst;
}
void Nco_tick(Nco self)
{
    int32_t auxReal, auxImag;
    auxReal = ((bReal * self->real) >> 16) - ((bImag * self->imag) >> 16);
    auxImag = ((bReal * self->imag) >> 16) + ((bImag * self->real) >> 16);
    if (!auxImag) auxReal = auxReal >= 0 ? INT16_MAX : -INT16_MAX;
    else if (!auxReal) auxImag = auxImag >= 0 ? INT16_MAX : -INT16_MAX;
    self->real = (int16_t)auxReal;
    self->imag = (int16_t)auxImag;
}
int16_t Nco_getReal(Nco self)
{
    return self->real;
}
int16_t Nco_getImag(Nco self)
{
    return self->imag;
}
