PROJECT(FraunhoferDiffractionSim)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

set(SOURCE_FILES
    FraunhofferDiffractionSim.cpp
    main.cpp
)

set(HEADER_FILES
    FraunhoferDiffractionSim.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_constexpr)

