/*   dog.c  �Ȃ�Ƃт����錢  Yoshiko.TOMONO   */
#include<stdio.h>
#include<math.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

static int rotx=0,roty=0,rotz=0;
static int jump,i=0,j=0,n;
static float deg=0.0,smi=0.0;
static float boul=0.0,bour=0.0,bounl=0.0,bounr=0.0,bouku=0.0,bounku=0.0;
static float a=1.0,b=1.0,c=1.0,d=0.0,e=0.0;
static float rs=1.0,gs=0.0,bs=1.0;
static float fdeg=0.0,hana=0.0,k=0.0,l=0.0;

GLfloat mat_ambient[]={1.0,1.0,1.0,1.0};  /* �� */
GLfloat mat_diffuse[]={1.0,1.0,1.0,1.0};
GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
GLfloat mat_ambient1[]={0.0,0.0,0.0,1.0};  /* �� */
GLfloat mat_diffuse1[]={0.0,0.0,0.0,1.0};
GLfloat mat_specular1[]={0.0,0.0,0.0,1.0};
GLfloat mat_ambient2[]={1.0,1.0,0.0,1.0};  /* �� */
GLfloat mat_diffuse2[]={1.0,1.0,0.0,1.0};
GLfloat mat_specular2[]={1.0,1.0,0.0,1.0};
GLfloat mat_ambient3[]={0.0,0.0,1.0,1.0};  /* �� */
GLfloat mat_diffuse3[]={0.0,0.0,1.0,1.0};
GLfloat mat_specular3[]={0.0,0.0,1.0,1.0};
GLfloat mat_ambient4[]={0.8,0.3,0.2,1.0};  /* �� */
GLfloat mat_diffuse4[]={0.8,0.3,0.2,1.0};
GLfloat mat_specular4[]={0.8,0.3,0.2,1.0};
GLfloat mat_ambient5[]={1.0,0.0,0.0,1.0};  /* �� */
GLfloat mat_diffuse5[]={1.0,0.0,0.0,1.0};
GLfloat mat_specular5[]={1.0,0.0,0.0,1.0};
GLfloat mat_ambient6[]={1.0,0.7,0.4,1.0};  /* ���F */
GLfloat mat_diffuse6[]={1.0,0.7,0.4,1.0};
GLfloat mat_specular6[]={1.0,0.7,0.4,1.0};
GLfloat mat_ambient7[]={0.0,1.0,0.0,1.0};  /* �ΐF */
GLfloat mat_diffuse7[]={0.0,1.0,0.0,1.0};
GLfloat mat_specular7[]={0.0,1.0,0.0,1.0};
GLfloat mat_ambient8[]={0.5,1.0,0.0,1.0};  /* �ΐF2 */
GLfloat mat_diffuse8[]={0.5,1.0,0.0,1.0};
GLfloat mat_specular8[]={0.5,1.0,0.0,1.0};
GLfloat mat_shininess[]={50.0};
GLfloat light_position[]={20.0,30.0,30.0,0.0};

void init(void)
{
    glClearColor(rs,gs,bs,0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void clip(void)
{
	float i;
	GLdouble eqn[4]={1.0,0.0,0.0,0.0};      /*  x>0  */
	GLdouble eqn2[4]={-1.0,0.0,0.0,0.0};    /*  x<0  */
	GLdouble eqn3[4]={0.0,1.0,0.0,0.0};     /*  y>0  */
	GLdouble eqn4[4]={0.0,-1.0,0.0,0.0};    /*  y<0  */
	GLdouble eqn5[4]={0.0,0.0,1.0,0.0};     /*  z>0  */
	GLdouble eqn6[4]={0.0,0.0,-1.0,0.0};    /*  z<0  */
/*  �n��  */
    /*z������*/
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient7);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse7);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular7);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3d(0.0,1.0,0.0);	
	for(i=0;i<=120;i+=3.0){
		glVertex3f(60.0-i,-40.0,60.0);
		glVertex3f(60.0-i,-40.0,-60.0);
	}
	glEnd();
    /*x������*/
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient8);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse8);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular8);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glBegin(GL_LINES);
	glColor3d(0.0,1.0,0.0);
	for(i=0;i<=120;i+=3.0){
		glVertex3f(60.0,-40.0,60.0-i);
		glVertex3f(-60.0,-40.0,60.0-i);
	}
	glEnd();

/*  �Ȃ�  */ 
	glPushMatrix();
	jump=jump-9.0;
	glTranslated(0.0,jump-5.0,-4.0);
	glRotated(deg+50,1.0,0.0,0.0);
	glScaled(0.8,1.3,1.0);
	glClipPlane(GL_CLIP_PLANE0,eqn5);  //z>0
	glEnable(GL_CLIP_PLANE0);
	glTranslated(0.0,0.0,1.0);
	glClipPlane(GL_CLIP_PLANE1,eqn6);  //z<0
	glEnable(GL_CLIP_PLANE1);
	glTranslated(0.0,0.0,-1.0);
	glClipPlane(GL_CLIP_PLANE2,eqn4);  //y<0
	glEnable(GL_CLIP_PLANE2);
	glTranslated(0.0,-4.0,0.0);
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient5);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse5);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular5);
	glutSolidSphere(25.0,50.0,50.0);
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glPopMatrix();
jump=jump+9.0;

/*  ��  */	
    /*  ����  */
	glPushMatrix();
	glLineWidth (2.0);
	glBegin(GL_LINES);
	  glVertex3f(-3.5,16.5+jump,6.0);
	  glVertex3f(-6.0,17.0+jump+smi,6.0);
    glEnd();
	glPopMatrix();
    /*  �E��  */
	glPushMatrix();
	glBegin(GL_LINES);
	  glVertex3f(3.5,16.5+jump,6.0);
	  glVertex3f(6.0,17.0+jump+smi,6.0);
	glEnd();
	glPopMatrix();
/*  ��  */
	/*  ����  */
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient1);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse1);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glTranslated(-3.5,12.0+jump,6.5);
	glutSolidSphere(1.5,20.0,20.0);
	glPopMatrix();
    /*  �E��  */
	glPushMatrix();
	glTranslated(3.5,12.0+jump,6.5);
	glutSolidSphere(1.5,20.0,20.0);
	glPopMatrix();
/*  �@  */
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient1);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse1);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glTranslated(0.0,10.0+jump,10.5);
	glRotated(-20.0,1.0,0.0,0.0);
	glRotated(90.0,0.0,1.0,0.0);
	glScaled(1.0,1.0,1.4);
    glutSolidSphere(1.7,20.0,20.0);
	glPopMatrix();
/*  ��  */
	/*  �牺��  */
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient6);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse6);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular6);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glTranslated(0.0,5.5+jump,2.9);
	glScaled(1.3,1.2,1.4);
	glRotated(90.0,1.0,0.0,0.0);
	glutSolidSphere(6.0,50.0,50.0);
	glPopMatrix();
	/*  ��㕔  */
	glPushMatrix();
	glTranslated(0.0,10.0+jump,-3.0);
	glScaled(2.3,2.7,2.3);
	glRotated(90.0,1.0,0.0,0.0);
	glutSolidSphere(4.8,30.0,30.0);
	glPopMatrix();

	/*  ����  */
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient4);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse4);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular4);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glTranslated(13.0+bounl,8.0+jump+bounl,-3.0);	
	glRotated(30.0+boul,0.0,0.0,1.0);
	glScaled(0.8,3.0,2.0);
	glutSolidSphere(2.5,20.0,20.0);
	glPopMatrix();
	/*   �E��  */
	glPushMatrix();
	glTranslated(-13.0+bounr,8.0+jump-bounr,-3.0);
	glRotated(-30.0+bour,0.0,0.0,1.0);
	glScaled(0.8,3.0,2.0);
	glutSolidSphere(2.5,20.0,20.0);
	glPopMatrix();
	/*�@���́@*/
	glPushMatrix();
	glTranslated(0.0,-20.0+jump,3.0);
	glClipPlane(GL_CLIP_PLANE0,eqn3);  /*�@�N���b�v���ʂ̒�`�@y>0*/
	glEnable(GL_CLIP_PLANE0);  /*�@��`�����N���b�v���ʂ�L�����@*/
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient6);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse6);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular6);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glTranslated(0.0,3.0,-3.0);
	glRotated(-8.0,1.0,0.0,0.0);
	glScaled(1.0,1.5,0.9);
	glutSolidSphere(9.0,20.0,20.0);
	glDisable(GL_CLIP_PLANE0);  /*�@�N���b�v���ʂ̖������@*/
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.0,-19.0+jump,0.0);
	glRotated(-8.0,1.0,0.0,0.0);
	glScaled(1.0,1.0,0.9);
	glutSolidSphere(9.0,20.0,20.0);
	glPopMatrix();

	/*  ��  */
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient6);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse6);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular6);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glTranslated(0.0,-2.0+jump,-3.0);
	glScaled(1.0,3.0,1.0);
	glutSolidSphere(2.0,20.0,20.0);
	glPopMatrix();
	/*  ���  */
    glPushMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient5);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse5);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular5);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glTranslated(0.0,-4.0+jump+bounku,-3.0);
	glRotated(-10.0+bouku,1.0,0.0,0.0);
	glScaled(2.0,0.5,2.0);
	glutSolidSphere(2.0,20.0,20.0);
	glPopMatrix();

	/*  ���r  */ 
    /*  ����r  */
	glPushMatrix();
	glTranslated(10.5,-12.0+jump,-3.0);
	glRotated(60.0,0.0,0.0,1.0);
	glClipPlane(GL_CLIP_PLANE0,eqn3);    //y>0
	glEnable(GL_CLIP_PLANE0);  
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient6);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse6);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular6);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glScaled(0.8,3.5,1.0);
	glutSolidSphere(2.8,20.0,20.0);
	glDisable(GL_CLIP_PLANE0); 
	glPopMatrix();
	/*  �����r  */
	glPushMatrix();
	glTranslated(10.5,-12.0+jump,-3.0);
	glRotated(70.0,0.0,0.0,1.0);
	glClipPlane(GL_CLIP_PLANE0,eqn4);  //y<0
	glEnable(GL_CLIP_PLANE0);  
	glScaled(0.8,3.5,1.0);
	glutSolidSphere(2.8,20.0,20.0);
	glDisable(GL_CLIP_PLANE0); 
	glPopMatrix();
	/*  �E�r  */
    /*  �E��r  */
	glPushMatrix();
	glTranslated(-10.5,-12.0+jump,-3.0);
	glRotated(-60.0,0.0,0.0,1.0);
	glClipPlane(GL_CLIP_PLANE0,eqn3);  //y>0
	glEnable(GL_CLIP_PLANE0);  
	glScaled(0.8,3.5,1.0);
	glutSolidSphere(2.8,20.0,20.0);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();
	/*  �E���r  */
	glPushMatrix();
	glTranslated(-10.5,-12.0+jump,-3.0);
	glRotated(-70.0,0.0,0.0,1.0);
	glClipPlane(GL_CLIP_PLANE0,eqn4);   //y<0
	glEnable(GL_CLIP_PLANE0);  
	glScaled(0.8,3.5,1.0);
	glutSolidSphere(2.8,20.0,20.0);
	glDisable(GL_CLIP_PLANE0); 
	glPopMatrix();
	/*  ����  */
	glPushMatrix();
	glTranslated(3.0,-35.0+jump,-3.0);
	glClipPlane(GL_CLIP_PLANE0,eqn3);     //y>0
	glEnable(GL_CLIP_PLANE0);
	glScaled(1.0,3.8,1.0);
	glutSolidSphere(2.8,20.0,20.0);
	glDisable(GL_CLIP_PLANE0);  
	glPopMatrix();
	glPushMatrix();
	glTranslated(4.0,-36.0+jump,-1.0);
	glScaled(1.5,0.8,2.0);
	glutSolidSphere(3.0,20.0,20.0);
	glPopMatrix();

	/*  �E��  */
	glPushMatrix();
	glTranslated(-3.0,-35.0+jump,-3.0);
	glClipPlane(GL_CLIP_PLANE0,eqn3);   //y>0
	glEnable(GL_CLIP_PLANE0);
	glScaled(1.0,3.8,1.0);
	glutSolidSphere(2.8,20.0,20.0);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-4.0,-36.0+jump,-1.0);
	glScaled(1.5,0.8,2.0);
	glutSolidSphere(3.0,20.0,20.0);
	glPopMatrix();

/*  ������  */
	glPushMatrix();
    glTranslated(0.0,-25.0+jump+bounl,-10.5);
	glRotated(30.0+boul,1.0,0.0,0.0);
	glScaled(1.0,3.0,1.0);
	glutSolidSphere(2.0,20.0,20.0);
	glPopMatrix();
glPopMatrix();
   	glDisable(GL_CLIP_PLANE0);
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotated((double)rotx,1.0,0.0,0.0);
	glRotated((double)roty,0.0,1.0,0.0);
	glRotated((double)rotz,0.0,0.0,1.0);
	glColor3d(0.0,0.0,0.0);
	clip();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void x1rotation(void)
{
	rotx+=12; rotx%=360;  draw();
}
void x2rotation(void)
{
	rotx-=12; rotx%=360;  draw();
}
void y1rotation(void)
{
	roty+=12; roty%=360;  draw();
}
void y2rotation(void)
{
	roty-=12; roty%=360;  draw();
}
void z1rotation(void)
{
	rotz+=12; rotz%=360;  draw();
}
void z2rotation(void)
{
	rotz-=12; rotz%=360;  draw();
}

void jumpup(void)    //�O����
{
	for(i=0;i<=5;i++){
		deg+=30.0;  
		jump+=1.2; 
		draw();}
		boul+=42.0;  bounl+=3.0;
		bour-=42.0;  bounr-=3.0; 
		bouku+=18.0; bounku+=1.2;
	for(j=0;j<=5;j++){
		deg+=30.0;         
		jump-=1.2;        
		boul-=7.0;  bounl-=0.5;   
		bour+=7.0;  bounr+=0.5;
		bouku-=3.0; bounku-=0.2;
		draw();}  
}
void jumpupb(void)   //��뒵��
{
	for(i=0;i<=5;i++){
		deg-=30.0;  
		jump+=1.2; 
		draw();}
		boul+=42.0;  bounl+=3.0;
		bour-=42.0;  bounr-=3.0;
		bouku+=18.0; bounku+=1.2;
	for(j=0;j<=5;j++){
		deg-=30.0;       //�Ȃ�̉�]�p�x
		jump-=1.2;
		boul-=7.0;  bounl-=0.5;     //�����̒e��
		bour+=7.0;  bounr+=0.5;     //�E���̒e��
		bouku-=3.0; bounku-=0.2;    //��ւ̒e��
	    draw();}
}

void sky(void)     //��̐F�ω�    
{
	rs=rs-0.1;
	if(rs<=0.2)rs=rs+0.5;
	init();
}
void smile1(void)  //��up
{
	smi=smi+1.0; draw();
}
void smile2(void)  //��down
{
	smi=smi-1.0; draw();
}
void sizes(void)   //�k��
{
	a=a-0.1;  b=b-0.1;  c=c-0.1;
	d=d-1.8;    e=e+5.0;
	draw();
}
void sizel(void)   //�g��
{
	a=a+0.1;  b=b+0.1;  c=c+0.1;
	d=d+1.8;  e=e-5.0;
	draw();
}

void key_press(unsigned char key,int mpx,int mpy)
{
	if(key=='x')x1rotation();
	if(key=='X')x2rotation();
	if(key=='y')y1rotation();
	if(key=='Y')y2rotation();
	if(key=='z')z1rotation();
	if(key=='Z')z2rotation();
	if(key=='j'){jumpup();  sky();}
    if(key=='J'){jumpupb(); sky();}
    if(key=='s')sizes();
    if(key=='S')sizel();
	if(key=='w'){smile1();}
	if(key=='W'){smile2();}
}
void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,20.0,100.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

int main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Dog");
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key_press);
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
