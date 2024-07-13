# PeopleCounter Library

## Overview

PeopleCounter is a library designed to simplify the creation of visitor counting systems using Arduino. It supports dual sensor inputs and various modes of operation.

## Features

- Dual sensor input (e.g., infrared sensors)
- Two modes of operation: ACTIVE_LOW and ACTIVE_HIGH
- Non-blocking and blocking algorithm implementations
- Easy to set up and use

## Installation

1. Download the latest release from the [GitHub repository](https://github.com/george10hany77/People_Counter_Lib).
2. Extract the downloaded ZIP file.
3. Copy the extracted folder to your Arduino libraries directory (typically located at `Documents/Arduino/libraries`).

## Usage

### Basic Example

```cpp
#include <PeopleCounter.h>

PeopleCounter counter;

void setup() {
    Serial.begin(9600);
    counter.setSensor1Pin(2);
    counter.setSensor2Pin(3);
    counter.setMode(PeopleCounter::ACTIVE_LOW);
    if (counter.begin()) {
        Serial.println("PeopleCounter started successfully.");
    } else {
        Serial.println("Failed to start PeopleCounter.");
    }
}

void loop() {
    counter.runAlgorithm();
    Serial.print("Count: ");
    Serial.println(counter.getCount());
    delay(1000);
}
