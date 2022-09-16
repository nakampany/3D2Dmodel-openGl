#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <opengl.ft>



#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (720)

#define BLOCK_WIDTH (256)
#define BLOCK_HEIGHT (32)

#define BLOCK_COLUM_MAX (BLOCK_WIDTH/BLOCK_HEIGHT)
#define BLOCK_ROW_MAX (6)

#define PADDLE_WIDTH (256)
#define PADDLE_HEIGHT (32)

#define BALL_SCALE (8)
#define BALL_SPEED (WINDOW_HEIGHT / (1000.0f))

typedef struct {
	bool isBroken;
}BLOCK;

typedef struct {
	glm::vec2 position;
}PADDLE;

typedef struct {
	glm::vec2 position;
	glm::vec2 lastPosition;
	glm::vec2 velocity;
}BALL;

BLOCK blocks[BLOCK_ROW_MAX][BLOCK_COLUM_MAX];
PADDLE paddle;
BALL ball;

void Init(void) {
	memset(blocks, 0, sizeof blocks);
	paddle.position = { WINDOW_WIDTH / 2 - PADDLE_WIDTH / 2,WINDOW_HEIGHT - PADDLE_HEIGHT * 3 };

	ball.lastPosition = 
	ball.position = { WINDOW_WIDTH / 2,BLOCK_HEIGHT * BLOCK_ROW_MAX };
	ball.velocity = { BALL_SPEED,BALL_SPEED };
	ball.velocity - glm::normalize(ball.velocity) * BALL_SPEED;
}

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for (int y = 0; y < BLOCK_ROW_MAX; y++) {
		const unsigned char colors[][3] = {
			{0xff,0x00,0x00},
			{0xff,0xff,0x00},
			{0x00,0xff,0x00},
			{0x00,0xff,0xff},
			{0x00,0x00,0xff},
			{0xff,0x00,0xff} };
		glColor3ubv((GLubyte*)&colors[y]);
			for (int x = 0; x < BLOCK_COLUM_MAX; x++) {
				if (blocks[y][x].isBroken)
					continue;

				glPushMatrix();
				{
					glTranslated(BLOCK_WIDTH * x, BLOCK_HEIGHT * y,0);
					glBegin(GL_QUADS);
					{
						glVertex2d(0, 0);
						glVertex2d(0, BLOCK_HEIGHT - 1);
						glVertex2d(BLOCK_WIDTH - 1, BLOCK_HEIGHT - 1);
						glVertex2d(BLOCK_WIDTH - 1, 0);
					}
					glEnd();
				}
				glPopMatrix();
			}
		}


	glColor3ub(0xff, 0xff, 0xff);
	glPushMatrix();
	{
		glTranslatef(paddle.position.x, paddle.position.y, 0);
		glBegin(GL_QUADS);
		{
			glVertex2d(0, 0);
			glVertex2d(0, PADDLE_HEIGHT);
			glVertex2d(PADDLE_WIDTH, PADDLE_HEIGHT);
			glVertex2d(PADDLE_WIDTH, 0);
		}
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(ball.position.x, ball.position.y, 0);
		glScalef(BALL_SCALE, BALL_SCALE, 0);
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex2d(0, 0);
			int n = 32;
			for (int i = 0; i <= n; i++) {
				float r = glm::pi <float>() * 2 * i / n;
				glVertex2f(cosf(r), -sinf(r));
			}
		}
		glEnd();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void Idle(void) {
	ball.lastPosition = ball.position;
	ball.position += ball.velocity;

	if (ball.position.y >= WINDOW_HEIGHT) {
		Init();
		glutPostRedisplay();
		return;
	}

	if ((ball.position.x < 0) || (ball.position.x >= WINDOW_WIDTH)) {
		ball.position = ball.lastPosition;
		ball.velocity.x *= -1.0f;
	}

	if ((ball.position.y< 0) || (ball.position.y >= WINDOW_HEIGHT)) {
		ball.position = ball.lastPosition;
		ball.velocity.y *= -1.0f;
	}
	if ((ball.position.x >= paddle.position.x) && (ball.position.x < paddle.position.x + PADDLE_WIDTH)
		&& (ball.position.y >= paddle.position.y) && (ball.position.y < paddle.position.y + PADDLE_HEIGHT)) {
		ball.position = ball.lastPosition;
		float paddleCenterX = paddle.position.x + PADDLE_WIDTH / 2;
		ball.velocity.x = (ball.position.x - paddleCenterX) / (PADDLE_WIDTH / 2)*2;
		ball.velocity.y = -glm::sign(ball.velocity.y);
		ball.velocity = glm::normalize(ball.velocity) * BALL_SPEED;
	}

	{
		int x = (int)ball.position.x / BLOCK_WIDTH;
		int y = (int)ball.position.y / BLOCK_HEIGHT;
		if ((x >= 0) && (y < BLOCK_COLUM_MAX) && (y >= 0) && (y < BLOCK_ROW_MAX)
			&&(!blocks[y][x].isBroken)) {
			ball.position = ball.lastPosition;
			blocks[y][x].isBroken = true;

			if ((ball.lastPosition.y < BLOCK_HEIGHT) || (ball.lastPosition.y >= BLOCK_HEIGHT * (y + 1))) 
				ball.velocity.y *= -1.0f;
			else
				ball.velocity.x *= -1.0f;
		}

	}

	glutPostRedisplay();
}

void PassiveMotion(int _x, int _y) {
	paddle.position.x = (float)_x - PADDLE_WIDTH/2;
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("title");
	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutPassiveMotionFunc(PassiveMotion);
	Init();
	glutMainLoop();

}