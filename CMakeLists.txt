cmake_minimum_required(VERSION 3.16)
project(LMS LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Find Qt6 or Qt5 (Uncomment based on your version)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets UiTools)  # For Qt6

# Add sources and headers (since everything is in the root folder)
set(SOURCES
    employeepage.cpp
    main.cpp
    mainwindow.cpp
)

set(HEADERS
    employeepage.h
    mainwindow.h
)

set(UI_FILES
    employeepage.ui
    mainwindow.ui
)

# Add executable
add_executable(LMS ${SOURCES} ${HEADERS} ${UI_FILES})

# Link Qt libraries
target_link_libraries(LMS PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::UiTools
)

# Enable MOC, UI Compiler, and RCC for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# For Qt 5, use qt_wrap_ui for .ui files (remove if using Qt 6)



# Process the Qt resource file (.qrc)
qt_add_resources(LMS resources.qrc)

# Ensure headers are linked correctly
target_sources(LMS PRIVATE ${HEADERS})
