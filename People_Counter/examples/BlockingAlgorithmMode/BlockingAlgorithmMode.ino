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
    counter.runAlgorithmBlocking();  // Call runAlgorithmBlocking to process sensor inputs
    Serial.print("Visitor Count: ");
    Serial.println(counter.getCount());  // Print the current count
}
