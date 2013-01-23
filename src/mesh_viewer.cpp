#include "mesh.cpp"
#include "world.cpp"
#include <glut.h>
#include <iostream>

using namespace std;

float size = 500.0f;

float screen_x = 0.0f;
float screen_y = 0.0f;
float angle1 = 0.0f;
float angle2 = 0.0f;
float scale = 1.0f;

float mouse_x = -1;
float mouse_y = -1;

bool move = false;
bool zoom = false;

World world;

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'x':
            move = true; break;
        case 'z':
            zoom = true; break;
        case 'q':
            exit(0);
    }
}
void keyboard_up(unsigned char key, int x, int y){
    switch(key){
        case 'x':
            move = false; break;
        case 'z':
            zoom = false; break;
    }
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(screen_x,screen_y,0);
        glRotatef(angle1,0,0,1);
        glRotatef(angle2,1,0,0);
        glScalef(scale,scale,scale);

        world.display();

    glPopMatrix();

    glFlush();
}
void mouse_clicked(int button, int state, int x, int y){
    mouse_x = -1;
    mouse_y = -1;
}
void translate(int dx, int dy){
    screen_x += dx/size;
    screen_y -= dy/size;
}
void zoom_window(int dx, int dy){
    scale -= dy*5/size;;
}
void rotate(int dx, int dy){
    angle1 -= dx;
    angle2 += dy;
}
void mouse_dragged(int x, int y){
    if(mouse_x==-1 || mouse_y == -1)
    {
        mouse_x = x;
        mouse_y = y;
    }
    else{
        float dx = x-mouse_x;
        float dy = y-mouse_y;
        mouse_x = x;
        mouse_y = y;
        if(move)
            translate(dx,dy);
        else if(zoom)
            zoom_window(dx,dy);
        else
            rotate(dx,dy);
        display();
    }
}
void idle(){
}
void reshape(int w, int h){
    glViewport( 0, 0, w, h);
    glutPostRedisplay();
}

int main(int argc, char* argv[]){

    //set up basic window
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // set RGBA mode with double and depth buffers
    glutInitDisplayMode(24); //8 bits per color

    glutInitWindowSize(size,size);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Test");

    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );


    //set callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMotionFunc(mouse_dragged);
    glutMouseFunc(mouse_clicked);

    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc( keyboard_up );

    glutIdleFunc(idle);

    Mesh m;
    if(argc>1)
        m.loadFromFile(argv[1]);
    else
        m.loadFromFile("../data/bunny.off");
    world.addMesh(m);

    //start
    glutMainLoop();

    return 0;
}
