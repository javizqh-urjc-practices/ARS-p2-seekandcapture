# ASR-1-SeekAndCapture
![distro](https://img.shields.io/badge/Ubuntu%2022-Jammy%20Jellyfish-green)
![distro](https://img.shields.io/badge/ROS2-Humble-blue)

Práctica 1 – Arquitectura Software para Robots

En esta práctica el robot debe:

1. Buscar a las personas a su alrededor.
2. Cuando detecta nua, debe ir hacia ella, incluso si ésta se mueve.
3. Cuando esté cerca, debe hacer alguna señal (sonido, mensaje,..)
4. El robot busca a otra persona diferente

* El software debe tener un subsistema de percepción que detecte a la persona en la imagen, transforme esa detección a una detección 3D y genere un frame desde "odom" para la detección. Usa los nodos del paquete perception_asr para esto.
* Debe haber un subsistema de actuación que, a partir de los frames de las percepciones de personas, elija una y genere los comandos para seguirla. Debe pararse a ~1 metro y hacer la señal.

Puntuación:

* Sistema de percepción funcionando correctamente [+1]
* El robot se aproxima a una persona [+2]
* El robot usa PIDs para seguir a la persona [+1]
* El robot se para y avisa cuando ha "cogido" a una persona [+1]
* El robot usa Behavior Trees para organizar su comportamiento [+2]
* El robot busca y sigue a otra persona cuando ha alcanzado a una [+2]
* Todo se lanza con un solo launcher. Tiene un sistema de depuración efectivo [+1]

***

# seek-and-capture-forocoches V.1.0.0
![ROS2 version](https://img.shields.io/badge/ROS2-Humble-blue)
![License](https://img.shields.io/badge/License-Apache%202.0-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-orange)
![Build status](https://img.shields.io/badge/Build-Passing-brightgreen)

*LOGO SEEK-AND-CAPTURE FOROCOCHES*

¡Bienvenidos al repositorio de seekandcapture-forocoches! Este en un modelo de sistema desarrollado en ROS-2, que dotan al robot de la capacidad de seguir a varias personas utilizando la cámara Astra del Kobuki y algoritmos basados en transformaciones mediante la librería darknet-ros que se nos ha proporcionado. Este proyecto es el resultado de la unión de las dos partes que principalmente componen nuestro subsistema, para la cual una mitad del grupo se ha ocupado de la parte perceptiva, mientras que la otra mitad se ha encargado de la parte de movimiento.

En este repositorio se encuentran todos los componentes necesarios para utilizar este modelo de sistema en tu propio robot. Además, hemos hecho todo lo posible para facilitar la instalación y uso del paquete , lo que significa que puedes poner en marcha tu robot y que comience a seguir a todas las personas que vaya detectando.

Este proyecto ha sido desarrollado por un equipo altamente calificado y dedicado, que ha trabajado duro para hacer que, partiendo de un funcionamiento básico por separado de las partes de percepción y movimiento, respectivamente, empezando por seguir a una sola persona, se hayan mejorado y perfeccionado ambas partes para que el robot pueda seguir a varias personas y se ajuste todo lo posible con los requisitos pedidos en esta práctica.

Como introducción a nuestro modelo de sistema seek-and-capture, se muestra el funcionamiento de esta conjunción de percepción y movimiento. En este vídeo, se puede ver cómo el robot se va moviendo por un entorno mientras va siguiendo a una persona:

*VÍDEO DEMOSTRACIÓN (GRABAR LUNES 27/03 POR LOS PASILLOS)*

Como se observa, nuestro robot va moviéndose por el entorno de manera eficiente y segura gracias a la combinación de capacidades de percepción y movimiento integradas en el modelo del sistema seek-and-capture que permiten al robot seguir a una persona en tiempo real.

*CAPACIDADES ADICIONALES*

*IMÁGENES DE APOYO (GRÄFICOS, GIF DE LA TRANSFORMADA EN RVIZ, ETC …)*

## Instalación

*GIFS DE TERMINAL Y BREVE DESCRIPCIÓN DE CADA UNO DE LOS PASOS A SEGUIR*

## Topics usados en este modelo

*BREVE DESCRIPCIÓN Y DIAGRAMA DE LOS TOPICS*

## Behavior Tree implementado para este modelo

*BREVE DESCRIPCIÓN E IMAGEN DEL BEHAVIOR TREE DE GROOT ESPECIFICANDO SU COMPORTAMIENTO*

## Problemas

## Autores
* Javier Izquierdo
* Alberto León
* Luis Moreno
* Sebastian Mayorquín

__By Forocoches__



