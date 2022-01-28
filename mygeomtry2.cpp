#include "mygeomtry2.h"

#include <QRandomGenerator>

#include <QtQuick/qsgnode.h>
#include <QtQuick/qsgflatcolormaterial.h>

MyGeomtry2::MyGeomtry2(QQuickItem *parent)
    : QQuickItem(parent)
{
    setFlag(ItemHasContents, true);
}

MyGeomtry2::~MyGeomtry2()
{

}

void MyGeomtry2::addLine()
{
    qDebug() << "Add line";
    constexpr auto randomFloat = [](float l, float h)
    {
      return l + QRandomGenerator::global()->generateDouble() * (h-l);
    };

    const float x = randomFloat(0,500);
    const float y = randomFloat(0, 500);
    const float z = randomFloat(-5, 5);


    m_verticles.push_back({x,y,z});
    update();
}

QSGNode *MyGeomtry2::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data)
{
    QSGGeometryNode *node = nullptr;
    QSGGeometry *geometry = nullptr;

    QSGGeometry::Attribute MyPoint2D_Attributes[] = {
        QSGGeometry::Attribute::create(0, 3, QSGGeometry::FloatType, true),
    };

    QSGGeometry::AttributeSet MyPoint2D_AttributeSet = {
        1,
        sizeof(Point3d),
        MyPoint2D_Attributes
    };

    if (!oldNode) {
        qDebug() << "here 1";
        node = new QSGGeometryNode;

        geometry = new QSGGeometry(MyPoint2D_AttributeSet, m_verticles.size());
        geometry->setLineWidth(2);
        geometry->setDrawingMode(QSGGeometry::DrawLineStrip);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);


        QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
        material->setColor(QColor(255, 0, 0));
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);

    } else {
        qDebug() << "here 2";
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
        geometry->allocate(m_verticles.size());
    }
qDebug() << "here 3";
    //QSizeF itemSize = size();
    Point3d*p = static_cast<Point3d*>(geometry->vertexData());
    qDebug() << geometry->vertexCount() << geometry->sizeOfVertex() << sizeof(QVector3D);
qDebug() << "here 4";
    //Vector3D *vertices = geometry->vertexDataAsPoint2D();

    for(int i=0;i<m_verticles.size(); i++)
    {
        p[i].set(m_verticles[i].x, m_verticles[i].y, m_verticles[i].z);
    }
qDebug() << "here 5";
    node->markDirty(QSGNode::DirtyGeometry);
qDebug() << "here 6";
    return node;
}
