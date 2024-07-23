# Georgia Tech Robotics Summer Institute

## Directory Layout

    GTRSI-2024

    ├── src                                 # D: contains all code to be used in summer camp 2023
    │   ├── TemplateProgram                 # D: use this as the starting point for all programs
    |   | 
    │   └── HardwareTests                   # D: for debugging hardware
    |       ├── Reset                       # D: used to raise the robot arm and open the gripper
    |       │   ├── Reset.ino [*]
    |       │   ├── Homing.h
    |       │   └── Motors.h 
    |       |
    │       ├── test_barcodes               # D: check if camera can detect barcodes. detected items are printed via serial
    |       |   └── test_barcodes.ino [*]
    |       | 
    │       ├── test_closeGripperToFSR      # D: closes gripper until FSR detects a force
    |       |   └── test_barcodes.ino [*]
    |       |
    │       ├── test_fsr                    # D: prints force measured by FSR via serial
    |       |   └── test_fsr.ino [*]  
    |       |   
    │       ├── test_homing                 # D: homes the arm and prints the zero encoder reading via serial
    |       |   ├── test_homing.ino [*]  
    |       |   ├── homing.h  
    |       |   └── motors.h
    |       |
    │       |   ├── test_limitSwitch        # D: prints limit switch rising and falling edges via serial
    |       |   └── test_limitSwitch.ino [*]  
    |       |
    │       └── test_motors                 # D: moves the robot forward for 3 seconds
    |           ├── test_motors.ino [*]  
    |           ├── Motors.h  
    |           └── Utilities.h
    |
    ├── .gitignore                          
    └── README.md

**Note: [*] denotes that the file can be run as a top-level file (i.e. uploaded in Arduino IDE).**