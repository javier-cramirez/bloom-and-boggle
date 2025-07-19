add_executable(
    test_hash
        test_hash_fns.cpp
)
target_link_libraries(test_hash PRIVATE bloom)
add_test(NAME hash_test COMMAND test_hash)

add_executable(
    test_bloom 
        test_bloom.cpp
)
target_link_libraries(test_bloom PRIVATE bloom)
add_test(NAME bloom_test COMMAND test_bloom)

