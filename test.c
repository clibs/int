
//
// test.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "int.h"

void
test_read_u16_be() {
  unsigned char buf[2] = { 0xd9, 0x03 };
  uint16_t n = read_u16_be(buf);
  assert(0xd903 == n);
}

void
test_read_u16_le() {
  unsigned char buf[2] = { 0x03, 0xd9 };
  uint16_t n = read_u16_le(buf);
  assert(0xd903 == n);
}

void
test_read_u32_be() {
  unsigned char buf[4] = { 0xff, 0xff, 0xec, 0x78 };
  uint32_t n = read_u32_be(buf);
  assert(0xffffec78 == n);
}

void
test_read_u32_le() {
  unsigned char buf[4] = { 0x78, 0xec, 0xff, 0xff };
  uint32_t n = read_u32_le(buf);
  assert(0xffffec78 == n);
}

void
test_read_u64_be() {
  unsigned char buf[8] = { 0xff, 0xfb, 0xa0, 0x31, 0x0e, 0xaf, 0xb0, 0x00 };
  uint64_t n = read_u64_be(buf);
  assert(0xfffba0310eafb000 == n);
}

void
test_read_u64_le() {
  unsigned char buf[8] = { 0x00, 0xb0, 0xaf, 0x0e, 0x31, 0xa0, 0xfb, 0xff };
  uint64_t n = read_u64_le(buf);
  assert(0xfffba0310eafb000 == n);
}

void
test_read() {
  test_read_u16_be();
  test_read_u16_le();
  test_read_u32_be();
  test_read_u32_le();
  test_read_u64_be();
  test_read_u64_le();
}

void
test_write_u16_be() {
  unsigned char buf[2] = {0};
  write_u16_be(buf, 0xd903);
  assert(0xd9 == buf[0]);
  assert(0x03 == buf[1]);
}

void
test_write_u16_le() {
  unsigned char buf[2] = {0};
  write_u16_le(buf, 0xd903);
  assert(0x03 == buf[0]);
  assert(0xd9 == buf[1]);
}

void
test_write_u32_be() {
  unsigned char buf[4] = {0};
  write_u32_be(buf, 0xffffec78);
  assert(0xff == buf[0]);
  assert(0xff == buf[1]);
  assert(0xec == buf[2]);
  assert(0x78 == buf[3]);
}

void
test_write_u32_le() {
  unsigned char buf[4] = {0};
  write_u32_le(buf, 0xffffec78);
  assert(0xff == buf[3]);
  assert(0xff == buf[2]);
  assert(0xec == buf[1]);
  assert(0x78 == buf[0]);
}

void
test_write_u64_be() {
  unsigned char buf[8] = {0};
  write_u64_be(buf, 0xfffba0310eafb000);
  assert(buf[0] == 0xff);
  assert(buf[1] == 0xfb);
  assert(buf[2] == 0xa0);
  assert(buf[3] == 0x31);
  assert(buf[4] == 0x0e);
  assert(buf[5] == 0xaf);
  assert(buf[6] == 0xb0);
  assert(buf[7] == 0x00);
}

void
test_write_u64_le() {
  unsigned char buf[8] = {0};
  write_u64_le(buf, 0xfffba0310eafb000);
  assert(buf[7] == 0xff);
  assert(buf[6] == 0xfb);
  assert(buf[5] == 0xa0);
  assert(buf[4] == 0x31);
  assert(buf[3] == 0x0e);
  assert(buf[2] == 0xaf);
  assert(buf[1] == 0xb0);
  assert(buf[0] == 0x00);
}

void
test_write() {
  test_write_u16_be();
  test_write_u16_le();
  test_write_u32_be();
  test_write_u32_le();
  test_write_u64_be();
  test_write_u64_le();
}

int
main(){
  test_read();
  test_write();
  printf("\n  \e[32m\u2713 \e[90mok\e[0m\n\n");
  return 0;
}
