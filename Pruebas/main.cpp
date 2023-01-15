
/*
	Hecho por Max Flores Saldaña , Usando la programación orientada a Objetos en C++.
	Si desea ver la documentacion de GLUT: https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
*/

#include "Cuadrado.h" // Clase Cuadrado para crear objetos 
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//Crea Objeto
Cuadrado cuad;
//Crea Estructura para teclado (Control de la figura/Objeto)
typedef struct {
	int w, s, a, d;
}BotonTeclas; BotonTeclas tecla;

void Iniciar() {
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50,50,-50,50);
}

void Dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);
	cuad.Dibuja();
	glutSwapBuffers();
}

// Cuando la tecla es presionada
void TeclaAbajo(unsigned char teclas, int x, int y) {
	if (teclas == 'w') { tecla.w = 1; }
	if (teclas == 's') { tecla.s = 1; }
	if (teclas == 'a') { tecla.a = 1; }
	if (teclas == 'd') { tecla.d = 1; }

	switch (teclas) {
	case 27:
		exit(0); // Al precionar escape (Esc) se cierra el progrma 
		//Visita la pagina de codigo ASCII: https://elcodigoascii.com.ar/
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

//Cuando la tecla deja de estar presionada
void TeclaArriba(unsigned char teclas, int x, int y) {
	if (teclas == 'w') { tecla.w = 0; }
	if (teclas == 's') { tecla.s = 0; }
	if (teclas == 'a') { tecla.a = 0; }
	if (teclas == 'd') { tecla.d = 0; }
	glutPostRedisplay();
}

void Actualiza() {
	float velocidad = 0.02f;
	if (tecla.w == 1) { cuad.setPosY(cuad.getPosY() + velocidad); }
	if (tecla.s == 1) { cuad.setPosY(cuad.getPosY() - velocidad); }
	if (tecla.d == 1) { cuad.setPosX(cuad.getPosX() + velocidad); }
	if (tecla.a == 1) { cuad.setPosX(cuad.getPosX() - velocidad); }
	glutPostRedisplay();
}

int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(50,50);
	glutCreateWindow("COLISION 2D");

	Iniciar();
	glutDisplayFunc(Dibuja);
	glutIdleFunc(Actualiza);
	glutKeyboardFunc(TeclaAbajo); glutKeyboardUpFunc(TeclaArriba); // LLamanos a las funciones creadas anteriormente 
	glutMainLoop();
	return 0;
}