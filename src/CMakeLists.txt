set(PRINTCLR_SRC
		"printclr.c")

set(COMMAND_SRC
		"command.c")

set(SCAN_SRC
		"scan.c")

set(GEN_XML_SRC
		"genXml.c")

add_library(${GITMAP_LIBRARY} STATIC
				${PRINTCLR_SRC}
				${COMMAND_SRC}
				${SCAN_SRC}
				${GEN_XML_SRC})

target_link_libraries(${GITMAP_LIBRARY} PUBLIC
							${MXML_LIBRARIES})

target_include_directories(${GITMAP_LIBRARY} PUBLIC
									${HEADER_DIR}
									${MXML_INCLUDE_DIRS})