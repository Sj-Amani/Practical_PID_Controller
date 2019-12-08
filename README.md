# Practical PID Controller

![Practical_PID_Controller_10X_gif](results/Practical_PID_Controller_10X.gif)

---

## Overview
In this project I will `implement a proportional–integral–derivative controller (PID controller) in C++ to maneuver the vehicle around the track`. The main codes are in the "src/" directory:

* main.cpp
* PID.h
* PID.cpp
* json.hpp

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Simulator
You can download the Udacity Term2 Simulator for this project from the [releases tab (https://github.com/udacity/self-driving-car-sim/releases).  

To run the simulator on Mac/Linux, first make the binary file executable with the following command:
```shell
sudo chmod u+x {simulator_file_name}
```
The simulator will provide you the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle.

## Basic Build Instructions

1. Clone this repo.
2. Install uWebSockets: `install-ubuntu.sh` for the case of ubuntu
3. Run the simulator: `./term2_sim.x86_64`
4. Compile and Run the path planning: `./run`

## Reflection

### P, I, D components 
* P : This proportional component is primarily for feedback control and tries to steer the car toward the center line (against the cross-track error (CTE)).
* I : This integral component can eliminate systematic bias.
* D : This derivative component can improve the dynamic performance of the controller, preventing overshooting by smoothing the approach to it. 

### Hyperparameters
The parameters were chosen by both twiddle and manually by try and error. At first, using the twiddle, the resulted controller could track the trajectory successfully. However, the steering angle was usually larger than it should be, resulting in large jerks. Therefore, I continued by manual tuning to further adjust the parameters so that the movement of the car could be smoother (Please see the top video).

## Code Style

[Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

References:
---
https://classroom.udacity.com/nanodegrees

https://github.com/nlohmann/json

https://github.com/udacity/CarND-PID-Control-Project

http://jeremyshannon.com/2017/06/16/udacity-sdcnd-PID-control.html

https://github.com/udacity/self-driving-car-sim/releases

How Referencing This Project
---
If you like my code and you want to use it in your project, please refer it like this:

`Amani, Sajjad. "How to practically implement a proportional–integral–derivative controller (PID controller) to maneuver the vehicle in a road" GitHub, 8 December 2019, https://github.com/Sj-Amani/Practical_PID_Controller`
