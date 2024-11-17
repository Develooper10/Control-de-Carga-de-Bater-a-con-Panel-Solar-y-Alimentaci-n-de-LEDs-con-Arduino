#include <Adafruit_LiquidCrystal.h>

// Configuración de la pantalla LCD con I2C en la dirección 0x27
Adafruit_LiquidCrystal lcd_1(0);

const int pinVoltajeBateria = A0; // Pin para medir el voltaje de la batería
const int pinVoltajePanel = A1;   // Pin para medir el voltaje del panel solar
const int pinCarga = 9;           // Pin para controlar el transistor TIP120 (carga)
const int pinSistema = 8;         // Pin para controlar la alimentación del sistema (LEDs)

// Resistencias del divisor de voltaje
float r1 = 10000;
float r2 = 10000;

float voltajeBateria = 0;         // Voltaje de la batería
float voltajePanel = 0;           // Voltaje del panel solar
float nivelBateria = 0;           // Nivel de carga de la batería en porcentaje

void setup() {
  // Iniciar LCD
  lcd_1.begin(16, 2);             // Inicia el LCD de 16 columnas y 2 filas
  pinMode(pinCarga, OUTPUT);      // Configura el pin de carga como salida
  pinMode(pinSistema, OUTPUT);    // Configura el pin del sistema como salida
  lcd_1.print("Iniciando...");
  delay(2000);
  lcd_1.clear();
}

void loop() {
  // Leer el voltaje de la batería y el panel solar
  voltajeBateria = analogRead(pinVoltajeBateria) * (5.0 / 1023.0) * 2; // Compensa divisor de voltaje
  voltajePanel = analogRead(pinVoltajePanel) * (5.0 / 1023.0);         // Voltaje del panel solar

  // Calcular porcentaje de carga de la batería (asumiendo 3.0V a 4.2V)
  nivelBateria = map(voltajeBateria * 100, 300, 420, 0, 100);
  if (nivelBateria < 0) nivelBateria = 0;
  if (nivelBateria > 100) nivelBateria = 100;

  // Mostrar voltaje y nivel de carga en el LCD
  lcd_1.setCursor(0, 0);
  lcd_1.print("Panel:");
  lcd_1.print(voltajePanel, 2);
  lcd_1.print("V  ");

  lcd_1.setCursor(0, 1);
  lcd_1.print("Bateria:");
  lcd_1.print(nivelBateria);
  lcd_1.print("%    ");

  // Lógica de control de carga y alimentación
  if (nivelBateria >= 95) {
    digitalWrite(pinCarga, LOW); 
    if (voltajePanel > 0.5) {
      digitalWrite(pinSistema, HIGH); 
      lcd_1.setCursor(0, 1);
      lcd_1.print("Panel -> LEDs   ");
    } else {
      digitalWrite(pinSistema, HIGH); 
      lcd_1.setCursor(0, 1);
      lcd_1.print("Bateria -> LEDs ");
    }
  } else if (voltajePanel > 0.5) {
    if (voltajePanel < 5.0) {
      digitalWrite(pinCarga, HIGH); 
      digitalWrite(pinSistema, HIGH);
      lcd_1.setCursor(0, 1);
      lcd_1.print("Panel+Bateria  ");
    } else {
      digitalWrite(pinCarga, HIGH); 
      digitalWrite(pinSistema, HIGH);
      lcd_1.setCursor(0, 1);
      lcd_1.print("Cargando y LEDs");
    }
  } else {
    digitalWrite(pinCarga, LOW); 
    digitalWrite(pinSistema, HIGH); 
    lcd_1.setCursor(0, 1);
    lcd_1.print("Usando Bateria ");
  }

  delay(500);
}
