/* Opengl�̊֐��������g�������̕`�� 							*/
#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void draw_line(void){
	glClear(GL_COLOR_BUFFER_BIT);		 /* �`��o�b�t�@�̃N���A */
	glColor3d(1.0,1.0,1.0);			   /* �`�悷��G�̐F�F(r,g,b)*/
	glBegin(GL_LINES);								 /* �����w�� */
		glVertex2d(0.0,0.0);						 /* ���̎n�_ */
		glVertex2d(100.0,100.0);					 /* ���̏I�_ */
	glEnd();								   /* ���w��̏I��� */
	glFlush();					   /* ���ׂẴo�b�t�@���e��`�� */
}

void ginit(void){
	glClearColor(0.0,0.0,0.0,0.0);	   /* �`��o�b�t�@�����ɂ��� */
	glMatrixMode(GL_PROJECTION);   /* �ϊ��s����ˉe���[�h�ɂ��� */
	glLoadIdentity();			/* �ϊ��s��ɒP�ʍs���ݒ肷��B*/
	glOrtho(-256.0,256.0,-256.0,256.0,-1.0,1.0);
					 /* ���ˉe�̎w��							 */
					 /* ��=-256.0  �E=256.0  ��=-256.0  ��=256.0 */
					 /*	��O=-1.0  ���s=1.0�i�񎟌��j			 */
}

int main(int argc,char **argv){
	
glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);/*�`���ʂ�RGB�ꖇ*/
	glutInitWindowSize(512,512);		/* ��ʃT�C�Y�F512 x 512 */
	glutInitWindowPosition(280,0);		  /* ��ʂ̏����ʒu(x,y) */
	glutCreateWindow("Opengl_Window");		   /* �`���ʂ̖��O */
	ginit();
	glutDisplayFunc(draw_line);
	glutMainLoop();
	return 0;
}
