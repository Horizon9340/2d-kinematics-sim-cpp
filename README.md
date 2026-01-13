# 2d-kinematics-sim-cpp
This repo documents my journey of learning how to code in C++, and how to create a basic 2D kinematics simulation of projectile motion in C++. 

## The Learning Process ([link](learn))
Before making any simulations, I first need to learn how to code in C++, as well as the behavior, syntax, and how to compile code.
[learn](learn/): This folder contains three files where I learned the basics of coding in C++. In [learn.cpp](learn.cpp), I experimented with functions, types, and other things while learning how C++ works. in [gravity.h](gravity.h) and [gravity.cpp](gravity.cpp), I defined a class `gravity` split across a header document in C and a describing document in C++ to understand how to create classes outside of specific files, so that functions can be reused. 

## Version 1 ([link](2d_kinematics_v1))
The first version of my simulation in C++ is simply be able to output the x and y positions accurately in the console based on the forces acting upon velocities. While this may sound okay, this actually poses a few problems. The most obvious flaw is that my code uses global variables. When a variable is declared outside the main function, everything in the file can access and change those variables, which becomes a huge problem when naming conflicts become a concern. Globals create hidden dependencies. Global variables also become annoying. The moment I want to add another object, I need to create an entire new set of variables.

For example:
`updateY` *looks like* it only depends on `(double y, double velocityY)`, but it in secret uses the global variables `gravity` and `dt`. If something goes wrong later, debugging will make me wonder what part of my program silently changed its value. In larger sims, when I add wind, drag, multiple objects, or collisions, my life will become a nightmare.

Another problem present in the code is that there are duplicate names, meaning that the name of a global variable matches the name of a local variable, such as `x`. This can cause both confusion and bugs when scaled. My functions also have mixed responsibilites. For example, my functions that update position also secretly access and change velocities. Again, this can cause confusion and problems later. 

## Version 2 ([link](2d_kinematics_v2))
The second version of the simulation will be much cleaner and more optimized. After that, I will work on displaying data in a visual way.

## Learning OpenGL ([link](learn-opengl))
I chose OpenGL to be the graphis API that I would learn graphic modeling with. This will likely be the most complex thing I've done thus far.

The current output of the program right now is just a dark screen with nothing in it. I am currently learning the basics of OpenGL and I am testing to see if it works on my MacBook.