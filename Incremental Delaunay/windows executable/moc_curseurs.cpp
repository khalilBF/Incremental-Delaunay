/****************************************************************************
** Meta object code from reading C++ file 'curseurs.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab3KhalilBFadhel/curseurs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'curseurs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Curseurs[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x05,
      37,   10,    9,    9, 0x05,
      58,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   10,    9,    9, 0x08,
     117,   10,    9,    9, 0x08,
     155,   10,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Curseurs[] = {
    "Curseurs\0\0value\0xValueChanged(float)\0"
    "yValueChanged(float)\0zValueChanged(float)\0"
    "on_parametreXSlider_valueChanged(int)\0"
    "on_parametreYSlider_valueChanged(int)\0"
    "on_parametreZSlider_valueChanged(int)\0"
};

void Curseurs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Curseurs *_t = static_cast<Curseurs *>(_o);
        switch (_id) {
        case 0: _t->xValueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->yValueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->zValueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->on_parametreXSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_parametreYSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_parametreZSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Curseurs::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Curseurs::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Curseurs,
      qt_meta_data_Curseurs, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Curseurs::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Curseurs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Curseurs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Curseurs))
        return static_cast<void*>(const_cast< Curseurs*>(this));
    return QDialog::qt_metacast(_clname);
}

int Curseurs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Curseurs::xValueChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Curseurs::yValueChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Curseurs::zValueChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
