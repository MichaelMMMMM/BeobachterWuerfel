/****************************************************************************
** Meta object code from reading C++ file 'CRxThread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BeobachterWuerfel_Client/CRxThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CRxThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CRxThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   10,   10,   10, 0x0a,
      65,   10,   10,   10, 0x0a,
      87,   10,   10,   10, 0x0a,
     108,   10,   10,   10, 0x0a,
     133,  129,   10,   10, 0x0a,
     161,  129,   10,   10, 0x0a,
     189,  129,   10,   10, 0x0a,
     222,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CRxThread[] = {
    "CRxThread\0\0data\0expDataReceivedSIG(SExpData)\0"
    "runV1SysIdentSLOT()\0startExperimentSLOT()\0"
    "stopExperimentSLOT()\0selectNoSignalSLOT()\0"
    "amp\0selectJumpSignalSLOT(float)\0"
    "selectSineSignalSLOT(float)\0"
    "selectMultiSineSignalSLOT(float)\0"
    "runV2BalanceSLOT()\0"
};

void CRxThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CRxThread *_t = static_cast<CRxThread *>(_o);
        switch (_id) {
        case 0: _t->expDataReceivedSIG((*reinterpret_cast< const SExpData(*)>(_a[1]))); break;
        case 1: _t->runV1SysIdentSLOT(); break;
        case 2: _t->startExperimentSLOT(); break;
        case 3: _t->stopExperimentSLOT(); break;
        case 4: _t->selectNoSignalSLOT(); break;
        case 5: _t->selectJumpSignalSLOT((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->selectSineSignalSLOT((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->selectMultiSineSignalSLOT((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: _t->runV2BalanceSLOT(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CRxThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CRxThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CRxThread,
      qt_meta_data_CRxThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CRxThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CRxThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CRxThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CRxThread))
        return static_cast<void*>(const_cast< CRxThread*>(this));
    return QThread::qt_metacast(_clname);
}

int CRxThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CRxThread::expDataReceivedSIG(const SExpData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
