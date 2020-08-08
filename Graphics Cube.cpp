#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>


GLfloat angleCube = 0.0f;
GLfloat angleCube2 = 0.0f;
float move_x = 0.5;
float move_nx = 0.5;
float move_y = 0.5;
float move_ny = 0.5;


void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


void display();
void keyboard(int,int,int);

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(50,50);
    glutInitWindowSize(1080,720);

    glutCreateWindow("First graphic");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard);

    glutMainLoop();

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    //glColor3f(1.0,0.0,0.0);
   //glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);
   glRotatef(angleCube2, 1.0f, 0.0f, 0.0f);
   glRotatef(angleCube, 0.0f, 1.0f, 0.0f);
    //glBegin(GL_POINTS);
   // glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f);

    glutWireSphere(2,25,25);
    //glEnd();
   //glEnd();  // End of drawing color-cube


    glLoadIdentity();                  // Reset the model-view matrix
    glutPostRedisplay();
    glutSwapBuffers();

    //draws
    glFlush();

}



void keyboard(int key,int x,int y)
{
    switch(key)
    {
        case GLUT_KEY_RIGHT:{
            angleCube += 0.3f;
            break;
        }
        case GLUT_KEY_LEFT:{
            angleCube -= 0.3f;
            break;
        }
        case GLUT_KEY_UP:{
            angleCube2 -= 0.3f;
            move_y += .1;
            move_ny -= .1;
            break;
        }
        case GLUT_KEY_DOWN:{
            angleCube2 += 0.3f;
            move_y -= .1;
            move_ny += .1;
            break;
        }
    }
    glutPostRedisplay();
}

