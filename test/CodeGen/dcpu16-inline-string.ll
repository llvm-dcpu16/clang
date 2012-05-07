// RUN: %clang_cc1 -triple dcpu16 -O1 -emit-llvm < %s | FileCheck %s

void lookup(char* ptr, int index) {
  *ptr = "foo"[index];
}
// CHECK: define void @lookup
// CHECK: %arrayidx = getelementptr inbounds [4 x i16]* @.str, i16 0, i16 %index
// CHECK: %0 = load i16* %arrayidx
// CHECK: store i16 %0, i16* %ptr
