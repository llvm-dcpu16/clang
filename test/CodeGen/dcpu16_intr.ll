// RUN: %clang_cc1 -triple dcpu16 -emit-llvm < %s | FileCheck %s

void __attribute__((dcpu16_intr)) f1(unsigned msg) { }
// CHECK: define dcpu16_intrcc void @f1
