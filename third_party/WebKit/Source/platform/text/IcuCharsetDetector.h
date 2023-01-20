
<<<<<<< HEAD
#include "unicode/umachine.h"
#include "unicode/utypes.h"

class InputText {
    // Prevent copying
    InputText(const InputText&);

public:
    InputText(UErrorCode& status);
    ~InputText();

    void setText(const char* in, int32_t len);
    //     void setDeclaredEncoding(const char *encoding, int32_t len);
=======
class InputText {
    // Prevent copying
    InputText(const InputText &);
public:
    InputText(UErrorCode &status);
    ~InputText();

    void setText(const char *in, int32_t len);
//     void setDeclaredEncoding(const char *encoding, int32_t len);
>>>>>>> miniblink49
    UBool isSet() const;
    void MungeInput(UBool fStripTags);

    // The text to be checked.  Markup will have been
    //   removed if appropriate.
<<<<<<< HEAD
    uint8_t* fInputBytes;
    int32_t fInputLen; // Length of the byte data in fInputBytes.
    // byte frequency statistics for the input text.
    //   Value is percent, not absolute.
    //   Value is rounded up, so zero really means zero occurences.
    int16_t* fByteStats;
    UBool fC1Bytes; // True if any bytes in the range 0x80 - 0x9F are in the input;false by default
    char* fDeclaredEncoding;

    const uint8_t* fRawInput; // Original, untouched input bytes.
    //  If user gave us a byte array, this is it.
    //  If user gave us a stream, it's read to a
    //   buffer here.
    int32_t fRawLength; // Length of data in fRawInput array.
=======
    uint8_t    *fInputBytes;
    int32_t     fInputLen;          // Length of the byte data in fInputBytes.
    // byte frequency statistics for the input text.
    //   Value is percent, not absolute.
    //   Value is rounded up, so zero really means zero occurences. 
    int16_t  *fByteStats;
    UBool     fC1Bytes;          // True if any bytes in the range 0x80 - 0x9F are in the input;false by default
    char     *fDeclaredEncoding;

    const uint8_t           *fRawInput;     // Original, untouched input bytes.
    //  If user gave us a byte array, this is it.
    //  If user gave us a stream, it's read to a 
    //   buffer here.
    int32_t                  fRawLength;    // Length of data in fRawInput array.
>>>>>>> miniblink49
};

class CharsetRecognizer;

class CharsetMatch {
private:
<<<<<<< HEAD
    InputText* textIn;
    int32_t confidence;
    const char* fCharsetName;
    const char* fLang;
=======
    InputText               *textIn;
    int32_t                 confidence;
    const char              *fCharsetName;
    const char              *fLang;
>>>>>>> miniblink49

public:
    CharsetMatch();

    /**
    * fully set the state of this CharsetMatch.
    * Called by the CharsetRecognizers to record match results.
    * Default (NULL) parameters for names will be filled by calling the
    *   corresponding getters on the recognizer.
    */
<<<<<<< HEAD
    void set(InputText* input,
        const CharsetRecognizer* cr,
        int32_t conf,
        const char* csName = NULL,
        const char* lang = NULL);
=======
    void set(InputText               *input,
        const CharsetRecognizer *cr,
        int32_t                  conf,
        const char              *csName = NULL,
        const char              *lang = NULL);
>>>>>>> miniblink49

    /**
    * Return the name of the charset for this Match
    */
<<<<<<< HEAD
    const char* getName() const;

    const char* getLanguage() const;

    int32_t getConfidence() const;

    int32_t getUChars(UChar* buf, int32_t cap, UErrorCode* status) const;
=======
    const char *getName() const;

    const char *getLanguage()const;

    int32_t getConfidence()const;

    int32_t getUChars(UChar *buf, int32_t cap, UErrorCode *status) const;
>>>>>>> miniblink49
};

class CharsetRecognizer {
public:
<<<<<<< HEAD
    virtual const char* getName() const = 0;

    virtual const char* getLanguage() const { return ""; }

    virtual UBool match(InputText* textIn, CharsetMatch* results) const = 0;

    virtual ~CharsetRecognizer() { }
=======

    virtual const char *getName() const = 0;

    virtual const char *getLanguage() const { return ""; }

    virtual UBool match(InputText *textIn, CharsetMatch *results) const = 0;

    virtual ~CharsetRecognizer() {}
>>>>>>> miniblink49
};

class CharsetRecog_UTF8 : public CharsetRecognizer {

public:
<<<<<<< HEAD
    virtual ~CharsetRecog_UTF8();

    const char* getName() const;
=======

    virtual ~CharsetRecog_UTF8();

    const char *getName() const;
>>>>>>> miniblink49

    /* (non-Javadoc)
    * @see com.ibm.icu.text.CharsetRecognizer#match(com.ibm.icu.text.CharsetDetector)
    */
<<<<<<< HEAD
    UBool match(InputText* input, CharsetMatch* results) const;
=======
    UBool match(InputText *input, CharsetMatch *results) const;
>>>>>>> miniblink49
};

class CharsetDetector {
private:
<<<<<<< HEAD
    InputText* textIn;
    CharsetMatch** resultArray;
    int32_t resultCount;
    UBool fStripTags; // If true, setText() will strip tags from input text.
    UBool fFreshTextSet;
    static void setRecognizers(UErrorCode& status);

    UBool* fEnabledRecognizers; // If not null, active set of charset recognizers had
=======
    InputText *textIn;
    CharsetMatch **resultArray;
    int32_t resultCount;
    UBool fStripTags;   // If true, setText() will strip tags from input text.
    UBool fFreshTextSet;
    static void setRecognizers(UErrorCode &status);

    UBool *fEnabledRecognizers;  // If not null, active set of charset recognizers had
>>>>>>> miniblink49
    // been changed from the default. The array index is
    // corresponding to fCSRecognizers. See setDetectableCharset().

public:
<<<<<<< HEAD
    CharsetDetector(UErrorCode& status);

    ~CharsetDetector();

    void setText(const char* in, int32_t len);

    const CharsetMatch* const* detectAll(int32_t& maxMatchesFound, UErrorCode& status);

    const CharsetMatch* detect(UErrorCode& status);
=======
    CharsetDetector(UErrorCode &status);

    ~CharsetDetector();

    void setText(const char *in, int32_t len);

    const CharsetMatch * const *detectAll(int32_t &maxMatchesFound, UErrorCode &status);

    const CharsetMatch *detect(UErrorCode& status);
>>>>>>> miniblink49
};

//////////////////////////////////////////////////////////////////////////
struct CSRecognizerInfo {
<<<<<<< HEAD
    CSRecognizerInfo(CharsetRecognizer* recognizer, UBool isDefaultEnabled)
        : recognizer(recognizer)
        , isDefaultEnabled(isDefaultEnabled) {};

    ~CSRecognizerInfo() { delete recognizer; };

    CharsetRecognizer* recognizer;
=======
    CSRecognizerInfo(CharsetRecognizer *recognizer, UBool isDefaultEnabled)
        : recognizer(recognizer), isDefaultEnabled(isDefaultEnabled) {};

    ~CSRecognizerInfo() { delete recognizer; };

    CharsetRecognizer *recognizer;
>>>>>>> miniblink49
    UBool isDefaultEnabled;
};