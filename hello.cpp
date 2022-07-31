#include <cassert>
#include <string>
#include <iostream>
#include "rocksdb/db.h"

int main(int argc, char* argv[]) {
	rocksdb::DB* db;
	rocksdb::Options options;
	options.create_if_missing = true;
	rocksdb::Status s =
		rocksdb::DB::Open(options, "./hellodb", &db);
	assert(s.ok());
	std::string key = "hello";
	std::string message;
	s = db->Get(rocksdb::ReadOptions(), key, &message);
	if (!s.ok()) s = db->Put(rocksdb::WriteOptions(), key, "Hello World!");
	assert(s.ok());
	s = db->Get(rocksdb::ReadOptions(), key, &message);
	assert(s.ok());
	delete db;
	std::cout << message;
	return 0;
}
