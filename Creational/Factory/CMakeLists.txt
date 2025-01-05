# Create an executable for FurnitureFactory
add_executable(CoffeeMakerFactoryApp
    CoffeeMakerFactory.cpp
)

# Include the current directory to locate headers
target_include_directories(CoffeeMakerFactoryApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


# Create an executable for FurnitureFactory
add_executable(ShapeFactoryApp
    ShapeFactory.cpp
)

# Include the current directory to locate headers
target_include_directories(ShapeFactoryApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ShapeFactory)


# Create an executable for FurnitureFactory
add_executable(TransportFactoryApp
    TransportFactory.cpp
)

# Include the current directory to locate headers
target_include_directories(TransportFactoryApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/TransportFactory)
