#include <Servo.h>

// Pin assignments
const int LDR_TopLeft = A0;
const int LDR_TopRight = A1;
const int LDR_BottomLeft = A2;
const int LDR_BottomRight = A3;

// Servo objects
Servo servoX;  // Controls left-right movement
Servo servoY;  // Controls up-down movement

// Servo control pins
const int servoXPin = 9;
const int servoYPin = 10;

// Tolerance and delay settings
int tol = 15;  // Reduced sensitivity threshold for testing
int dtime = 10; // Delay time for smooth movement

void setup() {
  // Initialize servos
  servoX.attach(servoXPin);
  servoY.attach(servoYPin);
  
  // Center servos
  servoX.write(90);  // Middle position
  servoY.write(90);  // Middle position

  Serial.begin(9600);  // For debugging
}

void loop() {
  // Read values from LDRs
  int topLeft = analogRead(LDR_TopLeft);
  int topRight = analogRead(LDR_TopRight);
  int bottomLeft = analogRead(LDR_BottomLeft);
  int bottomRight = analogRead(LDR_BottomRight);

  // Calculate average readings for top, bottom, left, and right
  int avgTop = (topLeft + topRight) / 2;
  int avgBottom = (bottomLeft + bottomRight) / 2;
  int avgLeft = (topLeft + bottomLeft) / 2;
  int avgRight = (topRight + bottomRight) / 2;

  // Servo position tracking
  int posX = servoX.read();
  int posY = servoY.read();

  // Debugging output for averages
  Serial.print("AvgTop: "); Serial.print(avgTop);
  Serial.print(" | AvgBottom: "); Serial.print(avgBottom);
  Serial.print(" | AvgLeft: "); Serial.print(avgLeft);
  Serial.print(" | AvgRight: "); Serial.println(avgRight);

  // Vertical movement (Y-axis) - compare top and bottom averages
  if (abs(avgTop - avgBottom) > tol) {
    if (avgTop > avgBottom && posY < 180) {
      posY += 1;  // Move up
    } else if (avgBottom > avgTop && posY > 0) {
      posY -= 1;  // Move down
    }
    servoY.write(posY);  // Update Y-axis servo position
  }

  // Horizontal movement (X-axis) - compare left and right averages
  if (abs(avgLeft - avgRight) > tol) {
    if (avgLeft > avgRight && posX < 180) {
      posX += 1;  // Move left
    } else if (avgRight > avgLeft && posX > 0) {
      posX -= 1;  // Move right
    }
    servoX.write(posX);  // Update X-axis servo position
  }

  // Debugging output to monitor LDR values and servo positions
  Serial.print("TopLeft: "); Serial.print(topLeft);
  Serial.print(" | TopRight: "); Serial.print(topRight);
  Serial.print(" | BottomLeft: "); Serial.print(bottomLeft);
  Serial.print(" | BottomRight: "); Serial.print(bottomRight);
  Serial.print(" | ServoX: "); Serial.print(posX);
  Serial.print(" | ServoY: "); Serial.println(posY);

  delay(dtime);  // Small delay for smooth movement
}
