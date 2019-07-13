/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../15puzzle-master/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[21];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 26), // "on_mixPiecesButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 22), // "on_closeBurron_clicked"
QT_MOC_LITERAL(4, 58, 18), // "on_newGame_clicked"
QT_MOC_LITERAL(5, 77, 23), // "on_continueGame_clicked"
QT_MOC_LITERAL(6, 101, 21), // "on_bestScores_clicked"
QT_MOC_LITERAL(7, 123, 19), // "on_setLevel_clicked"
QT_MOC_LITERAL(8, 143, 15), // "on_help_clicked"
QT_MOC_LITERAL(9, 159, 18), // "on_aboutUs_clicked"
QT_MOC_LITERAL(10, 178, 15), // "on_back_clicked"
QT_MOC_LITERAL(11, 194, 21), // "on_backToMenu_clicked"
QT_MOC_LITERAL(12, 216, 8), // "showTime"
QT_MOC_LITERAL(13, 225, 8), // "showMenu"
QT_MOC_LITERAL(14, 234, 5), // "event"
QT_MOC_LITERAL(15, 240, 7), // "QEvent*"
QT_MOC_LITERAL(16, 248, 6), // "setOne"
QT_MOC_LITERAL(17, 255, 2), // "on"
QT_MOC_LITERAL(18, 258, 6), // "setTwo"
QT_MOC_LITERAL(19, 265, 8), // "setThree"
QT_MOC_LITERAL(20, 274, 7) // "setFour"

    },
    "Dialog\0on_mixPiecesButton_clicked\0\0"
    "on_closeBurron_clicked\0on_newGame_clicked\0"
    "on_continueGame_clicked\0on_bestScores_clicked\0"
    "on_setLevel_clicked\0on_help_clicked\0"
    "on_aboutUs_clicked\0on_back_clicked\0"
    "on_backToMenu_clicked\0showTime\0showMenu\0"
    "event\0QEvent*\0setOne\0on\0setTwo\0setThree\0"
    "setFour"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      16,    1,  114,    2, 0x08 /* Private */,
      18,    1,  117,    2, 0x08 /* Private */,
      19,    1,  120,    2, 0x08 /* Private */,
      20,    1,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 15,   14,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_mixPiecesButton_clicked(); break;
        case 1: _t->on_closeBurron_clicked(); break;
        case 2: _t->on_newGame_clicked(); break;
        case 3: _t->on_continueGame_clicked(); break;
        case 4: _t->on_bestScores_clicked(); break;
        case 5: _t->on_setLevel_clicked(); break;
        case 6: _t->on_help_clicked(); break;
        case 7: _t->on_aboutUs_clicked(); break;
        case 8: _t->on_back_clicked(); break;
        case 9: _t->on_backToMenu_clicked(); break;
        case 10: _t->showTime(); break;
        case 11: _t->showMenu(); break;
        case 12: { bool _r = _t->event((*reinterpret_cast< QEvent*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setOne((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setTwo((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->setThree((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->setFour((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
