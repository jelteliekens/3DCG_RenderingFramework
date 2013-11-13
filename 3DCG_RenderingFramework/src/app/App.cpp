#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "Renderer.h"
#include "Camera.h"
#include "Scene.h"
#include "SceneFactory.h"
#include "Sphere.h"
#include "Quaternion.h"

#include "Vector.h"
#include <iostream>

Renderer * renderer;
Camera * camera;

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
}

void renderScene(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear (GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	glDisable (GL_LIGHTING);
	renderer->render();
	glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
	if (key == 'f') {
		camera->forward();
	} else if (key == 'b') {
		camera->backward();
	}
	glutPostRedisplay();
}

void keySpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		camera->up();
	} else if (key == GLUT_KEY_DOWN) {
		camera->down();
	} else if (key == GLUT_KEY_RIGHT) {
		camera->right();
	} else if (key == GLUT_KEY_LEFT) {
		camera->left();
	}

	glutPostRedisplay();
}

int main(int argc, char ** argv) {
	AppConfiguration appCfg = AppConfigurationFileReader::read(argv[1]);
	camera = new Camera(appCfg);
	Scene scene = SceneFactory::createScene(appCfg["scene.file"]);
	renderer = new Renderer(camera, scene, appCfg);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	int nCols = std::atoi(appCfg["image.nCols"].c_str());
	int nRows = std::atoi(appCfg["image.nRows"].c_str());
	glutInitWindowSize(nCols, nRows);
	glutCreateWindow("3D Computer Graphics 2");
	glutReshapeFunc(reshape);
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(keySpecial);
	glutMainLoop();
	delete camera;
	delete renderer;
	return 0;
}
