set(TEST_EXECUTABLE 
		"test_main")

set(TEST_SRC
		"test_main.c")

add_executable(${TEST_EXECUTABLE}
					${TEST_SRC})

target_link_libraries(${TEST_EXECUTABLE} PUBLIC
								${GITMAP_LIBRARY})