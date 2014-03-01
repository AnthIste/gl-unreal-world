include_directories ("${PROJECT_SOURCE_DIR}/src/modules/ogl")

include_directories (
    uwl
    uwlec
    uwlevt
    uwlinf
    uwlman
    uwlsys
    uwlutil
)

file(GLOB sources
    uwl/*.cc
    uwlec/*.cc
    uwlevt/*.cc
    uwlinf/*.cc
    uwlman/*.cc
    uwlsys/*.cc
    uwlutil/*.cc
)

add_library (uwl ${sources})
target_link_libraries (uwl ogl)

install (TARGETS uwl DESTINATION bin)
