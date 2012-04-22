// RUN: %clang_cc1 -emit-llvm -triple dcpu16 -O3 -o %t.opt.ll %s \
// RUN:   -fdump-record-layouts 2> %t.dump.txt
// RUN: FileCheck -check-prefix=CHECK-RECORD < %t.dump.txt %s

// CHECK-RECORD: *** Dumping AST Record Layout
// CHECK-RECORD: Record: struct mybitfield
// CHECK-RECORD: Layout: <CGRecordLayout
// CHECK-RECORD:   LLVMType:%struct.mybitfield = type { i16 }
// CHECK-RECORD:   IsZeroInitializable:1
// CHECK-RECORD:   BitFields:[
// CHECK-RECORD:     <CGBitFieldInfo Size:8 IsSigned:0
// CHECK-RECORD:                     NumComponents:1 Components: [
// CHECK-RECORD:         <AccessInfo FieldIndex:0 FieldByteOffset:0 FieldBitStart:0 AccessWidth:16
// CHECK-RECORD:                     AccessAlignment:1 TargetBitOffset:0 TargetBitWidth:8>
// CHECK-RECORD:     ]>
// CHECK-RECORD:     <CGBitFieldInfo Size:8 IsSigned:0
// CHECK-RECORD:                     NumComponents:1 Components: [
// CHECK-RECORD:         <AccessInfo FieldIndex:0 FieldByteOffset:0 FieldBitStart:8 AccessWidth:16
// CHECK-RECORD:                     AccessAlignment:1 TargetBitOffset:0 TargetBitWidth:8>
// CHECK-RECORD:     ]>
struct mybitfield {
  unsigned hi : 8;
  unsigned lo : 8;
};

struct mybitfield foo = {0xab, 0xcd};
