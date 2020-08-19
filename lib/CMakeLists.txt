file(GLOB SOURCES
    "*.cpp"
)

file(GLOB HEADERS
    "*.h"
)

add_library(money_to_caseslib STATIC ${SOURCES} ${HEADERS})
