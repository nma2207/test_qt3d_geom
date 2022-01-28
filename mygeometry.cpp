#include "mygeometry.h"

#include <QRandomGenerator>
#include <QVector3D>

#include <QDebug>
MyGeometry::MyGeometry()
    : QQuick3DGeometry{}
    , m_offset{0}
{
    updateGeometry();
    //qDebug() << "ASdasdasd";
//    clear();

//    setBounds(QVector3D(-5.0f, -5.0f, -5.0f), QVector3D(+5.0f, +5.0f, +5.0f));

//    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Lines);

//    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
//                 0,
//                 QQuick3DGeometry::Attribute::F32Type);
    constexpr int stride = 3 * sizeof(float);
    setStride(stride);

//    for(int i =0;i<5;i++)
//        qwert();
}

void MyGeometry::qwert()
{
    //qDebug() << "saddas";
    //clear();
    constexpr auto randomFloat = [](float l, float h)
    {
      return l + QRandomGenerator::global()->generateDouble() * (h-l);
    };

    const float x1 = randomFloat(-5,5);
    const float y1 = randomFloat(-5, 5);
    const float z = 0;


    m_verticles.push_back(QVector3D{x1,y1,z});
    //const float x2 = randomFloat(-5,5);
    //const float y2 = randomFloat(-5, 5);
    //m_verticles.push_back(QVector3D{x2,y2,z});

    updateGeometry();

}

void MyGeometry::updateGeometry()
{
    clear();
    QByteArray vertexData;

    vertexData.resize(m_verticles.size() * sizeof(float) *3);
    float *p = reinterpret_cast<float *>(vertexData.data());

    foreach(const auto& vert, m_verticles)
    {
        *p++ = vert.x();
        *p++ = vert.y();
        *p++ = vert.z();
    }


    setVertexData(vertexData);

    //setIndexData()


    setStride(3 * sizeof(float));
    setBounds(QVector3D(-5.0f, -5.0f, 0), QVector3D(+5.0f, +5.0f, +0));

    setPrimitiveType(QQuick3DGeometry::PrimitiveType::LineStrip);

    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
                 0,
                 QQuick3DGeometry::Attribute::F32Type);
    update();
}

