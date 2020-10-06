/****************************************************************************
** Meta object code from reading C++ file 'systemconf.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SS_GDE/SystemConf/systemconf.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemconf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SystemConf_t {
    QByteArrayData data[10];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SystemConf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SystemConf_t qt_meta_stringdata_SystemConf = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SystemConf"
QT_MOC_LITERAL(1, 11, 9), // "sigSaveOk"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "sigViewWidget"
QT_MOC_LITERAL(4, 36, 14), // "slotBtnAddHost"
QT_MOC_LITERAL(5, 51, 14), // "slotBtnDelHost"
QT_MOC_LITERAL(6, 66, 15), // "slotBtnSaveHost"
QT_MOC_LITERAL(7, 82, 18), // "slotCellCheckClick"
QT_MOC_LITERAL(8, 101, 3), // "row"
QT_MOC_LITERAL(9, 105, 6) // "column"

    },
    "SystemConf\0sigSaveOk\0\0sigViewWidget\0"
    "slotBtnAddHost\0slotBtnDelHost\0"
    "slotBtnSaveHost\0slotCellCheckClick\0"
    "row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemConf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    2,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

       0        // eod
};

void SystemConf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SystemConf *_t = static_cast<SystemConf *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSaveOk(); break;
        case 1: _t->sigViewWidget(); break;
        case 2: _t->slotBtnAddHost(); break;
        case 3: _t->slotBtnDelHost(); break;
        case 4: _t->slotBtnSaveHost(); break;
        case 5: _t->slotCellCheckClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SystemConf::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemConf::sigSaveOk)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SystemConf::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemConf::sigViewWidget)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SystemConf::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SystemConf.data,
      qt_meta_data_SystemConf,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SystemConf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemConf::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SystemConf.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SystemConf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SystemConf::sigSaveOk()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SystemConf::sigViewWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
