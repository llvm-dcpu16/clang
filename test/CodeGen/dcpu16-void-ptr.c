// RUN: %clang_cc1 -emit-llvm -o - -triple dcpu16 %s | FileCheck %s

struct void_struct {
  void *a, *b;
};
// CHECK: %struct.void_struct = type { i16*, i16* }

void use_void_struct(struct void_struct *vs) {
  vs->a = vs->b;
}
// CHECK: define void @use_void_struct
// CHECK: store i16* %1, i16** %a, align 1

void *cast_to_void(int *x) {
  return x;
}
// CHECK: define i16* @cast_to_void(i16* %x)
// CHECK: ret i16* %0
