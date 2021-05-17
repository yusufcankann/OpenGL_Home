# OpenGL_Home
Simple rotation-scaling-resizing operation in 3D OpenGL

## How To Run?
* If opengl and glut libraries are not installed on your system;
  * sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev


* For compiling code;
  * g++ 161044006.cpp -o 161044007 -lglut -lGLU -lGL

* Run;
  *  ./161044007


### Keyboard


Keys | Job
------------ | -------------
q | +x translation
e | +y translation
t | +z translation
w | -x translation
r | -y translation
y | -z translation
s | increase rotation vector +x
f | increase rotation vector +y
h | increase rotation vector +z
d | decrease rotation vector -x
g | decrease rotation vector -y
j | decrease rotation vector -z
a | apply rotation
z | +x scaling
c | +y scaling
b | +z scaling 
x | -x scaling
v | -y scaling
n | -z scaling
