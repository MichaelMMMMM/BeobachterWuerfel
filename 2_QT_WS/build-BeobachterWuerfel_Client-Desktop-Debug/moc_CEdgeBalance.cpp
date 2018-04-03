/****************************************************************************
** Meta object code from reading C++ file 'CEdgeBalance.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BeobachterWuerfel_Client/CEdgeBalance.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CEdgeBalance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CEdgeBalance[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      34,   13,   13,   13, 0x05,
      55,   13,   13,   13, 0x05,
      79,   13,   13,   13, 0x05,
     102,   13,   13,   13, 0x05,
     125,   13,   13,   13, 0x05,
     166,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     194,  184,   13,   13, 0x0a,
     244,  184,   13,   13, 0x0a,
     296,  184,   13,   13, 0x0a,
     349,   13,   13,   13, 0x0a,
     367,   13,   13,   13, 0x0a,
     384,   13,   13,   13, 0x0a,
     403,   13,   13,   13, 0x0a,
     428,   13,   13,   13, 0x0a,
     453,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CEdgeBalance[] = {
    "CEdgeBalance\0\0runEdgeBalanceSIG()\0"
    "stopEdgeBalanceSIG()\0setPhiOffsetSIG(double)\0"
    "setUKOffsetSIG(double)\0setUROffsetSIG(double)\0"
    "selectControlSystemSIG(E1DControlSystem)\0"
    "updateConfigSIG()\0time,data\0"
    "compLQR1DDataReceivedSLOT(double,QVector<double>)\0"
    "phiObsLQR1DDataReceivedSLOT(double,QVector<double>)\0"
    "fullObsLQR1DDataReceivedSLOT(double,QVector<double>)\0"
    "startButtonSLOT()\0saveButtonSLOT()\0"
    "offsetButtonSLOT()\0controlRadioButtonSLOT()\0"
    "updateConfigButtonSLOT()\0displayButtonSLOT()\0"
};

void CEdgeBalance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CEdgeBalance *_t = static_cast<CEdgeBalance *>(_o);
        switch (_id) {
        case 0: _t->runEdgeBalanceSIG(); break;
        case 1: _t->stopEdgeBalanceSIG(); break;
        case 2: _t->setPhiOffsetSIG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setUKOffsetSIG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setUROffsetSIG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->selectControlSystemSIG((*reinterpret_cast< E1DControlSystem(*)>(_a[1]))); break;
        case 6: _t->updateConfigSIG(); break;
        case 7: _t->compLQR1DDataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 8: _t->phiObsLQR1DDataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 9: _t->fullObsLQR1DDataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 10: _t->startButtonSLOT(); break;
        case 11: _t->saveButtonSLOT(); break;
        case 12: _t->offsetButtonSLOT(); break;
        case 13: _t->controlRadioButtonSLOT(); break;
        case 14: _t->updateConfigButtonSLOT(); break;
        case 15: _t->displayButtonSLOT(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CEdgeBalance::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CEdgeBalance::staticMetaObject = {
    { &CExperimentWidget::staticMetaObject, qt_meta_stringdata_CEdgeBalance,
      qt_meta_data_CEdgeBalance, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CEdgeBalance::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CEdgeBalance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CEdgeBalance::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CEdgeBalance))
        return static_cast<void*>(const_cast< CEdgeBalance*>(this));
    return CExperimentWidget::qt_metacast(_clname);
}

int CEdgeBalance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CExperimentWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void CEdgeBalance::runEdgeBalanceSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CEdgeBalance::stopEdgeBalanceSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CEdgeBalance::setPhiOffsetSIG(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CEdgeBalance::setUKOffsetSIG(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CEdgeBalance::setUROffsetSIG(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CEdgeBalance::selectControlSystemSIG(E1DControlSystem _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CEdgeBalance::updateConfigSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
