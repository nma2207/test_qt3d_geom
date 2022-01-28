#ifndef MYGEOMETRY_H
#define MYGEOMETRY_H

#include <QQuick3DGeometry>
#include <QVector>
#include <QVector3D>

class MyGeometry : public QQuick3DGeometry
{
    Q_OBJECT
    //QML_NAMED_ELEMENT(MyGeometry)
public:
    MyGeometry();


public:
    Q_INVOKABLE
    void qwert();

    int m_offset;
    QVector<QVector3D> m_verticles;
private:
    void updateGeometry();
};

#endif // MYGEOMETRY_H
