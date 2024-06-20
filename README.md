<div align="center">
<h1>fractol</h1>
<img src="https://raw.githubusercontent.com/gusgonza42/my-utils-gusgonza/main/ft_badges_42/badge_01_fractol_500px.png" style="width: 150px; height: 150px;">

[![Build Status](https://img.shields.io/static/v1?label=Build%20Status&message=success&color=green)](https://github.com/gusgonza42/fractol)

</div>

- - -

## 💡 Acerca del Proyecto

> _El objetivo de este proyecto es crear un pequeño programa de exploración de fractales._

Este proyecto te permitirá explorar y visualizar fractales matemáticos como los conjuntos de Julia y Mandelbrot. Utiliza la biblioteca miniLibX para renderizar los fractales en una ventana gráfica interactiva. El programa permite la exploración de diferentes tipos de fractales mediante parámetros pasados por la línea de comandos, ofreciendo zoom y manipulación visual para una experiencia interactiva.

Para obtener información más detallada, consulta el [**Subject**](https://github.com/gusgonza42/fractol/blob/main/Fractol.es.subject.pdf).

## 🛠️ Uso

### Requisitos

El proyecto está desarrollado en C y utiliza la biblioteca miniLibX para la manipulación gráfica. Asegúrate de tener instalado miniLibX correctamente para compilar y ejecutar el programa.

### Funcionalidades Obligatorias

- Implementación de los conjuntos de Julia y Mandelbrot como fractales visuales.
- Interacción mediante zoom in y zoom out usando la rueda del ratón.
- Manipulación fluida de la ventana gráfica.
- Especificación del tipo de fractal a visualizar mediante parámetros de línea de comandos.

### Funcionalidades Opcionales (Bonus)

- Implementación de fractales adicionales (por ejemplo, el conjunto de Burning Ship).
- Interactividad mejorada como zoom que sigue la posición del ratón y navegación con flechas del teclado.
- Personalización del rango de colores utilizados para representar los fractales.

### Instrucciones

**1. Compilación**

Para compilar el proyecto, utiliza el Makefile proporcionado:

```shell
make
