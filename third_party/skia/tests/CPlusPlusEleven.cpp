/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkTemplates.h"
#include "Test.h"
#include <utility>

namespace {
class Moveable {
public:
    Moveable() { }
    Moveable(Moveable&&) { }
    Moveable& operator=(Moveable&&) { return *this; }

=======
#include "Test.h"

namespace {
template <class T> T&& Move(T& o) { return static_cast<T&&>(o); }

class Moveable {
public:
    Moveable() {}
    Moveable(Moveable&&) {}
    Moveable& operator=(Moveable&&) { return *this; }
>>>>>>> miniblink49
private:
    Moveable(const Moveable&);
    Moveable& operator=(const Moveable&);
};
<<<<<<< HEAD
template <typename T>
void deleter(T*) { }
template <typename T>
struct Deleter {
    void operator()(T* t) { delete static_cast<const Moveable*>(t); }
};
} // namespace

DEF_TEST(CPlusPlusEleven_RvalueAndMove, r)
{
    Moveable src1;
    Moveable dst1(std::move(src1));
    Moveable src2, dst2;
    dst2 = std::move(src2);
}

DEF_TEST(CPlusPlusEleven_constexpr, r)
{
    static constexpr int x = Sk32ToBool(50);
    REPORTER_ASSERT(r, x == 1);
    static constexpr int y = SkTPin<int>(100, 0, 10);
    REPORTER_ASSERT(r, y == 10);
=======
} // namespace

DEF_TEST(CPlusPlusEleven_RvalueAndMove, r) {
    Moveable src1; Moveable dst1(Move(src1));
    Moveable src2, dst2; dst2 = Move(src2);
>>>>>>> miniblink49
}
