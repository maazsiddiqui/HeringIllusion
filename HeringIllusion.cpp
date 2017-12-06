#include "stdafx.h"
#include <gl/glut.h>

int width = 600;
int height = 300;
int lineGap = 50;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// Circular Lines

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	
	for (int x = width/2, y = width/2; x <= width && y >= 0; x+=lineGap, y-=lineGap) {
		glVertex2i(x, 0);
		glVertex2i(y, height);
	}

	for (int x = width/2, y = width/2; x <= width && y >= 0; x+=lineGap, y-=lineGap) {
		glVertex2i(y, 0);
		glVertex2i(x, height);
	}

	for (int i = height, j = 0; i >= 0 && j < height; i -= lineGap, j += lineGap) {
		if (j != (height / 2) - lineGap && j != (height / 2) + lineGap && j != height/2) {
			glVertex2i(width, j);
			glVertex2i(0, i);
		}
	}

	glEnd();

	// Red Horizontal Lines

	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	
	glVertex2i(0, (height / 2) - lineGap);
	glVertex2i(width, (height / 2) - lineGap);

	glVertex2i(0, (height / 2) + lineGap);
	glVertex2i(width, (height / 2) + lineGap);

	glEnd();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Hering Illusion");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)width, 0.0, (double)height);
	glutDisplayFunc(display);
	glutMainLoop();
}