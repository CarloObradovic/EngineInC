#include <GL/glut.h>
#include<stdlib.h>
#include<stdio.h>


// tokom kompiliranja ovog primerka koristite ove parametre u gcc funkciji -lglu32 -lglut32 -lopengl32 ovako to treba izgledati (gcc 3D_grafikaC.c -lglu32 -lglut32 -lopengl32) takodje kompiliranje u terminalu nije preporucano jer moze doci do greske stoga bolje je koristiti dev-cc++ program

float px,py; //igraceva pozicija

void drawPlayer()
{
    glColor3f(1,1,0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(px,py);
    glEnd();
}

int mapX=8,mapY=8,mapS=64;
int map[]={
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,1,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
					





};


void drawMap2D()
{
	int x,y,xo,yo;
	for(y=0;y<mapY;y++)
	{
		for(x=0;x<mapX;x++)
		{
			if(map[y*mapX+x]==1) { glColor3f(1,1,1);} else{ glColor3f(0,0,0);}
			xo=x*mapS; yo=y*mapS;
			glBegin(GL_QUADS);
			glVertex2i(xo	+1, yo	+1);
			glVertex2i(xo	+1, yo+mapS-1);
			glVertex2i(xo+mapS-1, yo+mapS-1);
			glVertex2i(xo+mapS-1, yo	+1);
			glEnd;
		}
	}
}



void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 drawMap2D();
 drawPlayer();
 glutSwapBuffers();
}

void buttons(unsigned char key,int x,int y)
{
    if(key=='a'){ px-=5;}
    if(key=='d'){ px+=5;}
    if(key=='w'){ py-=5;}
    if(key=='s'){ py+=5;}
    glutPostRedisplay();
}

void init()
{
    glClearColor(0.3,0.3,0.3,0);
    gluOrtho2D(0,1024,510,0);
    px=150; py=150;
}

int main(int argc, char** argv)
{ 
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowSize(1024, 510);
 glutCreateWindow("Carlo-StandardTemplate");
 init();
 glutDisplayFunc(display);
 glutKeyboardFunc(buttons);
 glutMainLoop();
}

