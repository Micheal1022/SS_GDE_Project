/****************************************************************************
** Meta object code from reading C++ file 'graphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SS_GDE/ViewWidget/graphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphicsView_t {
    QByteArrayData data[29];
    char stringdata0[359];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicsView_t qt_meta_stringdata_GraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GraphicsView"
QT_MOC_LITERAL(1, 13, 15), // "sigNodeInfoZoom"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "loop"
QT_MOC_LITERAL(4, 35, 2), // "id"
QT_MOC_LITERAL(5, 38, 18), // "QPair<qreal,qreal>"
QT_MOC_LITERAL(6, 57, 3), // "pox"
QT_MOC_LITERAL(7, 61, 5), // "scale"
QT_MOC_LITERAL(8, 67, 4), // "path"
QT_MOC_LITERAL(9, 72, 21), // "QList<SensorItemInfo>"
QT_MOC_LITERAL(10, 94, 12), // "itemInfoList"
QT_MOC_LITERAL(11, 107, 26), // "QList<QPair<qreal,qreal> >"
QT_MOC_LITERAL(12, 134, 7), // "poxList"
QT_MOC_LITERAL(13, 142, 13), // "slotBtnZoomIn"
QT_MOC_LITERAL(14, 156, 14), // "slotBtnZoomOut"
QT_MOC_LITERAL(15, 171, 14), // "slotBtnRestore"
QT_MOC_LITERAL(16, 186, 11), // "slotBtnEdit"
QT_MOC_LITERAL(17, 198, 11), // "slotBtnSave"
QT_MOC_LITERAL(18, 210, 12), // "slotHostData"
QT_MOC_LITERAL(19, 223, 8), // "hostData"
QT_MOC_LITERAL(20, 232, 15), // "slotInfoTimeOut"
QT_MOC_LITERAL(21, 248, 20), // "slotFindItemErrorPos"
QT_MOC_LITERAL(22, 269, 3), // "row"
QT_MOC_LITERAL(23, 273, 6), // "column"
QT_MOC_LITERAL(24, 280, 20), // "slotFindItemAlarmPos"
QT_MOC_LITERAL(25, 301, 12), // "slotAlignTop"
QT_MOC_LITERAL(26, 314, 13), // "slotAlignLeft"
QT_MOC_LITERAL(27, 328, 14), // "slotAlignRight"
QT_MOC_LITERAL(28, 343, 15) // "slotAlignBottom"

    },
    "GraphicsView\0sigNodeInfoZoom\0\0loop\0"
    "id\0QPair<qreal,qreal>\0pox\0scale\0path\0"
    "QList<SensorItemInfo>\0itemInfoList\0"
    "QList<QPair<qreal,qreal> >\0poxList\0"
    "slotBtnZoomIn\0slotBtnZoomOut\0"
    "slotBtnRestore\0slotBtnEdit\0slotBtnSave\0"
    "slotHostData\0hostData\0slotInfoTimeOut\0"
    "slotFindItemErrorPos\0row\0column\0"
    "slotFindItemAlarmPos\0slotAlignTop\0"
    "slotAlignLeft\0slotAlignRight\0"
    "slotAlignBottom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   89,    2, 0x06 /* Public */,
       1,    4,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  109,    2, 0x08 /* Private */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    1,  114,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,
      21,    2,  118,    2, 0x08 /* Private */,
      24,    2,  123,    2, 0x08 /* Private */,
      25,    0,  128,    2, 0x08 /* Private */,
      26,    0,  129,    2, 0x08 /* Private */,
      27,    0,  130,    2, 0x08 /* Private */,
      28,    0,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    3,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11, QMetaType::QStringList, QMetaType::QString,   10,   12,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsView *_t = static_cast<GraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigNodeInfoZoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QPair<qreal,qreal>(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 1: _t->sigNodeInfoZoom((*reinterpret_cast< QList<SensorItemInfo>(*)>(_a[1])),(*reinterpret_cast< QList<QPair<qreal,qreal> >(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->slotBtnZoomIn(); break;
        case 3: _t->slotBtnZoomOut(); break;
        case 4: _t->slotBtnRestore(); break;
        case 5: _t->slotBtnEdit(); break;
        case 6: _t->slotBtnSave(); break;
        case 7: _t->slotHostData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->slotInfoTimeOut(); break;
        case 9: _t->slotFindItemErrorPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->slotFindItemAlarmPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->slotAlignTop(); break;
        case 12: _t->slotAlignLeft(); break;
        case 13: _t->slotAlignRight(); break;
        case 14: _t->slotAlignBottom(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GraphicsView::*_t)(QString , QString , QPair<qreal,qreal> , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicsView::sigNodeInfoZoom)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(QList<SensorItemInfo> , QList<QPair<qreal,qreal>> , QStringList , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicsView::sigNodeInfoZoom)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GraphicsView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GraphicsView.data,
      qt_meta_data_GraphicsView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void GraphicsView::sigNodeInfoZoom(QString _t1, QString _t2, QPair<qreal,qreal> _t3, QString _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicsView::sigNodeInfoZoom(QList<SensorItemInfo> _t1, QList<QPair<qreal,qreal>> _t2, QStringList _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
