#ifndef CAMOP_H
#define CAMOP_H

#include <QGLWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QString>
class camop : public QGLWidget
{
    Q_OBJECT
public:
    explicit camop(QWidget *parent = 0);
    void initGL(int w, int h);
    void display();
    void resize(int w, int ht);
    int myMouseMove(QMouseEvent *ev);
    int LoadImage(char *filename);
    int imageexecute(char *filename);

};

#endif // CAMOP_H
