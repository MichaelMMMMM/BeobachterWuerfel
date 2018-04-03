/****************************************************************************
** Meta object code from reading C++ file 'CSensorCalibration.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BeobachterWuerfel_Client/CSensorCalibration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSensorCalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CSensorCalibration[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      48,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   68,   19,   19, 0x0a,
     115,   68,   19,   19, 0x0a,
     156,   68,   19,   19, 0x0a,
     197,   68,   19,   19, 0x0a,
     238,   68,   19,   19, 0x0a,
     279,   68,   19,   19, 0x0a,
     320,   19,   19,   19, 0x0a,
     354,  345,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CSensorCalibration[] = {
    "CSensorCalibration\0\0startSensorCalibrationSIG()\0"
    "endMeasurementSIG()\0time,\0"
    "sensor1DataReceivedSLOT(double,CMPUData)\0"
    "sensor2DataReceivedSLOT(double,CMPUData)\0"
    "sensor3DataReceivedSLOT(double,CMPUData)\0"
    "sensor4DataReceivedSLOT(double,CMPUData)\0"
    "sensor5DataReceivedSLOT(double,CMPUData)\0"
    "sensor6DataReceivedSLOT(double,CMPUData)\0"
    "startButtonClickedSLOT()\0newValue\0"
    "numberOfValuesChangedSLOT(int)\0"
};

void CSensorCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CSensorCalibration *_t = static_cast<CSensorCalibration *>(_o);
        switch (_id) {
        case 0: _t->startSensorCalibrationSIG(); break;
        case 1: _t->endMeasurementSIG(); break;
        case 2: _t->sensor1DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 3: _t->sensor2DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 4: _t->sensor3DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 5: _t->sensor4DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 6: _t->sensor5DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 7: _t->sensor6DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 8: _t->startButtonClickedSLOT(); break;
        case 9: _t->numberOfValuesChangedSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CSensorCalibration::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CSensorCalibration::staticMetaObject = {
    { &CExperimentWidget::staticMetaObject, qt_meta_stringdata_CSensorCalibration,
      qt_meta_data_CSensorCalibration, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CSensorCalibration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CSensorCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CSensorCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CSensorCalibration))
        return static_cast<void*>(const_cast< CSensorCalibration*>(this));
    return CExperimentWidget::qt_metacast(_clname);
}

int CSensorCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CExperimentWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CSensorCalibration::startSensorCalibrationSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CSensorCalibration::endMeasurementSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
