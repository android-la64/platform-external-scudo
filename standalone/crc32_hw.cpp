//===-- crc32_hw.cpp --------------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "checksum.h"

namespace scudo {

#if defined(__CRC32__) || defined(__SSE4_2__) || defined(__ARM_FEATURE_CRC32)
u32 computeHardwareCRC32(u32 Crc, uptr Data) {
  return static_cast<u32>(CRC32_INTRINSIC(Crc, Data));
}
#endif // defined(__CRC32__) || defined(__SSE4_2__) || defined(__ARM_FEATURE_CRC32)

} // namespace scudo
