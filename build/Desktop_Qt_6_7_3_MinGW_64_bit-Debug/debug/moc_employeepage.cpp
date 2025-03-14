/****************************************************************************
** Meta object code from reading C++ file 'employeepage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../employeepage.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employeepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSemployeePageENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSemployeePageENDCLASS = QtMocHelpers::stringData(
    "employeePage",
    "on_exitButton_clicked",
    "",
    "on_homeButton_clicked",
    "on_notifButton_clicked",
    "on_aboutButton_clicked",
    "on_addEmployeeButton_clicked",
    "on_refreshButton_clicked",
    "on_delete_employee_clicked",
    "row",
    "on_update_employee_clicked",
    "empInsertionValidateInputs",
    "on_filterButton_clicked",
    "on_cancelFilter_clicked",
    "on_searchCriteriaBox_currentIndexChanged",
    "index",
    "on_applyFilter_clicked",
    "QSqlQuery",
    "on_searchButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSemployeePageENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    1,  104,    2, 0x08,    7 /* Private */,
      10,    1,  107,    2, 0x08,    9 /* Private */,
      11,    0,  110,    2, 0x08,   11 /* Private */,
      12,    0,  111,    2, 0x08,   12 /* Private */,
      13,    0,  112,    2, 0x08,   13 /* Private */,
      14,    1,  113,    2, 0x08,   14 /* Private */,
      16,    0,  116,    2, 0x08,   16 /* Private */,
      18,    0,  117,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    0x80000000 | 17,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject employeePage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSemployeePageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSemployeePageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSemployeePageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<employeePage, std::true_type>,
        // method 'on_exitButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_homeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_notifButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_aboutButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addEmployeeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_refreshButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delete_employee_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_update_employee_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'empInsertionValidateInputs'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_filterButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancelFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchCriteriaBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_applyFilter_clicked'
        QtPrivate::TypeAndForceComplete<QSqlQuery, std::false_type>,
        // method 'on_searchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void employeePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<employeePage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_exitButton_clicked(); break;
        case 1: _t->on_homeButton_clicked(); break;
        case 2: _t->on_notifButton_clicked(); break;
        case 3: _t->on_aboutButton_clicked(); break;
        case 4: _t->on_addEmployeeButton_clicked(); break;
        case 5: _t->on_refreshButton_clicked(); break;
        case 6: _t->on_delete_employee_clicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_update_employee_clicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: { bool _r = _t->empInsertionValidateInputs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->on_filterButton_clicked(); break;
        case 10: _t->on_cancelFilter_clicked(); break;
        case 11: _t->on_searchCriteriaBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: { QSqlQuery _r = _t->on_applyFilter_clicked();
            if (_a[0]) *reinterpret_cast< QSqlQuery*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->on_searchButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *employeePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *employeePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSemployeePageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int employeePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
