#ifndef SENSORITEMINFO_H
#define SENSORITEMINFO_H
#include <QObject>

class SensorItemInfo
{
public:
    SensorItemInfo () {
        m_zoom = 0.0;
        m_posX = 0.0;
        m_posY = 0.0;
        m_idStr.clear();
        m_loopStr.clear();
        m_typeStr.clear();
        m_areaStr.clear();
    }
    qreal m_zoom;       //缩放大小比
    qreal m_posX;       //X轴位置
    qreal m_posY;       //Y轴位置
    QString m_idStr;    //探测器地址
    QString m_loopStr;  //探测器回路
    QString m_typeStr;  //探测器类型
    QString m_areaStr;  //安装位置
};

#endif // SENSORITEMINFO_H
