#ifndef MYGEOMTRY2_H
#define MYGEOMTRY2_H

#include <QQuickItem>
#include <QVector>
#include <QVector3D>

struct Point3d
{
    float x;
    float y;
    float z;
    void set(float x_, float y_, float z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
};

class MyGeomtry2 : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
public:
    MyGeomtry2(QQuickItem *parent = 0);
    ~MyGeomtry2();


signals:
public slots:
    Q_INVOKABLE void addLine();

    // QQuickItem interface
public:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;
private:
    QVector<Point3d> m_verticles;

};

#endif // MYGEOMTRY2_H
