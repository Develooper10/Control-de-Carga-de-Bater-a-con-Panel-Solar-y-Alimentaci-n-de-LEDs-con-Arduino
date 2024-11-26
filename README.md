# 🌞 Sistema Solar con Control de Carga

Este proyecto implementa un sistema de monitoreo y control de carga para una batería alimentada por un panel solar. Está diseñado para gestionar eficientemente la energía generada, mostrando la información en una pantalla LCD con interfaz I2C.

---

## 📑 Tabla de Contenidos

- [Características](#-características)
- [Requisitos](#-requisitos)
- [Cómo funciona](#-cómo-funciona)
- [Código](#-código)
- [Licencia](#-licencia)
- [Demostración](#-demostración)
- [Tareas Futuras](#-tareas-futuras)

---

## 🌟 Características

- **Lectura de voltajes:** Mide el voltaje del panel solar y de la batería usando pines analógicos.
- **Cálculo del nivel de carga de la batería:** Convierte los valores de voltaje en un porcentaje de carga (0% a 100%).
- **Control inteligente:** Detiene la carga cuando la batería está completa. Prioriza el uso del panel solar para alimentar el sistema cuando es posible.
- **Interfaz visual:** Muestra la información en tiempo real en un LCD de 16x2.
- **Simulación previa:** Implementado en **TinkerCAD** para verificar el funcionamiento del circuito antes de armarlo.

---

## 🔧 Requisitos

### Hardware

1. Arduino (cualquier modelo compatible, como Arduino Uno).
2. Pantalla LCD con controlador I2C (dirección predeterminada: `0x27`).
3. Transistor TIP120 para controlar la carga de la batería.
4. Resistencias:
   - 2 resistencias de **10 kΩ** (divisor de voltaje).
   - 1 resistencia de **100 Ω**.
   - 1 resistencia de **220 Ω**.
5. Capacitor electrolítico de **100 µF 25V**.
6. **LED rojo**.
7. Panel solar y batería recargable.
8. Cables y protoboard.

---

## 💡 Cómo Funciona

1. **Inicialización:** El sistema configura los pines y muestra un mensaje inicial en el LCD.
2. **Medición de voltajes:** Se mide el voltaje de la batería y el panel solar.
3. **Cálculo del nivel de batería:** El voltaje de la batería se convierte en un porcentaje.
4. **Control de carga:** El sistema prioriza el uso del panel solar o la batería según la situación.
5. **Salida visual:** En el LCD se muestran los voltajes actuales y el porcentaje de batería.

## 🎥 Demostración

Aquí puedes ver cómo funciona el sistema solar con control de carga en acción:

[![Demostración del proyecto](https://i.ytimg.com/vi/oTs-uA852_Y/hqdefault.jpg)](https://youtu.be/oTs-uA852_Y)

## 🚀 Tareas Futuras

- Implementar la medición de la corriente de carga para una medición más precisa de la energía.
- Agregar una interfaz de usuario web para controlar remotamente el sistema.

---

## 📄 Licencia

Este proyecto está bajo la licencia **MIT**. Consulta el archivo [LICENSE](./LICENSE.txt) para más detalles.

---

## 📸 Diagrama del Circuito

![Diagrama del Circuito](images/Recarga%20con%20Panel%20solar.PNG)
