#define trigPin 9
#define echoPin 8
#define led 13

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    long duration, distance;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;

    if (distance < 70) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }

    // Optional: Print the distance to the serial monitor for debugging
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(100); // Small delay to avoid too many serial prints
}
