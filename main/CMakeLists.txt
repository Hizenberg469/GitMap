set(GITMAP Gitmap)
set(MAIN_SRC "main.c")

add_executable(${GITMAP}
					${MAIN_SRC})

target_link_libraries(${GITMAP} PUBLIC
								${GTIMAP_LIBRARY})