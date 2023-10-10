QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_apt_hard.cpp \
    admin_apt_med.cpp \
    admin_core_hard.cpp \
    admin_core_med.cpp \
    admin_homepage.cpp \
    admin_tech_hard.cpp \
    admin_tech_med.cpp \
    admin_verbal_hard.cpp \
    admin_verbal_med.cpp \
    adminedit_apt.cpp \
    adminedit_core.cpp \
    adminedit_technical.cpp \
    adminedit_verbal.cpp \
    apt_category.cpp \
    apt_easy_page.cpp \
    catergory.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp

HEADERS += \
    admin_apt_hard.h \
    admin_apt_med.h \
    admin_core_hard.h \
    admin_core_med.h \
    admin_homepage.h \
    admin_tech_hard.h \
    admin_tech_med.h \
    admin_verbal_hard.h \
    admin_verbal_med.h \
    adminedit_apt.h \
    adminedit_core.h \
    adminedit_technical.h \
    adminedit_verbal.h \
    apt_category.h \
    apt_easy_page.h \
    catergory.h \
    loginpage.h \
    mainwindow.h \
    register.h

FORMS += \
    admin_apt_hard.ui \
    admin_apt_med.ui \
    admin_core_hard.ui \
    admin_core_med.ui \
    admin_homepage.ui \
    admin_tech_hard.ui \
    admin_tech_med.ui \
    admin_verbal_hard.ui \
    admin_verbal_med.ui \
    adminedit_apt.ui \
    adminedit_core.ui \
    adminedit_technical.ui \
    adminedit_verbal.ui \
    apt_category.ui \
    apt_easy_page.ui \
    catergory.ui \
    loginpage.ui \
    mainwindow.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
