
# 🔌 Control de LED con Servidor Web – ESP32

Este proyecto implementa un **servidor web embebido en un ESP32**, permitiendo **encender y apagar un LED** desde cualquier navegador conectado a la misma red WiFi. Es una base ideal para proyectos IoT simples y escalables.

---

## 🚀 Características

- 🌐 Servidor web en el puerto **80**
- 💡 Control de un LED (GPIO 2 por defecto)
- 📱 Interfaz web responsiva con botones ON/OFF
- 🔁 Manejo de solicitudes **HTTP GET**
- 🧩 Compatible con **ESP32** y **ESP8266**

---

## 🧰 Hardware Necesario

- ESP32 DevKitC / NodeMCU ESP32  
- LED integrado (GPIO 2) o LED externo  
- Cable USB  
- Red WiFi 2.4 GHz  

---

## 📡 Configuración WiFi

Antes de subir el código, reemplaza estas líneas:

```cpp
const char* ssid = "TU_SSID";
const char* password = "TU_PASSWORD";
```

## 



Para la comunicación con el webserver se tienen dos opciones abrir directamente en el navegador web, o usando la aplicación

Usando el navegador web:
1. Upload el código WebBoton.ino en la placa ESP32
2. en el monitor serie revisar la dirección IP a la que se ha conectado
3. Escribir esa dirección IP en el navegador web y presionar los botones para verificar el funcionamiento

   usando la app con app inventor

   1. Programe la aplicación según desee, la parte escencial para la comunicación web es la siguiente.
      ![image](https://github.com/user-attachments/assets/d11584c3-eaa5-4223-b596-6fadee074caf)

   3. Descargue la aplicación movil 
   3.Upload el código WebBoton.ino en la placa ESP32
   4. En el monitor serie revisar la dirección IP a la que se ha conectado
   5. Anotar la dirección IP en la aplicación movil y presionar los botones para verificar su funcionamiento
