/****************************************************************************
** Meta object code from reading C++ file 'serverSends.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Server/serverSends.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverSends.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serverSends_t {
    QByteArrayData data[14];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serverSends_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serverSends_t qt_meta_stringdata_serverSends = {
    {
QT_MOC_LITERAL(0, 0, 11), // "serverSends"
QT_MOC_LITERAL(1, 12, 10), // "logMessage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "msg"
QT_MOC_LITERAL(4, 28, 10), // "stopServer"
QT_MOC_LITERAL(5, 39, 9), // "broadcast"
QT_MOC_LITERAL(6, 49, 7), // "message"
QT_MOC_LITERAL(7, 57, 14), // "serverConnect*"
QT_MOC_LITERAL(8, 72, 7), // "exclude"
QT_MOC_LITERAL(9, 80, 12), // "jsonReceived"
QT_MOC_LITERAL(10, 93, 6), // "sender"
QT_MOC_LITERAL(11, 100, 3), // "doc"
QT_MOC_LITERAL(12, 104, 16), // "userDisconnected"
QT_MOC_LITERAL(13, 121, 9) // "userError"

    },
    "serverSends\0logMessage\0\0msg\0stopServer\0"
    "broadcast\0message\0serverConnect*\0"
    "exclude\0jsonReceived\0sender\0doc\0"
    "userDisconnected\0userError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serverSends[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x0a /* Public */,
       5,    2,   48,    2, 0x08 /* Private */,
       9,    2,   53,    2, 0x08 /* Private */,
      12,    1,   58,    2, 0x08 /* Private */,
      13,    1,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QJsonObject,   10,   11,
    QMetaType::Void, 0x80000000 | 7,   10,
    QMetaType::Void, 0x80000000 | 7,   10,

       0        // eod
};

void serverSends::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serverSends *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->stopServer(); break;
        case 2: _t->broadcast((*reinterpret_cast< const QJsonObject(*)>(_a[1])),(*reinterpret_cast< serverConnect*(*)>(_a[2]))); break;
        case 3: _t->jsonReceived((*reinterpret_cast< serverConnect*(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 4: _t->userDisconnected((*reinterpret_cast< serverConnect*(*)>(_a[1]))); break;
        case 5: _t->userError((*reinterpret_cast< serverConnect*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (serverSends::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serverSends::logMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serverSends::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_serverSends.data,
    qt_meta_data_serverSends,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serverSends::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serverSends::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serverSends.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int serverSends::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
void serverSends::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
