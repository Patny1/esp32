#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

const char* ssid = "xxxx";
const char* password = "xxxx";

WiFiServer server(80);
String header;
unsigned long lastTime, timeout = 2000;

const int outputPin = 2; // LED integrado 
String outputState = "apagado";

void setup() {
  Serial.begin(115200);

  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);

  Serial.print("Conectando a ");
  Serial.println(ssid);

WiFi.begin(ssid, password);

int intentos = 0;
while (WiFi.status() != WL_CONNECTED && intentos < 20) {
  delay(500);
  Serial.print(".");
  intentos++;
}

if (WiFi.status() == WL_CONNECTED) {
  Serial.println("");
  Serial.println("Dispositivo conectado.");
  Serial.println("Dirección IP:");
  Serial.println(WiFi.localIP());
} else {
  Serial.println("");
  Serial.println("Error al conectar a la red WiFi.");
}
 

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    lastTime = millis();
    Serial.println("Nuevo cliente");
    String currentLine = "";

    while (client.connected() && millis() - lastTime <= timeout) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;

        if (c == '\n') {
          if (currentLine.length() == 0) {

            // ENCABEZADO HTTP
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Control del pin por URL
            if (header.indexOf("GET /on") >= 0) {
              Serial.println("GPIO encendido");
              outputState = "encendido";
              digitalWrite(outputPin, HIGH);
            }                         
            else if (header.indexOf("GET /off") >= 0) {
              Serial.println("GPIO apagado");
              outputState = "apagado";
              digitalWrite(outputPin, LOW);
            } 

            // PÁGINA WEB CON BOTONES
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<style>");
            client.println("html { font-family: Arial; text-align: center; }");
            client.println("h2 { color: #333; }");
            client.println("button { padding: 16px 40px; font-size: 20px; margin: 10px; cursor: pointer; border: none; border-radius: 8px; }");
            client.println(".on { background-color: green; color: white; }");
            client.println(".off { background-color: red; color: white; }");
            client.println("</style></head>");

            client.println("<body>");
            client.println("<h2>Control del LED (GPIO 2)</h2>");
            client.println("<p>Estado actual: <strong>" + outputState + "</strong></p>");
            client.println("<p><a href=\"/on\"><button class=\"on\">ENCENDER</button></a></p>");
            client.println("<p><a href=\"/off\"><button class=\"off\">APAGAR</button></a></p>");
            client.println("</body></html>");

            client.println(); // fin de la respuesta HTTP
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }

    header = "";
    client.stop();
    Serial.println("Cliente desconectado.");
    Serial.println("");
  }
}
