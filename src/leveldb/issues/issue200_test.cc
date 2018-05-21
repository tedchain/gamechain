// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

// Test for issue 200: when iterator switches direction from backward
// to forward, the current key can be yielded unexpectedly if a new
// mutation has been added just before the current key.

#include "leveldb/db.h"
#include "util/testharness.h"

namespace leveldb {

class Issue200 { };

TEST(Issue200, Test) {
  // Get rid of any state from an old run.
  std::string dbpath = test::TmpDir() + "/leveldb_issue200_test";
  DestroyDB(dbpath, Options());

  DB *db;
  Options options;
  options.create_if_missing = true;
  ASSERT_OK(DB::Open(options, dbpath, &db));

  WriteOptions write_options;
  ASSERT_OK(db->Put(write_options, "1", "b"));
  ASSERT_OK(db->Put(write_options, "2", "c"));
  ASSERT_OK(db->Put(write_options, "3", "d"));
  ASSERT_OK(db->Put(write_options, "4", "e"));
  ASSERT_OK(db->Put(write_options, "5", "f"));

  ReadOptions read_options;
  Iterator *iter = db->NewIterator(read_options);

  // Add an element that should not be reflected in the iterator.
  ASSERT_OK(db->Put(write_options, "25", "cd"));

  iter->Seek("5");
  ASSERT_EQ(iter->key().ToString(), "5");
  iter->Prev();
  ASSERT_EQ(iter->key().ToString(), "4");
  iter->Prev();
  ASSERT_EQ(iter->key().ToString(), "3");
  iter->Next();
  ASSERT_EQ(iter->key().ToString(), "4");
  iter->Next();
  ASSERT_EQ(iter->key().ToString(), "5");

  delete iter;
  delete db;
  DestroyDB(dbpath, options);
}

}  // namespace leveldb

int main(int argc, char** argv) {
  return leveldb::test::RunAllTests();
}
