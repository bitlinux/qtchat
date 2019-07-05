/****************************************************************************
** Meta object code from reading C++ file 'private_chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../chat/private_chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'private_chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_private_chat_t {
    QByteArrayData data[12];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_private_chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_private_chat_t qt_meta_stringdata_private_chat = {
    {
QT_MOC_LITERAL(0, 0, 12), // "private_chat"
QT_MOC_LITERAL(1, 13, 18), // "on_records_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "on_file_clicked"
QT_MOC_LITERAL(4, 49, 15), // "on_send_clicked"
QT_MOC_LITERAL(5, 65, 19), // "on_sendfile_clicked"
QT_MOC_LITERAL(6, 85, 11), // "readmessage"
QT_MOC_LITERAL(7, 97, 4), // "int&"
QT_MOC_LITERAL(8, 102, 6), // "readID"
QT_MOC_LITERAL(9, 109, 8), // "QString&"
QT_MOC_LITERAL(10, 118, 19), // "read_record_message"
QT_MOC_LITERAL(11, 138, 12) // "receive_file"

    },
    "private_chat\0on_records_clicked\0\0"
    "on_file_clicked\0on_send_clicked\0"
    "on_sendfile_clicked\0readmessage\0int&\0"
    "readID\0QString&\0read_record_message\0"
    "receive_file"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_private_chat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
      10,    1,   64,    2, 0x08 /* Private */,
      11,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void private_chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<private_chat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_records_clicked(); break;
        case 1: _t->on_file_clicked(); break;
        case 2: _t->on_send_clicked(); break;
        case 3: _t->on_sendfile_clicked(); break;
        case 4: _t->readmessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->readID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->read_record_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->receive_file((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject private_chat::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_private_chat.data,
    qt_meta_data_private_chat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *private_chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *private_chat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_private_chat.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int private_chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
