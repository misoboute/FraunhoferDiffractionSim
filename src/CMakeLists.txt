PROJECT(FraunhoferDiffractionSim)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

set(SOURCE_FILES
    fraunhofer_diffraction.cpp
    main.cpp
)

set(HEADER_FILES
    fraunhofer_diffraction.h
)

find_package(ROOT REQUIRED)
include_directories(${ROOT_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} ${ROOT_LIBRARIES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_constexpr)