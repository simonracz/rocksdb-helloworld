* RocksDB Hello World

1. Get and build Rocksdb in a sibling folder. (installing librocksdb-dev would also work)
2. `g++ -o hello hello.cpp -O2 -march=native -mtune=native -Wall -Wextra -std=c++17 -lrocksdb -I../rocksdb/include -L../rocksdb/build`
3. `LD_LIBRARY_PATH=../rocksdb/build ./hello`
