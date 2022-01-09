/****************************************************************************
** Meta object code from reading C++ file 'labelarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CameraDataAnnotationInterface/labelarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labelarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LabelArea_t {
    QByteArrayData data[6];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LabelArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LabelArea_t qt_meta_stringdata_LabelArea = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LabelArea"
QT_MOC_LITERAL(1, 10, 7), // "boxMade"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(4, 34, 4), // "band"
QT_MOC_LITERAL(5, 39, 8) // "boxMoved"

    },
    "LabelArea\0boxMade\0\0QGraphicsItem*\0"
    "band\0boxMoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabelArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void LabelArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LabelArea *_t = static_cast<LabelArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->boxMade((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 1: _t->boxMoved(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LabelArea::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelArea::boxMade)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LabelArea::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelArea::boxMoved)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LabelArea::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_LabelArea.data,
      qt_meta_data_LabelArea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LabelArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabelArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LabelArea.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int LabelArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void LabelArea::boxMade(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LabelArea::boxMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
