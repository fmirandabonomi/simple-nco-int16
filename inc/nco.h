#ifndef NCO_H
#define NCO_H

#include <stdint.h>

/**
 * @brief Oscilador de control numérico
 */
typedef struct Nco_s *Nco;

/**
 * @brief Crea un oscilador de control numérico
 * @retval Nco El oscilador
 * @retval NULL Si no pudo crearlo
 */
Nco Nco_create(void);

/**
 * @brief Ejecuta un paso de un oscilador de control numérico
 * @param self El oscilador
 */
void Nco_tick(Nco self);

/**
 * @brief Obtiene la parte real de la muestra actual
 * @param self El oscilador
 * @return int16_t Parte real actual
 */
int16_t Nco_getReal(Nco self);

/**
 * @brief Obtiene la parte imaginaria de la muestra actual
 * @param self El oscilador
 * @return int16_t Parte imaginaria
 */
int16_t Nco_getImag(Nco self);

#endif // NCO_H
