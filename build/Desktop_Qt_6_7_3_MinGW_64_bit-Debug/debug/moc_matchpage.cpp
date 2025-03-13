/****************************************************************************
** Meta object code from reading C++ file 'matchpage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../matchpage.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'matchpage.h' doesn't include <QObject>."
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
<<<<<<< HEAD
struct qt_meta_stringdata_CLASSmatchPageENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSmatchPageENDCLASS = QtMocHelpers::stringData(
    "matchPage",
    "on_homeButton_clicked",
    ""
=======
struct qt_meta_stringdata_CLASSemployeePageENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSemployeePageENDCLASS = QtMocHelpers::stringData(
    "employeePage"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

<<<<<<< HEAD
Q_CONSTINIT static const uint qt_meta_data_CLASSmatchPageENDCLASS[] = {
=======
Q_CONSTINIT static const uint qt_meta_data_CLASSemployeePageENDCLASS[] = {
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
       1,   14, // methods
=======
       0,    0, // methods
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

<<<<<<< HEAD
 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject matchPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSmatchPageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmatchPageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmatchPageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<matchPage, std::true_type>,
        // method 'on_homeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
=======
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
        QtPrivate::TypeAndForceComplete<employeePage, std::true_type>
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
    >,
    nullptr
} };

<<<<<<< HEAD
void matchPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<matchPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_homeButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *matchPage::metaObject() const
=======
void employeePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *employeePage::metaObject() const
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

<<<<<<< HEAD
void *matchPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmatchPageENDCLASS.stringdata0))
=======
void *employeePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSemployeePageENDCLASS.stringdata0))
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

<<<<<<< HEAD
int matchPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
=======
int employeePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
    return _id;
}
QT_WARNING_POP
