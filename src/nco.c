#include "nco.h"

#include <stdlib.h>

struct Nco_s {
    int64_t real;
    int64_t imag;
};

static const int64_t bReal = 2069116275L;
static const int64_t bImag = -3763708532L;

Nco Nco_create(void)
{
    Nco inst = malloc(sizeof(*inst));
    if (inst) *inst = (struct Nco_s){.real = INT32_MAX};
    return inst;
}
void Nco_tick(Nco self)
{
    int64_t auxReal, auxImag;
    auxReal    = bReal * self->real - bImag * self->imag;
    auxImag    = bReal * self->imag + bImag * self->real;
    self->real = auxReal >> 32;
    self->imag = auxImag >> 32;
}
int32_t Nco_getReal(Nco self)
{
    return self->real;
}
int32_t Nco_getImag(Nco self)
{
    return self->imag;
}

