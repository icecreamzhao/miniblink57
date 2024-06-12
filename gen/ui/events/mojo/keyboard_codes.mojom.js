// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("ui/events/mojo/keyboard_codes.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var KeyboardCode = {};
  KeyboardCode.BACK = 0x08;
  KeyboardCode.TAB = 0x09;
  KeyboardCode.CLEAR = 0x0C;
  KeyboardCode.RETURN = 0x0D;
  KeyboardCode.SHIFT = 0x10;
  KeyboardCode.CONTROL = 0x11;
  KeyboardCode.MENU = 0x12;
  KeyboardCode.PAUSE = 0x13;
  KeyboardCode.CAPITAL = 0x14;
  KeyboardCode.KANA = 0x15;
  KeyboardCode.HANGUL = 0x15;
  KeyboardCode.JUNJA = 0x17;
  KeyboardCode.FINAL = 0x18;
  KeyboardCode.HANJA = 0x19;
  KeyboardCode.KANJI = 0x19;
  KeyboardCode.ESCAPE = 0x1B;
  KeyboardCode.CONVERT = 0x1C;
  KeyboardCode.NONCONVERT = 0x1D;
  KeyboardCode.ACCEPT = 0x1E;
  KeyboardCode.MODECHANGE = 0x1F;
  KeyboardCode.SPACE = 0x20;
  KeyboardCode.PRIOR = 0x21;
  KeyboardCode.NEXT = 0x22;
  KeyboardCode.END = 0x23;
  KeyboardCode.HOME = 0x24;
  KeyboardCode.LEFT = 0x25;
  KeyboardCode.UP = 0x26;
  KeyboardCode.RIGHT = 0x27;
  KeyboardCode.DOWN = 0x28;
  KeyboardCode.SELECT = 0x29;
  KeyboardCode.PRINT = 0x2A;
  KeyboardCode.EXECUTE = 0x2B;
  KeyboardCode.SNAPSHOT = 0x2C;
  KeyboardCode.INSERT = 0x2D;
  KeyboardCode.KEY_DELETE = 0x2E;
  KeyboardCode.HELP = 0x2F;
  KeyboardCode.NUM_0 = 0x30;
  KeyboardCode.NUM_1 = 0x31;
  KeyboardCode.NUM_2 = 0x32;
  KeyboardCode.NUM_3 = 0x33;
  KeyboardCode.NUM_4 = 0x34;
  KeyboardCode.NUM_5 = 0x35;
  KeyboardCode.NUM_6 = 0x36;
  KeyboardCode.NUM_7 = 0x37;
  KeyboardCode.NUM_8 = 0x38;
  KeyboardCode.NUM_9 = 0x39;
  KeyboardCode.A = 0x41;
  KeyboardCode.B = 0x42;
  KeyboardCode.C = 0x43;
  KeyboardCode.D = 0x44;
  KeyboardCode.E = 0x45;
  KeyboardCode.F = 0x46;
  KeyboardCode.G = 0x47;
  KeyboardCode.H = 0x48;
  KeyboardCode.I = 0x49;
  KeyboardCode.J = 0x4A;
  KeyboardCode.K = 0x4B;
  KeyboardCode.L = 0x4C;
  KeyboardCode.M = 0x4D;
  KeyboardCode.N = 0x4E;
  KeyboardCode.O = 0x4F;
  KeyboardCode.P = 0x50;
  KeyboardCode.Q = 0x51;
  KeyboardCode.R = 0x52;
  KeyboardCode.S = 0x53;
  KeyboardCode.T = 0x54;
  KeyboardCode.U = 0x55;
  KeyboardCode.V = 0x56;
  KeyboardCode.W = 0x57;
  KeyboardCode.X = 0x58;
  KeyboardCode.Y = 0x59;
  KeyboardCode.Z = 0x5A;
  KeyboardCode.LWIN = 0x5B;
  KeyboardCode.COMMAND = 0x5B;
  KeyboardCode.RWIN = 0x5C;
  KeyboardCode.APPS = 0x5D;
  KeyboardCode.SLEEP = 0x5F;
  KeyboardCode.NUMPAD0 = 0x60;
  KeyboardCode.NUMPAD1 = 0x61;
  KeyboardCode.NUMPAD2 = 0x62;
  KeyboardCode.NUMPAD3 = 0x63;
  KeyboardCode.NUMPAD4 = 0x64;
  KeyboardCode.NUMPAD5 = 0x65;
  KeyboardCode.NUMPAD6 = 0x66;
  KeyboardCode.NUMPAD7 = 0x67;
  KeyboardCode.NUMPAD8 = 0x68;
  KeyboardCode.NUMPAD9 = 0x69;
  KeyboardCode.MULTIPLY = 0x6A;
  KeyboardCode.ADD = 0x6B;
  KeyboardCode.SEPARATOR = 0x6C;
  KeyboardCode.SUBTRACT = 0x6D;
  KeyboardCode.DECIMAL = 0x6E;
  KeyboardCode.DIVIDE = 0x6F;
  KeyboardCode.F1 = 0x70;
  KeyboardCode.F2 = 0x71;
  KeyboardCode.F3 = 0x72;
  KeyboardCode.F4 = 0x73;
  KeyboardCode.F5 = 0x74;
  KeyboardCode.F6 = 0x75;
  KeyboardCode.F7 = 0x76;
  KeyboardCode.F8 = 0x77;
  KeyboardCode.F9 = 0x78;
  KeyboardCode.F10 = 0x79;
  KeyboardCode.F11 = 0x7A;
  KeyboardCode.F12 = 0x7B;
  KeyboardCode.F13 = 0x7C;
  KeyboardCode.F14 = 0x7D;
  KeyboardCode.F15 = 0x7E;
  KeyboardCode.F16 = 0x7F;
  KeyboardCode.F17 = 0x80;
  KeyboardCode.F18 = 0x81;
  KeyboardCode.F19 = 0x82;
  KeyboardCode.F20 = 0x83;
  KeyboardCode.F21 = 0x84;
  KeyboardCode.F22 = 0x85;
  KeyboardCode.F23 = 0x86;
  KeyboardCode.F24 = 0x87;
  KeyboardCode.NUMLOCK = 0x90;
  KeyboardCode.SCROLL = 0x91;
  KeyboardCode.LSHIFT = 0xA0;
  KeyboardCode.RSHIFT = 0xA1;
  KeyboardCode.LCONTROL = 0xA2;
  KeyboardCode.RCONTROL = 0xA3;
  KeyboardCode.LMENU = 0xA4;
  KeyboardCode.RMENU = 0xA5;
  KeyboardCode.BROWSER_BACK = 0xA6;
  KeyboardCode.BROWSER_FORWARD = 0xA7;
  KeyboardCode.BROWSER_REFRESH = 0xA8;
  KeyboardCode.BROWSER_STOP = 0xA9;
  KeyboardCode.BROWSER_SEARCH = 0xAA;
  KeyboardCode.BROWSER_FAVORITES = 0xAB;
  KeyboardCode.BROWSER_HOME = 0xAC;
  KeyboardCode.VOLUME_MUTE = 0xAD;
  KeyboardCode.VOLUME_DOWN = 0xAE;
  KeyboardCode.VOLUME_UP = 0xAF;
  KeyboardCode.MEDIA_NEXT_TRACK = 0xB0;
  KeyboardCode.MEDIA_PREV_TRACK = 0xB1;
  KeyboardCode.MEDIA_STOP = 0xB2;
  KeyboardCode.MEDIA_PLAY_PAUSE = 0xB3;
  KeyboardCode.MEDIA_LAUNCH_MAIL = 0xB4;
  KeyboardCode.MEDIA_LAUNCH_MEDIA_SELECT = 0xB5;
  KeyboardCode.MEDIA_LAUNCH_APP1 = 0xB6;
  KeyboardCode.MEDIA_LAUNCH_APP2 = 0xB7;
  KeyboardCode.OEM_1 = 0xBA;
  KeyboardCode.OEM_PLUS = 0xBB;
  KeyboardCode.OEM_COMMA = 0xBC;
  KeyboardCode.OEM_MINUS = 0xBD;
  KeyboardCode.OEM_PERIOD = 0xBE;
  KeyboardCode.OEM_2 = 0xBF;
  KeyboardCode.OEM_3 = 0xC0;
  KeyboardCode.OEM_4 = 0xDB;
  KeyboardCode.OEM_5 = 0xDC;
  KeyboardCode.OEM_6 = 0xDD;
  KeyboardCode.OEM_7 = 0xDE;
  KeyboardCode.OEM_8 = 0xDF;
  KeyboardCode.OEM_102 = 0xE2;
  KeyboardCode.PROCESSKEY = 0xE5;
  KeyboardCode.PACKET = 0xE7;
  KeyboardCode.DBE_SBCSCHAR = 0xF3;
  KeyboardCode.DBE_DBCSCHAR = 0xF4;
  KeyboardCode.ATTN = 0xF6;
  KeyboardCode.CRSEL = 0xF7;
  KeyboardCode.EXSEL = 0xF8;
  KeyboardCode.EREOF = 0xF9;
  KeyboardCode.PLAY = 0xFA;
  KeyboardCode.ZOOM = 0xFB;
  KeyboardCode.NONAME = 0xFC;
  KeyboardCode.PA1 = 0xFD;
  KeyboardCode.OEM_CLEAR = 0xFE;
  KeyboardCode.UNKNOWN = 0;
  KeyboardCode.ALTGR = 0xE1;

  KeyboardCode.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 8:
    case 9:
    case 12:
    case 13:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
    case 24:
    case 25:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
    case 144:
    case 145:
    case 160:
    case 161:
    case 162:
    case 163:
    case 164:
    case 165:
    case 166:
    case 167:
    case 168:
    case 169:
    case 170:
    case 171:
    case 172:
    case 173:
    case 174:
    case 175:
    case 176:
    case 177:
    case 178:
    case 179:
    case 180:
    case 181:
    case 182:
    case 183:
    case 186:
    case 187:
    case 188:
    case 189:
    case 190:
    case 191:
    case 192:
    case 219:
    case 220:
    case 221:
    case 222:
    case 223:
    case 225:
    case 226:
    case 229:
    case 231:
    case 243:
    case 244:
    case 246:
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
    case 252:
    case 253:
    case 254:
      return true;
    }
    return false;
  };

  KeyboardCode.validate = function(enumValue) {
    var isExtensible = true;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.KeyboardCode = KeyboardCode;

  return exports;
});