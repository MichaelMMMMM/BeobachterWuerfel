/****************************************************************************
** Meta object code from reading C++ file 'CADCCalibration.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BeobachterWuerfel_Client/CADCCalibration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CADCCalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CADCCalibration[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      42,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   62,   16,   16, 0x0a,
     102,   16,   16,   16, 0x0a,
     134,  128,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CADCCalibration[] = {
    "CADCCalibration\0\0startADCCalibrationSIG()\0"
    "endMeasurementSIG()\0newValue\0"
    "numberOfValuesChangedSLOT(int)\0"
    "startButtonClickedLSLOT()\0time,\0"
    "adcDataReceivedSLOT(double,CADCData)\0"
};

void CADCCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CADCCalibration *_t = static_cast<CADCCalibration *>(_o);
        switch (_id) {
        case 0: _t->startADCCalibrationSIG(); break;
        case 1: _t->endMeasurementSIG(); break;
        case 2: _t->numberOfValuesChangedSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->startButtonClickedLSLOT(); break;
        case 4: _t->adcDataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CADCData(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CADCCalibration::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CADCCalibration::staticMetaObject = {
    { &CExperimentWidget::staticMetaObject, qt_meta_stringdata_CADCCalibration,
      qt_meta_data_CADCCalibration, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CADCCalibration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CADCCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CADCCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CADCCalibration))
        return static_cast<void*>(const_cast< CADCCalibration*>(this));
    return CExperimentWidget::qt_metacast(_clname);
}

int CADCCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CExperimentWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CADCCalibration::startADCCalibrationSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CADCCalibration::endMeasurementSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
