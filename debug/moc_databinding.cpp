/****************************************************************************
** Meta object code from reading C++ file 'databinding.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/databinding.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databinding.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataBinding_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataBinding_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataBinding_t qt_meta_stringdata_DataBinding = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DataBinding"
QT_MOC_LITERAL(1, 12, 11), // "dataChanged"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "DataBinding\0dataChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBinding[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void DataBinding::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataBinding *_t = static_cast<DataBinding *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataBinding::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataBinding::dataChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DataBinding::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataBinding.data,
      qt_meta_data_DataBinding,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataBinding::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBinding::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataBinding.stringdata0))
        return static_cast<void*>(const_cast< DataBinding*>(this));
    return QObject::qt_metacast(_clname);
}

int DataBinding::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DataBinding::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_IntBinding_t {
    QByteArrayData data[7];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IntBinding_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IntBinding_t qt_meta_stringdata_IntBinding = {
    {
QT_MOC_LITERAL(0, 0, 10), // "IntBinding"
QT_MOC_LITERAL(1, 11, 9), // "updateInt"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "newValue"
QT_MOC_LITERAL(4, 31, 12), // "updateString"
QT_MOC_LITERAL(5, 44, 10), // "intChanged"
QT_MOC_LITERAL(6, 55, 13) // "stringChanged"

    },
    "IntBinding\0updateInt\0\0newValue\0"
    "updateString\0intChanged\0stringChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntBinding[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   40,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void IntBinding::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntBinding *_t = static_cast<IntBinding *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateInt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->intChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->stringChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IntBinding::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntBinding::updateInt)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IntBinding::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntBinding::updateString)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject IntBinding::staticMetaObject = {
    { &DataBinding::staticMetaObject, qt_meta_stringdata_IntBinding.data,
      qt_meta_data_IntBinding,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IntBinding::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntBinding::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IntBinding.stringdata0))
        return static_cast<void*>(const_cast< IntBinding*>(this));
    return DataBinding::qt_metacast(_clname);
}

int IntBinding::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataBinding::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void IntBinding::updateInt(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IntBinding::updateString(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_BoolBinding_t {
    QByteArrayData data[4];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoolBinding_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoolBinding_t qt_meta_stringdata_BoolBinding = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BoolBinding"
QT_MOC_LITERAL(1, 12, 11), // "boolChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8) // "newValue"

    },
    "BoolBinding\0boolChanged\0\0newValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoolBinding[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void BoolBinding::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoolBinding *_t = static_cast<BoolBinding *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->boolChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BoolBinding::staticMetaObject = {
    { &DataBinding::staticMetaObject, qt_meta_stringdata_BoolBinding.data,
      qt_meta_data_BoolBinding,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BoolBinding::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoolBinding::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BoolBinding.stringdata0))
        return static_cast<void*>(const_cast< BoolBinding*>(this));
    return DataBinding::qt_metacast(_clname);
}

int BoolBinding::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataBinding::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_ChoiceBinding_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChoiceBinding_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChoiceBinding_t qt_meta_stringdata_ChoiceBinding = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ChoiceBinding"
QT_MOC_LITERAL(1, 14, 10), // "intChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8) // "newValue"

    },
    "ChoiceBinding\0intChanged\0\0newValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChoiceBinding[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ChoiceBinding::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChoiceBinding *_t = static_cast<ChoiceBinding *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->intChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ChoiceBinding::staticMetaObject = {
    { &DataBinding::staticMetaObject, qt_meta_stringdata_ChoiceBinding.data,
      qt_meta_data_ChoiceBinding,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChoiceBinding::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChoiceBinding::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChoiceBinding.stringdata0))
        return static_cast<void*>(const_cast< ChoiceBinding*>(this));
    return DataBinding::qt_metacast(_clname);
}

int ChoiceBinding::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataBinding::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
