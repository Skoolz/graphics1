
#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GL/freeglut.h>

GLuint VBO;

void func() {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glDrawArrays(GL_POINTS, 0, 1);
	glDrawArrays(GL_POLYGON, 0, 6);
	//glDrawArrays(GL_LINE_STRIP, 0, 6);
	glDisableVertexAttribArray(0);

	glutSolidTeapot();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 01");
	glutDisplayFunc(func);
	//glClearColor(1.0, 1.0, 0.0, 1.0);

	//GLEW init

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	//glm::vec3 Vertices[1];
	//Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::vec3 Vertices[6];
	for (int i = 0; i < 6; ++i) {
		Vertices[i] = glm::vec3(sin(i / 6.0 * 2 * 3.14),
			cos(i / 6.0 * 2 * 3.14),0.0f);
	}



	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);



	glutMainLoop();
}


