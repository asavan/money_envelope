file(GLOB SOURCES
    "*.cpp"
)

file(GLOB HEADERS
    "*.h"
)

add_library(utilslib STATIC ${SOURCES} ${HEADERS})

