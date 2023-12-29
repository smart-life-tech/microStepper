#include <AccelStepper.h>

// Define the stepper motor connections and settings
#define MOTOR_A_STEP_PIN 3
#define MOTOR_A_DIR_PIN 2
#define MOTOR_B_STEP_PIN 5
#define MOTOR_B_DIR_PIN 4

// Define maximum speed and acceleration values
#define MAX_SPEED 5000
#define ACCELERATION 3000

AccelStepper motorA(1, MOTOR_A_STEP_PIN, MOTOR_A_DIR_PIN);
AccelStepper motorB(1, MOTOR_B_STEP_PIN, MOTOR_B_DIR_PIN);

void setup()
{
    // Set up motor parameters
    motorA.setMaxSpeed(MAX_SPEED);
    motorA.setAcceleration(ACCELERATION);

    motorB.setMaxSpeed(MAX_SPEED);
    motorB.setAcceleration(ACCELERATION);

    // Set initial positions for both motors
    motorA.setCurrentPosition(0);
    motorB.setCurrentPosition(400);
}

void loop()
{
    // Move Motor A out (Steps 0 to 50) and Motor B in (Steps 100 to 50)
    for (int step = 0; step <= 400; ++step)
    {
        // Motor A
        if (step <= 50)
        {
            // Acceleration for Motor A
            int accelerationA = map(step, 0, 50, 0, MAX_SPEED);
            motorA.setSpeed(accelerationA);
            motorA.setAcceleration(accelerationA);
        }
        else
        {
            // Deceleration for Motor A
            int decelerationA = map(step, 50, 100, MAX_SPEED, 0);
            motorA.setSpeed(decelerationA);
            motorA.setAcceleration(decelerationA);
        }

        // Motor B
        if (step >= 50)
        {
            // Acceleration for Motor B
            int accelerationB = map(step, 50, 75, 0, MAX_SPEED);
            motorB.setSpeed(accelerationB);
            motorB.setAcceleration(accelerationB);
        }
        else
        {
            // Deceleration for Motor B
            int decelerationB = map(step, 75, 100, MAX_SPEED, 0);
            motorB.setSpeed(decelerationB);
            motorB.setAcceleration(decelerationB);
        }

        // Run both motors simultaneously
        motorA.runSpeed();
        motorB.runSpeed();

        delay(10); // Adjust this delay if needed
    }

    // Move Motor A out (Steps 0 to 50) and Motor B in (Steps 100 to 50)
    for (int step = 0; step <= 400; ++step)
    {
        // Motor A
        if (step <= 50)
        {
            // Acceleration for Motor A
            int accelerationA = map(step, 0, 50, 0, MAX_SPEED);
            motorA.setSpeed(-accelerationA);
            motorA.setAcceleration(-accelerationA);
        }
        else
        {
            // Deceleration for Motor A
            int decelerationA = map(step, 50, 100, MAX_SPEED, 0);
            motorA.setSpeed(-decelerationA);
            motorA.setAcceleration(-decelerationA);
        }

        // Motor B
        if (step >= 50)
        {
            // Acceleration for Motor B
            int accelerationB = map(step, 50, 75, 0, MAX_SPEED);
            motorB.setSpeed(-accelerationB);
            motorB.setAcceleration(-accelerationB);
        }
        else
        {
            // Deceleration for Motor B
            int decelerationB = map(step, 75, 100, MAX_SPEED, 0);
            motorB.setSpeed(-decelerationB);
            motorB.setAcceleration(-decelerationB);
        }

        // Run both motors simultaneously
        motorA.runSpeed();
        motorB.runSpeed();

        delay(10); // Adjust this delay if needed
    }
    // Pause between movements (you can adjust this as needed)
    delay(1000);
}
