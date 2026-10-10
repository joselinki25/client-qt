# Cliente de Red - Laboratorio Qt

Este es un proyecto de laboratorio desarrollado en C++ utilizando el framework Qt. La aplicación consiste en un cliente con interfaz gráfica (GUI) diseñado para conectarse a un servidor e intercambiar mensajes mediante sockets de red.

## Características Principales
* Interfaz gráfica (GUI) construida con **Qt Widgets** y diseñada visualmente en Qt Designer.
* Integración del módulo **Qt Network** para el manejo de conexiones TCP (`QTcpSocket`).
* Entradas dinámicas para configurar la dirección IP (por defecto `127.0.0.1`) y el puerto (por defecto `1234`).
* Funciones implementadas mediante la arquitectura de Señales y Slots de Qt (`requestMessage`, `readMessage`).
* Construido bajo el estándar **C++17**.

## Requisitos del Sistema
* Qt Creator
* Framework Qt (versión 5.x o 6.x)
* Compilador compatible con C++17 (ej. MinGW 64-bit).

## Estructura del Proyecto
* `Client.pro`: Archivo de configuración qmake (incluye los módulos `widgets` y `network`).
* `Headers/client.h`: Declaración de la clase `Client`, interfaz de usuario y métodos de red.
* `Sources/client.cpp`: Implementación de la lógica, constructor y conexiones de los botones.
* `Sources/main.cpp`: Punto de entrada de la aplicación.
* `Forms/client.ui`: Archivo XML con el diseño visual de la interfaz.

## Compilación y Ejecución
1. Abre el archivo `Client.pro` utilizando Qt Creator.
2. Si es la primera vez que lo abres o si modificaste el archivo `.pro`, haz clic derecho sobre la carpeta principal del proyecto y selecciona **Run qmake**.
3. Presiona **Ctrl + B** para compilar el proyecto y verificar que no existan errores de sintaxis.
4. Presiona **Ctrl + R** (o haz clic en el botón de Play en la esquina inferior izquierda) para ejecutar el cliente.