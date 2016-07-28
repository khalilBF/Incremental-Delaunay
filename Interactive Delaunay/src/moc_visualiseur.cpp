/****************************************************************************
** Meta object code from reading C++ file 'visualiseur.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "visualiseur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualiseur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Visualiseur[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x08,
      55,   13,   12,   12, 0x08,
      90,   13,   12,   12, 0x08,
     125,   13,   12,   12, 0x08,
     158,   13,   12,   12, 0x08,
     188,   13,   12,   12, 0x08,
     221,   13,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Visualiseur[] = {
    "Visualiseur\0\0checked\0"
    "on_checkBoxPPVoisin_clicked(bool)\0"
    "on_checkBoxImmediats_clicked(bool)\0"
    "on_checkBoxTriangles_clicked(bool)\0"
    "on_checkBoxVoronoi_clicked(bool)\0"
    "on_checkBoxSwap_clicked(bool)\0"
    "on_checkBoxCentres_clicked(bool)\0"
    "on_checkBoxSommets_clicked(bool)\0"
};

void Visualiseur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Visualiseur *_t = static_cast<Visualiseur *>(_o);
        switch (_id) {
        case 0: _t->on_checkBoxPPVoisin_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_checkBoxImmediats_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_checkBoxTriangles_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_checkBoxVoronoi_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_checkBoxSwap_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_checkBoxCentres_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_checkBoxSommets_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Visualiseur::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Visualiseur::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Visualiseur,
      qt_meta_data_Visualiseur, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Visualiseur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Visualiseur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Visualiseur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Visualiseur))
        return static_cast<void*>(const_cast< Visualiseur*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int Visualiseur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
