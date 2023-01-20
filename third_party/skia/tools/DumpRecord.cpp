/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdio.h>

#include "SkRecord.h"
#include "SkRecordDraw.h"

#include "DumpRecord.h"
<<<<<<< HEAD
#include "SkTime.h"
=======
#include "Timer.h"
>>>>>>> miniblink49

namespace {

class Dumper {
public:
    explicit Dumper(SkCanvas* canvas, int count, bool timeWithCommand)
        : fDigits(0)
        , fIndent(0)
        , fIndex(0)
<<<<<<< HEAD
        , fDraw(canvas, nullptr, nullptr, 0, nullptr)
        , fTimeWithCommand(timeWithCommand)
    {
=======
        , fDraw(canvas, NULL, NULL, 0, NULL)
        , fTimeWithCommand(timeWithCommand) {
>>>>>>> miniblink49
        while (count > 0) {
            count /= 10;
            fDigits++;
        }
    }

    template <typename T>
<<<<<<< HEAD
    void operator()(const T& command)
    {
        auto start = SkTime::GetNSecs();
        fDraw(command);
        this->print(command, SkTime::GetNSecs() - start);
    }

    void operator()(const SkRecords::NoOp&)
    {
=======
    void operator()(const T& command) {
        Timer timer;
        timer.start();
            fDraw(command);
        timer.end();

        this->print(command, timer.fCpu);
    }

    void operator()(const SkRecords::NoOp&) {
>>>>>>> miniblink49
        // Move on without printing anything.
    }

    template <typename T>
<<<<<<< HEAD
    void print(const T& command, double ns)
    {
        this->printNameAndTime(command, ns);
    }

    void print(const SkRecords::Restore& command, double ns)
    {
        --fIndent;
        this->printNameAndTime(command, ns);
    }

    void print(const SkRecords::Save& command, double ns)
    {
        this->printNameAndTime(command, ns);
        ++fIndent;
    }

    void print(const SkRecords::SaveLayer& command, double ns)
    {
        this->printNameAndTime(command, ns);
        ++fIndent;
    }

    void print(const SkRecords::DrawPicture& command, double ns)
    {
        this->printNameAndTime(command, ns);

        if (auto bp = command.picture->asSkBigPicture()) {
            ++fIndent;

            const SkRecord& record = *bp->record();
            for (int i = 0; i < record.count(); i++) {
                record.visit(i, *this);
            }

            --fIndent;
        }
    }

private:
    template <typename T>
    void printNameAndTime(const T& command, double ns)
    {
        int us = (int)(ns * 1e-3);
        if (!fTimeWithCommand) {
            printf("%6dus  ", us);
        }
        printf("%*d ", fDigits, fIndex++);
        for (int i = 0; i < fIndent; i++) {
            printf("    ");
        }
        if (fTimeWithCommand) {
            printf("%6dus  ", us);
=======
    void print(const T& command, double time) {
        this->printNameAndTime(command, time);
    }

    void print(const SkRecords::Restore& command, double time) {
        --fIndent;
        this->printNameAndTime(command, time);
    }

    void print(const SkRecords::Save& command, double time) {
        this->printNameAndTime(command, time);
        ++fIndent;
    }

    void print(const SkRecords::SaveLayer& command, double time) {
        this->printNameAndTime(command, time);
        ++fIndent;
    }

private:
    template <typename T>
    void printNameAndTime(const T& command, double time) {
        if (!fTimeWithCommand) {
            printf("%6.1f ", time * 1000);
        }
        printf("%*d ", fDigits, fIndex++);
        for (int i = 0; i < fIndent; i++) {
            putchar('\t');
        }
        if (fTimeWithCommand) {
            printf("%6.1f ", time * 1000);
>>>>>>> miniblink49
        }
        puts(NameOf(command));
    }

    template <typename T>
<<<<<<< HEAD
    static const char* NameOf(const T&)
    {
#define CASE(U)               \
    case SkRecords::U##_Type: \
        return #U;
        switch (T::kType) {
            SK_RECORD_TYPES(CASE);
        }
#undef CASE
=======
    static const char* NameOf(const T&) {
    #define CASE(U) case SkRecords::U##_Type: return #U;
        switch(T::kType) { SK_RECORD_TYPES(CASE); }
    #undef CASE
>>>>>>> miniblink49
        SkDEBUGFAIL("Unknown T");
        return "Unknown T";
    }

<<<<<<< HEAD
    static const char* NameOf(const SkRecords::SaveLayer&)
    {
        return "\x1b[31;1mSaveLayer\x1b[0m"; // Bold red.
=======
    static const char* NameOf(const SkRecords::SaveLayer&) {
        return "\x1b[31;1mSaveLayer\x1b[0m";  // Bold red.
>>>>>>> miniblink49
    }

    int fDigits;
    int fIndent;
    int fIndex;
    SkRecords::Draw fDraw;
    const bool fTimeWithCommand;
};

<<<<<<< HEAD
} // namespace

void DumpRecord(const SkRecord& record,
    SkCanvas* canvas,
    bool timeWithCommand)
{
    Dumper dumper(canvas, record.count(), timeWithCommand);
    for (int i = 0; i < record.count(); i++) {
        record.visit(i, dumper);
=======
}  // namespace

void DumpRecord(const SkRecord& record,
                  SkCanvas* canvas,
                  bool timeWithCommand) {
    Dumper dumper(canvas, record.count(), timeWithCommand);
    for (unsigned i = 0; i < record.count(); i++) {
        record.visit<void>(i, dumper);
>>>>>>> miniblink49
    }
}
