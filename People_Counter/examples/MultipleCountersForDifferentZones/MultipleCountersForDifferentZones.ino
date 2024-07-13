#include <PeopleCounter.h>

PeopleCounter counterZone1(2, 3, PeopleCounter::ACTIVE_LOW);
PeopleCounter counterZone2(4, 5, PeopleCounter::ACTIVE_HIGH);

void setup() {
    Serial.begin(9600);

    if (counterZone1.begin() && counterZone2.begin()) {
        Serial.println("Both PeopleCounters started successfully.");
    } else {
        Serial.println("Failed to start one or both PeopleCounters.");
    }
}

void loop() {
    counterZone1.runAlgorithm();  // Process sensor inputs for Zone 1
    counterZone2.runAlgorithm();  // Process sensor inputs for Zone 2

    Serial.print("Zone 1 Count: ");
    Serial.print(counterZone1.getCount());
    Serial.print(" | Zone 2 Count: ");
    Serial.println(counterZone2.getCount());  // Print the counts for both zones
    
    delay(500);  // Wait for 500ms before the next loop iteration
}
