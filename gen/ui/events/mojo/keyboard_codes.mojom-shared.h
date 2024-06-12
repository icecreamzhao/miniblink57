// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_KEYBOARD_CODES_MOJOM_SHARED_H_
#define UI_EVENTS_MOJO_KEYBOARD_CODES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/events/mojo/keyboard_codes.mojom-shared-internal.h"

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {

    enum class KeyboardCode : int32_t {
        BACK = 0x08,
        TAB = 0x09,
        CLEAR = 0x0C,
        RETURN = 0x0D,
        SHIFT = 0x10,
        CONTROL = 0x11,
        MENU = 0x12,
        PAUSE = 0x13,
        CAPITAL = 0x14,
        KANA = 0x15,
        HANGUL = 0x15,
        JUNJA = 0x17,
        FINAL = 0x18,
        HANJA = 0x19,
        KANJI = 0x19,
        ESCAPE = 0x1B,
        CONVERT = 0x1C,
        NONCONVERT = 0x1D,
        ACCEPT = 0x1E,
        MODECHANGE = 0x1F,
        SPACE = 0x20,
        PRIOR = 0x21,
        NEXT = 0x22,
        END = 0x23,
        HOME = 0x24,
        LEFT = 0x25,
        UP = 0x26,
        RIGHT = 0x27,
        DOWN = 0x28,
        SELECT = 0x29,
        PRINT = 0x2A,
        EXECUTE = 0x2B,
        SNAPSHOT = 0x2C,
        INSERT = 0x2D,
        KEY_DELETE = 0x2E,
        HELP = 0x2F,
        NUM_0 = 0x30,
        NUM_1 = 0x31,
        NUM_2 = 0x32,
        NUM_3 = 0x33,
        NUM_4 = 0x34,
        NUM_5 = 0x35,
        NUM_6 = 0x36,
        NUM_7 = 0x37,
        NUM_8 = 0x38,
        NUM_9 = 0x39,
        A = 0x41,
        B = 0x42,
        C = 0x43,
        D = 0x44,
        E = 0x45,
        F = 0x46,
        G = 0x47,
        H = 0x48,
        I = 0x49,
        J = 0x4A,
        K = 0x4B,
        L = 0x4C,
        M = 0x4D,
        N = 0x4E,
        O = 0x4F,
        P = 0x50,
        Q = 0x51,
        R = 0x52,
        S = 0x53,
        T = 0x54,
        U = 0x55,
        V = 0x56,
        W = 0x57,
        X = 0x58,
        Y = 0x59,
        Z = 0x5A,
        LWIN = 0x5B,
        COMMAND = 0x5B,
        RWIN = 0x5C,
        APPS = 0x5D,
        SLEEP = 0x5F,
        NUMPAD0 = 0x60,
        NUMPAD1 = 0x61,
        NUMPAD2 = 0x62,
        NUMPAD3 = 0x63,
        NUMPAD4 = 0x64,
        NUMPAD5 = 0x65,
        NUMPAD6 = 0x66,
        NUMPAD7 = 0x67,
        NUMPAD8 = 0x68,
        NUMPAD9 = 0x69,
        MULTIPLY = 0x6A,
        ADD = 0x6B,
        SEPARATOR = 0x6C,
        SUBTRACT = 0x6D,
        DECIMAL = 0x6E,
        DIVIDE = 0x6F,
        F1 = 0x70,
        F2 = 0x71,
        F3 = 0x72,
        F4 = 0x73,
        F5 = 0x74,
        F6 = 0x75,
        F7 = 0x76,
        F8 = 0x77,
        F9 = 0x78,
        F10 = 0x79,
        F11 = 0x7A,
        F12 = 0x7B,
        F13 = 0x7C,
        F14 = 0x7D,
        F15 = 0x7E,
        F16 = 0x7F,
        F17 = 0x80,
        F18 = 0x81,
        F19 = 0x82,
        F20 = 0x83,
        F21 = 0x84,
        F22 = 0x85,
        F23 = 0x86,
        F24 = 0x87,
        NUMLOCK = 0x90,
        SCROLL = 0x91,
        LSHIFT = 0xA0,
        RSHIFT = 0xA1,
        LCONTROL = 0xA2,
        RCONTROL = 0xA3,
        LMENU = 0xA4,
        RMENU = 0xA5,
        BROWSER_BACK = 0xA6,
        BROWSER_FORWARD = 0xA7,
        BROWSER_REFRESH = 0xA8,
        BROWSER_STOP = 0xA9,
        BROWSER_SEARCH = 0xAA,
        BROWSER_FAVORITES = 0xAB,
        BROWSER_HOME = 0xAC,
        VOLUME_MUTE = 0xAD,
        VOLUME_DOWN = 0xAE,
        VOLUME_UP = 0xAF,
        MEDIA_NEXT_TRACK = 0xB0,
        MEDIA_PREV_TRACK = 0xB1,
        MEDIA_STOP = 0xB2,
        MEDIA_PLAY_PAUSE = 0xB3,
        MEDIA_LAUNCH_MAIL = 0xB4,
        MEDIA_LAUNCH_MEDIA_SELECT = 0xB5,
        MEDIA_LAUNCH_APP1 = 0xB6,
        MEDIA_LAUNCH_APP2 = 0xB7,
        OEM_1 = 0xBA,
        OEM_PLUS = 0xBB,
        OEM_COMMA = 0xBC,
        OEM_MINUS = 0xBD,
        OEM_PERIOD = 0xBE,
        OEM_2 = 0xBF,
        OEM_3 = 0xC0,
        OEM_4 = 0xDB,
        OEM_5 = 0xDC,
        OEM_6 = 0xDD,
        OEM_7 = 0xDE,
        OEM_8 = 0xDF,
        OEM_102 = 0xE2,
        PROCESSKEY = 0xE5,
        PACKET = 0xE7,
        DBE_SBCSCHAR = 0xF3,
        DBE_DBCSCHAR = 0xF4,
        ATTN = 0xF6,
        CRSEL = 0xF7,
        EXSEL = 0xF8,
        EREOF = 0xF9,
        PLAY = 0xFA,
        ZOOM = 0xFB,
        NONAME = 0xFC,
        PA1 = 0xFD,
        OEM_CLEAR = 0xFE,
        UNKNOWN = 0,
        ALTGR = 0xE1,
    };

    inline std::ostream& operator<<(std::ostream& os, KeyboardCode value)
    {
        switch (value) {
        case KeyboardCode::UNKNOWN:
            return os << "KeyboardCode::UNKNOWN";
        case KeyboardCode::BACK:
            return os << "KeyboardCode::BACK";
        case KeyboardCode::TAB:
            return os << "KeyboardCode::TAB";
        case KeyboardCode::CLEAR:
            return os << "KeyboardCode::CLEAR";
        case KeyboardCode::RETURN:
            return os << "KeyboardCode::RETURN";
        case KeyboardCode::SHIFT:
            return os << "KeyboardCode::SHIFT";
        case KeyboardCode::CONTROL:
            return os << "KeyboardCode::CONTROL";
        case KeyboardCode::MENU:
            return os << "KeyboardCode::MENU";
        case KeyboardCode::PAUSE:
            return os << "KeyboardCode::PAUSE";
        case KeyboardCode::CAPITAL:
            return os << "KeyboardCode::CAPITAL";
        case KeyboardCode::KANA:
            return os << "KeyboardCode::{KANA, HANGUL}";
        case KeyboardCode::JUNJA:
            return os << "KeyboardCode::JUNJA";
        case KeyboardCode::FINAL:
            return os << "KeyboardCode::FINAL";
        case KeyboardCode::HANJA:
            return os << "KeyboardCode::{HANJA, KANJI}";
        case KeyboardCode::ESCAPE:
            return os << "KeyboardCode::ESCAPE";
        case KeyboardCode::CONVERT:
            return os << "KeyboardCode::CONVERT";
        case KeyboardCode::NONCONVERT:
            return os << "KeyboardCode::NONCONVERT";
        case KeyboardCode::ACCEPT:
            return os << "KeyboardCode::ACCEPT";
        case KeyboardCode::MODECHANGE:
            return os << "KeyboardCode::MODECHANGE";
        case KeyboardCode::SPACE:
            return os << "KeyboardCode::SPACE";
        case KeyboardCode::PRIOR:
            return os << "KeyboardCode::PRIOR";
        case KeyboardCode::NEXT:
            return os << "KeyboardCode::NEXT";
        case KeyboardCode::END:
            return os << "KeyboardCode::END";
        case KeyboardCode::HOME:
            return os << "KeyboardCode::HOME";
        case KeyboardCode::LEFT:
            return os << "KeyboardCode::LEFT";
        case KeyboardCode::UP:
            return os << "KeyboardCode::UP";
        case KeyboardCode::RIGHT:
            return os << "KeyboardCode::RIGHT";
        case KeyboardCode::DOWN:
            return os << "KeyboardCode::DOWN";
        case KeyboardCode::SELECT:
            return os << "KeyboardCode::SELECT";
        case KeyboardCode::PRINT:
            return os << "KeyboardCode::PRINT";
        case KeyboardCode::EXECUTE:
            return os << "KeyboardCode::EXECUTE";
        case KeyboardCode::SNAPSHOT:
            return os << "KeyboardCode::SNAPSHOT";
        case KeyboardCode::INSERT:
            return os << "KeyboardCode::INSERT";
        case KeyboardCode::KEY_DELETE:
            return os << "KeyboardCode::KEY_DELETE";
        case KeyboardCode::HELP:
            return os << "KeyboardCode::HELP";
        case KeyboardCode::NUM_0:
            return os << "KeyboardCode::NUM_0";
        case KeyboardCode::NUM_1:
            return os << "KeyboardCode::NUM_1";
        case KeyboardCode::NUM_2:
            return os << "KeyboardCode::NUM_2";
        case KeyboardCode::NUM_3:
            return os << "KeyboardCode::NUM_3";
        case KeyboardCode::NUM_4:
            return os << "KeyboardCode::NUM_4";
        case KeyboardCode::NUM_5:
            return os << "KeyboardCode::NUM_5";
        case KeyboardCode::NUM_6:
            return os << "KeyboardCode::NUM_6";
        case KeyboardCode::NUM_7:
            return os << "KeyboardCode::NUM_7";
        case KeyboardCode::NUM_8:
            return os << "KeyboardCode::NUM_8";
        case KeyboardCode::NUM_9:
            return os << "KeyboardCode::NUM_9";
        case KeyboardCode::A:
            return os << "KeyboardCode::A";
        case KeyboardCode::B:
            return os << "KeyboardCode::B";
        case KeyboardCode::C:
            return os << "KeyboardCode::C";
        case KeyboardCode::D:
            return os << "KeyboardCode::D";
        case KeyboardCode::E:
            return os << "KeyboardCode::E";
        case KeyboardCode::F:
            return os << "KeyboardCode::F";
        case KeyboardCode::G:
            return os << "KeyboardCode::G";
        case KeyboardCode::H:
            return os << "KeyboardCode::H";
        case KeyboardCode::I:
            return os << "KeyboardCode::I";
        case KeyboardCode::J:
            return os << "KeyboardCode::J";
        case KeyboardCode::K:
            return os << "KeyboardCode::K";
        case KeyboardCode::L:
            return os << "KeyboardCode::L";
        case KeyboardCode::M:
            return os << "KeyboardCode::M";
        case KeyboardCode::N:
            return os << "KeyboardCode::N";
        case KeyboardCode::O:
            return os << "KeyboardCode::O";
        case KeyboardCode::P:
            return os << "KeyboardCode::P";
        case KeyboardCode::Q:
            return os << "KeyboardCode::Q";
        case KeyboardCode::R:
            return os << "KeyboardCode::R";
        case KeyboardCode::S:
            return os << "KeyboardCode::S";
        case KeyboardCode::T:
            return os << "KeyboardCode::T";
        case KeyboardCode::U:
            return os << "KeyboardCode::U";
        case KeyboardCode::V:
            return os << "KeyboardCode::V";
        case KeyboardCode::W:
            return os << "KeyboardCode::W";
        case KeyboardCode::X:
            return os << "KeyboardCode::X";
        case KeyboardCode::Y:
            return os << "KeyboardCode::Y";
        case KeyboardCode::Z:
            return os << "KeyboardCode::Z";
        case KeyboardCode::LWIN:
            return os << "KeyboardCode::{LWIN, COMMAND}";
        case KeyboardCode::RWIN:
            return os << "KeyboardCode::RWIN";
        case KeyboardCode::APPS:
            return os << "KeyboardCode::APPS";
        case KeyboardCode::SLEEP:
            return os << "KeyboardCode::SLEEP";
        case KeyboardCode::NUMPAD0:
            return os << "KeyboardCode::NUMPAD0";
        case KeyboardCode::NUMPAD1:
            return os << "KeyboardCode::NUMPAD1";
        case KeyboardCode::NUMPAD2:
            return os << "KeyboardCode::NUMPAD2";
        case KeyboardCode::NUMPAD3:
            return os << "KeyboardCode::NUMPAD3";
        case KeyboardCode::NUMPAD4:
            return os << "KeyboardCode::NUMPAD4";
        case KeyboardCode::NUMPAD5:
            return os << "KeyboardCode::NUMPAD5";
        case KeyboardCode::NUMPAD6:
            return os << "KeyboardCode::NUMPAD6";
        case KeyboardCode::NUMPAD7:
            return os << "KeyboardCode::NUMPAD7";
        case KeyboardCode::NUMPAD8:
            return os << "KeyboardCode::NUMPAD8";
        case KeyboardCode::NUMPAD9:
            return os << "KeyboardCode::NUMPAD9";
        case KeyboardCode::MULTIPLY:
            return os << "KeyboardCode::MULTIPLY";
        case KeyboardCode::ADD:
            return os << "KeyboardCode::ADD";
        case KeyboardCode::SEPARATOR:
            return os << "KeyboardCode::SEPARATOR";
        case KeyboardCode::SUBTRACT:
            return os << "KeyboardCode::SUBTRACT";
        case KeyboardCode::DECIMAL:
            return os << "KeyboardCode::DECIMAL";
        case KeyboardCode::DIVIDE:
            return os << "KeyboardCode::DIVIDE";
        case KeyboardCode::F1:
            return os << "KeyboardCode::F1";
        case KeyboardCode::F2:
            return os << "KeyboardCode::F2";
        case KeyboardCode::F3:
            return os << "KeyboardCode::F3";
        case KeyboardCode::F4:
            return os << "KeyboardCode::F4";
        case KeyboardCode::F5:
            return os << "KeyboardCode::F5";
        case KeyboardCode::F6:
            return os << "KeyboardCode::F6";
        case KeyboardCode::F7:
            return os << "KeyboardCode::F7";
        case KeyboardCode::F8:
            return os << "KeyboardCode::F8";
        case KeyboardCode::F9:
            return os << "KeyboardCode::F9";
        case KeyboardCode::F10:
            return os << "KeyboardCode::F10";
        case KeyboardCode::F11:
            return os << "KeyboardCode::F11";
        case KeyboardCode::F12:
            return os << "KeyboardCode::F12";
        case KeyboardCode::F13:
            return os << "KeyboardCode::F13";
        case KeyboardCode::F14:
            return os << "KeyboardCode::F14";
        case KeyboardCode::F15:
            return os << "KeyboardCode::F15";
        case KeyboardCode::F16:
            return os << "KeyboardCode::F16";
        case KeyboardCode::F17:
            return os << "KeyboardCode::F17";
        case KeyboardCode::F18:
            return os << "KeyboardCode::F18";
        case KeyboardCode::F19:
            return os << "KeyboardCode::F19";
        case KeyboardCode::F20:
            return os << "KeyboardCode::F20";
        case KeyboardCode::F21:
            return os << "KeyboardCode::F21";
        case KeyboardCode::F22:
            return os << "KeyboardCode::F22";
        case KeyboardCode::F23:
            return os << "KeyboardCode::F23";
        case KeyboardCode::F24:
            return os << "KeyboardCode::F24";
        case KeyboardCode::NUMLOCK:
            return os << "KeyboardCode::NUMLOCK";
        case KeyboardCode::SCROLL:
            return os << "KeyboardCode::SCROLL";
        case KeyboardCode::LSHIFT:
            return os << "KeyboardCode::LSHIFT";
        case KeyboardCode::RSHIFT:
            return os << "KeyboardCode::RSHIFT";
        case KeyboardCode::LCONTROL:
            return os << "KeyboardCode::LCONTROL";
        case KeyboardCode::RCONTROL:
            return os << "KeyboardCode::RCONTROL";
        case KeyboardCode::LMENU:
            return os << "KeyboardCode::LMENU";
        case KeyboardCode::RMENU:
            return os << "KeyboardCode::RMENU";
        case KeyboardCode::BROWSER_BACK:
            return os << "KeyboardCode::BROWSER_BACK";
        case KeyboardCode::BROWSER_FORWARD:
            return os << "KeyboardCode::BROWSER_FORWARD";
        case KeyboardCode::BROWSER_REFRESH:
            return os << "KeyboardCode::BROWSER_REFRESH";
        case KeyboardCode::BROWSER_STOP:
            return os << "KeyboardCode::BROWSER_STOP";
        case KeyboardCode::BROWSER_SEARCH:
            return os << "KeyboardCode::BROWSER_SEARCH";
        case KeyboardCode::BROWSER_FAVORITES:
            return os << "KeyboardCode::BROWSER_FAVORITES";
        case KeyboardCode::BROWSER_HOME:
            return os << "KeyboardCode::BROWSER_HOME";
        case KeyboardCode::VOLUME_MUTE:
            return os << "KeyboardCode::VOLUME_MUTE";
        case KeyboardCode::VOLUME_DOWN:
            return os << "KeyboardCode::VOLUME_DOWN";
        case KeyboardCode::VOLUME_UP:
            return os << "KeyboardCode::VOLUME_UP";
        case KeyboardCode::MEDIA_NEXT_TRACK:
            return os << "KeyboardCode::MEDIA_NEXT_TRACK";
        case KeyboardCode::MEDIA_PREV_TRACK:
            return os << "KeyboardCode::MEDIA_PREV_TRACK";
        case KeyboardCode::MEDIA_STOP:
            return os << "KeyboardCode::MEDIA_STOP";
        case KeyboardCode::MEDIA_PLAY_PAUSE:
            return os << "KeyboardCode::MEDIA_PLAY_PAUSE";
        case KeyboardCode::MEDIA_LAUNCH_MAIL:
            return os << "KeyboardCode::MEDIA_LAUNCH_MAIL";
        case KeyboardCode::MEDIA_LAUNCH_MEDIA_SELECT:
            return os << "KeyboardCode::MEDIA_LAUNCH_MEDIA_SELECT";
        case KeyboardCode::MEDIA_LAUNCH_APP1:
            return os << "KeyboardCode::MEDIA_LAUNCH_APP1";
        case KeyboardCode::MEDIA_LAUNCH_APP2:
            return os << "KeyboardCode::MEDIA_LAUNCH_APP2";
        case KeyboardCode::OEM_1:
            return os << "KeyboardCode::OEM_1";
        case KeyboardCode::OEM_PLUS:
            return os << "KeyboardCode::OEM_PLUS";
        case KeyboardCode::OEM_COMMA:
            return os << "KeyboardCode::OEM_COMMA";
        case KeyboardCode::OEM_MINUS:
            return os << "KeyboardCode::OEM_MINUS";
        case KeyboardCode::OEM_PERIOD:
            return os << "KeyboardCode::OEM_PERIOD";
        case KeyboardCode::OEM_2:
            return os << "KeyboardCode::OEM_2";
        case KeyboardCode::OEM_3:
            return os << "KeyboardCode::OEM_3";
        case KeyboardCode::OEM_4:
            return os << "KeyboardCode::OEM_4";
        case KeyboardCode::OEM_5:
            return os << "KeyboardCode::OEM_5";
        case KeyboardCode::OEM_6:
            return os << "KeyboardCode::OEM_6";
        case KeyboardCode::OEM_7:
            return os << "KeyboardCode::OEM_7";
        case KeyboardCode::OEM_8:
            return os << "KeyboardCode::OEM_8";
        case KeyboardCode::ALTGR:
            return os << "KeyboardCode::ALTGR";
        case KeyboardCode::OEM_102:
            return os << "KeyboardCode::OEM_102";
        case KeyboardCode::PROCESSKEY:
            return os << "KeyboardCode::PROCESSKEY";
        case KeyboardCode::PACKET:
            return os << "KeyboardCode::PACKET";
        case KeyboardCode::DBE_SBCSCHAR:
            return os << "KeyboardCode::DBE_SBCSCHAR";
        case KeyboardCode::DBE_DBCSCHAR:
            return os << "KeyboardCode::DBE_DBCSCHAR";
        case KeyboardCode::ATTN:
            return os << "KeyboardCode::ATTN";
        case KeyboardCode::CRSEL:
            return os << "KeyboardCode::CRSEL";
        case KeyboardCode::EXSEL:
            return os << "KeyboardCode::EXSEL";
        case KeyboardCode::EREOF:
            return os << "KeyboardCode::EREOF";
        case KeyboardCode::PLAY:
            return os << "KeyboardCode::PLAY";
        case KeyboardCode::ZOOM:
            return os << "KeyboardCode::ZOOM";
        case KeyboardCode::NONAME:
            return os << "KeyboardCode::NONAME";
        case KeyboardCode::PA1:
            return os << "KeyboardCode::PA1";
        case KeyboardCode::OEM_CLEAR:
            return os << "KeyboardCode::OEM_CLEAR";
        default:
            return os << "Unknown KeyboardCode value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(KeyboardCode value)
    {
        return internal::KeyboardCode_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::KeyboardCode>
    : public mojo::internal::EnumHashImpl<::ui::mojom::KeyboardCode> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::KeyboardCode, ::ui::mojom::KeyboardCode> {
    static ::ui::mojom::KeyboardCode ToMojom(::ui::mojom::KeyboardCode input) { return input; }
    static bool FromMojom(::ui::mojom::KeyboardCode input, ::ui::mojom::KeyboardCode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::KeyboardCode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::KeyboardCode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::KeyboardCode>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

#endif // UI_EVENTS_MOJO_KEYBOARD_CODES_MOJOM_SHARED_H_
