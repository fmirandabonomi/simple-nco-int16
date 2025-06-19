# Oscilador numérico (NCO)

Este proyecto contiene la implementación básica de un oscilador controlado numéricamente que genera muestras enteras complejas de 16 bit. Se basa en la actualización

$$A_{k+1}=\left\lfloor\frac{A_{k}\left\lfloor 2^{16}\mathop{e}^{-j2\pi \frac{f_{c}}{f_{s}}} \right\rfloor}{2^{16}}\right\rfloor$$

donde $f_{s}$ es la frecuencia de muestreo y $f_{c}$ la frecuencia portadora. Desarrollando partes real e imaginaria quedará

$$\begin{aligned}
A_{\text{re},k+1}&=\left\lfloor\frac{A_{\text{re},k}b_{\text{re}}}{2^{16}}\right\rfloor-\left\lfloor\frac{A_{\text{im},k}b_{\text{im}}}{2^{16}}\right\rfloor\\
A_{\text{im},k+1}&=\left\lfloor\frac{A_{\text{re},k}b_{\text{im}}}{2^{16}}\right\rfloor+\left\lfloor\frac{A_{\text{im},k}b_{\text{re}}}{2^{16}}\right\rfloor
\end{aligned}$$

donde

$$\begin{aligned}
b_{\text{re}}&=\left\lfloor2^{16} \cos{\left(2\pi\frac{f_{c}}{f_{s}}\right)}\right\rfloor\\
b_{\text{im}}&=-\left\lfloor2^{16} \mathop{\mathrm{sen}}{\left(2\pi\frac{f_{c}}{f_{s}}\right)}\right\rfloor\\
A_{\text{re},0}&=2^{15}-1\\
A_{\text{im},0}&=0
\end{aligned}$$

Además, para compensar los errores debidos a la precisión finita siempre que la parte real (imaginaria) resulte cero, la parte imaginaria (real) se establecerá en $\pm(2^{15}-1)$ según sea esta positiva o negativa.

El cálculo de $b$ se realiza utilizando aritmética de punto flotante al configurar el oscilador, durante el funcionamiento del mismo se utiliza siempre aritmética entera. El oscilador está pensado para su uso en la implementación de translación de frecuencia en procesadores embebidos con soporte para producto entero de 32 bit.

## Prueba

El comando `make all` genera un ejecutable en `build/bin` y código objeto en `build/obj`, para el programa principal en `main.c`, al ejecutar dicho programa genera una tabla de valores de parte real e imaginaria por la salida estándar.

El comando `make doc` genera la documentación en `build/doc` (requiere doxygen y runtime de java)
