/****************************************************************************
** Meta object code from reading C++ file 'visualiseur.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab3KhalilBFadhel/visualiseur.h"
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x05,
      33,   31,   12,   12, 0x05,
      60,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,   12,   12,   12, 0x08,
     102,   12,   12,   12, 0x08,
     113,   12,   12,   12, 0x08,
     131,   12,   12,   12, 0x08,
     158,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Visualiseur[] = {
    "Visualiseur\0\0c\0centre(Point3D)\0d\0"
    "distancePerspective(float)\0"
    "visualisationInitiale()\0chargerPoints3D()\0"
    "reTracer()\0calculerLimites()\0"
    "creerPointsTriangulation()\0recadrer()\0"
};

void Visualiseur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Visualiseur *_t = static_cast<Visualiseur *>(_o);
        switch (_id) {
        case 0: _t->centre((*reinterpret_cast< Point3D(*)>(_a[1]))); break;
        case 1: _t->distancePerspective((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->visualisationInitiale(); break;
        case 3: _t->chargerPoints3D(); break;
        case 4: _t->reTracer(); break;
        case 5: _t->calculerLimites(); break;
        case 6: _t->creerPointsTriangulation(); break;
        case 7: _t->recadrer(); break;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Visualiseur::centre(Point3D _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Visualiseur::distancePerspective(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Visualiseur::visualisationInitiale()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
