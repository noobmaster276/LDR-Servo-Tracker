LDR-Servo-Tracker
This project showcases a light-tracking system built with an Arduino, LDR (Light-Dependent Resistor) sensors, and servo motors. The setup is designed to detect the direction of a light source and adjust the servos accordingly, simulating a simple solar tracker or automated spotlight system. The system provides a practical demonstration of sensor-based feedback control and can serve as a foundation for IoT or robotics applications requiring real-time environmental interaction.

Features
Light Detection: Four LDR sensors are positioned to detect the direction of light, enabling precise tracking.
Servo Control: Two servo motors are configured to adjust in horizontal and vertical directions based on sensor input, mimicking pan-tilt functionality.
Adaptive Sensitivity: Configurable tolerance and delay settings ensure smooth and stable movement, with minimized sensitivity to sudden changes in light.
Arduino-Powered: Built using an Arduino Uno, leveraging its analog input capabilities for sensor data and PWM outputs for servo control.
Components
Arduino Uno: Microcontroller for processing sensor data and controlling servos.
LDR Sensors: Four light sensors used to detect light intensity from different directions.
Servo Motors: Two servos for X (left-right) and Y (up-down) axis movement.
Breadboard and Jumper Wires: Basic prototyping setup for connections.
Usage
Upload Code: Use the Arduino IDE to upload the provided code to your Arduino Uno.
Simulate or Test: Run the setup in a simulation environment (e.g., Tinkercad) or on physical hardware to observe the light-tracking behavior.
Adjust Settings: Modify sensitivity thresholds and delay settings to suit your environment and light conditions.
Applications
This project can be adapted for various use cases, including:

Solar tracking systems
Automated lighting systems
Introductory projects in robotics and IoT
Environmental monitoring systems
