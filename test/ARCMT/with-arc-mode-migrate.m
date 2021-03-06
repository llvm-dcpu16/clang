// RUN: rm -rf %t
// RUN: %clang_cc1 -fsyntax-only -fobjc-arc -x objective-c %s.result
// RUN: %clang_cc1 -arcmt-migrate -mt-migrate-directory %t -fsyntax-only -fobjc-arc %s
// RUN: c-arcmt-test -mt-migrate-directory %t | arcmt-test -verify-transformed-files %s.result
// RUN: rm -rf %t

@protocol NSObject
- (oneway void)release;
@end

void test1(id p) {
  [p release];
}
