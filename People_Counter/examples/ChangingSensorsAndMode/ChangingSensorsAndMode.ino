#include <PeopleCounter.h>

PeopleCounter counter;

void setup() {
    Serial.begin(9600);
    counter.setSensor1Pin(2);  // Set the initial pin number for the first sensor
    counter.setSensor2Pin(3);  // Set the initial pin number for the second sensor
    counter.setMode(PeopleCounter::ACTIVE_LOW);  // Set the initial mode to ACTIVE_LOW

    if (counter.begin()) {
        Serial.println("PeopleCounter started successfully.");
    } else {
        Serial.println("Failed to start PeopleCounter.");
    }
}

void loop() {
    counter.runAlgorithm();  // Call runAlgorithm to process sensor inputs
    Serial.print("Visitor Count: ");
    Serial.println(counter.getCount());  // Print the current count
    
    // Example of changing the mode and sensors dynamically
    if (millis() % 10000 < 5000) {
        counter.setMode(PeopleCounter::ACTIVE_LOW);
    } else {
        counter.setMode(PeopleCounter::ACTIVE_HIGH);
    }
    
    delay(500);  // Wait for 500ms before the next loop iteration
}
