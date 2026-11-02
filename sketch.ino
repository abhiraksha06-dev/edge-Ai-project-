#include <DHT.h>
#include <ESP32Servo.h>

// -------------------------
// Pin definitions
// -------------------------

#define LED_PIN 25
#define DHT_PIN 4
#define PIR_PIN 27
#define SERVO_PIN 26
#define POT_PIN 34

#define DHT_TYPE DHT22

// -------------------------
// Device objects
// -------------------------

DHT dht(DHT_PIN, DHT_TYPE);
Servo lockServo;

// -------------------------
// Setup
// -------------------------

void setup() {

  Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
      pinMode(PIR_PIN, INPUT);

        dht.begin();

          lockServo.attach(SERVO_PIN);

            // Start with the smart lock locked
              lockServo.write(0);

                // Start with the smart light OFF
                  digitalWrite(LED_PIN, LOW);

                    Serial.println();
                      Serial.println("================================");
                        Serial.println("EDGE-AI IoT DEVICE SIMULATION");
                          Serial.println("================================");

                            Serial.println("ESP32 Gateway Started");
                              Serial.println("Smart Light       : READY");
                                Serial.println("Smart Thermostat  : READY");
                                  Serial.println("Smart Camera      : READY");
                                    Serial.println("Smart Lock        : LOCKED");
                                      Serial.println("Smart Meter       : READY");
                                        Serial.println("--------------------------------");
                                        }

                                        // -------------------------
                                        // Main loop
                                        // -------------------------

                                        void loop() {

                                          // -------------------------
                                            // Smart Light
                                              // -------------------------

                                                digitalWrite(LED_PIN, HIGH);

                                                  Serial.println("Smart Light: ON");

                                                    delay(1000);

                                                      digitalWrite(LED_PIN, LOW);

                                                        Serial.println("Smart Light: OFF");


                                                          // -------------------------
                                                            // Smart Thermostat
                                                              // -------------------------

                                                                float temperature = dht.readTemperature();
                                                                  float humidity = dht.readHumidity();

                                                                    if (!isnan(temperature) && !isnan(humidity)) {

                                                                        Serial.print("Smart Thermostat: ");
                                                                            Serial.print("Temperature = ");
                                                                                Serial.print(temperature);
                                                                                    Serial.print(" C, Humidity = ");
                                                                                        Serial.print(humidity);
                                                                                            Serial.println(" %");

                                                                                              } else {

                                                                                                  Serial.println("Smart Thermostat: Sensor reading unavailable");
                                                                                                    }


                                                                                                      // -------------------------
                                                                                                        // Smart Camera
                                                                                                          // -------------------------

                                                                                                            int motion = digitalRead(PIR_PIN);

                                                                                                              if (motion == HIGH) {

                                                                                                                  Serial.println("Smart Camera: MOTION DETECTED");

                                                                                                                    } else {

                                                                                                                        Serial.println("Smart Camera: NO MOTION");
                                                                                                                          }


                                                                                                                            // -------------------------
                                                                                                                              // Smart Lock
                                                                                                                                // -------------------------

                                                                                                                                  Serial.println("Smart Lock: UNLOCKED");

                                                                                                                                    lockServo.write(90);

                                                                                                                                      delay(1000);

                                                                                                                                        Serial.println("Smart Lock: LOCKED");

                                                                                                                                          lockServo.write(0);


                                                                                                                                            // -------------------------
                                                                                                                                              // Smart Meter
                                                                                                                                                // -------------------------

                                                                                                                                                  int meterValue = analogRead(POT_PIN);

                                                                                                                                                    Serial.print("Smart Meter: ");
                                                                                                                                                      Serial.println(meterValue);


                                                                                                                                                        // -------------------------
                                                                                                                                                          // End of device cycle
                                                                                                                                                            // -------------------------

                                                                                                                                                              Serial.println("--------------------------------");
                                                                                                                                                                Serial.println("IoT device cycle completed");
                                                                                                                                                                  Serial.println();

                                                                                                                                                                    delay(2000);
                                                                                                                                                                    }