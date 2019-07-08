#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#ifdef __linux__
#include <unistd.h>
#endif

#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

/* Generic bar value */
struct Bar
{
    float x;
    float y;
    float w;
    float h;
    float step;
};

/* Generic ball value */
struct Ball
{
    float r;
    float x;
    float y;
    float velocity;
    float xstep;
    float ystep;
};

/* bar */
Bar bar = {0, -11, 3, 1, 0.5};
/* Top bar*/
Bar top_bar = {0, 9, 3, 1, 0.5};
Bar d_bar = {0, 11, 16, 1, 0};
/* Main ball */
Ball ball = {0.5, 0, 0, 0.5, 0.10, 0.10};

const float bar_maxr = 13; // right
const float bar_maxl = -13; // left

const float top_bar_maxr = 13; // right
const float top_bar_maxl = -13; // left

const float ball_maxu = 7.5; // up
const float ball_maxd = -9.5; // down
const float ball_maxr = 15; // right
const float ball_maxl = -15; // left

bool isReachedXMax = false;
bool isReachedYMax = false;
bool isGameEnd = false;
bool isGameOver = false;
static int turn = 5;
/* Start the scene at 30 unit backward from center */
const int zoom = -30;

/* Player1 configs */
static signed int player1_score = 0;

/* Player2 configs */
static signed int player2_score = 0;
static int page=0;
/* Text buffer */
char finaltext[100];

static void printscore()
{
    char text[100];
    /* Printing values with formatted text */
    sprintf(text, "Player1 Score:%d     Player2 Score:%d                                 Rounds left:%d ", player1_score, player2_score,turn);
    /* blue color */  
    glColor3f(0, 0, 0);
    /* Top left corner */
    glRasterPos3f( -15 ,10.75 , zoom);
    /* Print using glutBitmapCharacter() */
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

static void finalscore()
{
    char text[100];
    /* Printing values with formatted text */
    sprintf(text, "Player1 Scored: %d Player2 Scored: %d", player1_score, player2_score);
    /* Yellow color */
    glColor3f(0, 0, 0);
    /* Top left corner */
    glRasterPos3f(-8 , 10.75 , zoom);
    /* Print using glutBitmapCharacter() */
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

	sprintf(text, "GAME OVER!!");
glScalef(3, 3, 3);
    /* white color */
    glColor3f(0, 0, 0);
    /* Top left corner */
    glRasterPos3f(-4.4, 2 , zoom);
    /* Print using glutBitmapCharacter() */
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
sprintf(text, " Press an ESC key to exit ");
    /* white color */
    glColor3f(0, 0, 0);
    /* Top left corner */
    glRasterPos3f(-6 , -10.75 , zoom);
    /* Print using glutBitmapCharacter() */
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	

}

static void finalscreen()
{
    /* If game over, show text in red color */
    if(isGameOver)
    {
        glColor3f(1, 0, 0);
    }
    /* Or show text in normal yellow color */
    /* Center position */
	finalscore();
    glRasterPos3f(-4, 0, zoom);
    for(int i = 0; finaltext[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, finaltext[i]);
    glutSwapBuffers();
	
}
void drawfirstpage()
{
    int i;
    char buffer[100]="WELCOME TO PING PONG GAME";
    glColor3f(0.0,0.0,0.0);

    glRasterPos3f(-11,0.0,1.5);

    for (i = 0; buffer[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
strcpy(buffer,"----------------------------------------------------");
    glRasterPos3f(-14,-1.0,1.5);
    for (i = 0; buffer[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
strcpy(buffer,"Save the ball from hitting the wall by moving the brick left and right");
    glRasterPos3f(-14,-2.0,1.5);
    for (i = 0; buffer[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
strcpy(buffer,"Control keys are:");
    glRasterPos3f(-14,-5.5,1.5);
    for (i = 0; buffer[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
strcpy(buffer,"------------");
    glRasterPos3f(-14,-6.5,1.5);
    for (i = 0; buffer[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
    strcpy(buffer,"player 1 is left arrow (<--) and right arrow(-->)");
    glRasterPos3f(-14,-8.5,1.5);
    for (i = 0; buffer[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
strcpy(buffer,"player 2 is left movement(a) and right movement(d) ");
    glRasterPos3f(-14,-10.5,1.5);
    for (i = 0; buffer[i] != '\0'; i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
strcpy(buffer,"Press ESC key to exit from the game");
    glRasterPos3f(-14,-17.0,1.5);
    for (i = 0; buffer[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
	
strcpy(buffer,"Press any key to start the game");
    glRasterPos3f(-14,-18.5,1.5);
    for (i = 0; buffer[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
	return;

}


void render(void)
{
 if(page==0)
    {
        glClearColor (1.5,0.90,1.0,1.0);
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0,10,-30);
        glColor3f(0,0,0);

        drawfirstpage();

        glutSwapBuffers();
	return;
}

else{
 glClearColor (1.5,0.90,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /* If game is at end, don't render scene, show final screen */
    if(isGameEnd)
    {
        finalscreen();
        return;
    }

    /* Print score in each step */
    printscore();

    // Ball
    glPushMatrix();
    glTranslatef(ball.x, ball.y, zoom);
    glColor3f(0.8, 0, 0.1);
    glutSolidSphere(ball.r, 20, 20);
    glPopMatrix();

    // Display bar
    glPushMatrix();
    glTranslatef(d_bar.x, d_bar.y, zoom);
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.75, 0.75);
    glVertex2f(d_bar.w, d_bar.h);
    glColor3f(0.75, 0.75, 0.75);
    glVertex2f(d_bar.w, -d_bar.h);
    glColor3f(0.75, 0.75, 0.75);
    glVertex2f(-d_bar.w, -d_bar.h);
    glColor3f(0.75, 0.75, 0.75);
    glVertex2f(-d_bar.w, d_bar.h);
    glEnd();
    glPopMatrix();
	
 glPushMatrix();
    glTranslatef(d_bar.x, d_bar.y, zoom);
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.75, 0.75);
    glVertex2f(d_bar.w, d_bar.h);
    glColor3f(0.75, 0.75, 0.75);
    glVertex2f(d_bar.w, -d_bar.h);
    glColor3f(0.75, 0.75, 0.75);
    glVertex2f(-d_bar.w, -d_bar.h);
    glColor3f(0.75, 0.75, 0.75);
    glVertex2f(-d_bar.w, d_bar.h);
    glEnd();
    glPopMatrix();

    // Bottom bar
    glPushMatrix();
    glTranslatef(bar.x, bar.y, zoom);
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(bar.w, bar.h);
    glColor3f(0, 1, 0);
    glVertex2f(bar.w, -bar.h);
    glColor3f(0, 0, 1);
    glVertex2f(-bar.w, -bar.h);
    glColor3f(1, 0, 1);
    glVertex2f(-bar.w, bar.h);
    glEnd();
    glPopMatrix();

    // Top bar
    glPushMatrix();
    glTranslatef(top_bar.x, top_bar.y, zoom);
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(top_bar.w, top_bar.h);
    glColor3f(0, 1, 0);
    glVertex2f(top_bar.w, -top_bar.h);
    glColor3f(0, 0, 1);
    glVertex2f(-top_bar.w, -top_bar.h);
    glColor3f(1, 0, 1);
    glVertex2f(-top_bar.w, top_bar.h);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}
}

void init(void)
{
    /* Init bg with grey color */
    glClearColor( 0.9, 0.9, 0.9, 1);
    glClearDepth( 1.0 );
    /* 32bit */
    glEnable(GL_DEPTH_TEST);
    /* Smooth rendering */
    glShadeModel(GL_SMOOTH);
    /* Enabling colored objects */
    glEnable(GL_COLOR_MATERIAL);
}

void reshape(int w, int h)
{
    float aspectRatio;
    h = (h == 0) ? 1 : h;
    w = (w == 0) ? 1 : w;
    /* Setting window dimention as viewport */
    glViewport( 0, 0, w, h );
    aspectRatio = (float)w/(float)h;
    /* Projection mode */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* Set perspective */
    gluPerspective(45, aspectRatio, 1.0, 100.0);
    /* Back to modelview mode */
    glMatrixMode(GL_MODELVIEW);
}


void idle()
{
#ifdef _WIN32
    Sleep(100); //Sleep = usleep/1000
#else
    usleep(10000);
#endif

    /* Don't calculate any score if game is at end */

    if(isGameEnd)
        return;

    /* If ball's Y value is equal to maximum_down value
    then check if it touched the bar */
	if(page==1){
    if(ball.y <= ball_maxd)
    {
        /* Check ball's co-ord is between bar's width */
        if(ball.x<=bar.x-bar.w or ball.x>=bar.x+bar.w) // Bar missing
        {
            /* Reduce score */
            player1_score--;
	turn--;
            /* Start the ball from bar, for user's ease */
       
            /* Reset bar */
            bar.y = -11;

            /*
            end the game and show black banner */
            if(turn==0)
            {
		if(player1_score>player2_score)
		{
                glClearColor(0, 0, 0, 1);
                isGameEnd = true;
                isGameOver = true;
                strcpy(finaltext, "Player1 won...");
		}
		else if(player1_score<player2_score)
		{
                glClearColor(0, 0, 0, 1);
                isGameEnd = true;
                isGameOver = true;
                strcpy(finaltext, "Player2 won...");
		}
		else
		{
                glClearColor(0, 0, 0, 1);
                isGameEnd = true;
                isGameOver = true;
                strcpy(finaltext,"Match Draw...");
		}
            }
        }
        else // Score
        {
            /* Count score */
            player1_score++;

            /* Increase ball's speed by 0.1 */
            ball.velocity += 0.1;
        }
    }

    /* Ball bounce */

    /* If X value of the ball has touched right area */
    if(ball.x>ball_maxr)
        isReachedXMax=true;
    /* If X value of the ball has touched left area */
    else if(ball.x<ball_maxl)
        isReachedXMax=false;

    /* If Y value of the ball has touched top area */
    if(ball.y>ball_maxu)
        isReachedYMax=true;
    /* If Y value of the ball has touched down area */
    else if(ball.y<ball_maxd)
        isReachedYMax=false;

    /* Move the ball by step and velocity */
    if(isReachedXMax)
        ball.x -= ball.xstep * ball.velocity;
    else
        ball.x += ball.xstep * ball.velocity;
    if(isReachedYMax)
        ball.y -= ball.ystep * ball.velocity;
    else
        ball.y += ball.ystep * ball.velocity;
    
    if(ball.y >= ball_maxu)
    {
        /* Check ball's co-ord is between bar's width */
        if(ball.x<=top_bar.x-top_bar.w or ball.x>=top_bar.x+top_bar.w) // Bar missing
        {
            /* Reduce score */
            player2_score--;
	turn--;
            /* Start the ball from bar, for user's ease */
            
            /* Reset bar */
            top_bar.y = 9;

            /*
            end the game and show black banner */
            if(turn==0)
            {
		if(player1_score>player2_score)
		{
                glClearColor(0, 0, 0, 1);
                isGameEnd = true;
                isGameOver = true;
                strcpy(finaltext, "Player1 won...");
		}
		else if(player1_score<player2_score)
		{
                glClearColor(0, 0, 0, 1);
                isGameEnd = true;
                isGameOver = true;
                strcpy(finaltext, "Player2 won...");
		}
		else
		{
                glClearColor(0, 0, 0, 1);
                isGameEnd = true;
                isGameOver = true;
                strcpy(finaltext, "Match Draw...");
		}
            }
        }
        else // Score
        {
            /* Count score */
            player2_score++;

            /* Increase ball's speed by 0.1 */
            ball.velocity += 0.1;
        }
    }


    glutPostRedisplay();

}}

void keyboard( unsigned char key, int x, int y )
{
    /* If user press ESC key, quit */
    switch(key)
    {
	
    case 27:
        exit(1);
default: 
page=1;
render();

    }
   //keys for player2 where 97-a-left and 100-d-right
   if(key==97 and top_bar.x > top_bar_maxl)
    {
        top_bar.x -= top_bar.step;
    }
    else if(key==100 and top_bar.x < top_bar_maxr)
    {
        top_bar.x += top_bar.step;
    }
}

void specialkey(int key, int x, int y)
{
    /* Move the bar with left right key */
    if(key==GLUT_KEY_LEFT and bar.x > bar_maxl)
    {
        bar.x -= bar.step;
    }
    else if(key==GLUT_KEY_RIGHT and bar.x < bar_maxr)
    {
        bar.x += bar.step;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(600, 480);
    glutCreateWindow("Ping Pong Game");
    init();
	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    
    
    glutSpecialFunc(specialkey);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
