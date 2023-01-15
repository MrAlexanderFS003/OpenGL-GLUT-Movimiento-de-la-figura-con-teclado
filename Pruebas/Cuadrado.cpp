#include "Cuadrado.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void Cuadrado::Dibuja() {
	glPushMatrix();
	glColor3ub(82, 190, 128); // Color en formato(255,255,255)
	glPointSize(20); // Tamaño del punto
	glTranslatef(posX,posY,0); // Transformacion de la figura/Punto
	glBegin(GL_POINTS); // Uso de primitivas
	glVertex2f(0,0); // Punto en el plano
	glEnd(); // Fin del uso de primitvas
	glPopMatrix();
}

void Cuadrado::Actualiza() {
	//Colsiones y mas...
	glutPostRedisplay();
}