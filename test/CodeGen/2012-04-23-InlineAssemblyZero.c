// RUN: %clang_cc1 -emit-llvm -o - -triple dcpu16 %s | FileCheck %s

unsigned func(void) {
	unsigned x;
    // CHECK-NOT: \00
    asm volatile ("SET %0, SP" : "=m" (x):);
    return x;
}
