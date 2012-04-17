// RUN: %clang_cc1 %s -x c -triple dcpu16 -emit-llvm -o - | FileCheck %s
void foo(char *str) {
  str[0] = '\0';
}
// CHECK: @foo
