add_executable(
    test_hash
        test_hash_fns.cpp
)
target_link_directories(test_hash PRIVATE bloom)
add_test(NAME hash_test COMMAND test_hash)
