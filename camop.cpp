#include "camop.h"
#include <GL/glut.h>
#include <IL/il.h>
#include <QMouseEvent>

#define DEFAULT_WIDTH  1080
#define DEFAULT_HEIGHT 960

int wid  = DEFAULT_WIDTH;
int ht = DEFAULT_HEIGHT;
camop::camop(QWidget *parent) : QGLWidget(parent)
{



    setMouseTracking(true);
}

void camop::initGL(int w,int ht){
    glViewport(0,0, w, ht);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(0,(float)w/ht,0.01,100.0);
    //glOrtho(0.0,w,ht,0.0,0.0,100.0);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the window

}

void camop::display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Draw a quad
    glBegin(GL_QUADS);
        glTexCoord2i(0,0);
        glVertex2i(0,0);
        glTexCoord2i(0,1);
        glVertex2i(0,ht);
        glTexCoord2i(1,1);
        glVertex2i(wid,ht);
        glTexCoord2i(1,0);
        glVertex2i(wid,0);
    glEnd();

    glutSwapBuffers();
}

void camop::resize(int w, int h){
    // viewport to cover new window
       glViewport(0,0, w, h);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       glOrtho(0.0,wid,ht,0.0,0.0,100.0);
       glMatrixMode(GL_MODELVIEW);

       glutPostRedisplay();
}

int camop::myMouseMove(QMouseEvent *ev){

if(ev->button()==Qt::LeftButton){
    return (ev->x(),ev->y());
}
return -1;
}

int camop::LoadImage(char *filename)
{
    ILboolean success;
         ILuint image;

        ilGenImages(1, &image); /* Generation of one image name */
         ilBindImage(image); /* Binding of image name */
         success = ilLoadImage(filename); /* Loading of the image filename by DevIL */

        if (success) /* If no error occured: */
        {
            /* Convert every colour component into unsigned byte. If your image contains alpha channel you can replace IL_RGB with IL_RGBA */
               success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

            if (!success)
               {
                     return -1;
               }
        }
        else
            return -1;

        return image;
}

