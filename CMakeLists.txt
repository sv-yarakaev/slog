cmake_minimum_required(VERSION 3.10)
project(slog C)

set(CMAKE_C_STANDARD 11)
FIND_PACKAGE(GTK)
find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)

pkg_check_modules(JSON-GLIB REQUIRED json-glib-1.0)
include_directories(${JSON-GLIB_INCLUDE_DIRS})

pkg_check_modules(GLIB   glib-2.0 gobject-2.0 REQUIRED)
include_directories(${GLIB_INCLUDE_DIRS})

include_directories (${GTK3_INCLUDE_DIRS})
link_directories (${GTK3_LIBRARY_DIRS})


add_compile_options(-export-dynamic -rdynamic)
#add_compile_options(-Wall -Wextra -pedantic )

configure_file(main.xml main.xml COPYONLY)


add_definitions (${GTK3_CFLAGS_OTHER})
add_executable(${PROJECT_NAME} main.c w_tarm_ui.c window.c signal_note.c)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTK3_LIBRARIES} ${GLIB_LIBRARIES}  ${JSON-GLIB_LIBRARIES} -export-dynamic)