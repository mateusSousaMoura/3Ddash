#include <GL/glut.h>

bool isButtonPressed = false;
int selectedLevel = 0;

void menuCallback(int choice) {
    switch (choice) {
        case 1:
            selectedLevel = 1;
            break;
        case 2:
            selectedLevel = 2;
            break;
        case 3:
            selectedLevel = 3;
            break;
        default:
            break;
    }

    glutPostRedisplay();
}

void drawButton(float x, float y, float width, float height, const char* label) {
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x + 0.5 * (width - 8 * strlen(label)), y + height * 0.5); // Ajuste de posicionamento
    for (const char* c = label; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }

    glPopMatrix();
}

void createMenu() {
    int submenu = glutCreateMenu(menuCallback);
    glutAddMenuEntry("Fácil", 1);
    glutAddMenuEntry("Médio", 2);
    glutAddMenuEntry("Difícil", 3);

    glutCreateMenu(menuCallback);
    glutAddSubMenu("Selecionar Nível", submenu);
    glutAddMenuEntry("Sair", 0);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawButton(150, 200, 100, 40, "Iniciar Jogo");
    drawButton(150, 150, 100, 40, "Opções");
    drawButton(150, 100, 100, 40, "Sair");

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(10, 10);
    switch (selectedLevel) {
        case 1:
            for (const char* c = "Nível: Fácil"; *c != '\0'; ++c) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
            }
            break;
        case 2:
            for (const char* c = "Nível: Médio"; *c != '\0'; ++c) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
            }
            break;
        case 3:
            for (const char* c = "Nível: Difícil"; *c != '\0'; ++c) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
            }
            break;
        default:
            break;
    }

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x >= 150 && x <= 250 && y >= 200 && y <= 240) {
            isButtonPressed = true;
        }
    }
}

void motion(int x, int y) {
    if (isButtonPressed) {
        // Adicione lógica para o movimento do mouse enquanto um botão está pressionado, se necessário
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("Menu de Escolha de Níveis");
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);

    createMenu();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 400, 0, 300);

    glutMainLoop();
    return 0;
}
