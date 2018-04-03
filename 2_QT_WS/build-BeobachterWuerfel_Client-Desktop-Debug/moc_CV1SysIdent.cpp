/****************************************************************************
** Meta object code from reading C++ file 'CV1SysIdent.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BeobachterWuerfel_Client/CV1SysIdent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CV1SysIdent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CV1SysIdent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      34,   12,   12,   12, 0x05,
      54,   12,   12,   12, 0x05,
      78,   74,   12,   12, 0x05,
     105,   74,   12,   12, 0x05,
     132,   74,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     164,   12,   12,   12, 0x0a,
     189,   12,   12,   12, 0x0a,
     212,   12,   12,   12, 0x0a,
     237,   12,   12,   12, 0x0a,
     262,   12,   12,   12, 0x0a,
     297,  292,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CV1SysIdent[] = {
    "CV1SysIdent\0\0startExperimentSIG()\0"
    "stopExperimentSIG()\0selectNoSignalSIG()\0"
    "amp\0selectJumpSignalSIG(float)\0"
    "selectSineSignalSIG(float)\0"
    "selectMultiSineSignalSIG(float)\0"
    "startButtonClickedSLOT()\0"
    "noSignalSelectedSLOT()\0jumpSignalSelectedSLOT()\0"
    "sineSignalSelectedSLOT()\0"
    "multiSineSignalSelectedSLOT()\0data\0"
    "expDataReceivedSLOT(SExpData)\0"
};

void CV1SysIdent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CV1SysIdent *_t = static_cast<CV1SysIdent *>(_o);
        switch (_id) {
        case 0: _t->startExperimentSIG(); break;
        case 1: _t->stopExperimentSIG(); break;
        case 2: _t->selectNoSignalSIG(); break;
        case 3: _t->selectJumpSignalSIG((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 4: _t->selectSineSignalSIG((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 5: _t->selectMultiSineSignalSIG((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 6: _t->startButtonClickedSLOT(); break;
        case 7: _t->noSignalSelectedSLOT(); break;
        case 8: _t->jumpSignalSelectedSLOT(); break;
        case 9: _t->sineSignalSelectedSLOT(); break;
        case 10: _t->multiSineSignalSelectedSLOT(); break;
        case 11: _t->expDataReceivedSLOT((*reinterpret_cast< const SExpData(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CV1SysIdent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CV1SysIdent::staticMetaObject = {
    { &CExperimentWidget::staticMetaObject, qt_meta_stringdata_CV1SysIdent,
      qt_meta_data_CV1SysIdent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CV1SysIdent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CV1SysIdent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CV1SysIdent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CV1SysIdent))
        return static_cast<void*>(const_cast< CV1SysIdent*>(this));
    return CExperimentWidget::qt_metacast(_clname);
}

int CV1SysIdent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CExperimentWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CV1SysIdent::startExperimentSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CV1SysIdent::stopExperimentSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CV1SysIdent::selectNoSignalSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CV1SysIdent::selectJumpSignalSIG(const float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CV1SysIdent::selectSineSignalSIG(const float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CV1SysIdent::selectMultiSineSignalSIG(const float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
