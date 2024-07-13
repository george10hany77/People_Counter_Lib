#include <PeopleCounter.h>

PeopleCounter counter;

void setup() {
    Serial.begin(9600);
    counter.setSensor1Pin(2);  // Set the pin number for the first sensor
    counter.setSensor2Pin(3);  // Set the pin number for the second sensor
    counter.setMode(PeopleCounter::ACTIVE_LOW);  // Set the mode to ACTIVE_LOW

    if (counter.begin()) {
        Serial.println("PeopleCounter started successfully.");
    } else {
        Serial.println("Failed to start PeopleCounter.");
    }
}

void loop() {
    counter.runAlgorithm();  // Call runAlgorithm to process sensor inputs

    static unsigned long lastPrintTime = 0;
    if (millis() - lastPrintTime > 1000) {  // Print every second
        lastPrintTime = millis();
        Serial.print("Visitor Count: ");
        Serial.println(counter.getCount());  // Print the current count
    }
}
