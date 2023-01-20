/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkChecksum.h"
#include "SkMD5.h"
#include "SkRandom.h"
<<<<<<< HEAD
#include "SkTemplates.h"

enum ChecksumType {
    kMD5_ChecksumType,
=======
#include "SkSHA1.h"
#include "SkTemplates.h"

enum ChecksumType {
    kChecksum_ChecksumType,
    kMD5_ChecksumType,
    kSHA1_ChecksumType,
>>>>>>> miniblink49
    kMurmur3_ChecksumType,
};

class ComputeChecksumBench : public Benchmark {
    enum {
<<<<<<< HEAD
        U32COUNT = 256,
        SIZE = U32COUNT * 4,
    };
    uint32_t fData[U32COUNT];
    ChecksumType fType;

public:
    ComputeChecksumBench(ChecksumType type)
        : fType(type)
    {
=======
        U32COUNT  = 256,
        SIZE      = U32COUNT * 4,
    };
    uint32_t    fData[U32COUNT];
    ChecksumType fType;

public:
    ComputeChecksumBench(ChecksumType type) : fType(type) {
>>>>>>> miniblink49
        SkRandom rand;
        for (int i = 0; i < U32COUNT; ++i) {
            fData[i] = rand.nextU();
        }
    }

<<<<<<< HEAD
    bool isSuitableFor(Backend backend) override
    {
=======
    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
        switch (fType) {
        case kMD5_ChecksumType:
            return "compute_md5";
        case kMurmur3_ChecksumType:
            return "compute_murmur3";

        default:
            SK_ABORT("Invalid Type");
            return "";
        }
    }

    void onDraw(int loops, SkCanvas*) override
    {
        switch (fType) {
        case kMD5_ChecksumType: {
            for (int i = 0; i < loops; i++) {
                SkMD5 md5;
                md5.write(fData, sizeof(fData));
                SkMD5::Digest digest;
                md5.finish(digest);
            }
        } break;
        case kMurmur3_ChecksumType: {
            for (int i = 0; i < loops; i++) {
                volatile uint32_t result = SkChecksum::Murmur3(fData, sizeof(fData));
                sk_ignore_unused_variable(result);
            }
        } break;
        }
=======
    virtual const char* onGetName() {
        switch (fType) {
            case kChecksum_ChecksumType: return "compute_checksum";
            case kMD5_ChecksumType: return "compute_md5";
            case kSHA1_ChecksumType: return "compute_sha1";
            case kMurmur3_ChecksumType: return "compute_murmur3";

            default: SK_CRASH(); return "";
        }
    }

    virtual void onDraw(const int loops, SkCanvas*) {
        switch (fType) {
            case kChecksum_ChecksumType: {
                for (int i = 0; i < loops; i++) {
                    volatile uint32_t result = SkChecksum::Compute(fData, sizeof(fData));
                    sk_ignore_unused_variable(result);
                }
            } break;
            case kMD5_ChecksumType: {
                for (int i = 0; i < loops; i++) {
                    SkMD5 md5;
                    md5.update(reinterpret_cast<uint8_t*>(fData), sizeof(fData));
                    SkMD5::Digest digest;
                    md5.finish(digest);
                }
            } break;
            case kSHA1_ChecksumType: {
                for (int i = 0; i < loops; i++) {
                    SkSHA1 sha1;
                    sha1.update(reinterpret_cast<uint8_t*>(fData), sizeof(fData));
                    SkSHA1::Digest digest;
                    sha1.finish(digest);
                }
            } break;
            case kMurmur3_ChecksumType: {
                for (int i = 0; i < loops; i++) {
                    volatile uint32_t result = SkChecksum::Murmur3(fData, sizeof(fData));
                    sk_ignore_unused_variable(result);
                }
            }break;
        }

>>>>>>> miniblink49
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new ComputeChecksumBench(kMD5_ChecksumType);)
DEF_BENCH(return new ComputeChecksumBench(kMurmur3_ChecksumType);)
=======
DEF_BENCH( return new ComputeChecksumBench(kChecksum_ChecksumType); )
DEF_BENCH( return new ComputeChecksumBench(kMD5_ChecksumType); )
DEF_BENCH( return new ComputeChecksumBench(kSHA1_ChecksumType); )
DEF_BENCH( return new ComputeChecksumBench(kMurmur3_ChecksumType); )
>>>>>>> miniblink49
