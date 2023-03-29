#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Servo.h>


const char* ssid = "";
const char* password = "";



const int servoPin = 12;

// instance of the async web server
AsyncWebServer server(80);
//instance of the Servo library
Servo doorLock;

void setup() {
  // Connection to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // endpoint for receiving unlock commands

  server.on("/unlock", HTTP_GET, [](AsyncWebServerRequest *request){
    // unlocking the door

    

        void setup() {
          
          doorLock.attach(servoPin);
          
          // Set the initial position of the servo to 0 degrees
          doorLock.write(0);
        }

        // Function to unlock the door
        void unlockDoor() {
          // Set the position of the servo to 90 degrees
          doorLock.write(90);
          delay(1000); // Wait for the servo to move for 1 scond before turing back to 0 degrees
        }
    request->send(200);
  });

  // Start the server
  server.begin();
  Serial.println("Server started");
}


