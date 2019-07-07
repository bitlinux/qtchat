#-------------------------------------------------
#
# Project created by QtCreator 2019-06-01T21:37:54
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chat
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        add_group_member.cpp \
        bbs.cpp \
        bbsitem.cpp \
        bbsitem_detail.cpp \
        forget_one.cpp \
        forget_two.cpp \
        group_chat.cpp \
        group_chat_message.cpp \
        login.cpp \
        main.cpp \
        notice_dialog.cpp \
        private_chat.cpp \
        private_chat_message.cpp \
        reg_one.cpp \
        reg_success.cpp \
        reg_two.cpp \
        addfriend.cpp \
        creategroup.cpp \
        editname.cpp \
        frienditem.cpp \
        mainwindow.cpp \
        groupitem.cpp \
        noticeitem.cpp \
        tcpsocket.cpp \
        newpostwindow.cpp \
        widget.cpp

HEADERS += \
        add_group_member.h \
        bbs.h \
        bbsitem.h \
        bbsitem_detail.h \
        constant.h \
        forget_one.h \
        forget_two.h \
        group_chat.h \
        group_chat_message.h \
        login.h \
        notice_dialog.h \
        private_chat.h \
        private_chat_message.h \
        reg_one.h \
        reg_success.h \
        reg_two.h \
        addfriend.h \
        creategroup.h \
        editname.h \
        frienditem.h \
        mainwindow.h \
        groupitem.h \
        noticeitem.h \
        tcpsocket.h \
        newpostwindow.h \
        widget.h


FORMS += \
        add_group_member.ui \
        bbs.ui \
        bbsitem.ui \
        bbsitem_detail.ui \
        forget_one.ui \
        forget_two.ui \
        group_chat.ui \
        group_chat_message.ui \
        login.ui \
        notice_dialog.ui \
        private_chat.ui \
        private_chat_message.ui \
        reg_one.ui \
        reg_success.ui \
        reg_two.ui \
        addfriend.ui \
        creategroup.ui \
        editname.ui \
        frienditem.ui \
        mainwindow.ui \
        groupitem.ui \
        noticeitem.ui \
        newpostwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
