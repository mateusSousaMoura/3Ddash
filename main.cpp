#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

const int numRows = 10;
const int numCols = 200;
int matrix[numRows][numCols] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
float pyramidLength = 2.0f; // Comprimento de uma pirâmide
float cubeHeight = 2.0f;    // Altura do cubo
float cameraSpeed = 0.6f;   // Velocidade de movimento da câmera
float jumpSpeed = 1.0f;     // Velocidade do pulo
float gravity = 0.4f;    // Velocidade do pulo
float cameraX = 0.0f;       // Posição inicial da câmera em x
float cubeY = 0.0f;         // Altura do cubo
float jumpHeight = 14.0f;

bool jumping = false;       // Flag indicando se o cubo está pulando

void drawGround() {
    glBegin(GL_QUADS);
    glColor3d(0.5, 0.5, 0.5);
    glVertex3f(-50.0f, 0.0f, -50.0f);
    glVertex3f(50.0f, 0.0f, -50.0f);
    glVertex3f(50.0f, 0.0f, 50.0f);
    glVertex3f(-50.0f, 0.0f, 50.0f);
    glEnd();
}

void drawPyramid(float x, float y, float z, int heightIndex) {
    glBegin(GL_TRIANGLES);
    glColor3d(0.65, 0.79, 0.34);
    glVertex3f(x, y + 3.0f + heightIndex * pyramidLength, z);
    glVertex3f(x - 1.0f, y + heightIndex * pyramidLength, z - 1.0f);
    glVertex3f(x + 1.0f, y + heightIndex * pyramidLength, z - 1.0f);

    glVertex3f(x, y + 3.0f + heightIndex * pyramidLength, z);
    glVertex3f(x + 1.0f, y + heightIndex * pyramidLength, z - 1.0f);
    glVertex3f(x + 1.0f, y + heightIndex * pyramidLength, z + 1.0f);

    glVertex3f(x, y + 3.0f + heightIndex * pyramidLength, z);
    glVertex3f(x + 1.0f, y + heightIndex * pyramidLength, z + 1.0f);
    glVertex3f(x - 1.0f, y + heightIndex * pyramidLength, z + 1.0f);

    glVertex3f(x, y + 3.0f + heightIndex * pyramidLength, z);
    glVertex3f(x - 1.0f, y + heightIndex * pyramidLength, z + 1.0f);
    glVertex3f(x - 1.0f, y + heightIndex * pyramidLength, z - 1.0f);
    glEnd();
}

void drawCube(float x, float y, float z, float sideLength, float height) {
    glBegin(GL_QUADS);
    glColor3d(0.34, 0.65, 0.79); // Cor do cubo
    // Faces do cubo
    glVertex3f(x - sideLength / 2, y, z - sideLength / 2);
    glVertex3f(x + sideLength / 2, y, z - sideLength / 2);
    glVertex3f(x + sideLength / 2, y + height, z - sideLength / 2);
    glVertex3f(x - sideLength / 2, y + height, z - sideLength / 2);

    glVertex3f(x - sideLength / 2, y, z + sideLength / 2);
    glVertex3f(x + sideLength / 2, y, z + sideLength / 2);
    glVertex3f(x + sideLength / 2, y + height, z + sideLength / 2);
    glVertex3f(x - sideLength / 2, y + height, z + sideLength / 2);

    glVertex3f(x - sideLength / 2, y, z - sideLength / 2);
    glVertex3f(x - sideLength / 2, y, z + sideLength / 2);
    glVertex3f(x - sideLength / 2, y + height, z + sideLength / 2);
    glVertex3f(x - sideLength / 2, y + height, z - sideLength / 2);

    glVertex3f(x + sideLength / 2, y, z - sideLength / 2);
    glVertex3f(x + sideLength / 2, y, z + sideLength / 2);
    glVertex3f(x + sideLength / 2, y + height, z + sideLength / 2);
    glVertex3f(x + sideLength / 2, y + height, z - sideLength / 2);

    glVertex3f(x - sideLength / 2, y, z - sideLength / 2);
    glVertex3f(x + sideLength / 2, y, z - sideLength / 2);
    glVertex3f(x + sideLength / 2, y, z + sideLength / 2);
    glVertex3f(x - sideLength / 2, y, z + sideLength / 2);
    glEnd();
}

void drawPlane(float x, float y, float z, int heightIndex) {
    // Desenha um cubo do tamanho da pirâmide
    glBegin(GL_QUADS);
    glColor3d(1.0, 0.0, 0.0); // Cor do cubo do plano
    // Faces do cubo
    glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z - pyramidLength / 2);
    glVertex3f(x - pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z - pyramidLength / 2);

    glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z + pyramidLength / 2);
    glVertex3f(x - pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z + pyramidLength / 2);

    glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
    glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
    glVertex3f(x - pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z + pyramidLength / 2);
    glVertex3f(x - pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z - pyramidLength / 2);

    glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z + pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z - pyramidLength / 2);

    glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
    glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
    glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
    glEnd();
}

void checkCollision() {
    // Posições do cubo
    float cubeX = cameraX;
    float cubeZ = 0.0f;

    // Verifica a colisão com cada pirâmide
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (matrix[i][j] == 1) {  // Verifica se há uma pirâmide nesta posição
                float pyramidX = j * 2.0f - numCols;  // Calcula a posição x da pirâmide
                float pyramidZ = i * 2.0f - numRows;  // Calcula a posição z da pirâmide

                // Verifica a colisão entre o cubo e a pirâmide
                if (fabs(cubeX - pyramidX) < 1.0f && fabs(cubeZ - pyramidZ) < 1.0f) {
                    // Colisão detectada, reinicia o nível
                    cameraX = 0.0f;
                    cubeY = 0.0f;
                    jumping = false;
                    break;
                }
            }
        }
    }
}

void update(int value) {
    cameraX += cameraSpeed;

    if (cameraX > (numCols - 1) * pyramidLength) {
        cameraX = 0.0f;
    }
    if (jumping) {
        cubeY += jumpSpeed;

        // Verifica se o cubo atingiu a altura máxima do pulo
        if (cubeY >= jumpHeight) {
            jumping = false;
        }
    } else {
        // Aplica a gravidade ao cubo
        cubeY -= jumpSpeed;
        // Impede que o cubo vá abaixo do solo
        if (cubeY < 0.0f) {
            cubeY = 0.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cameraX, 20.0f, 100.0f,
              cameraX, cubeY + cubeHeight / 2, 0.0f,
              0.0f, 1.0f, 0.0f);

    drawGround();
    checkCollision();

    float spacingX = pyramidLength;

    for (int j = 0; j < numCols; ++j) {
        float x = static_cast<float>(j) * spacingX - 50.0f;

        for (int i = 0; i < numRows; ++i) {
            if (matrix[i][j] == 1) {
                drawPyramid(x, 0.0f, 0.0f, i);
            } else if (matrix[i][j] == 2) {
                drawPlane(x, 0.0f, 0.0f, i);
            }
        }
    }

    // Desenha o cubo na mesma reta das pirâmides
    drawCube(cameraX, cubeY, 0.0f, pyramidLength, cubeHeight);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case ' ':
        if (!jumping && cubeY == 0.0f) {
            jumping = true;
        }
        break;
    case 27:
        exit(0);
        break;
    }
}

void init() {
    glEnable(GL_DEPTH_TEST);
}

void runGame() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Jogo de Pirâmides com Cubo");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    init();
    runGame();
    return 0;
}