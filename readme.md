# Oscilador numérico (NCO)

Este proyecto contiene la implementación básica de un oscilador controlado numéricamente que genera muestras enteras complejas de 16 bit. Se basa en la actualización
$$A_{k+1}=\operatorname{truncar}{\left(\frac{A_{k}\operatorname{truncar}{\left(2^{16}\operatorname{e}^{-j2\pi \frac{f_{c}}{f_{s}}}\right)}}{2^{16}}\right)}$$
donde $f_{s}$ es la frecuencia de muestreo y $f_{c}$ la frecuencia portadora. Desarrollando partes real e imaginaria quedará
$$\begin{aligned}
A_{\text{re},k+1}&=\operatorname{truncar}{\left(\frac{A_{\text{re},k}b_{\text{re}}}{2^{16}}\right)}-\operatorname{truncar}{\left(\frac{A_{\text{im},k}b_{\text{im}}}{2^{16}}\right)}\\
A_{\text{im},k+1}&=\operatorname{truncar}{\left(\frac{A_{\text{re},k}b_{\text{im}}}{2^{16}}\right)}+\operatorname{truncar}{\left(\frac{A_{\text{im},k}b_{\text{re}}}{2^{16}}\right)}
\end{aligned}$$
donde
$$\begin{aligned}
b_{\text{re}}}&=\operatorname{truncar}{\left(2^{16} \cos{\left(2\pi\frac{f_{c}}{f_{s}}}\right)}\\[.5em]
b_{\text{im}}}&=-\operatorname{truncar}{\left(2^{16} \operatorname{sen}{\left(2\pi\frac{f_{c}}{f_{s}}}\right)}\\[.5em]
A_{\text{re},0}&=2^{15}-1\\
A_{\text{im},0}&=0
\end{aligned}$$

Además, para compensar los errores debidos a la precisión finita siempre que la parte real (imaginaria) resulte cero, la parte imaginaria (real) se establecerá en $\pm(2^{15}-1)$ según sea esta positiva o negativa.

El cálculo de $b$ se realiza utilizando aritmética de punto flotante al configurar el oscilador, durante el funcionamiento del mismo se utiliza siempre aritmética entera. El oscilador está pensado para su uso en la implementación de translación de frecuencia en procesadores embebidos con soporte para producto entero de 32 bit.
