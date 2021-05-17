#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstring>
#include <string>

using namespace std;

void display();
void reshape(int w,int h);
static void key(unsigned char key, int x, int y);
void printText(std::string s,int x,int y);

static void idle(void){
    glutPostRedisplay();
}

void init(){
    glClearColor(0.3,0.35,0.3,1.0); //Set Background
    glEnable(GL_DEPTH_TEST); // Open depth test
}

/*Global values for translate*/
float translateX=0.0;
float translateY=0.0;
float translateZ=-30.0;

/*Global values for rotate*/
float rotateX=0.0;
float rotateY=0.0;
float rotateZ=0.0;
float angle =0.0;

/*Global values for scale*/
float scaleX=1;
float scaleY=1;
float scaleZ=1;

int main(int argc,char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    /*Create window*/
    glutInitWindowPosition(200,100);
    glutInitWindowSize(700,700);
    glutCreateWindow("My Home");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    init();

    glutMainLoop();
}

/* The home shape and texts are obstructed under this function. */
void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    /*Update the scale-rotate values.*/
    glRotatef(angle,rotateX,rotateY,rotateZ);
    glScalef(scaleX,scaleY,scaleZ);

    glBegin(GL_QUADS);
    // front low
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-3.0+translateX,0.0+translateY,0.0+translateZ);
    glVertex3f(-3.0+translateX,-4.0+translateY,0.0+translateZ);
    glVertex3f(3.0+translateX,-4.0+translateY,0.0+translateZ);
    glVertex3f(3.0+translateX,0.0+translateY,0.0+translateZ);
	
    glColor3f(1.0,0.0,0.4);
    // right low
    glVertex3f(3.0+translateX,0.0+translateY,10.0+translateZ);
    glVertex3f(3.0+translateX,-4.0+translateY,10.0+translateZ);
    glVertex3f(3.0+translateX,-4.0+translateY,0.0+translateZ);
    glVertex3f(3.0+translateX,0.0+translateY,0.0+translateZ);
	
    glColor3f(1.0,0.0,0.4);
    // right low
    glVertex3f(-3.0+translateX,0.0+translateY,10.0+translateZ);
    glVertex3f(-3.0+translateX,-4.0+translateY,10.0+translateZ);
    glVertex3f(-3.0+translateX,-4.0+translateY,0.0+translateZ);
    glVertex3f(-3.0+translateX,0.0+translateY,0.0+translateZ);

    // back low
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-3.0+translateX,0.0+translateY,10.0+translateZ);
    glVertex3f(3.0+translateX,0.0+translateY,10.0+translateZ);
    glVertex3f(3.0+translateX,-4.0+translateY,10.0+translateZ);
    glVertex3f(-3.0+translateX,-4.0+translateY,10.0+translateZ);

    // below part
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-3.0+translateX,-4.0+translateY,0.0+translateZ);
    glVertex3f(3.0+translateX,-4.0+translateY,0.0+translateZ);
    glVertex3f(3.0+translateX,-4.0+translateY,10.0+translateZ);
    glVertex3f(-3.0+translateX,-4.0+translateY,10.0+translateZ);

    // roof part front triangle
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-3.0+translateX,0.0+translateY,0.0+translateZ);
    glVertex3f(3.0+translateX,0.0+translateY,0.0+translateZ);
    glVertex3f(0.0+translateX,3.0+translateY,0.0+translateZ);
    glVertex3f(0.0+translateX,3.0+translateY,0.0+translateZ);

    // roof part back triangle
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-3.0+translateX,0.0+translateY,10.0+translateZ);
    glVertex3f(3.0+translateX,0.0+translateY,10.0+translateZ);
    glVertex3f(0.0+translateX,3.0+translateY,10.0+translateZ);
    glVertex3f(0.0+translateX,3.0+translateY,10.0+translateZ);

    // roof part left
    glColor3f(1.0,0.3,0.0);
    glVertex3f(0.0+translateX,3.0+translateY,0.0+translateZ);
    glVertex3f(0.0+translateX,3.0+translateY,10.0+translateZ);
    glVertex3f(-3.0+translateX,0.0+translateY,10.0+translateZ);
    glVertex3f(-3.0+translateX,0.0+translateY,0.0+translateZ);

    // roof part right
    glColor3f(1.0,0.3,0.0);
    glVertex3f(0.0+translateX,3.0+translateY,0.0+translateZ);
    glVertex3f(0.0+translateX,3.0+translateY,10.0+translateZ);
    glVertex3f(3.0+translateX,0.0+translateY,10.0+translateZ);
    glVertex3f(3.0+translateX,0.0+translateY,0.0+translateZ);

    //door
    glColor3f(0.5,0.2,0.3);
    glVertex3f(-1.0+translateX,-2.5+translateY,10.1+translateZ);
    glVertex3f(-1.0+translateX,-4.0+translateY,10.1+translateZ);
    glVertex3f(1.0+translateX,-4.0+translateY,10.1+translateZ);
    glVertex3f(1.0+translateX,-2.5+translateY,10.1+translateZ);
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 800, 0.0, 500);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);

    /* Print parameters to the screen*/    
    string s1 = "Rotation Vector:"+ to_string(rotateX) + " " +
        to_string(rotateY)+ " " +to_string(rotateZ) ;

    printText(s1,10,35); /*Print Rotation Vector to the Screen*/

    string s2 = "Translated Values:"+ to_string(translateX) + " " +
        to_string(translateY)+ " " +to_string(translateZ);

    printText(s2,10,25); /*Print Translation Values to the Screen*/
    
    string s3 = "Scale Values:"+ to_string(scaleX) + " " +
        to_string(scaleY)+ " " +to_string(scaleZ);

    printText(s3,10,15); /*Print Scale Vector to the Screen*/

    string s4 = "Press P for reset";
    printText(s4,10,5);

    string s5 = "Press q - w - e - r - t - y for translation";
    string s6 = "Press a - s - d - f - g - h - j for rotation (s-d-f-g-h-j sets the rotation vector)";
    string s7 = "Press z - x - c - v - b - n for scaling";

    printText(s6,10,490);
    printText(s5,10,480);
    printText(s7,10,470);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);

    glutSwapBuffers();
    glutPostRedisplay();
}

/*Print text to screen*/
void printText(string s,int x,int y){
    void * font = GLUT_BITMAP_9_BY_15;
    glRasterPos2i(x, y);
    for (string::iterator i = s.begin(); i != s.end(); ++i){
        char c = *i;
        glutBitmapCharacter(font, c);
    }
}

/*Reset current plane and obstruct perspective projection.*/
void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); /* reset current matrix - projection */
    gluPerspective(60,1,2,50.0); /* degree,aspect ratio,near clip plane,far clip plane */
    glMatrixMode(GL_MODELVIEW);
}

/*Update the values using keyboard inputs*/
static void key(unsigned char key, int x, int y){
    switch (key){
        case 'q':
            translateX+=1;
            break;
        case 'w':
            translateX-=1;
            break;
        case 'e':
            translateY+=1;
            break;
        case 'r':
            translateY-=1;
            break;
        case 't':
            translateZ+=1;
            break;
        case 'y':
            translateZ-=1;
            break;
        case 'a':
            angle+=10;
            break;
        case 's':
            rotateX+=1;
            break;
        case 'd':
            rotateX-=1;
            break;
        case 'f':
            rotateY+=1;
            break;
        case 'g':
            rotateY-=1;
            break;
        case 'h':
            rotateZ+=1;
            break;
        case 'j':
            rotateZ-=1;
            break;
        case 'z':
            scaleX+=1;
            break;
        case 'x':
            scaleX-=1;
            break;
        case 'c':
            scaleY+=1;
            break;
        case 'v':
            scaleY-=0.5;
            break;
        case 'b':
            scaleZ+=0.5;
            break;
        case 'n':
            scaleZ-=0.5;
            break;
        case 'p':
            translateX=0.0;
            translateY=0.0;
            translateZ=-30.0;
            rotateX=0.0;
            rotateY=0.0;
            rotateZ=0.0;
            angle =0.0;
            scaleX=1;
            scaleY=1;
            scaleZ=1;
            break;
    }
    glutPostRedisplay();
}
