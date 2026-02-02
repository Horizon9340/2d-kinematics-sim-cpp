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

## Learning OpenGL ([link](learn-opengl))
The ultimate goal I had with the project of creating a 2D kinematics simulation was to learn the basic concepts needed to program a simulation, and then to learn to display it. I chose OpenGL to be the graphis API that I would learn graphic modeling with to display my simulations. This will likely be the most complex thing I've done thus far.

So far, I have learned a lot about the inner workings of computer graphics. I now understand the fundamentals of how OpenGL talks to the GPU, including the vertex and fragment shaders' roles, how each works together to display pixels, rasterization, shader code in GLSL, VBOs and VAOs, and how to program objects to actually be displayed. Right now, I have learned how to display several dots with a 2D position (x,y) and each with an individual color (r,g,b).

I had to import the [glad](learn-opengl/glad) library and understand GLFW. I also learned how to create a [makefile](learn-opengl/makefile) to compile my programs much faster and more efficiently.

## Version 2 ([link](2d_kinematics_v2))
The second version of the simulation will be much cleaner and more optimized. It will be my first simulation with a real display, and I will be using OpenGL to create it.
