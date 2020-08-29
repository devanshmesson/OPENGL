#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <gl/glut.h>
#include<windows.h>


void display();
void display1();
void reshape(int,int);
void timer();
int arr[]={8,7,6,3,4};
void init()
{
 glClearColor(150/255,249/255,1,1.0);


}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);

    init();
    glutMainLoop();
}

float x=-10.0,y=1.0,a=7,b=1,s=-10,d=1.0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //glColor3d(1,1,0);
    //glRasterPos2d(x,y);
    //glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');

    glBegin(GL_POLYGON);
    glColor3d(1,1,0);

    glVertex2f(x,y);
    glVertex2f(x,(y-2));
    glVertex2f(x+2.0,(y-2));
    glVertex2f(x+2.0,y);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(1,0,0);
    glVertex2f(s+6,d);
    glVertex2f(s+6,(d-2));
    glVertex2f(s+8,(d-2));
    glVertex2f(s+8,d);
    glEnd();
    glColor3d(1,1,0);
    //glRasterPos2d(s+6,d);

    //glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');

    glBegin(GL_POLYGON);

    glVertex2f(a,b);
    glVertex2f(a,(b-2));
    glVertex2f(a+2.0,(b-2));
    glVertex2f(a+2.0,b);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(a-3,b);
    glVertex2f(a-3,(b-2));
    glVertex2f(a-5.0,(b-2));
    glVertex2f(a-5,b);
    glEnd();

    glutSwapBuffers();
}


void reshape(int w, int h)
{
 glViewport(0,0,(GLsizei)w,(GLsizei)h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-10,10,-10,10);
 glMatrixMode(GL_MODELVIEW);
}
float ok=0,yes=1,inx,ins;

void timer()
{

 glutPostRedisplay();
 glutTimerFunc(1000/60,timer,0);

 if(y<=5 && ok==0)
 {
  //printf("hello\n");
  y+=0.10;
  d+=0.10;
  if(y>=5)ok=1;
  inx=x,ins=s+6;

 }
 else
 {
   if(yes==1)
   {
   printf("hello yes=%f\n",yes);
   x+=0.1;
   s-=0.1;
   }
   printf("y= %f ins= %f\n",y,ins);
   if(yes!=-1)
   {
    if(x>=ins)
    {
        printf("devansh x>=ins\n");
        yes=0;
        y-=0.1;
        d-=0.1;
        if(y<=1)yes=-1;
    }
   }


}
}
