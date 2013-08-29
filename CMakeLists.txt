cmake_minimum_required(VERSION 2.6)
project(omf2097-tools C)

SET(TOOLPREFIX omf-)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-scripts)
find_package(SDL)
find_package(SDL2)
find_package(argtable2)
find_package(shadowdive)
find_package(dumb)
find_package(ao)
find_package(PNG)

set(CMAKE_C_FLAGS "-Wall -std=c99 -ggdb -Werror")
set(CMAKE_C_FLAGS_DEBUG "-Wall -std=c99 -ggdb -Werror")
set(CMAKE_C_FLAGS_RELEASE "-Wall -std=c99 -O2 -march=i686 -Werror")

add_executable(${TOOLPREFIX}bktool src/bktool/main.c src/shared/animation_misc.c src/shared/conversions.c)
add_executable(${TOOLPREFIX}aftool src/aftool/main.c src/shared/animation_misc.c src/shared/conversions.c)
add_executable(${TOOLPREFIX}bkhtmlprinter src/bkhtmlprinter/main.c)
add_executable(${TOOLPREFIX}soundtool src/soundtool/main.c)
add_executable(${TOOLPREFIX}musictool src/musictool/main.c)
add_executable(${TOOLPREFIX}fonttool src/fonttool/main.c)
add_executable(${TOOLPREFIX}languagetool src/languagetool/main.c)

set(CORELIBS ${ARGTABLE2_LIBRARY})
IF(MINGW)
    set(CORELIBS mingw32 ${CORELIBS})
ENDIF(MINGW)

include_directories(
    ${SDL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    ${PNG_INCLUDE_DIR}
    ${ARGTABLE2_INCLUDE_DIR}
    ${SHADOWDIVE_INCLUDE_DIR}
    ${DUMB_INCLUDE_DIR}
    ${AO_INCLUDE_DIR}
) 
target_link_libraries(${TOOLPREFIX}bktool ${CORELIBS} ${SDL_LIBRARY} ${SHADOWDIVE_LIBRARY})
target_link_libraries(${TOOLPREFIX}aftool ${CORELIBS} ${SDL2_LIBRARY} ${SHADOWDIVE_LIBRARY})
target_link_libraries(${TOOLPREFIX}bkhtmlprinter ${CORELIBS} ${PNG_LIBRARY} ${ZLIB_LIBRARY} ${SHADOWDIVE_LIBRARY})
target_link_libraries(${TOOLPREFIX}soundtool ${CORELIBS} ${SDL2_LIBRARY} ${SHADOWDIVE_LIBRARY} ${AO_LIBRARY})
target_link_libraries(${TOOLPREFIX}musictool ${CORELIBS} ${SDL2_LIBRARY} ${DUMB_LIBRARY} ${AO_LIBRARY})
target_link_libraries(${TOOLPREFIX}fonttool ${CORELIBS} ${SDL2_LIBRARY} ${SHADOWDIVE_LIBRARY})
target_link_libraries(${TOOLPREFIX}languagetool ${CORELIBS} ${SDL2_LIBRARY} ${SHADOWDIVE_LIBRARY})

INSTALL(TARGETS ${TOOLPREFIX}bktool ${TOOLPREFIX}bkhtmlprinter ${TOOLPREFIX}aftool ${TOOLPREFIX}soundtool ${TOOLPREFIX}musictool ${TOOLPREFIX}fonttool ${TOOLPREFIX}languagetool
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
