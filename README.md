# 🌞 Sistema Solar con Control de Carga

Este proyecto implementa un sistema de monitoreo y control de carga para una batería alimentada por un panel solar. Está diseñado para gestionar eficientemente la energía generada, mostrando la información en una pantalla LCD con interfaz I2C.

---

## 🌟 Características

- **Lectura de voltajes**: Mide el voltaje del panel solar y de la batería usando pines analógicos.
- **Cálculo del nivel de carga de la batería**: Convierte los valores de voltaje en un porcentaje de carga (0% a 100%).
- **Control inteligente**:
  - Detiene la carga cuando la batería está completa.
  - Prioriza el uso del panel solar para alimentar el sistema cuando es posible.
  - Cambia al uso de la batería cuando el panel no genera energía.
- **Interfaz visual**: Muestra la información en tiempo real en un LCD de 16x2.
- **Simulación previa**: Implementado en **TinkerCAD** para verificar el funcionamiento del circuito antes de armarlo.

---

## 🔧 Requisitos

### Hardware

1. Arduino (cualquier modelo compatible, como Arduino Uno).
2. **Pantalla LCD** con controlador I2C (dirección predeterminada: `0x27`).
3. **Transistor TIP120** para controlar la carga de la batería.
4. Resistencias:
   - 2 resistencias de **10 kΩ** (divisor de voltaje).
   - 1 resistencia de **100 Ω**.
   - 1 resistencia de **220 Ω**.
5. Capacitor electrolítico de **100 µF 25V**.
6. **LED rojo**.
7. Panel solar y batería recargable.
8. Cables y protoboard.

### Software

1. [Arduino IDE](https://www.arduino.cc/en/software) o [Visual Studio Code](https://code.visualstudio.com/) con extensión de Arduino.
2. Librería **Adafruit_LiquidCrystal.h**.
3. **TinkerCAD**.

---

## 💡 Código

Puedes encontrar el código completo en el archivo [`Sistema_Solar_Arduino.ino`](./Sistema_Solar_Arduino.ino).

---

## 📄 Licencia

Este proyecto está bajo la licencia **MIT**. Consulta el archivo [LICENSE](./LICENSE) para más detalles.

---

## 🎥 Demostración

Aquí puedes ver cómo funciona el sistema solar con control de carga en acción:

![Demostración del sistema](https://www.youtube.com/watch?v=tu_video)

---

## 📸 Diagrama

![Esquema del circuito](images/Recarga%20con%20Panel%20solar.PNG)

---

## 📜 Simulación en TinkerCAD

Este proyecto fue simulado utilizando **TinkerCAD** para validar el funcionamiento del circuito antes de implementarlo físicamente.
