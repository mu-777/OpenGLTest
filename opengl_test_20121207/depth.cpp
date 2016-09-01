
//�A�ʏ����̎d��


#include <GL/glut.h>
//------ �e��O���ϐ� --------//
enum { OFF,ON };
	
//-------------  �v���g�^�C�v�錾  ----------------//
void display();
void reshape(int w, int h);
void SpecialKey(int key, int x, int y);
void menu(int val);

void DRAW_XYZ();
void DRAW_TRI();



int main(int argc, char **argv){

	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_RGBA| GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow("Depth Buffer");

	//�`��֐�
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutSpecialFunc(SpecialKey);

	////�E�N���b�N���j���[
	//glutCreateMenu(menu);
	//glutAddMenuEntry("ON", ON);
	//glutAddMenuEntry("OFF", OFF);
	//glutAttachMenu(GLUT_RIGHT_BUTTON);

	//glClearColor(1.0, 1.0, 1.0, 1.0);
	//glEnable(GL_DEPTH_TEST); //z�o�b�t�@�L����

	glutMainLoop();
	
	return 0;
}



//------------ ��������e��R�[���o�b�N -----------------//
double z = 0;

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	DRAW_XYZ(); //XYZ���̕`��

	glPushMatrix();
	glColor3d(0,1,0);
	DRAW_TRI(); //�`��
	glPopMatrix();

	glPushMatrix();
	glColor3d(1,1,0);
	glTranslated(0,0,2);
	glTranslated(0,0,z);
	DRAW_TRI();  //�`��
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void menu(int val){
	switch(val){
	case ON:
		glEnable(GL_DEPTH_TEST);
		break;
	case OFF:
		glDisable(GL_DEPTH_TEST);
		break;
	}

	glutPostRedisplay();//�ĕ`��
}

//�L�[�{�[�h����
void SpecialKey(int key, int x, int y){
	switch (key) {
	case GLUT_KEY_UP:
		z-=0.1;
		break;
	case GLUT_KEY_DOWN:
		z+= 0.1;
		break;
	default:
		break;
	}
	glutPostRedisplay(); //�ĕ`��
}

//----------- ��������e��֐� ---------------//
void DRAW_XYZ(){
	glBegin(GL_LINES);
	glColor3d(0,1,0);//x
		glVertex2d(-100,0);
		glVertex2d(100, 0);
	glColor3d(1,0,0);//y
		glVertex2d(0,0);
		glVertex2d(0,100);
	glColor3d(0,0,1);//z
		glVertex3d(0,0,-100);
		glVertex3d(0,0, 100);
	glEnd();
}

void DRAW_TRI(){
	glBegin(GL_TRIANGLES);
		glVertex2d(0,1);
		glVertex2d(-0.5, 0);
		glVertex2d(0.5, 0);
	glEnd();
}
