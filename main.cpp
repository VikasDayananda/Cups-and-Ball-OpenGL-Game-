#include<windows.h>

#include<stdio.h>
#include <GL\glut.h>


int score=0;
static GLuint texture;
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
void draw();
void reset(void);

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=0.3;




 GLdouble viewer[]= {0.0,0.3,1.0}; /* initial viewer location */
 GLfloat xRot = 0.0f;
 GLfloat yRot = -0.7f;
 GLfloat zRot = 0.0f;
 GLfloat y1Cup = 0.0f;
 GLfloat y2Cup = 0.0f;
 GLfloat y3Cup = 0.0f;
 GLfloat z1Cup = 0.0f;
 GLfloat z2Cup = 0.0f;
 GLfloat z3Cup = 0.0f;
 GLfloat x1Cup = -1.8f;
 GLfloat x2Cup = 0.0f;
 GLfloat x3Cup = 1.8f;
int MenuMode=1;
int GameMode=0;
int GameOver=0;
int win=0;
int next=0;
 GLint moveBall=1;
 GLint ShuffleCups=1;

GLfloat vertices[][3] ={{-0.6,-0.0,-0.5},{0.6,0.0,-0.5},{0.3,0.6,-0.5},{-0.3,0.6,-0.5}, {-0.6,0.0,0.5},{0.6,0.0,0.5},{0.3,0.6,0.5}, {-0.3,0.6,0.5}};
/*GLfloat colors[][3] ={{1.0,0.0,0.0},{1.0,0.0,0.0},{1.0,0.0,0.0},{1.0,0.0,0.0},{1.0,0.0,0.0},{1.0,0.0,0.0},{1.0,0.0,0.0},{1.0,0.0,0.0}};*/

void display(void);
void myReshape(int w, int h);
void mykey(unsigned char key, int x, int y);
void *currentfont;

void Initialize1()
{
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	//glEnable(GL_LIGHT3);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[]	= {0.24725,0.1995,0.0745,1.0};
	GLfloat qaDiffuseLight[]	= {0.75164,0.60648,0.22648,1.0};
	GLfloat qaSpecularLight[]	= {0.628281,0.555802,0.366065,1.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);

	glLightfv(GL_LIGHT2, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT2, GL_SPECULAR, qaSpecularLight);

	glLightfv(GL_LIGHT3, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT3, GL_SPECULAR, qaSpecularLight);


	GLfloat qaLightPosition1[]	= {0.0,0.2,0.5,1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition1);

	GLfloat qaLightPosition2[]	= {0.0,0.2,-0.5,1.0};
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition2);

	GLfloat qaLightPosition3[]	= {2.0,0.5,0.0,0.0};
	glLightfv(GL_LIGHT2, GL_POSITION, qaLightPosition3);

	/*GLfloat qaLightPosition3[]	= {1.8,0.2,-0.5,1.0};
	glLightfv(GL_LIGHT3, GL_POSITION, qaLightPosition3);*/
}

void Initialize2()
{

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[]	= {0.19225,0.19225,0.19225, 1.0};
	GLfloat qaDiffuseLight[]	= {0.50754,0.50754,0.50754, 1.0};
	GLfloat qaSpecularLight[]	= {0.508273,0.508273,0.508273, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[]	= {0.0,0.0,1.0,0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}
void setFont(void *font)
{
	currentfont=font;
}
void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void menu(int num)
{
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
    moveBall=1;
    ShuffleCups=1;
    MenuMode=0;
  }
  display();
}
void createMenu(void){     submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Level 1", 2);
    glutAddMenuEntry("Level 2", 3);
    glutAddMenuEntry("Level 3", 4);
    glutAddMenuEntry("Level 4", 5);
    glutAddMenuEntry("Level 5", 6);

    menu_id = glutCreateMenu(menu);
    glutAddSubMenu("Play", submenu_id);
    glutAddMenuEntry("Help", 7);
    glutAddMenuEntry("About", 1);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void polygon(int a, int b,int c , int d)
{
    glBegin(GL_POLYGON);
      glVertex3fv(vertices[a]);
      glVertex3fv(vertices[b]);
      glVertex3fv(vertices[c]);
      glVertex3fv(vertices[d]);
	glEnd();
}

void colorcube(void)
{
    glColor3f(1.0,0.0,0.0);
	polygon(0,3,2,1);
    glColor3f(0.0,1.0,0.0);
	polygon(2,3,7,6);
	glColor3f(0.0,0.0,1.0);
	polygon(0,4,7,3);
	glColor3f(0.0,0.0,1.0);
	polygon(1,2,6,5);
	glColor3f(1.0,0.0,0.0);
	polygon(4,5,6,7);
	//polygon(0,1,5,4);
}
void moveCups()
{
    if(moveBall)
         {
          for(int i=0;i<900;i++)
            {
             yRot+=0.001;
             moveBall=0;
             display();
            }
        if(ShuffleCups && value==2)
        {
          for(int a=0;a<=44;a++)   /*move cups 2 and 3*/
          {
           ShuffleCups=0;
           x2Cup+=0.02;
           z2Cup-=0.04;
           x3Cup-=0.02;
           z3Cup+=0.04;
           xRot+=0.02;
           zRot-=0.04;
           display();

          }
         for(int b=0;b<=44;b++)
         {
           x2Cup+=0.02;
           z2Cup+=0.04;
           x3Cup-=0.02;
           z3Cup-=0.04;
           xRot+=0.02;
           zRot+=0.04;
           display();

          }
         for(int a=0;a<=44;a++)
        {
           x1Cup+=0.02;
           z1Cup-=0.04;
           x3Cup-=0.02;
           z3Cup+=0.04;

           display();

         }
        for(int b=0;b<=44;b++)
       {
           x1Cup+=0.02;
           z1Cup+=0.04;
           x3Cup-=0.02;
           z3Cup-=0.04;
           display();
        }
        for(int a=0;a<=89;a++)   /*move cups 2 and 3*/
       {
           x3Cup+=0.02;
           z3Cup-=0.04;
           x2Cup-=0.02;
           z2Cup+=0.04;
           xRot-=0.02;
           zRot+=0.04;
           display();

       }
        for(int b=0;b<=89;b++)
       {
           x3Cup+=0.02;
           z3Cup+=0.04;
           x2Cup-=0.02;
           z2Cup-=0.04;
           xRot-=0.02;
           zRot-=0.04;
           display();

        }
       for(int a=0;a<=44;a++)
       {
           x2Cup+=0.02;
           z2Cup-=0.04;
           x1Cup-=0.02;
           z1Cup+=0.04;
           xRot+=0.02;
           zRot-=0.04;

           display();

       }
        for(int b=0;b<=44;b++)
        {
           x2Cup+=0.02;
           z2Cup+=0.04;
           x1Cup-=0.02;
           z1Cup-=0.04;
           xRot+=0.02;
           zRot+=0.04;
           display();


        }
         for(int a=0;a<=44;a++)
         {
           x2Cup+=0.02;
           z2Cup-=0.04;
           x3Cup-=0.02;
           z3Cup+=0.04;
           xRot+=0.02;
           zRot-=0.04;
           display();

         }
        for(int b=0;b<=44;b++)
        {
           x2Cup+=0.02;
           z2Cup+=0.04;
           x3Cup-=0.02;
           z3Cup-=0.04;
           xRot+=0.02;
           zRot+=0.04;
           display();
        }
      }
    else if(ShuffleCups && value==3)
      {
           printf("jbhkjkjhkj");
         for(int a=0;a<=26;a++)   /*move cups 2 and 3*/
       {
           ShuffleCups=0;
           x2Cup+=0.033;
           z2Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;
           display();
        }
        for(int b=0;b<=26;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x3Cup-=0.033;
           z3Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;
           display();
        }
      for(int a=0;a<=26;a++)  //move 3 and 2 by 1
       {
           x1Cup+=0.033;
           z1Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;
           display();
      }
        for(int b=0;b<=26;b++)
       {
           x1Cup+=0.033;
           z1Cup+=0.066;
           x3Cup-=0.033;
           z3Cup-=0.066;
           display();
        }
        for(int a=0;a<=53;a++)   /*move cups 2 and 3 by 2*/
       {
           x3Cup+=0.033;
           z3Cup-=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;
           display();

       }
        for(int b=0;b<=53;b++)
       {
           x3Cup+=0.033;
           z3Cup+=0.066;
           x2Cup-=0.033;
           z2Cup-=0.066;
           xRot-=0.033;
           zRot-=0.066;
           display();

      }
       for(int a=0;a<=26;a++) // move 2 and 1 by 1
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x1Cup-=0.033;
           z1Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;
           display();

        }
        for(int a=0;a<=53;a++)   /*move cups 1 and 3 by 1,remain original */
       {
           x1Cup+=0.033;
           z1Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;

           display();

       }
        for(int b=0;b<=53;b++)
       {
           x3Cup+=0.033;
           z3Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;

           display();

      }
       for(int a=0;a<=26;a++) //move 1 and 2 by 1
       {
           x1Cup+=0.033;
           z1Cup-=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x1Cup+=0.033;
           z1Cup+=0.066;
           x2Cup-=0.033;
           z2Cup-=0.066;
           xRot-=0.033;
           zRot-=0.066;
           display();

        }

      }
        else if(ShuffleCups && value==4)
      {


       for(int a=0;a<=26;a++)   /*move cups 2 and 3*/
       {
           ShuffleCups=0;
           x1Cup+=0.033;
           z1Cup-=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;
           display();

       }
        for(int b=0;b<=26;b++)
       {
           x1Cup+=0.033;
           z1Cup+=0.066;
           x2Cup-=0.033;
           z2Cup-=0.066;
           xRot-=0.033;
           zRot-=0.066;
           display();

      }

        for(int a=0;a<=53;a++)
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;
           display();

       }
        for(int b=0;b<=53;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x3Cup-=0.033;
           z3Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;
           display();

      }
       for(int a=0;a<=26;a++) // move 2 and 1 by 1
       {
           x3Cup+=0.033;
           z3Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x3Cup+=0.033;
           z3Cup+=0.066;
           x1Cup-=0.033;
           z1Cup-=0.066;

           display();

        }
         for(int a=0;a<=53;a++)   /*move cups 1 and 3 by 1,remain original */
       {
           x1Cup+=0.033;
           z1Cup-=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;

           display();

       }
        for(int b=0;b<=53;b++)
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;

           display();

      }
       for(int a=0;a<=53;a++)
       {
           x1Cup+=0.033;
           z1Cup-=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;
           display();

       }
        for(int b=0;b<=53;b++)
       {
           x1Cup+=0.033;
           z1Cup+=0.066;
           x2Cup-=0.033;
           z2Cup-=0.066;
           xRot-=0.033;
           zRot-=0.066;
           display();

      }
      for(int a=0;a<=26;a++) // move 2 and 1 by 1
       {
           x3Cup+=0.033;
           z3Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x3Cup+=0.033;
           z3Cup+=0.066;
           x1Cup-=0.033;
           z1Cup-=0.066;


           display();

        }
      for(int a=0;a<=26;a++) // move 2 and 1 by 1
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x1Cup-=0.033;
           z1Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;

           display();

        }
         for(int a=0;a<=26;a++) // move 2 and 1 by 1
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x3Cup-=0.033;
           z3Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;

           display();

        }
         for(int a=0;a<=53;a++)
       {
           x1Cup+=0.033;
           z1Cup-=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;
           display();

       }
        for(int b=0;b<=53;b++)
       {
           x1Cup+=0.033;
           z1Cup+=0.066;
           x2Cup-=0.033;
           z2Cup-=0.066;
           xRot-=0.033;
           zRot-=0.066;
           display();

      }
         for(int a=0;a<=53;a++)
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;
           display();

       }
        for(int b=0;b<=53;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x1Cup-=0.033;
           z1Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;
           display();

      }
       for(int a=0;a<=53;a++)
       {
           x1Cup+=0.033;
           z1Cup-=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;
           display();

       }
        for(int b=0;b<=53;b++)
       {
           x1Cup+=0.033;
           z1Cup+=0.066;
           x2Cup-=0.033;
           z2Cup-=0.066;
           xRot-=0.033;
           zRot-=0.066;
           display();

      }
      for(int a=0;a<=26;a++) // move 2 and 1 by 1
       {
           x3Cup+=0.033;
           z3Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x3Cup+=0.033;
           z3Cup+=0.066;
           x1Cup-=0.033;
           z1Cup-=0.066;


           display();

        }

      }
          else if(ShuffleCups && value==5)
      {
           for(int a=0;a<=53;a++)
       {
           ShuffleCups=0;
           x1Cup+=0.033;
           z1Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;

           display();

       }
        for(int b=0;b<=53;b++)
       {
           x1Cup+=0.033;
           z1Cup+=0.066;
           x3Cup-=0.033;
           z3Cup-=0.066;

           display();

      }
      for(int a=0;a<=53;a++)   /*move cups 1 and 3 by 1,remain original */
       {
           x3Cup+=0.033;
           z3Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;

           display();

       }
        for(int b=0;b<=53;b++)
       {
           x1Cup+=0.033;
           z1Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;

           display();

      }
     for(int b=0;b<=26;b++)
      {
          x2Cup+=0.033;
          z2Cup-=0.066;
          x1Cup-=0.066;
          z1Cup+=0.132;
           x3Cup+=0.033;
           z3Cup-=0.066;
           xRot+=0.033;
           zRot-=0.066;

           display();


      }
       for(int b=0;b<=26;b++)
      {
          x2Cup+=0.033;
          z2Cup+=0.066;
          x1Cup-=0.066;
          z1Cup-=0.132;
           x3Cup+=0.033;
           z3Cup+=0.066;
           xRot+=0.033;
           zRot+=0.066;

           display();


      }
       for(int b=0;b<=26;b++)
      {
          x3Cup+=0.033;
          z3Cup-=0.066;
          x2Cup-=0.066;
          z2Cup+=0.132;
           x1Cup+=0.033;
           z1Cup-=0.066;
           xRot-=0.066;
           zRot+=0.132;

           display();


      }
       for(int b=0;b<=26;b++)
      {
          x3Cup+=0.033;
          z3Cup+=0.066;
          x2Cup-=0.066;
          z2Cup-=0.132;
           x1Cup+=0.033;
           z1Cup+=0.066;
           xRot-=0.066;
           zRot-=0.132;

           display();
          }
           for(int a=0;a<=53;a++)   /*move cups 2 and 3 by 2*/
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;
           display();

       }
        for(int b=0;b<=53;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x3Cup-=0.033;
           z3Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;
           display();

      }
      for(int a=0;a<=53;a++)   /*move cups 2 and 3 by 2*/
       {
           x3Cup+=0.033;
           z3Cup-=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;
           display();

       }
        for(int b=0;b<=53;b++)
       {
           x3Cup+=0.033;
           z3Cup+=0.066;
           x2Cup-=0.033;
           z2Cup-=0.066;
           xRot-=0.033;
           zRot-=0.066;
           display();

      }
      for(int b=0;b<=26;b++)
      {
          x1Cup+=0.033;
          z1Cup-=0.066;
          x3Cup-=0.066;
          z3Cup+=0.132;
           x2Cup+=0.033;
           z2Cup-=0.066;
           xRot+=0.033;
           zRot-=0.066;

           display();


      }
       for(int b=0;b<=26;b++)
      {
          x1Cup+=0.033;
          z1Cup+=0.066;
          x3Cup-=0.066;
          z3Cup-=0.132;
           x2Cup+=0.033;
           z2Cup+=0.066;
           xRot+=0.033;
           zRot+=0.066;

           display();
          }
          for(int a=0;a<=53;a++)   /*move cups 2 and 3 by 2*/
       {
           x3Cup+=0.033;
           z3Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;

           display();

       }
        for(int b=0;b<=53;b++)
       {
           x3Cup+=0.033;
           z3Cup+=0.066;
           x1Cup-=0.033;
           z1Cup-=0.066;

           display();

      }
      for(int b=0;b<=26;b++)
      {
          x1Cup+=0.066;
          z1Cup-=0.132;
          x3Cup-=0.033;
          z3Cup+=0.066;
           x2Cup-=0.033;
           z2Cup+=0.066;
           xRot-=0.033;
           zRot+=0.066;

           display();
          }
         for(int b=0;b<=26;b++)
      {
          x1Cup+=0.066;
          z1Cup+=0.132;
          x3Cup-=0.033;
          z3Cup-=0.066;
           x2Cup-=0.033;
           z2Cup-=0.066;
           xRot-=0.033;
           zRot-=0.066;

           display();
          }
      for(int a=0;a<=26;a++)
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x3Cup-=0.033;
           z3Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x3Cup-=0.033;
           z3Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;
           display();

        }
        for(int a=0;a<=26;a++)
       {
           x2Cup+=0.033;
           z2Cup-=0.066;
           x1Cup-=0.033;
           z1Cup+=0.066;
           xRot+=0.033;
           zRot-=0.066;

           display();

       }
        for(int b=0;b<=26;b++)
       {
           x2Cup+=0.033;
           z2Cup+=0.066;
           x1Cup-=0.033;
           z1Cup-=0.066;
           xRot+=0.033;
           zRot+=0.066;
           display();

        }


      }
       else if(ShuffleCups && value==6)
      {
           for(int a=0;a<=35;a++)
       {
           ShuffleCups=0;
           x1Cup+=0.05;
           z1Cup-=0.1;
           x3Cup-=0.05;
           z3Cup+=0.1;

           display();

       }
        for(int b=0;b<=35;b++)
       {
           x1Cup+=0.05;
           z1Cup+=0.1;
           x3Cup-=0.05;
           z3Cup-=0.1;

           display();

      }
     for(int a=0;a<=35;a++)   ///move cups 1 and 3 by 1,remain original
       {
           x3Cup+=0.05;
           z3Cup-=0.1;
           x1Cup-=0.05;
           z1Cup+=0.1;

           display();

       }
        for(int b=0;b<=35;b++)
       {
           x1Cup+=0.05;
           z1Cup-=0.1;
           x3Cup-=0.05;
           z3Cup+=0.1;

           display();

      }
     for(int b=0;b<=17;b++)
      {
          x2Cup+=0.05;
          z2Cup-=0.1;
          x1Cup-=0.1;
          z1Cup+=0.2;
           x3Cup+=0.05;
           z3Cup-=0.1;
           xRot+=0.05;
           zRot-=0.1;

           display();


      }
      for(int b=0;b<=17;b++)
      {
          x2Cup+=0.05;
          z2Cup+=0.1;
          x1Cup-=0.1;
          z1Cup-=0.2;
           x3Cup+=0.05;
           z3Cup+=0.1;
           xRot+=0.05;
           zRot+=0.1;

           display();


      }
      for(int b=0;b<=17;b++)
      {
          x3Cup+=0.05;
          z3Cup-=0.1;
          x2Cup-=0.1;
          z2Cup+=0.2;
           x1Cup+=0.05;
           z1Cup-=0.1;
           xRot-=0.1;
           zRot+=0.2;

           display();


      }
       for(int b=0;b<=17;b++)
      {
          x3Cup+=0.05;
          z3Cup+=0.1;
          x2Cup-=0.1;
          z2Cup-=0.2;
           x1Cup+=0.05;
           z1Cup+=0.1;
           xRot-=0.1;
           zRot-=0.2;

           display();
          }
           for(int a=0;a<=35;a++)   //move cups 2 and 3 by 2
       {
           x2Cup+=0.05;
           z2Cup-=0.1;
           x3Cup-=0.05;
           z3Cup+=0.1;
           xRot+=0.05;
           zRot-=0.1;
           display();

       }
        for(int b=0;b<=35;b++)
       {
           x2Cup+=0.05;
           z2Cup+=0.1;
           x3Cup-=0.05;
           z3Cup-=0.1;
           xRot+=0.05;
           zRot+=0.1;
           display();

      }
      for(int a=0;a<=35;a++)   //move cups 2 and 3 by 2
       {
           x3Cup+=0.05;
           z3Cup-=0.1;
           x2Cup-=0.05;
           z2Cup+=0.1;
           xRot-=0.05;
           zRot+=0.1;
           display();

       }
        for(int b=0;b<=35;b++)
       {
           x3Cup+=0.05;
           z3Cup+=0.1;
           x2Cup-=0.05;
           z2Cup-=0.1;
           xRot-=0.05;
           zRot-=0.1;
           display();

      }
      for(int b=0;b<=17;b++)
      {
          x1Cup+=0.05;
          z1Cup-=0.1;
          x3Cup-=0.1;
          z3Cup+=0.2;
           x2Cup+=0.05;
           z2Cup-=0.1;
           xRot+=0.05;
           zRot-=0.1;

           display();


      }
       for(int b=0;b<=17;b++)
      {
          x1Cup+=0.05;
          z1Cup+=0.1;
          x3Cup-=0.1;
          z3Cup-=0.2;
           x2Cup+=0.05;
           z2Cup+=0.1;
           xRot+=0.05;
           zRot+=0.1;

           display();
          }
          for(int a=0;a<=35;a++)   //move cups 2 and 3 by 2
       {
           x3Cup+=0.05;
           z3Cup-=0.1;
           x1Cup-=0.05;
           z1Cup+=0.1;

           display();

       }
        for(int b=0;b<=35;b++)
       {
           x3Cup+=0.05;
           z3Cup+=0.1;
           x1Cup-=0.05;
           z1Cup-=0.1;

           display();

      }
      for(int b=0;b<=17;b++)
      {
          x3Cup-=0.05;
          z3Cup+=0.1;
          x1Cup+=0.1;
          z1Cup-=0.2;
           x2Cup-=0.05;
           z2Cup+=0.1;
           xRot-=0.05;
           zRot+=0.1;

           display();
          }
         for(int b=0;b<=17;b++)
      {
          x3Cup-=0.05;
          z3Cup-=0.1;
          x1Cup+=0.1;
          z1Cup+=0.2;
           x2Cup-=0.05;
           z2Cup-=0.1;
           xRot-=0.05;
           zRot-=0.1;

           display();
          }
         for(int a=0;a<=17;a++)
       {
           x2Cup+=0.05;
           z2Cup-=0.1;
           x3Cup-=0.05;
           z3Cup+=0.1;
           xRot+=0.05;
           zRot-=0.1;

           display();

       }
        for(int b=0;b<=17;b++)
       {
           x2Cup+=0.05;
           z2Cup+=0.1;
           x3Cup-=0.05;
           z3Cup-=0.1;
           xRot+=0.05;
           zRot+=0.1;
           display();

        }
        for(int a=0;a<=17;a++)
       {
           x2Cup+=0.05;
           z2Cup-=0.1;
           x1Cup-=0.05;
           z1Cup+=0.1;
           xRot+=0.05;
           zRot-=0.1;

           display();

       }
        for(int b=0;b<=17;b++)
       {
           x2Cup+=0.05;
           z2Cup+=0.1;
           x1Cup-=0.05;
           z1Cup-=0.1;
           xRot+=0.05;
           zRot+=0.1;
           display();

        }
        for(int b=0;b<=17;b++)
      {
          x1Cup+=0.05;
          z1Cup-=0.1;
          x2Cup-=0.1;
          z2Cup+=0.2;
           x3Cup+=0.05;
           z3Cup-=0.1;
           xRot-=0.1;
           zRot+=0.2;

           display();


      }
       for(int b=0;b<=17;b++)
      {
          x1Cup+=0.05;
          z1Cup+=0.1;
          x2Cup-=0.1;
          z2Cup-=0.2;
           x3Cup+=0.05;
           z3Cup+=0.1;
           xRot-=0.1;
           zRot-=0.2;

           display();
          }
      }
   }
}

void mykey(unsigned char key, int x, int y)
{

  switch ( key )
	{
	case char(13):
	              glPushMatrix();
                  moveCups();
                  glPopMatrix();
	              break;
    case char(27):
                    score=0;
                    value=0;
                    glDisable(GL_LIGHTING);
                    reset();
                  display();
                  break;


    case char(121):
        {
              if(win)
              {
                  value=value+1;
                  if(value>6)
                  {
                      break;
                  }
                  reset();
                 display();
              }



                break;
        }

    }
}

GLuint LoadTextureRAW( const char * filename)
{
GLuint texture;
unsigned char* data;
FILE * file;
file = fopen( filename, "rb" );
if ( file == NULL )
{
printf("File not Found %s\n",filename);
return 0;
}
// allocate buffer
float width = 1024;
float height = 1024;
data = (unsigned char*)malloc( width * height * 3);
// read texture data
fread( data, width * height * 3, 1, file );
fclose( file );



glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
glGenTextures( 1, &texture );
glBindTexture( GL_TEXTURE_2D, texture );
glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
//even better quality, but this will do for now.
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_NEAREST);
//to the edge of our shape.
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
//Generate the texture
glTexImage2D(GL_TEXTURE_2D,0, GL_RGB, width, height, 0,GL_RGB, GL_UNSIGNED_BYTE, data);
gluBuild2DMipmaps(GL_TEXTURE_2D,4, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
free( data );
return texture; //return whether it was successful
}
void background()
{
glEnable(GL_TEXTURE_2D);
glBindTexture( GL_TEXTURE_2D, texture );
glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
const int iw = 22;
const int ih = 22;
float modelview[16];
int i,j;
glPushMatrix();
glGetFloatv(GL_MODELVIEW_MATRIX , modelview);
for( i=0; i<3; i++ )
for( j=0; j<3; j++ ) {
if ( i==j )
modelview[i*4+j] = 1.0;
else
modelview[i*4+j] = 0.0;
}
glLoadMatrixf(modelview);
glTranslatef( -iw/2, -ih/2, -3 );
glBegin(GL_QUADS);
glTexCoord2i(0,0); glVertex2i(0, 0);
glTexCoord2i(1,0); glVertex2i(iw, 0);
glTexCoord2i(1,1); glVertex2i(iw, ih);
glTexCoord2i(0,1); glVertex2i(0, ih);
glEnd();
glPopMatrix();
glDisable(GL_TEXTURE_2D);
glFlush();
}

void text()
{
  glClearColor(1.0,0.89,0.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,0.0,0.0);
	drawstring(-0.7,-1.05,1.0,"RIGHT CLICK TO START");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(0.387,0.0,0.0);
	drawstring(-3.00,-1.40,1.0,"PROJECT BY:");

    glColor3f(1.0,0.0,1.0);
	drawstring(-3.00,-1.55,1.0,"SUCHETHA & VIKAS");


    glColor3f(0.0,0.0,0.5);
    glLineWidth(20);

    glBegin(GL_LINES);
      glVertex2f(-1.75,0.15);    //1
      glVertex2f(-1.40,0.30);
      glVertex2f(-1.40,0.30);
      glVertex2f(-1.40,-0.45);
      glVertex2f(-1.05,-0.45);
      glVertex2f(-1.75,-0.45);
    glEnd();

    glBegin(GL_LINES);
     glVertex2f(-0.34,0.30);    //B
     glVertex2f(0.35,0.15);
     glVertex2f(0.35,0.15);
     glVertex2f(-0.35,0.0);
     glVertex2f(-0.35,0.0);
     glVertex2f(0.35,-0.225);
     glVertex2f(0.35,-0.225);
     glVertex2f(-0.35,-0.45);
     glVertex2f(-0.35,-0.45);
     glVertex2f(-0.35,0.30);
    glEnd();

   glBegin(GL_LINES);
    glVertex2f(0.7,0.30);    //B
    glVertex2f(1.05,-0.45);
    glVertex2f(0.7,0.30);
    glVertex2f(0.35,-0.45);
    glVertex2f(0.525,0.00);
    glVertex2f(0.875,0.00);
   glEnd();

   glBegin(GL_LINES);
    glVertex2f(1.225,0.30);    //L
    glVertex2f(1.225,-0.45);
    glVertex2f(1.225,-0.45);
    glVertex2f(1.575,-0.30);
   glEnd();

   glBegin(GL_LINES);
    glVertex2f(1.75,0.30);    //L
    glVertex2f(1.75,-0.45);
    glVertex2f(1.75,-0.45);
    glVertex2f(2.1,-0.30);
   glEnd();


   glBegin(GL_LINES);
    glVertex2f(-2.8,1.50);   //3
    glVertex2f(-1.75,1.50);
    glVertex2f(-1.75,1.50);
    glVertex2f(-2.8,1.125);
    glVertex2f(-2.8,1.125);
    glVertex2f(-1.75,0.75);
    glVertex2f(-1.75,0.75);
    glVertex2f(-2.8,0.75);
   glEnd();

   glBegin(GL_LINES);
    glVertex2f(0.0,1.50);      //C
    glVertex2f(-1.05,1.125);
    glVertex2f(-1.05,1.125);
    glVertex2f(0.0,0.75);
   glEnd();

   glBegin(GL_LINES);
    glVertex2f(0.35,1.50);    //U
    glVertex2f(0.35,0.90);
    glVertex2f(0.35,0.90);
    glVertex2f(0.7,0.75);
    glVertex2f(0.7,0.75);
    glVertex2f(1.05,0.75);
    glVertex2f(1.05,0.75);
    glVertex2f(1.4,0.90);
    glVertex2f(1.4,0.90);
    glVertex2f(1.4,1.50);
   glEnd();

   glBegin(GL_LINES);
    glVertex2f(1.75,1.50);    //P
    glVertex2f(1.75,0.75);
    glVertex2f(1.75,1.50);
    glVertex2f(2.45,1.275);
    glVertex2f(2.45,1.275);
    glVertex2f(1.75,1.05);
   glEnd();

   glBegin(GL_LINES);
    glVertex2f(3.15,1.50);      //S
    glVertex2f(2.625,1.20);
    glVertex2f(2.625,1.20);
    glVertex2f(3.15,0.975);
    glVertex2f(3.15,0.975);
    glVertex2f(2.625,0.75);
   glEnd();

glFlush();
}
void help()
{
glClearColor(1.0,1.0,1.0,1.0);
//glMatrixMode(GL_MODELVIEW);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,0.0,0.0);
	drawstring(-0.5,1.7,5.0,"3 CUPS ,1 BALL.");
   //setFont(GLUT_BITMAP_8_BY_13);
	glColor3f(0.0,0.2,0.2);
	drawstring(-2.5,1.40,1.0,"The 3 cups,1 ball is a trick performed by Conjurer/Trickster  to fool audience and gain profit. ");
    drawstring(-2.5,1.20,1.0,"The trick consists of placing a ball inside any of the three cup’s and shuffling it thoroughly ");
    drawstring(-2.5,1.00,1.0,"so as to misdirect audience. And then he bets the audience to guess which cup has ball.If audience ");
    drawstring(-2.5,0.8,1.0,"is right, he will get certain amount of money promised or according to the bet else it’s a good day ");
    drawstring(-2.5,0.6,1.0,"for trickster.This is also a sort of gambling which was widely spread in medieval era.");
    glColor3f(0.6,0.298,0.4);
    drawstring(-0.3,0.0,1.0,"CREDITS- ");
    glColor3f(0.0,0.0,0.4);
    drawstring(-0.8,-0.2,1.0,"WE THANK RAGHU SIR :) :) :) ");
    glColor3f(0.0,0.2,0.2);
    drawstring(-2.5,-0.6,1.0,"For giving us required knowledge about computer graphics and constantly guiding us to build" );
    drawstring(-2.5,-0.8,1.0,"this simple yet interesting project.We have learned lot through this project,from 'TIMES ROMAN' ");
    drawstring(-2.5,-1.0,1.0,"to 'GLUT_BITMAP_TIMES_ROMAN_24',from 'printf' to 'mouse click',from '50 lines of code' to ");
    drawstring(-2.5,-1.2,1.0,"'1500 lines of code'..We have done it all.");

	glColor3f(1.0,0.0,1.0);
	drawstring(-0.6,-1.55,1.0,"VIKAS & SUCHETHA");
	glFlush();
}

void about()
{
glClearColor(1.0,1.0,1.0,1.0);
//glMatrixMode(GL_MODELVIEW);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,0.0,0.0);
	drawstring(-0.5,1.7,5.0,"3 CUPS ,1 BALL.");
   //setFont(GLUT_BITMAP_8_BY_13);
	glColor3f(0.0,0.2,0.2);
	drawstring(-2.5,1.40,1.0,"The 3 cups,1 ball is a trick performed by Conjurer/Trickster  to fool audience and gain profit. ");
    drawstring(-2.5,1.20,1.0,"The trick consists of placing a ball inside any of the three cup’s and shuffling it thoroughly ");
    drawstring(-2.5,1.00,1.0,"so as to misdirect audience. And then he bets the audience to guess which cup has ball.If audience ");
    drawstring(-2.5,0.8,1.0,"is right, he will get certain amount of money promised or according to the bet else it’s a good day ");
    drawstring(-2.5,0.6,1.0,"for trickster.This is also a sort of gambling which was widely spread in medieval era.");
    glColor3f(0.6,0.298,0.4);
    drawstring(-0.3,0.0,1.0,"CREDITS- ");
    glColor3f(0.0,0.0,0.4);
    drawstring(-0.8,-0.2,1.0,"WE THANK RAGHU SIR :) :) :) ");
    glColor3f(0.0,0.2,0.2);
    drawstring(-2.5,-0.6,1.0,"For giving us required knowledge about computer graphics and constantly guiding us to build" );
    drawstring(-2.5,-0.8,1.0,"this simple yet interesting project.We have learned lot through this project,from 'TIMES ROMAN' ");
    drawstring(-2.5,-1.0,1.0,"to 'GLUT_BITMAP_TIMES_ROMAN_24',from 'printf' to 'mouse click',from '50 lines of code' to ");
    drawstring(-2.5,-1.2,1.0,"'1500 lines of code'..We have done it all.");

	glColor3f(1.0,0.0,1.0);
	drawstring(-0.6,-1.55,1.0,"VIKAS & SUCHETHA");
	glFlush();
}

void draw()
{
GameMode=1;
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

background();

if(value==2)
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

drawstring(-2.9,1.3,1.0,"Level : 1");

}
else if(value==3)
{

drawstring(-2.9,1.3,1.0,"Level : 2");

}
else if(value==4)
{

drawstring(-2.9,1.3,1.0,"Level : 3");

}
else if(value==5)
{

drawstring(-2.9,1.3,1.0,"Level : 4");

}
else if(value==6)
{

drawstring(-2.9,1.3,1.0,"Level : 5");

}
if(score==0)
{
       setFont(GLUT_BITMAP_TIMES_ROMAN_24);

drawstring(2.7,1.3,1.0,"Score : 0");
}

else if(score==1)
{


drawstring(2.7,1.3,1.0,"Score : 1");

}
else if(score==2)
{

drawstring(2.7,1.3,1.0,"Score : 2");

}
else if(score==3)
{

drawstring(2.7,1.3,1.0,"Score : 3");

}
else if(score==4)
{

drawstring(2.7,1.3,1.0,"Score : 4");

}
else if(score==5)
{

drawstring(2.7,1.3,1.0,"Score : 5");

}



printf("level :%d\n",value);
if(GameOver)
{
  setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,0.0,0.0);
	if(win)
    {
        if(value==6)
        {
             drawstring(-1.7,-1.05,1.0,"YOU WON.YOU COMPLETED THE GAME:)");
        }
else
{
   drawstring(-1.7,-1.05,1.0,"YOU WON.PRESS Y TO GO NEXT LEVEL:)");
   }
    }
   if(!win)
    {
     	drawstring(-1.7,-1.05,1.0,"YOU LOST.THANKS FOR PLAYING.TRY AGAIN:)");
    }
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	//setFont(GLUT_BITMAP_8_BY_13);
	glColor3f(0.387,1.0,1.0);
	drawstring(-3.00,-1.40,1.0,"PROJECT BY:");

	//setFont(GLUT_BITMAP_9_BY_15);
	glColor3f(1.0,0.0,1.0);
	drawstring(-3.00,-1.55,1.0,"SUCHETHA & VIKAS");


}
glRotatef(10,1.0,0.0,0.0);
gluLookAt(0.0,0.3,1.0,0.0,0.2,0.2,0.0,1.0,1.0);
glEnable(GL_DEPTH_TEST);
Initialize1();
	// Set material properties
	GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat qaGold[] = {1.0,0.84,0.0, 1.0};
	GLfloat qaRed[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat qaBlue[] = {0.0, 0.0, 1.0, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaLowAmbient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat qaFullAmbient[] = {1.0, 1.0, 1.0, 1.0};
        //Set, ambient, diffuse and specular lighting. Set ambient to 20%.
		glMaterialfv(GL_FRONT, GL_AMBIENT, qaGold);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGold);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);



      glPushMatrix();
         glTranslated(x2Cup,y2Cup,z2Cup);
         colorcube();
      glPopMatrix();
      glPushMatrix();
         glTranslatef(x1Cup,y1Cup,z1Cup);
         colorcube();
      glPopMatrix();
      glPushMatrix();
         glTranslatef(x3Cup,y3Cup,z3Cup);
         colorcube();
      glPopMatrix();


	glPushMatrix();
	Initialize2();
	glEnable(GL_DEPTH_TEST);
    GLfloat qaSilver[] = {0.8,0.8,0.8, 1.0};
      //Set, ambient, diffuse and specular lighting. Set ambient to 20%.
		glMaterialfv(GL_FRONT, GL_AMBIENT, qaSilver);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaSilver);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
//glColor3f(0.75,0.75,0.75);
    glRotatef(xRot, 0.0f, 1.0f, 0.0f);
    glTranslated(xRot,yRot,zRot);
    glutSolidSphere(radius,20,20);
   glPopMatrix();


//glFlu();

}
void reset(void)
{

  xRot = 0.0f;
  yRot = -0.7f;
 zRot = 0.0f;
  y1Cup = 0.0f;
  y2Cup = 0.0f;
  y3Cup = 0.0f;
 z1Cup = 0.0f;
z2Cup = 0.0f;
  z3Cup = 0.0f;
  x1Cup = -1.8f;
  x2Cup = 0.0f;
  x3Cup = 1.8f;
  MenuMode=1;
  GameMode=0;
 GameOver=0;
 win=0;
 next=0;

  moveBall=1;
  ShuffleCups=1;


}

void display(void)
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

gluLookAt(viewer[0],viewer[1], viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);
switch(value)
{

    case 2:draw();
          break;
    case 3:draw();
          break;
    case 4:draw();
          break;
    case 5:draw();
          break;
    case 6:draw();
          break;
    case 1:about();
           break;
    case 7:help();
           break;

   default:text();


}
glutSwapBuffers();

}


void myReshape(int w, int h)
{
          glClearColor(0.0,0.0,0.0,0.0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void MouseClick(int button, int state, int x, int y)
{

     printf("%d\n",x);
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ShuffleCups==0 && (value==2 ))
  {


    if(x<1104 && x>894)
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
        score++;
          win=1;
         next=1;
         GameOver=1;
         printf("%d",win);

         display();
    }
    else
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
         GameOver=1;
        win=0;
         next=1;
         printf("%d",win);
         display();
    }
ShuffleCups=1;

  }

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ShuffleCups==0 && (value==3 ))
  {


    if(x<424 && x>224)
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
        score++;
          win=1;
         next=1;
         GameOver=1;
         printf("%d",win);

         display();
    }
    else
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
         GameOver=1;
        win=0;
         next=1;
         printf("%d",win);
         display();
    }
ShuffleCups=1;

  }
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ShuffleCups==0 && (value==4 ))
  {


    if(x<424 && x>224)
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
        score++;
          win=1;
         next=1;
         GameOver=1;
         printf("%d",win);

         display();
    }
    else
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
         GameOver=1;
        win=0;
         next=1;
         printf("%d",win);
         display();
    }
ShuffleCups=1;

  }
 if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ShuffleCups==0 && (value==5 ))
  {


    if(x<1104 && x>894)
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
        score++;
          win=1;
         next=1;
         GameOver=1;
         printf("%d",win);

         display();
    }
    else
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
         GameOver=1;
        win=0;
         next=1;
         printf("%d",win);
         display();
    }
ShuffleCups=1;

  }
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ShuffleCups==0 && (value==6 ))
  {


    if(x<434 && x>224)
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
        score++;
          win=1;
         next=1;
         GameOver=1;
         printf("%d",win);

         display();
    }
    else
    {
        while(y2Cup<=1.0)
        {
            y2Cup+=0.001;
            display();
        }
        while(y1Cup<=1.0)
        {
            y1Cup+=0.001;
            y3Cup+=0.001;
            display();
        }
         GameOver=1;
        win=0;
         next=1;
         printf("%d",win);
         display();
    }
ShuffleCups=1;

  }


}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(500,500);
    window = glutCreateWindow("Cups and Balls");
    createMenu();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(mykey);
    glutMouseFunc(MouseClick);
    texture = LoadTextureRAW("C:\\Cups and Balls\\background4.bmp");
    glEnable (GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);
	glutMainLoop();
    return 0;
}

