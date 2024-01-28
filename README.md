# Proyecto Sobel

Este proyecto consiste en un programa que acepta una imagen como entrada, aplica el filtro Sobel y guarda el resultado en un nuevo archivo. 

Dada la prohibición de usar OpenCV excepto para la lectura/escritura de imágenes, se ha creado la clase Mat utilizando template, para simular la clase Mat de OpenCV.

Para la implementación del Sobel, se ha creado una función que realiza convolución sobre imagen y la propia función sobel, que crea el kernel con los parámetros de entrada y llama a esta función convolución.

La función sobel ha sido modelada siguiendo la llamada a la función correspondiente en OpenCV, de manera que comparte los mismos parámetros de entrada, tal como se describe en la [documentación de OpenCV](https://docs.opencv.org/3.4/d2/d2c/tutorial_sobel_derivatives.html).

Para la implementación de este ejercicio, se ha utilizado [Wikipedia](https://en.wikipedia.org/wiki/Kernel_(image_processing)) y otros foros de ayuda como [StackOverflow](https://stackoverflow.com).

## Estructura del Proyecto

- **external-libs/image-ps/:** Submodulo que contiene la implementación de la clase `Mat` y las funciones de operaciones.
  - `mat.h`: Definición de la clase `Mat`.
  - `mat.cpp`: Implementación de la clase `Mat`.
  - `operations.h`: Declaración de las funciones `convolution2D` y `sobel`.
  - `operations.cpp`: Implementación de las funciones `convolution2D` y `sobel`.

- **src/main.cpp:** Archivo principal que lee una imagen, aplica el filtro Sobel y guarda el resultado.

## Clonar proyecto

Para clonar el proyecto es necesario clonar también los submódulos. Para ello, ejecutar:
```
git clone --recursive https://github.com/NikoConn/sobel-ps.git
```

## Compilación

Para compilar es necesario tener opencv instalado. En el directorio raiz de este repo ejecuta:
```
mkdir build && cd build && cmake .. && make
```

## Uso

Ejecuta el programa proporcionando la imagen de entrada y el nombre del archivo de salida como argumentos de la línea de comandos:

```
./sobel <imagen_entrada> <imagen_salida>
```

### Ejemplo:

```
./sobel input.jpg output_sobel.jpg
```
