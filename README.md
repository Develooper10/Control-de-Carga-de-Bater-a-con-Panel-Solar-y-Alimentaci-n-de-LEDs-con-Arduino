# Sistema Solar con Control de Carga

Este proyecto implementa un sistema de monitoreo y control de carga para una batería alimentada por un panel solar. Está diseñado para gestionar eficientemente la energía generada, mostrando la información en una pantalla LCD con interfaz I2C.

## **Características**

- **Lectura de voltajes:** Mide el voltaje del panel solar y de la batería usando pines analógicos.
- **Cálculo del nivel de carga de la batería:** Convierte los valores de voltaje en un porcentaje de carga (0% a 100%).
- **Control inteligente:**
  - Detiene la carga cuando la batería está completa.
  - Prioriza el uso del panel solar para alimentar el sistema cuando es posible.
  - Cambia al uso de la batería cuando el panel no genera energía.
- **Interfaz visual:** Muestra la información en tiempo real en un LCD de 16x2.

## **Requisitos**

### Hardware

1. Arduino (cualquier modelo compatible, como Arduino Uno).
2. **Pantalla LCD** con controlador I2C (dirección predeterminada: `0x27`).
3. **Transistor TIP120** para controlar la carga de la batería.
4. Resistencias para divisor de voltaje (2 de 10 kΩ).
5. Panel solar y batería recargable.
6. Cables y protoboard.

### Software

1. [Arduino IDE](https://www.arduino.cc/en/software) o [Visual Studio Code](https://code.visualstudio.com/) con extensión de Arduino.
2. Librería **Adafruit_LiquidCrystal.h**:
   - Instalar desde el Administrador de Librerías del Arduino IDE o desde [Adafruit GitHub](https://github.com/adafruit/Adafruit_LiquidCrystal).

## **Cómo funciona**

1. **Inicialización:** El sistema configura los pines y muestra un mensaje inicial en el LCD.
2. **Medición de voltajes:**
   - La batería se mide con un divisor de voltaje para mantener los valores dentro del rango de 0-5V.
   - El panel solar se mide directamente en el rango permitido.
3. **Cálculo del nivel de batería:**
   - Se asume un rango típico de baterías Li-ion (3.0V a 4.2V).
   - La función `map()` convierte el voltaje en un porcentaje.
4. **Control de carga y sistema:**
   - Si la batería está completa, se detiene la carga y los LEDs se alimentan del panel.
   - Si el panel no genera suficiente energía, los LEDs usan la batería.
5. **Salida visual:**
   - En el LCD se muestran los voltajes actuales y el porcentaje de batería.

## **Código**

El código completo está disponible en el archivo [`Sistema_Solar_Arduino.ino`](./Sistema_Solar_Arduino.ino).

### **Fragmento importante:**

```cpp
voltajeBateria = analogRead(pinVoltajeBateria) * (5.0 / 1023.0) * 2; 
nivelBateria = map(voltajeBateria * 100, 300, 420, 0, 100);
```
