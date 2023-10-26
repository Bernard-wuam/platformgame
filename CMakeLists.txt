cmake_minimum_required(VERSION 3.16)

project(keepMe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appkeepMe
    main.cpp
    filemonitoringclass.h
    filemonitoringclass.cpp
    componentcreatorengine.h
    componentcreatorengine.cpp
)

qt_add_qml_module(appkeepMe
    URI keepMe
    VERSION 1.0
    QML_FILES
    Main.qml
    MainWindow.qml
    ChatList.qml
    SOURCES
    sprite.h sprite.cpp
    gameloop.h gameloop.cpp
    input.h input.cpp
    utils.h utils.cpp
    state.h
    movingrightstate.h movingrightstate.cpp
    movingleftstate.h movingleftstate.cpp
    testingvec.h testingvec.cpp
    iddlerightstate.h iddlerightstate.cpp
    iddleleftstate.h iddleleftstate.cpp
    movingupstate.h movingupstate.cpp
    iddleupstate.h iddleupstate.cpp
    movingdownstate.h movingdownstate.cpp
    iddledownstate.h iddledownstate.cpp
    walkable.h

    RESOURCES
    assets/sprites/sky.png
    assets/sprites/ground.png
    assets/sprites/hero-sheet.png
    assets/sprites/shadow.png
    assets/sprites/spritesheet.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appkeepMe PROPERTIES
    #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appkeepMe
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appkeepMe
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appkeepMe
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
