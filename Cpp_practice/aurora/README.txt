# Assumptions
1. The code simply tests setter, getter, send and receive. Any assigment operator overloads such as = were not created.
2. A send() and receive() pairs are created. A byte array is formed and used. 
3. sendText() and receiveText() pair is created and should be used in that sequence. main.cpp and unit tests cover have a template for this
4. A packet has 
    ____________________________________________
    Header                        | payload
    ____________________________________________
5. A packet for base protocol has a maximum payload size limit defined as PAYLOAD_SIZE
6. A derived class with Lights, Camera, Action, Name is named as 'Film'
7. The endianness is handled when the data is 64-bit (or could be 32-bit). For the packets with byte sized words, endianness was not introduced.
8. The maxmimum payload size for Film packets are limited to FILM_PAYLOAD_LEN
9. After running Unittests, changes were made in the code. These can be found in the comments with 'GTEST' in the comments, inside the src folder.

# Tools to Compile:
## Compile main
  cd src
  g++ -o program main.cpp base.cpp film.cpp

## Compile Unittests
Googletest could be pre-installed as a build-time tool or could be a Configure-time download.
This would make an executable src/main and a Googletest executable test/unittest_base 
To have Googletest as a build-time tool:

  sudo apt-get install libgtest-dev build-essential cmake
  cd /usr/src/gtest
  sudo cmake CMakeLists.txt
  sudo make
By this step, Two libs are built and linked;
  /usr/src/gtest/lib/libgtest.a
  /usr/src/gtest/lib/libgtest_main.a

### update cmake 
  wget https://github.com/Kitware/CMake/releases/download/v3.30.0-rc4/cmake-3.30.0-rc4.tar.gz
  tar -zxvf cmake-3.30
  cd cmake-3.30
  ./bootstrap
  make -j$(nproc)
  sudo make install
  cmake --version
  cd aurora
  mkdir build && cd build
  rm -rf *
  cmake -S ../ -B .
  make
  ./test/unittest_base

After calling 'make', the tests start to build:
[  6%] Building CXX object src/CMakeFiles/pkt_protocol.dir/base.cpp.o
[ 13%] Building CXX object src/CMakeFiles/pkt_protocol.dir/film.cpp.o
[ 20%] Building CXX object src/CMakeFiles/pkt_protocol.dir/main.cpp.o
[ 26%] Linking CXX static library libpkt_protocol.a
[ 26%] Built target pkt_protocol
[ 33%] Building CXX object src/CMakeFiles/main.dir/main.cpp.o
[ 40%] Building CXX object src/CMakeFiles/main.dir/base.cpp.o
[ 46%] Building CXX object src/CMakeFiles/main.dir/film.cpp.o
[ 53%] Linking CXX executable main
[ 53%] Built target main
[ 60%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 66%] Linking CXX static library ../../../lib/libgtest.a
[ 66%] Built target gtest
[ 73%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 80%] Linking CXX static library ../../../lib/libgtest_main.a
[ 80%] Built target gtest_main
[ 86%] Building CXX object test/CMakeFiles/unittest_base.dir/test_base.cpp.o
[ 93%] Building CXX object test/CMakeFiles/unittest_base.dir/test_film.cpp.o
[100%] Linking CXX executable unittest_base
[100%] Built target unittest_base

The new files created show in the tree
.
├── CMakeLists.txt
├── README.txt
├── build
│   ├── Makefile
│ .....
│   ├── bin
│   ├── lib
│   │   ├── libgtest.a
│   │   └── libgtest_main.a
│   ├── src
│ ........
│   │   └── main <-------- main() executable
│   └── test
│       ........
│       └── unittest_base <--------- Unit tests executable
├── src
│   ├── CMakeLists.txt
│   ├── base.cpp
│   ├── base.hpp
│   ├── film.cpp
│   └── main.cpp
└── test
    ├── CMakeLists.txt
    ├── test_base.cpp
    └── test_film.cpp

### Execute the tests
./test/unittest_base

[==========] Running 13 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 9 tests from BaseTest
[ RUN      ] BaseTest.payload_is_not_char_but_string
[       OK ] BaseTest.payload_is_not_char_but_string (0 ms)
[----------] 9 tests from BaseTest (0 ms total)

[----------] 4 tests from FilmTest
[ RUN      ] FilmTest.receive_and_send_empty_film
[       OK ] FilmTest.receive_and_send_empty_film (0 ms)

[----------] Global test environment tear-down
[==========] 13 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 13 tests.