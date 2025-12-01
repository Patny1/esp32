# 📘 Control de LED con Servidor Web – ESP32

Este proyecto implementa un **servidor web usando un ESP32**, permitiendo **encender y apagar un LED** mediante una página web accesible desde cualquier dispositivo conectado a la misma red WiFi.

Incluye:

- Conexión WiFi del ESP32  
- Servidor HTTP en el puerto 80  
- Página web con botones interactivos  
- Control del GPIO desde el navegador  

---

## 🚀 Características

- 🌐 Servidor web embebido en el ESP32  
- 💡 Control de un LED (GPIO 2) desde un navegador  
- 📱 Interfaz web responsiva  
- 🔁 Manejo de solicitudes HTTP GET  
- 🧩 Compatibilidad con ESP32 y ESP8266  

---

## 🧰 Hardware Necesario

- ESP32 DevKitC / NodeMCU ESP32  
- LED integrado (GPIO 2) o uno externo  
- Cable USB  
- Red WiFi 2.4 GHz  

---

## 📡 Configuración WiFi

Modifica estas líneas con tu SSID y contraseña:

```cpp
const char* ssid = "Naty";
const char* password = "nana4321";
```

⚠️ La ESP32 **solo funciona con redes WiFi de 2.4 GHz**, no con 5 GHz.

---

## 📁 Descripción del Código

### 1️⃣ Dependencias WiFi

```cpp
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
```

---

### 2️⃣ Configuración del servidor

```cpp
WiFiServer server(80);
```

---

### 3️⃣ Control del LED

```cpp
const int outputPin = 2;
```

El LED comienza apagado al iniciar el programa.

---

### 4️⃣ Conexión WiFi

```cpp
while (WiFi.status() != WL_CONNECTED && intentos < 20) {
    delay(500);
}
```

Cuando se conecta, el ESP32 imprime la IP en el monitor serie.

---

### 5️⃣ Generación de Página Web

El ESP32 envía una página con:

- Botón **ENCENDER**  
- Botón **APAGAR**  
- Estado actual del GPIO  

Rutas utilizadas:

```
/on
/off
```

---

## 🖥️ Uso

1. Sube el código a la ESP32.  
2. Abre el **Serial Monitor** a 115200 baud.  
3. Espera el mensaje:

```
Dispositivo conectado.
Dirección IP: 192.168.x.x
```

4. Ingresa esa IP en tu navegador.  
5. Controla el LED con los botones.

---

## 🌐 Interfaz Web

La página incluye:

- Diseño centrado y limpio  
- Botones con estilos CSS  
- Actualización instantánea del estado del LED  

---

## 🧪 Pruebas

✔ LED se enciende y apaga correctamente  
✔ Funciona en móviles y computadores  
✔ No requiere Internet  
✔ Compatible con cualquier navegador moderno  

---

## 🔒 Notas Importantes

- La ESP32 no se conecta a redes 5G.  
- Evita caracteres especiales en SSID o contraseña.  
- Asegúrate de estar en la misma red que el ESP32.  

---

## 📜 Licencia

Proyecto libre para uso educativo o personal.
