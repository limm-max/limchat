cmake_minimum_required(VERSION 3.19)
project(limchat LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets UiTools Network)
set(CMAKE_AUTORCC ON)
qt_standard_project_setup()

qt_add_executable(limchat
    WIN32 MACOSX_BUNDLE
    app.rc
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    singleton.h
    global.h
    global.cpp
    timerbutton.h timerbutton.cpp
    clickedlabel.h clickedlabel.cpp
    logindialog.h logindialog.cpp logindialog.ui
    registerdialog.h registerdialog.cpp registerdialog.ui
    resetdialog.h resetdialog.cpp resetdialog.ui
    rc.qrc
    testdialog.ui






)


target_include_directories(limchat PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(limchat
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::UiTools
        Qt::Network
)

install(TARGETS limchat
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET limchat
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
