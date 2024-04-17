/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
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
struct qt_meta_stringdata_CLASSFancyButtonENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSFancyButtonENDCLASS = QtMocHelpers::stringData(
    "FancyButton"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFancyButtonENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject FancyButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_CLASSFancyButtonENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFancyButtonENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFancyButtonENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FancyButton, std::true_type>
    >,
    nullptr
} };

void FancyButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *FancyButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FancyButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFancyButtonENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int FancyButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCustomLabelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCustomLabelENDCLASS = QtMocHelpers::stringData(
    "CustomLabel",
    "mousePressed",
    "",
    "mouseHolding",
    "pos"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCustomLabelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,
       3,    1,   29,    2, 0x06,    3 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject CustomLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_CLASSCustomLabelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCustomLabelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCustomLabelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CustomLabel, std::true_type>,
        // method 'mousePressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'mouseHolding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>
    >,
    nullptr
} };

void CustomLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomLabel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mousePressed((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 1: _t->mouseHolding((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CustomLabel::*)(const QPoint & );
            if (_t _q_method = &CustomLabel::mousePressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CustomLabel::*)(const QPoint & );
            if (_t _q_method = &CustomLabel::mouseHolding; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *CustomLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCustomLabelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int CustomLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CustomLabel::mousePressed(const QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CustomLabel::mouseHolding(const QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "handleMouseHolding",
    "",
    "pos",
    "on_loadImgBtn_clicked",
    "on_saveImgBtn_clicked",
    "outImageDisplay",
    "on_clearImg_clicked",
    "on_redoBtn_clicked",
    "on_undoBtn_clicked",
    "on_invertFilter_clicked",
    "on_rotateRight_clicked",
    "on_rotateLeft_clicked",
    "on_purpleFilter_clicked",
    "on_filterApply_clicked",
    "on_sunLightFilter_clicked",
    "checked",
    "on_filterSlider_valueChanged",
    "value",
    "on_blurFilter_clicked",
    "on_oilFilter_clicked",
    "on_resizeFilterBtn_clicked",
    "on_widthEditVal_textEdited",
    "on_heightEditVal_textEdited",
    "on_grayFilter_clicked",
    "on_B_W_Filter_clicked",
    "on_DetectFilter_clicked",
    "on_BrightFilter_clicked",
    "on_cropFilter_clicked",
    "on_cropWidth_textEdited",
    "arg1",
    "on_cropHeight_textChanged",
    "on_cropApply_clicked",
    "on_oldtvFilter_clicked",
    "on_NeonFilter_clicked",
    "on_HorizontalFlip_clicked",
    "on_VerticalFlip_clicked",
    "on_infraredFilter_clicked",
    "on_MergeFilter_clicked",
    "on_MergeCrop_clicked",
    "on_empossFilter_clicked",
    "on_SkewFilter_clicked",
    "on_swirlFilter_clicked",
    "on_FrameFilter_clicked",
    "on_colorBtn_clicked",
    "on_fancyBtn_clicked",
    "on_cheesFrameApply_clicked",
    "on_innerFrameApply_clicked",
    "on_coloredFrameApply_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  272,    2, 0x08,    1 /* Private */,
       4,    0,  275,    2, 0x08,    3 /* Private */,
       5,    0,  276,    2, 0x08,    4 /* Private */,
       6,    0,  277,    2, 0x08,    5 /* Private */,
       7,    0,  278,    2, 0x08,    6 /* Private */,
       8,    0,  279,    2, 0x08,    7 /* Private */,
       9,    0,  280,    2, 0x08,    8 /* Private */,
      10,    0,  281,    2, 0x08,    9 /* Private */,
      11,    0,  282,    2, 0x08,   10 /* Private */,
      12,    0,  283,    2, 0x08,   11 /* Private */,
      13,    0,  284,    2, 0x08,   12 /* Private */,
      14,    0,  285,    2, 0x08,   13 /* Private */,
      15,    1,  286,    2, 0x08,   14 /* Private */,
      17,    1,  289,    2, 0x08,   16 /* Private */,
      19,    1,  292,    2, 0x08,   18 /* Private */,
      20,    1,  295,    2, 0x08,   20 /* Private */,
      21,    0,  298,    2, 0x08,   22 /* Private */,
      22,    0,  299,    2, 0x08,   23 /* Private */,
      23,    0,  300,    2, 0x08,   24 /* Private */,
      24,    0,  301,    2, 0x08,   25 /* Private */,
      25,    0,  302,    2, 0x08,   26 /* Private */,
      26,    0,  303,    2, 0x08,   27 /* Private */,
      27,    1,  304,    2, 0x08,   28 /* Private */,
      28,    1,  307,    2, 0x08,   30 /* Private */,
      29,    1,  310,    2, 0x08,   32 /* Private */,
      31,    1,  313,    2, 0x08,   34 /* Private */,
      32,    0,  316,    2, 0x08,   36 /* Private */,
      33,    0,  317,    2, 0x08,   37 /* Private */,
      34,    0,  318,    2, 0x08,   38 /* Private */,
      35,    0,  319,    2, 0x08,   39 /* Private */,
      36,    0,  320,    2, 0x08,   40 /* Private */,
      37,    0,  321,    2, 0x08,   41 /* Private */,
      38,    0,  322,    2, 0x08,   42 /* Private */,
      39,    0,  323,    2, 0x08,   43 /* Private */,
      40,    0,  324,    2, 0x08,   44 /* Private */,
      41,    1,  325,    2, 0x08,   45 /* Private */,
      42,    1,  328,    2, 0x08,   47 /* Private */,
      43,    1,  331,    2, 0x08,   49 /* Private */,
      44,    0,  334,    2, 0x08,   51 /* Private */,
      45,    0,  335,    2, 0x08,   52 /* Private */,
      46,    0,  336,    2, 0x08,   53 /* Private */,
      47,    0,  337,    2, 0x08,   54 /* Private */,
      48,    0,  338,    2, 0x08,   55 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'handleMouseHolding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'on_loadImgBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveImgBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'outImageDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearImg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_redoBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_undoBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_invertFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateRight_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateLeft_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_purpleFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_filterApply_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sunLightFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_filterSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_blurFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_oilFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_resizeFilterBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_widthEditVal_textEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_heightEditVal_textEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_grayFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_B_W_Filter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DetectFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BrightFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_cropFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_cropWidth_textEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_cropHeight_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_cropApply_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_oldtvFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_NeonFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_HorizontalFlip_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_VerticalFlip_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_infraredFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_MergeFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_MergeCrop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_empossFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SkewFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_swirlFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_FrameFilter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_colorBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_fancyBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cheesFrameApply_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_innerFrameApply_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_coloredFrameApply_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleMouseHolding((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 1: _t->on_loadImgBtn_clicked(); break;
        case 2: _t->on_saveImgBtn_clicked(); break;
        case 3: _t->outImageDisplay(); break;
        case 4: _t->on_clearImg_clicked(); break;
        case 5: _t->on_redoBtn_clicked(); break;
        case 6: _t->on_undoBtn_clicked(); break;
        case 7: _t->on_invertFilter_clicked(); break;
        case 8: _t->on_rotateRight_clicked(); break;
        case 9: _t->on_rotateLeft_clicked(); break;
        case 10: _t->on_purpleFilter_clicked(); break;
        case 11: _t->on_filterApply_clicked(); break;
        case 12: _t->on_sunLightFilter_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->on_filterSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_blurFilter_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->on_oilFilter_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_resizeFilterBtn_clicked(); break;
        case 17: _t->on_widthEditVal_textEdited(); break;
        case 18: _t->on_heightEditVal_textEdited(); break;
        case 19: _t->on_grayFilter_clicked(); break;
        case 20: _t->on_B_W_Filter_clicked(); break;
        case 21: _t->on_DetectFilter_clicked(); break;
        case 22: _t->on_BrightFilter_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 23: _t->on_cropFilter_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 24: _t->on_cropWidth_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->on_cropHeight_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->on_cropApply_clicked(); break;
        case 27: _t->on_oldtvFilter_clicked(); break;
        case 28: _t->on_NeonFilter_clicked(); break;
        case 29: _t->on_HorizontalFlip_clicked(); break;
        case 30: _t->on_VerticalFlip_clicked(); break;
        case 31: _t->on_infraredFilter_clicked(); break;
        case 32: _t->on_MergeFilter_clicked(); break;
        case 33: _t->on_MergeCrop_clicked(); break;
        case 34: _t->on_empossFilter_clicked(); break;
        case 35: _t->on_SkewFilter_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 36: _t->on_swirlFilter_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 37: _t->on_FrameFilter_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 38: _t->on_colorBtn_clicked(); break;
        case 39: _t->on_fancyBtn_clicked(); break;
        case 40: _t->on_cheesFrameApply_clicked(); break;
        case 41: _t->on_innerFrameApply_clicked(); break;
        case 42: _t->on_coloredFrameApply_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 43;
    }
    return _id;
}
QT_WARNING_POP
