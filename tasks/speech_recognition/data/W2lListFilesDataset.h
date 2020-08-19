/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "data/SpeechSample.h"
#include "data/Utils.h"
#include "data/W2lDataset.h"

namespace fl {
namespace task {
namespace asr {

class W2lListFilesDataset : public W2lDataset {
 public:
  W2lListFilesDataset(
      const std::string& filenames,
      const lib::DictionaryMap& dicts,
      const lib::LexiconMap& lexicon,
      int64_t batchSize,
      int worldRank = 0,
      int worldSize = 1,
      bool fallback2Ltr = false,
      bool skipUnk = false,
      const std::string& rootdir = "");

  ~W2lListFilesDataset() override;

  virtual std::vector<W2lLoaderData> getLoaderData(
      const int64_t idx) const override;

 private:
  std::vector<int64_t> sampleSizeOrder_;
  std::vector<SpeechSample> data_;
  lib::LexiconMap lexicon_;
  bool includeWrd_;
  bool fallback2Ltr_;
  bool skipUnk_;

  std::vector<SpeechSampleMetaInfo> loadListFile(const std::string& filename);
};
} 
}
}