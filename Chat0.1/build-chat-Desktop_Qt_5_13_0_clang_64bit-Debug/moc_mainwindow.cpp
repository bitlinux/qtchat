/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../chat/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "send_ID"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "QString&"
QT_MOC_LITERAL(4, 29, 10), // "receive_ID"
QT_MOC_LITERAL(5, 40, 4), // "int&"
QT_MOC_LITERAL(6, 45, 14), // "send_record_ID"
QT_MOC_LITERAL(7, 60, 11), // "change_name"
QT_MOC_LITERAL(8, 72, 18), // "init_flock_message"
QT_MOC_LITERAL(9, 91, 9), // "send_file"
QT_MOC_LITERAL(10, 101, 13), // "change_status"
QT_MOC_LITERAL(11, 115, 8), // "new_noti"
QT_MOC_LITERAL(12, 124, 10), // "fresh_list"
QT_MOC_LITERAL(13, 135, 12), // "get_bbs_list"
QT_MOC_LITERAL(14, 148, 15), // "get_new_bbsitem"
QT_MOC_LITERAL(15, 164, 15), // "get_bbs_history"
QT_MOC_LITERAL(16, 180, 18), // "on_adf_but_clicked"
QT_MOC_LITERAL(17, 199, 19), // "on_crgp_but_clicked"
QT_MOC_LITERAL(18, 219, 20), // "on_edit_name_clicked"
QT_MOC_LITERAL(19, 240, 22), // "on_edit_header_clicked"
QT_MOC_LITERAL(20, 263, 11), // "readmessage"
QT_MOC_LITERAL(21, 275, 10), // "closeEvent"
QT_MOC_LITERAL(22, 286, 12), // "QCloseEvent*"
QT_MOC_LITERAL(23, 299, 5), // "event"
QT_MOC_LITERAL(24, 305, 12), // "get_new_noti"
QT_MOC_LITERAL(25, 318, 14), // "get_new_friend"
QT_MOC_LITERAL(26, 333, 18) // "on_bbs_but_clicked"

    },
    "MainWindow\0send_ID\0\0QString&\0receive_ID\0"
    "int&\0send_record_ID\0change_name\0"
    "init_flock_message\0send_file\0change_status\0"
    "new_noti\0fresh_list\0get_bbs_list\0"
    "get_new_bbsitem\0get_bbs_history\0"
    "on_adf_but_clicked\0on_crgp_but_clicked\0"
    "on_edit_name_clicked\0on_edit_header_clicked\0"
    "readmessage\0closeEvent\0QCloseEvent*\0"
    "event\0get_new_noti\0get_new_friend\0"
    "on_bbs_but_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    1,  122,    2, 0x06 /* Public */,
       6,    1,  125,    2, 0x06 /* Public */,
       7,    1,  128,    2, 0x06 /* Public */,
       8,    1,  131,    2, 0x06 /* Public */,
       9,    1,  134,    2, 0x06 /* Public */,
      10,    1,  137,    2, 0x06 /* Public */,
      11,    1,  140,    2, 0x06 /* Public */,
      12,    1,  143,    2, 0x06 /* Public */,
      13,    0,  146,    2, 0x06 /* Public */,
      14,    0,  147,    2, 0x06 /* Public */,
      15,    0,  148,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  149,    2, 0x08 /* Private */,
      17,    0,  150,    2, 0x08 /* Private */,
      18,    0,  151,    2, 0x08 /* Private */,
      19,    0,  152,    2, 0x08 /* Private */,
      20,    1,  153,    2, 0x08 /* Private */,
      21,    1,  156,    2, 0x08 /* Private */,
      24,    1,  159,    2, 0x08 /* Private */,
      25,    1,  162,    2, 0x08 /* Private */,
      26,    0,  165,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_ID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->receive_ID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->send_record_ID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->change_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->init_flock_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->send_file((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->change_status((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->new_noti((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->fresh_list((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->get_bbs_list(); break;
        case 10: _t->get_new_bbsitem(); break;
        case 11: _t->get_bbs_history(); break;
        case 12: _t->on_adf_but_clicked(); break;
        case 13: _t->on_crgp_but_clicked(); break;
        case 14: _t->on_edit_name_clicked(); break;
        case 15: _t->on_edit_header_clicked(); break;
        case 16: _t->readmessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 18: _t->get_new_noti((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->get_new_friend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_bbs_but_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_ID)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::receive_ID)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_record_ID)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::change_name)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::init_flock_message)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_file)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::change_status)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::new_noti)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::fresh_list)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::get_bbs_list)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::get_new_bbsitem)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::get_bbs_history)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::send_ID(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::receive_ID(int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::send_record_ID(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::change_name(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::init_flock_message(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::send_file(int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::change_status(int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::new_noti(int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::fresh_list(int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::get_bbs_list()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainWindow::get_new_bbsitem()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MainWindow::get_bbs_history()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
