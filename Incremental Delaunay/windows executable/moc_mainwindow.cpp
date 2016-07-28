/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab3KhalilBFadhel/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      61,   11,   11,   11, 0x08,
      81,   11,   11,   11, 0x08,
     108,  102,   11,   11, 0x08,
     120,  102,   11,   11, 0x08,
     132,  102,   11,   11, 0x08,
     147,  144,   11,   11, 0x08,
     165,  162,   11,   11, 0x08,
     183,  180,   11,   11, 0x08,
     200,  198,   11,   11, 0x08,
     214,  198,   11,   11, 0x08,
     228,  198,   11,   11, 0x08,
     244,  242,   11,   11, 0x08,
     268,  266,   11,   11, 0x08,
     296,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0dessiner()\0on_rotB_clicked()\0"
    "on_transB_clicked()\0on_scaleB_clicked()\0"
    "quitterApplication()\0angle\0rotX(float)\0"
    "rotY(float)\0rotZ(float)\0dx\0translX(float)\0"
    "dy\0translY(float)\0dz\0translZ(float)\0"
    "s\0scaleX(float)\0scaleY(float)\0"
    "scaleZ(float)\0p\0setCentroide(Point3D)\0"
    "d\0setPerspectiveMatrix(float)\0projeter()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->dessiner(); break;
        case 1: _t->on_rotB_clicked(); break;
        case 2: _t->on_transB_clicked(); break;
        case 3: _t->on_scaleB_clicked(); break;
        case 4: _t->quitterApplication(); break;
        case 5: _t->rotX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->rotY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->rotZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: _t->translX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->translY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->translZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->scaleX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->scaleY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: _t->scaleZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->setCentroide((*reinterpret_cast< Point3D(*)>(_a[1]))); break;
        case 15: _t->setPerspectiveMatrix((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 16: _t->projeter(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::dessiner()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
