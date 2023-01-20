#include "Resources.h"
#include "gm.h"

<<<<<<< HEAD
DEF_SIMPLE_GM(small_image, canvas, 8, 8)
{
=======
DEF_SIMPLE_GM(small_image, canvas, 8, 8) {
>>>>>>> miniblink49
    SkBitmap bitmap;
    if (GetResourceAsBitmap("randPixels.png", &bitmap)) {
        canvas->drawBitmap(bitmap, 0.0f, 0.0f);
    } else {
        SkDebugf("\nCould not decode resource.\n");
    }
}
