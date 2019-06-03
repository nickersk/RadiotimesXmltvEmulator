#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Credit: http://bryars.eu/projects/tv_grab_dvb/ */
static const char codeset[6][256][10] = {
	[0] = {	/* Character code table 00 - Latin alphabet - ISO 6937 {{{ */
		[0x20] = " ",
		[0x21] = "!",
		[0x22] = "&quot;",
		[0x23] = "#",
		[0x24] = "$",
		[0x25] = "%",
		[0x26] = "&amp;",
		[0x27] = "'",
		[0x28] = "(",
		[0x29] = ")",
		[0x2A] = "*",
		[0x2B] = "+",
		[0x2C] = ",",
		[0x2D] = "-",
		[0x2E] = ".",
		[0x2F] = "/",
		[0x30] = "0",
		[0x31] = "1",
		[0x32] = "2",
		[0x33] = "3",
		[0x34] = "4",
		[0x35] = "5",
		[0x36] = "6",
		[0x37] = "7",
		[0x38] = "8",
		[0x39] = "9",
		[0x3A] = ":",
		[0x3B] = ";",
		[0x3C] = "&lt;",
		[0x3D] = "=",
		[0x3E] = "&gt;",
		[0x3F] = "?",
		[0x40] = "@",
		[0x41] = "A",
		[0x42] = "B",
		[0x43] = "C",
		[0x44] = "D",
		[0x45] = "E",
		[0x46] = "F",
		[0x47] = "G",
		[0x48] = "H",
		[0x49] = "I",
		[0x4A] = "J",
		[0x4B] = "K",
		[0x4C] = "L",
		[0x4D] = "M",
		[0x4E] = "N",
		[0x4F] = "O",
		[0x50] = "P",
		[0x51] = "Q",
		[0x52] = "R",
		[0x53] = "S",
		[0x54] = "T",
		[0x55] = "U",
		[0x56] = "V",
		[0x57] = "W",
		[0x58] = "X",
		[0x59] = "Y",
		[0x5A] = "Z",
		[0x5B] = "[",
		[0x5C] = "\\",
		[0x5D] = "]",
		[0x5E] = "^",
		[0x5F] = "_",
		[0x60] = "`",
		[0x61] = "a",
		[0x62] = "b",
		[0x63] = "c",
		[0x64] = "d",
		[0x65] = "e",
		[0x66] = "f",
		[0x67] = "g",
		[0x68] = "h",
		[0x69] = "i",
		[0x6A] = "j",
		[0x6B] = "k",
		[0x6C] = "l",
		[0x6D] = "m",
		[0x6E] = "n",
		[0x6F] = "o",
		[0x70] = "p",
		[0x71] = "q",
		[0x72] = "r",
		[0x73] = "s",
		[0x74] = "t",
		[0x75] = "u",
		[0x76] = "v",
		[0x77] = "w",
		[0x78] = "x",
		[0x79] = "y",
		[0x7A] = "z",
		[0x7B] = "{",
		[0x7C] = "|",
		[0x7D] = "}",
		[0x7E] = "~",
		[0xA0] = "&#x00A0;", // NO-BREAK SPACE,
		[0xA1] = "&#x00A1;", // INVERTED EXCLAMATION MARK,
		[0xA2] = "&#x00A2;", // CENT SIGN,
		[0xA3] = "&#x00A3;", // POUND SIGN,
		[0xA4] = "&#x0024;", // DOLLAR SIGN,
		[0xA5] = "&#x00A5;", // YEN SIGN,
		[0xA7] = "&#x00A7;", // SECTION SIGN,
		[0xA9] = "&#x2018;", // LEFT SINGLE QUOTATION MARK,
		[0xAA] = "&#x201C;", // LEFT DOUBLE QUOTATION MARK,
		[0xAB] = "&#x00AB;", // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK,
		[0xAC] = "&#x2190;", // LEFTWARDS ARROW,
		[0xAD] = "&#x2191;", // UPWARDS ARROW,
		[0xAE] = "&#x2192;", // RIGHTWARDS ARROW,
		[0xAF] = "&#x2193;", // DOWNWARDS ARROW,
		[0xB0] = "&#x00B0;", // DEGREE SIGN,
		[0xB1] = "&#x00B1;", // PLUS-MINUS SIGN,
		[0xB2] = "&#x00B2;", // SUPERSCRIPT TWO,
		[0xB3] = "&#x00B3;", // SUPERSCRIPT THREE,
		[0xB4] = "&#x00D7;", // MULTIPLICATION SIGN,
		[0xB5] = "&#x00B5;", // MICRO SIGN,
		[0xB6] = "&#x00B6;", // PILCROW SIGN,
		[0xB7] = "&#x00B7;", // MIDDLE DOT,
		[0xB8] = "&#x00F7;", // DIVISION SIGN,
		[0xB9] = "&#x2019;", // RIGHT SINGLE QUOTATION MARK,
		[0xBa] = "&#x201D;", // RIGHT DOUBLE QUOTATION MARK,
		[0xBb] = "&#x00BB;", // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK,
		[0xBc] = "&#x00BC;", // VULGAR FRACTION ONE QUARTER,
		[0xBd] = "&#x00BD;", // VULGAR FRACTION ONE HALF,
		[0xBe] = "&#x00BE;", // VULGAR FRACTION THREE QUARTERS,
		[0xBf] = "&#x00BF;", // INVERTED QUESTION MARK,
		[0xC1] = "&#xE002;", // NON-SPACING GRAVE ACCENT <ISO-IR-103_C1>
		[0xC2] = "&#xE003;", // NON-SPACING ACUTE ACCENT <ISO-IR-103_C2>
		[0xC3] = "&#xE004;", // NON-SPACING CIRCUMFLEX ACCENT <ISO-IR-103_C3>
		[0xC4] = "&#xE005;", // NON-SPACING TILDE <ISO-IR-103_C4>
		[0xC5] = "&#xE006;", // NON-SPACING MACRON <ISO-IR-103_C5>
		[0xC6] = "&#xE007;", // NON-SPACING BREVE <ISO-IR-103_C6>
		[0xC7] = "&#xE008;", // NON-SPACING DOT ABOVE <ISO-IR-103_C7>
		[0xC8] = "&#xE009;", // NON-SPACING DIAERESIS <ISO-IR-103_C8>
		[0xCA] = "&#xE00A;", // NON-SPACING RING ABOVE <ISO-IR-103_CA>
		[0xCB] = "&#xE00B;", // NON-SPACING CEDILLA <ISO-IR-103_CB>
		[0xCD] = "&#xE00D;", // NON-SPACING DOUBLE ACCUTE ACCENT <ISO-IR-103_CD>
		[0xCE] = "&#xE00E;", // NON-SPACING OGONEK <ISO-IR-103_CE>
		[0xCF] = "&#xE00F;", // NON-SPACING CARON <ISO-IR-103_CF>
		[0xD0] = "&#x2014;", // EM DASH,
		[0xD1] = "&#x00B9;", // SUPERSCRIPT ONE,
		[0xD2] = "&#x00AE;", // REGISTERED SIGN,
		[0xD3] = "&#x00A9;", // COPYRIGHT SIGN,
		[0xD4] = "&#x2122;", // TRADE MARK SIGN,
		[0xD5] = "&#x266A;", // EIGHTH NOTE,
		[0xD6] = "&#x00AC;", // NOT SIGN,
		[0xD7] = "&#x00A6;", // BROKEN BAR,
		[0xDC] = "&#x215B;", // VULGAR FRACTION ONE EIGHTH,
		[0xDD] = "&#x215C;", // VULGAR FRACTION THREE EIGHTHS,
		[0xDE] = "&#x215D;", // VULGAR FRACTION FIVE EIGHTHS,
		[0xDF] = "&#x215E;", // VULGAR FRACTION SEVEN EIGHTHS,
		[0xE0] = "&#x2126;", // OHM SIGN,
		[0xE1] = "&#x00C6;", // LATIN CAPITAL LETTER AE,
		[0xE2] = "&#x00D0;", // LATIN CAPITAL LETTER ETH (Icelandic),
		[0xE3] = "&#x00AA;", // FEMININE ORDINAL INDICATOR,
		[0xE4] = "&#x0126;", // LATIN CAPITAL LETTER H WITH STROKE,
		[0xE6] = "&#x0132;", // LATIN CAPITAL LIGATURE IJ,
		[0xE7] = "&#x013F;", // LATIN CAPITAL LETTER L WITH MIDDLE DOT,
		[0xE8] = "&#x0141;", // LATIN CAPITAL LETTER L WITH STROKE,
		[0xE9] = "&#x00D8;", // LATIN CAPITAL LETTER O WITH STROKE,
		[0xEA] = "&#x0152;", // LATIN CAPITAL LIGATURE OE,
		[0xEB] = "&#x00BA;", // MASCULINE ORDINAL INDICATOR,
		[0xEC] = "&#x00DE;", // LATIN CAPITAL LETTER THORN (Icelandic),
		[0xED] = "&#x0166;", // LATIN CAPITAL LETTER T WITH STROKE,
		[0xEE] = "&#x014A;", // LATIN CAPITAL LETTER ENG (Sami),
		[0xEF] = "&#x0149;", // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE,
		[0xF0] = "&#x0138;", // LATIN SMALL LETTER KRA (Greenlandic),
		[0xF1] = "&#x00E6;", // LATIN SMALL LETTER AE,
		[0xF2] = "&#x0111;", // LATIN SMALL LETTER D WITH STROKE,
		[0xF3] = "&#x00F0;", // LATIN SMALL LETTER ETH (Icelandic),
		[0xF4] = "&#x0127;", // LATIN SMALL LETTER H WITH STROKE,
		[0xF5] = "&#x0131;", // LATIN SMALL LETTER DOTLESS I,
		[0xF6] = "&#x0133;", // LATIN SMALL LIGATURE IJ,
		[0xF7] = "&#x0140;", // LATIN SMALL LETTER L WITH MIDDLE DOT,
		[0xF8] = "&#x0142;", // LATIN SMALL LETTER L WITH STROKE,
		[0xF9] = "&#x00F8;", // LATIN SMALL LETTER O WITH STROKE,
		[0xFA] = "&#x0153;", // LATIN SMALL LIGATURE OE,
		[0xFB] = "&#x00DF;", // LATIN SMALL LETTER SHARP S (German),
		[0xFC] = "&#x00FE;", // LATIN SMALL LETTER THORN (Icelandic),
		[0xFD] = "&#x0167;", // LATIN SMALL LETTER T WITH STROKE,
		[0xFE] = "&#x014B;", // LATIN SMALL LETTER ENG (Sami),
		[0xFF] = "&#x00AD;", // SOFT HYPHEN,
	}, /* }}} */
	[1] = { /* Character code table 01 - Latin/Cyrillic alphabet - ISO 8859-5 {{{ */
		[0x20] = " ",
		[0x21] = "!",
		[0x22] = "&quot;",
		[0x23] = "#",
		[0x24] = "$",
		[0x25] = "%",
		[0x26] = "&amp;",
		[0x27] = "'",
		[0x28] = "(",
		[0x29] = ")",
		[0x2A] = "*",
		[0x2B] = "+",
		[0x2C] = ",",
		[0x2D] = "-",
		[0x2E] = ".",
		[0x2F] = "/",
		[0x30] = "0",
		[0x31] = "1",
		[0x32] = "2",
		[0x33] = "3",
		[0x34] = "4",
		[0x35] = "5",
		[0x36] = "6",
		[0x37] = "7",
		[0x38] = "8",
		[0x39] = "9",
		[0x3A] = ":",
		[0x3B] = ";",
		[0x3C] = "&lt;",
		[0x3D] = "=",
		[0x3E] = "&gt;",
		[0x3F] = "?",
		[0x40] = "@",
		[0x41] = "A",
		[0x42] = "B",
		[0x43] = "C",
		[0x44] = "D",
		[0x45] = "E",
		[0x46] = "F",
		[0x47] = "G",
		[0x48] = "H",
		[0x49] = "I",
		[0x4A] = "J",
		[0x4B] = "K",
		[0x4C] = "L",
		[0x4D] = "M",
		[0x4E] = "N",
		[0x4F] = "O",
		[0x50] = "P",
		[0x51] = "Q",
		[0x52] = "R",
		[0x53] = "S",
		[0x54] = "T",
		[0x55] = "U",
		[0x56] = "V",
		[0x57] = "W",
		[0x58] = "X",
		[0x59] = "Y",
		[0x5A] = "Z",
		[0x5B] = "[",
		[0x5C] = "\\",
		[0x5D] = "]",
		[0x5E] = "^",
		[0x5F] = "_",
		[0x60] = "`",
		[0x61] = "a",
		[0x62] = "b",
		[0x63] = "c",
		[0x64] = "d",
		[0x65] = "e",
		[0x66] = "f",
		[0x67] = "g",
		[0x68] = "h",
		[0x69] = "i",
		[0x6A] = "j",
		[0x6B] = "k",
		[0x6C] = "l",
		[0x6D] = "m",
		[0x6E] = "n",
		[0x6F] = "o",
		[0x70] = "p",
		[0x71] = "q",
		[0x72] = "r",
		[0x73] = "s",
		[0x74] = "t",
		[0x75] = "u",
		[0x76] = "v",
		[0x77] = "w",
		[0x78] = "x",
		[0x79] = "y",
		[0x7A] = "z",
		[0x7B] = "{",
		[0x7C] = "|",
		[0x7D] = "}",
		[0x7E] = "~",
		[0xA0] = "&#x00A0;", // NO-BREAK SPACE
		[0xA1] = "&#x0401;", // CYRILLIC CAPITAL LETTER IO
		[0xA2] = "&#x0402;", // CYRILLIC CAPITAL LETTER DJE
		[0xA3] = "&#x0403;", // CYRILLIC CAPITAL LETTER GJE
		[0xA4] = "&#x0404;", // CYRILLIC CAPITAL LETTER UKRAINIAN IE
		[0xA5] = "&#x0405;", // CYRILLIC CAPITAL LETTER DZE
		[0xA6] = "&#x0406;", // CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I
		[0xA7] = "&#x0407;", // CYRILLIC CAPITAL LETTER YI
		[0xA8] = "&#x0408;", // CYRILLIC CAPITAL LETTER JE
		[0xA9] = "&#x0409;", // CYRILLIC CAPITAL LETTER LJE
		[0xAA] = "&#x040A;", // CYRILLIC CAPITAL LETTER NJE
		[0xAB] = "&#x040B;", // CYRILLIC CAPITAL LETTER TSHE
		[0xAC] = "&#x040C;", // CYRILLIC CAPITAL LETTER KJE
		[0xAD] = "&#x00AD;", // SOFT HYPHEN
		[0xAE] = "&#x040E;", // CYRILLIC CAPITAL LETTER SHORT U
		[0xAF] = "&#x040F;", // CYRILLIC CAPITAL LETTER DZHE
		[0xB0] = "&#x0410;", // CYRILLIC CAPITAL LETTER A
		[0xB1] = "&#x0411;", // CYRILLIC CAPITAL LETTER BE
		[0xB2] = "&#x0412;", // CYRILLIC CAPITAL LETTER VE
		[0xB3] = "&#x0413;", // CYRILLIC CAPITAL LETTER GHE
		[0xB4] = "&#x0414;", // CYRILLIC CAPITAL LETTER DE
		[0xB5] = "&#x0415;", // CYRILLIC CAPITAL LETTER IE
		[0xB6] = "&#x0416;", // CYRILLIC CAPITAL LETTER ZHE
		[0xB7] = "&#x0417;", // CYRILLIC CAPITAL LETTER ZE
		[0xB8] = "&#x0418;", // CYRILLIC CAPITAL LETTER I
		[0xB9] = "&#x0419;", // CYRILLIC CAPITAL LETTER SHORT I
		[0xBA] = "&#x041A;", // CYRILLIC CAPITAL LETTER KA
		[0xBB] = "&#x041B;", // CYRILLIC CAPITAL LETTER EL
		[0xBC] = "&#x041C;", // CYRILLIC CAPITAL LETTER EM
		[0xBD] = "&#x041D;", // CYRILLIC CAPITAL LETTER EN
		[0xBE] = "&#x041E;", // CYRILLIC CAPITAL LETTER O
		[0xBF] = "&#x041F;", // CYRILLIC CAPITAL LETTER PE
		[0xC0] = "&#x0420;", // CYRILLIC CAPITAL LETTER ER
		[0xC1] = "&#x0421;", // CYRILLIC CAPITAL LETTER ES
		[0xC2] = "&#x0422;", // CYRILLIC CAPITAL LETTER TE
		[0xC3] = "&#x0423;", // CYRILLIC CAPITAL LETTER U
		[0xC4] = "&#x0424;", // CYRILLIC CAPITAL LETTER EF
		[0xC5] = "&#x0425;", // CYRILLIC CAPITAL LETTER HA
		[0xC6] = "&#x0426;", // CYRILLIC CAPITAL LETTER TSE
		[0xC7] = "&#x0427;", // CYRILLIC CAPITAL LETTER CHE
		[0xC8] = "&#x0428;", // CYRILLIC CAPITAL LETTER SHA
		[0xC9] = "&#x0429;", // CYRILLIC CAPITAL LETTER SHCHA
		[0xCA] = "&#x042A;", // CYRILLIC CAPITAL LETTER HARD SIGN
		[0xCB] = "&#x042B;", // CYRILLIC CAPITAL LETTER YERU
		[0xCC] = "&#x042C;", // CYRILLIC CAPITAL LETTER SOFT SIGN
		[0xCD] = "&#x042D;", // CYRILLIC CAPITAL LETTER E
		[0xCE] = "&#x042E;", // CYRILLIC CAPITAL LETTER YU
		[0xCF] = "&#x042F;", // CYRILLIC CAPITAL LETTER YA
		[0xD0] = "&#x0430;", // CYRILLIC SMALL LETTER A
		[0xD1] = "&#x0431;", // CYRILLIC SMALL LETTER BE
		[0xD2] = "&#x0432;", // CYRILLIC SMALL LETTER VE
		[0xD3] = "&#x0433;", // CYRILLIC SMALL LETTER GHE
		[0xD4] = "&#x0434;", // CYRILLIC SMALL LETTER DE
		[0xD5] = "&#x0435;", // CYRILLIC SMALL LETTER IE
		[0xD6] = "&#x0436;", // CYRILLIC SMALL LETTER ZHE
		[0xD7] = "&#x0437;", // CYRILLIC SMALL LETTER ZE
		[0xD8] = "&#x0438;", // CYRILLIC SMALL LETTER I
		[0xD9] = "&#x0439;", // CYRILLIC SMALL LETTER SHORT I
		[0xDA] = "&#x043A;", // CYRILLIC SMALL LETTER KA
		[0xDB] = "&#x043B;", // CYRILLIC SMALL LETTER EL
		[0xDC] = "&#x043C;", // CYRILLIC SMALL LETTER EM
		[0xDD] = "&#x043D;", // CYRILLIC SMALL LETTER EN
		[0xDE] = "&#x043E;", // CYRILLIC SMALL LETTER O
		[0xDF] = "&#x043F;", // CYRILLIC SMALL LETTER PE
		[0xE0] = "&#x0440;", // CYRILLIC SMALL LETTER ER
		[0xE1] = "&#x0441;", // CYRILLIC SMALL LETTER ES
		[0xE2] = "&#x0442;", // CYRILLIC SMALL LETTER TE
		[0xE3] = "&#x0443;", // CYRILLIC SMALL LETTER U
		[0xE4] = "&#x0444;", // CYRILLIC SMALL LETTER EF
		[0xE5] = "&#x0445;", // CYRILLIC SMALL LETTER HA
		[0xE6] = "&#x0446;", // CYRILLIC SMALL LETTER TSE
		[0xE7] = "&#x0447;", // CYRILLIC SMALL LETTER CHE
		[0xE8] = "&#x0448;", // CYRILLIC SMALL LETTER SHA
		[0xE9] = "&#x0449;", // CYRILLIC SMALL LETTER SHCHA
		[0xEA] = "&#x044A;", // CYRILLIC SMALL LETTER HARD SIGN
		[0xEB] = "&#x044B;", // CYRILLIC SMALL LETTER YERU
		[0xEC] = "&#x044C;", // CYRILLIC SMALL LETTER SOFT SIGN
		[0xED] = "&#x044D;", // CYRILLIC SMALL LETTER E
		[0xEE] = "&#x044E;", // CYRILLIC SMALL LETTER YU
		[0xEF] = "&#x044F;", // CYRILLIC SMALL LETTER YA
		[0xF0] = "&#x2116;", // NUMERO SIGN
		[0xF1] = "&#x0451;", // CYRILLIC SMALL LETTER IO
		[0xF2] = "&#x0452;", // CYRILLIC SMALL LETTER DJE
		[0xF3] = "&#x0453;", // CYRILLIC SMALL LETTER GJE
		[0xF4] = "&#x0454;", // CYRILLIC SMALL LETTER UKRAINIAN IE
		[0xF5] = "&#x0455;", // CYRILLIC SMALL LETTER DZE
		[0xF6] = "&#x0456;", // CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I
		[0xF7] = "&#x0457;", // CYRILLIC SMALL LETTER YI
		[0xF8] = "&#x0458;", // CYRILLIC SMALL LETTER JE
		[0xF9] = "&#x0459;", // CYRILLIC SMALL LETTER LJE
		[0xFA] = "&#x045A;", // CYRILLIC SMALL LETTER NJE
		[0xFB] = "&#x045B;", // CYRILLIC SMALL LETTER TSHE
		[0xFC] = "&#x045C;", // CYRILLIC SMALL LETTER KJE
		[0xFD] = "&#x00A7;", // SECTION SIGN
		[0xFE] = "&#x045E;", // CYRILLIC SMALL LETTER SHORT U
		[0xFF] = "&#x045F;", // CYRILLIC SMALL LETTER DZHE
	}, /* }}} */
	[2] = { /* Character code table 02 - Latin/Arabic alphabet - ISO 8859-6  {{{*/
		[0x20] = " ",
		[0x21] = "!",
		[0x22] = "&quot;",
		[0x23] = "#",
		[0x24] = "$",
		[0x25] = "%",
		[0x26] = "&amp;",
		[0x27] = "'",
		[0x28] = "(",
		[0x29] = ")",
		[0x2A] = "*",
		[0x2B] = "+",
		[0x2C] = ",",
		[0x2D] = "-",
		[0x2E] = ".",
		[0x2F] = "/",
		[0x30] = "&#x0660;", // ARABIC DIGIT ZERO
		[0x31] = "&#x0661;", // ARABIC DIGIT ONE
		[0x32] = "&#x0662;", // ARABIC DIGIT TWO
		[0x33] = "&#x0663;", // ARABIC DIGIT THREE
		[0x34] = "&#x0664;", // ARABIC DIGIT FOUR
		[0x35] = "&#x0665;", // ARABIC DIGIT FIVE
		[0x36] = "&#x0666;", // ARABIC DIGIT SIX
		[0x37] = "&#x0667;", // ARABIC DIGIT SEVEN
		[0x38] = "&#x0668;", // ARABIC DIGIT EIGHT
		[0x39] = "&#x0669;", // ARABIC DIGIT NINE
		[0x3A] = ":",
		[0x3B] = ";",
		[0x3C] = "&lt;",
		[0x3D] = "=",
		[0x3E] = "&gt;",
		[0x3F] = "?",
		[0x40] = "@",
		[0x41] = "A",
		[0x42] = "B",
		[0x43] = "C",
		[0x44] = "D",
		[0x45] = "E",
		[0x46] = "F",
		[0x47] = "G",
		[0x48] = "H",
		[0x49] = "I",
		[0x4A] = "J",
		[0x4B] = "K",
		[0x4C] = "L",
		[0x4D] = "M",
		[0x4E] = "N",
		[0x4F] = "O",
		[0x50] = "P",
		[0x51] = "Q",
		[0x52] = "R",
		[0x53] = "S",
		[0x54] = "T",
		[0x55] = "U",
		[0x56] = "V",
		[0x57] = "W",
		[0x58] = "X",
		[0x59] = "Y",
		[0x5A] = "Z",
		[0x5B] = "[",
		[0x5C] = "\\",
		[0x5D] = "]",
		[0x5E] = "^",
		[0x5F] = "_",
		[0x60] = "`",
		[0x61] = "a",
		[0x62] = "b",
		[0x63] = "c",
		[0x64] = "d",
		[0x65] = "e",
		[0x66] = "f",
		[0x67] = "g",
		[0x68] = "h",
		[0x69] = "i",
		[0x6A] = "j",
		[0x6B] = "k",
		[0x6C] = "l",
		[0x6D] = "m",
		[0x6E] = "n",
		[0x6F] = "o",
		[0x70] = "p",
		[0x71] = "q",
		[0x72] = "r",
		[0x73] = "s",
		[0x74] = "t",
		[0x75] = "u",
		[0x76] = "v",
		[0x77] = "w",
		[0x78] = "x",
		[0x79] = "y",
		[0x7A] = "z",
		[0x7B] = "{",
		[0x7C] = "|",
		[0x7D] = "}",
		[0x7E] = "~",
		[0xA0] = "&#x00A0;", // NO-BREAK SPACE
		[0xA4] = "&#x00A4;", // CURRENCY SIGN
		[0xAC] = "&#x060C;", // ARABIC COMMA
		[0xAD] = "&#x00AD;", // SOFT HYPHEN
		[0xBB] = "&#x061B;", // ARABIC SEMICOLON
		[0xBF] = "&#x061F;", // ARABIC QUESTION MARK
		[0xC1] = "&#x0621;", // ARABIC LETTER HAMZA
		[0xC2] = "&#x0622;", // ARABIC LETTER ALEF WITH MADDA ABOVE
		[0xC3] = "&#x0623;", // ARABIC LETTER ALEF WITH HAMZA ABOVE
		[0xC4] = "&#x0624;", // ARABIC LETTER WAW WITH HAMZA ABOVE
		[0xC5] = "&#x0625;", // ARABIC LETTER ALEF WITH HAMZA BELOW
		[0xC6] = "&#x0626;", // ARABIC LETTER YEH WITH HAMZA ABOVE
		[0xC7] = "&#x0627;", // ARABIC LETTER ALEF
		[0xC8] = "&#x0628;", // ARABIC LETTER BEH
		[0xC9] = "&#x0629;", // ARABIC LETTER TEH MARBUTA
		[0xCA] = "&#x062A;", // ARABIC LETTER TEH
		[0xCB] = "&#x062B;", // ARABIC LETTER THEH
		[0xCC] = "&#x062C;", // ARABIC LETTER JEEM
		[0xCD] = "&#x062D;", // ARABIC LETTER HAH
		[0xCE] = "&#x062E;", // ARABIC LETTER KHAH
		[0xCF] = "&#x062F;", // ARABIC LETTER DAL
		[0xD0] = "&#x0630;", // ARABIC LETTER THAL
		[0xD1] = "&#x0631;", // ARABIC LETTER REH
		[0xD2] = "&#x0632;", // ARABIC LETTER ZAIN
		[0xD3] = "&#x0633;", // ARABIC LETTER SEEN
		[0xD4] = "&#x0634;", // ARABIC LETTER SHEEN
		[0xD5] = "&#x0635;", // ARABIC LETTER SAD
		[0xD6] = "&#x0636;", // ARABIC LETTER DAD
		[0xD7] = "&#x0637;", // ARABIC LETTER TAH
		[0xD8] = "&#x0638;", // ARABIC LETTER ZAH
		[0xD9] = "&#x0639;", // ARABIC LETTER AIN
		[0xDA] = "&#x063A;", // ARABIC LETTER GHAIN
		[0xE0] = "&#x0640;", // ARABIC TATWEEL
		[0xE1] = "&#x0641;", // ARABIC LETTER FEH
		[0xE2] = "&#x0642;", // ARABIC LETTER QAF
		[0xE3] = "&#x0643;", // ARABIC LETTER KAF
		[0xE4] = "&#x0644;", // ARABIC LETTER LAM
		[0xE5] = "&#x0645;", // ARABIC LETTER MEEM
		[0xE6] = "&#x0646;", // ARABIC LETTER NOON
		[0xE7] = "&#x0647;", // ARABIC LETTER HEH
		[0xE8] = "&#x0648;", // ARABIC LETTER WAW
		[0xE9] = "&#x0649;", // ARABIC LETTER ALEF MAKSURA
		[0xEA] = "&#x064A;", // ARABIC LETTER YEH
		[0xEB] = "&#x064B;", // ARABIC FATHATAN
		[0xEC] = "&#x064C;", // ARABIC DAMMATAN
		[0xED] = "&#x064D;", // ARABIC KASRATAN
		[0xEE] = "&#x064E;", // ARABIC FATHA
		[0xEF] = "&#x064F;", // ARABIC DAMMA
		[0xF0] = "&#x0650;", // ARABIC KASRA
		[0xF1] = "&#x0651;", // ARABIC SHADDA
		[0xF2] = "&#x0652;", // ARABIC SUKUN
	}, /* }}} */
	[3] = { /* Character code table 03 - Latin/Greek alphabet - ISO 8859-7 {{{ */
		[0x20] = " ",
		[0x21] = "!",
		[0x22] = "&quot;",
		[0x23] = "#",
		[0x24] = "$",
		[0x25] = "%",
		[0x26] = "&amp;",
		[0x27] = "'",
		[0x28] = "(",
		[0x29] = ")",
		[0x2A] = "*",
		[0x2B] = "+",
		[0x2C] = ",",
		[0x2D] = "-",
		[0x2E] = ".",
		[0x2F] = "/",
		[0x30] = "0",
		[0x31] = "1",
		[0x32] = "2",
		[0x33] = "3",
		[0x34] = "4",
		[0x35] = "5",
		[0x36] = "6",
		[0x37] = "7",
		[0x38] = "8",
		[0x39] = "9",
		[0x3A] = ":",
		[0x3B] = ";",
		[0x3C] = "&lt;",
		[0x3D] = "=",
		[0x3E] = "&gt;",
		[0x3F] = "?",
		[0x40] = "@",
		[0x41] = "A",
		[0x42] = "B",
		[0x43] = "C",
		[0x44] = "D",
		[0x45] = "E",
		[0x46] = "F",
		[0x47] = "G",
		[0x48] = "H",
		[0x49] = "I",
		[0x4A] = "J",
		[0x4B] = "K",
		[0x4C] = "L",
		[0x4D] = "M",
		[0x4E] = "N",
		[0x4F] = "O",
		[0x50] = "P",
		[0x51] = "Q",
		[0x52] = "R",
		[0x53] = "S",
		[0x54] = "T",
		[0x55] = "U",
		[0x56] = "V",
		[0x57] = "W",
		[0x58] = "X",
		[0x59] = "Y",
		[0x5A] = "Z",
		[0x5B] = "[",
		[0x5C] = "\\",
		[0x5D] = "]",
		[0x5E] = "^",
		[0x5F] = "_",
		[0x60] = "`",
		[0x61] = "a",
		[0x62] = "b",
		[0x63] = "c",
		[0x64] = "d",
		[0x65] = "e",
		[0x66] = "f",
		[0x67] = "g",
		[0x68] = "h",
		[0x69] = "i",
		[0x6A] = "j",
		[0x6B] = "k",
		[0x6C] = "l",
		[0x6D] = "m",
		[0x6E] = "n",
		[0x6F] = "o",
		[0x70] = "p",
		[0x71] = "q",
		[0x72] = "r",
		[0x73] = "s",
		[0x74] = "t",
		[0x75] = "u",
		[0x76] = "v",
		[0x77] = "w",
		[0x78] = "x",
		[0x79] = "y",
		[0x7A] = "z",
		[0x7B] = "{",
		[0x7C] = "|",
		[0x7D] = "}",
		[0x7E] = "~",
		[0xA0] = "&#x00A0;", // NO-BREAK SPACE
		[0xA1] = "&#x2018;", // LEFT SINGLE QUOTATION MARK
		[0xA2] = "&#x2019;", // RIGHT SINGLE QUOTATION MARK
		[0xA3] = "&#x00A3;", // POUND SIGN
		[0xA6] = "&#x00A6;", // BROKEN BAR
		[0xA7] = "&#x00A7;", // SECTION SIGN
		[0xA8] = "&#x00A8;", // DIAERESIS
		[0xA9] = "&#x00A9;", // COPYRIGHT SIGN
		[0xAB] = "&#x00AB;", // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
		[0xAC] = "&#x00AC;", // NOT SIGN
		[0xAD] = "&#x00AD;", // SOFT HYPHEN
		[0xAF] = "&#x2015;", // HORIZONTAL BAR
		[0xB0] = "&#x00B0;", // DEGREE SIGN
		[0xB1] = "&#x00B1;", // PLUS-MINUS SIGN
		[0xB2] = "&#x00B2;", // SUPERSCRIPT TWO
		[0xB3] = "&#x00B3;", // SUPERSCRIPT THREE
		[0xB4] = "&#x0384;", // GREEK TONOS
		[0xB5] = "&#x0385;", // GREEK DIALYTIKA TONOS
		[0xB6] = "&#x0386;", // GREEK CAPITAL LETTER ALPHA WITH TONOS
		[0xB7] = "&#x00B7;", // MIDDLE DOT
		[0xB8] = "&#x0388;", // GREEK CAPITAL LETTER EPSILON WITH TONOS
		[0xB9] = "&#x0389;", // GREEK CAPITAL LETTER ETA WITH TONOS
		[0xBA] = "&#x038A;", // GREEK CAPITAL LETTER IOTA WITH TONOS
		[0xBB] = "&#x00BB;", // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
		[0xBC] = "&#x038C;", // GREEK CAPITAL LETTER OMICRON WITH TONOS
		[0xBD] = "&#x00BD;", // VULGAR FRACTION ONE HALF
		[0xBE] = "&#x038E;", // GREEK CAPITAL LETTER UPSILON WITH TONOS
		[0xBF] = "&#x038F;", // GREEK CAPITAL LETTER OMEGA WITH TONOS
		[0xC0] = "&#x0390;", // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
		[0xC1] = "&#x0391;", // GREEK CAPITAL LETTER ALPHA
		[0xC2] = "&#x0392;", // GREEK CAPITAL LETTER BETA
		[0xC3] = "&#x0393;", // GREEK CAPITAL LETTER GAMMA
		[0xC4] = "&#x0394;", // GREEK CAPITAL LETTER DELTA
		[0xC5] = "&#x0395;", // GREEK CAPITAL LETTER EPSILON
		[0xC6] = "&#x0396;", // GREEK CAPITAL LETTER ZETA
		[0xC7] = "&#x0397;", // GREEK CAPITAL LETTER ETA
		[0xC8] = "&#x0398;", // GREEK CAPITAL LETTER THETA
		[0xC9] = "&#x0399;", // GREEK CAPITAL LETTER IOTA
		[0xCA] = "&#x039A;", // GREEK CAPITAL LETTER KAPPA
		[0xCB] = "&#x039B;", // GREEK CAPITAL LETTER LAMDA
		[0xCC] = "&#x039C;", // GREEK CAPITAL LETTER MU
		[0xCD] = "&#x039D;", // GREEK CAPITAL LETTER NU
		[0xCE] = "&#x039E;", // GREEK CAPITAL LETTER XI
		[0xCF] = "&#x039F;", // GREEK CAPITAL LETTER OMICRON
		[0xD0] = "&#x03A0;", // GREEK CAPITAL LETTER PI
		[0xD1] = "&#x03A1;", // GREEK CAPITAL LETTER RHO
		[0xD3] = "&#x03A3;", // GREEK CAPITAL LETTER SIGMA
		[0xD4] = "&#x03A4;", // GREEK CAPITAL LETTER TAU
		[0xD5] = "&#x03A5;", // GREEK CAPITAL LETTER UPSILON
		[0xD6] = "&#x03A6;", // GREEK CAPITAL LETTER PHI
		[0xD7] = "&#x03A7;", // GREEK CAPITAL LETTER CHI
		[0xD8] = "&#x03A8;", // GREEK CAPITAL LETTER PSI
		[0xD9] = "&#x03A9;", // GREEK CAPITAL LETTER OMEGA
		[0xDA] = "&#x03AA;", // GREEK CAPITAL LETTER IOTA WITH DIALYTIKA
		[0xDB] = "&#x03AB;", // GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA
		[0xDC] = "&#x03AC;", // GREEK SMALL LETTER ALPHA WITH TONOS
		[0xDD] = "&#x03AD;", // GREEK SMALL LETTER EPSILON WITH TONOS
		[0xDE] = "&#x03AE;", // GREEK SMALL LETTER ETA WITH TONOS
		[0xDF] = "&#x03AF;", // GREEK SMALL LETTER IOTA WITH TONOS
		[0xE0] = "&#x03B0;", // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS
		[0xE1] = "&#x03B1;", // GREEK SMALL LETTER ALPHA
		[0xE2] = "&#x03B2;", // GREEK SMALL LETTER BETA
		[0xE3] = "&#x03B3;", // GREEK SMALL LETTER GAMMA
		[0xE4] = "&#x03B4;", // GREEK SMALL LETTER DELTA
		[0xE5] = "&#x03B5;", // GREEK SMALL LETTER EPSILON
		[0xE6] = "&#x03B6;", // GREEK SMALL LETTER ZETA
		[0xE7] = "&#x03B7;", // GREEK SMALL LETTER ETA
		[0xE8] = "&#x03B8;", // GREEK SMALL LETTER THETA
		[0xE9] = "&#x03B9;", // GREEK SMALL LETTER IOTA
		[0xEA] = "&#x03BA;", // GREEK SMALL LETTER KAPPA
		[0xEB] = "&#x03BB;", // GREEK SMALL LETTER LAMDA
		[0xEC] = "&#x03BC;", // GREEK SMALL LETTER MU
		[0xED] = "&#x03BD;", // GREEK SMALL LETTER NU
		[0xEE] = "&#x03BE;", // GREEK SMALL LETTER XI
		[0xEF] = "&#x03BF;", // GREEK SMALL LETTER OMICRON
		[0xF0] = "&#x03C0;", // GREEK SMALL LETTER PI
		[0xF1] = "&#x03C1;", // GREEK SMALL LETTER RHO
		[0xF2] = "&#x03C2;", // GREEK SMALL LETTER FINAL SIGMA
		[0xF3] = "&#x03C3;", // GREEK SMALL LETTER SIGMA
		[0xF4] = "&#x03C4;", // GREEK SMALL LETTER TAU
		[0xF5] = "&#x03C5;", // GREEK SMALL LETTER UPSILON
		[0xF6] = "&#x03C6;", // GREEK SMALL LETTER PHI
		[0xF7] = "&#x03C7;", // GREEK SMALL LETTER CHI
		[0xF8] = "&#x03C8;", // GREEK SMALL LETTER PSI
		[0xF9] = "&#x03C9;", // GREEK SMALL LETTER OMEGA
		[0xFA] = "&#x03CA;", // GREEK SMALL LETTER IOTA WITH DIALYTIKA
		[0xFB] = "&#x03CB;", // GREEK SMALL LETTER UPSILON WITH DIALYTIKA
		[0xFC] = "&#x03CC;", // GREEK SMALL LETTER OMICRON WITH TONOS
		[0xFD] = "&#x03CD;", // GREEK SMALL LETTER UPSILON WITH TONOS
		[0xFE] = "&#x03CE;", // GREEK SMALL LETTER OMEGA WITH TONOS
	}, /* }}} */
	[4] = { /* Character code table 04 - Latin/Hebrew alphabet - ISO 8859-8 {{{ */
		[0x20] = " ",
		[0x21] = "!",
		[0x22] = "&quot;",
		[0x23] = "#",
		[0x24] = "$",
		[0x25] = "%",
		[0x26] = "&amp;",
		[0x27] = "'",
		[0x28] = "(",
		[0x29] = ")",
		[0x2A] = "*",
		[0x2B] = "+",
		[0x2C] = ",",
		[0x2D] = "-",
		[0x2E] = ".",
		[0x2F] = "/",
		[0x30] = "0",
		[0x31] = "1",
		[0x32] = "2",
		[0x33] = "3",
		[0x34] = "4",
		[0x35] = "5",
		[0x36] = "6",
		[0x37] = "7",
		[0x38] = "8",
		[0x39] = "9",
		[0x3A] = ":",
		[0x3B] = ";",
		[0x3C] = "&lt;",
		[0x3D] = "=",
		[0x3E] = "&gt;",
		[0x3F] = "?",
		[0x40] = "@",
		[0x41] = "A",
		[0x42] = "B",
		[0x43] = "C",
		[0x44] = "D",
		[0x45] = "E",
		[0x46] = "F",
		[0x47] = "G",
		[0x48] = "H",
		[0x49] = "I",
		[0x4A] = "J",
		[0x4B] = "K",
		[0x4C] = "L",
		[0x4D] = "M",
		[0x4E] = "N",
		[0x4F] = "O",
		[0x50] = "P",
		[0x51] = "Q",
		[0x52] = "R",
		[0x53] = "S",
		[0x54] = "T",
		[0x55] = "U",
		[0x56] = "V",
		[0x57] = "W",
		[0x58] = "X",
		[0x59] = "Y",
		[0x5A] = "Z",
		[0x5B] = "[",
		[0x5C] = "\\",
		[0x5D] = "]",
		[0x5E] = "^",
		[0x5F] = "_",
		[0x60] = "`",
		[0x61] = "a",
		[0x62] = "b",
		[0x63] = "c",
		[0x64] = "d",
		[0x65] = "e",
		[0x66] = "f",
		[0x67] = "g",
		[0x68] = "h",
		[0x69] = "i",
		[0x6A] = "j",
		[0x6B] = "k",
		[0x6C] = "l",
		[0x6D] = "m",
		[0x6E] = "n",
		[0x6F] = "o",
		[0x70] = "p",
		[0x71] = "q",
		[0x72] = "r",
		[0x73] = "s",
		[0x74] = "t",
		[0x75] = "u",
		[0x76] = "v",
		[0x77] = "w",
		[0x78] = "x",
		[0x79] = "y",
		[0x7A] = "z",
		[0x7B] = "{",
		[0x7C] = "|",
		[0x7D] = "}",
		[0x7E] = "~",
		[0xA0] = "&#x00A0;", // NO-BREAK SPACE
		[0xA2] = "&#x00A2;", // CENT SIGN
		[0xA3] = "&#x00A3;", // POUND SIGN
		[0xA4] = "&#x00A4;", // CURRENCY SIGN
		[0xA5] = "&#x00A5;", // YEN SIGN
		[0xA6] = "&#x00A6;", // BROKEN BAR
		[0xA7] = "&#x00A7;", // SECTION SIGN
		[0xA8] = "&#x00A8;", // DIAERESIS
		[0xA9] = "&#x00A9;", // COPYRIGHT SIGN
		[0xAA] = "&#x00D7;", // MULTIPLICATION SIGN
		[0xAB] = "&#x00AB;", // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
		[0xAC] = "&#x00AC;", // NOT SIGN
		[0xAD] = "&#x00AD;", // SOFT HYPHEN
		[0xAE] = "&#x00AE;", // REGISTERED SIGN
		[0xAF] = "&#x00AF;", // MACRON
		[0xB0] = "&#x00B0;", // DEGREE SIGN
		[0xB1] = "&#x00B1;", // PLUS-MINUS SIGN
		[0xB2] = "&#x00B2;", // SUPERSCRIPT TWO
		[0xB3] = "&#x00B3;", // SUPERSCRIPT THREE
		[0xB4] = "&#x00B4;", // ACUTE ACCENT
		[0xB5] = "&#x00B5;", // MICRO SIGN
		[0xB6] = "&#x00B6;", // PILCROW SIGN
		[0xB7] = "&#x00B7;", // MIDDLE DOT
		[0xB8] = "&#x00B8;", // CEDILLA
		[0xB9] = "&#x00B9;", // SUPERSCRIPT ONE
		[0xBA] = "&#x00F7;", // DIVISION SIGN
		[0xBB] = "&#x00BB;", // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
		[0xBC] = "&#x00BC;", // VULGAR FRACTION ONE QUARTER
		[0xBD] = "&#x00BD;", // VULGAR FRACTION ONE HALF
		[0xBE] = "&#x00BE;", // VULGAR FRACTION THREE QUARTERS
		[0xDF] = "&#x2017;", // DOUBLE LOW LINE
		[0xE0] = "&#x05D0;", // HEBREW LETTER ALEF
		[0xE1] = "&#x05D1;", // HEBREW LETTER BET
		[0xE2] = "&#x05D2;", // HEBREW LETTER GIMEL
		[0xE3] = "&#x05D3;", // HEBREW LETTER DALET
		[0xE4] = "&#x05D4;", // HEBREW LETTER HE
		[0xE5] = "&#x05D5;", // HEBREW LETTER VAV
		[0xE6] = "&#x05D6;", // HEBREW LETTER ZAYIN
		[0xE7] = "&#x05D7;", // HEBREW LETTER HET
		[0xE8] = "&#x05D8;", // HEBREW LETTER TET
		[0xE9] = "&#x05D9;", // HEBREW LETTER YOD
		[0xEA] = "&#x05DA;", // HEBREW LETTER FINAL KAF
		[0xEB] = "&#x05DB;", // HEBREW LETTER KAF
		[0xEC] = "&#x05DC;", // HEBREW LETTER LAMED
		[0xED] = "&#x05DD;", // HEBREW LETTER FINAL MEM
		[0xEE] = "&#x05DE;", // HEBREW LETTER MEM
		[0xEF] = "&#x05DF;", // HEBREW LETTER FINAL NUN
		[0xF0] = "&#x05E0;", // HEBREW LETTER NUN
		[0xF1] = "&#x05E1;", // HEBREW LETTER SAMEKH
		[0xF2] = "&#x05E2;", // HEBREW LETTER AYIN
		[0xF3] = "&#x05E3;", // HEBREW LETTER FINAL PE
		[0xF4] = "&#x05E4;", // HEBREW LETTER PE
		[0xF5] = "&#x05E5;", // HEBREW LETTER FINAL TSADI
		[0xF6] = "&#x05E6;", // HEBREW LETTER TSADI
		[0xF7] = "&#x05E7;", // HEBREW LETTER QOF
		[0xF8] = "&#x05E8;", // HEBREW LETTER RESH
		[0xF9] = "&#x05E9;", // HEBREW LETTER SHIN
		[0xFA] = "&#x05EA;", // HEBREW LETTER TAV
		[0xFD] = "&#x200E;", // LEFT-TO-RIGHT MARK
		[0xFE] = "&#x200F;", // RIGHT-TO-LEFT MARK
	}, /* }}} */
	[5] = { /* Character code table 05 - Latin alphabet number 5 - ISO 8859-9 {{{ */
		[0x20] = " ",
		[0x21] = "!",
		[0x22] = "&quot;",
		[0x23] = "#",
		[0x24] = "$",
		[0x25] = "%",
		[0x26] = "&amp;",
		[0x27] = "'",
		[0x28] = "(",
		[0x29] = ")",
		[0x2A] = "*",
		[0x2B] = "+",
		[0x2C] = ",",
		[0x2D] = "-",
		[0x2E] = ".",
		[0x2F] = "/",
		[0x30] = "0",
		[0x31] = "1",
		[0x32] = "2",
		[0x33] = "3",
		[0x34] = "4",
		[0x35] = "5",
		[0x36] = "6",
		[0x37] = "7",
		[0x38] = "8",
		[0x39] = "9",
		[0x3A] = ":",
		[0x3B] = ";",
		[0x3C] = "&lt;",
		[0x3D] = "=",
		[0x3E] = "&gt;",
		[0x3F] = "?",
		[0x40] = "@",
		[0x41] = "A",
		[0x42] = "B",
		[0x43] = "C",
		[0x44] = "D",
		[0x45] = "E",
		[0x46] = "F",
		[0x47] = "G",
		[0x48] = "H",
		[0x49] = "I",
		[0x4A] = "J",
		[0x4B] = "K",
		[0x4C] = "L",
		[0x4D] = "M",
		[0x4E] = "N",
		[0x4F] = "O",
		[0x50] = "P",
		[0x51] = "Q",
		[0x52] = "R",
		[0x53] = "S",
		[0x54] = "T",
		[0x55] = "U",
		[0x56] = "V",
		[0x57] = "W",
		[0x58] = "X",
		[0x59] = "Y",
		[0x5A] = "Z",
		[0x5B] = "[",
		[0x5C] = "\\",
		[0x5D] = "]",
		[0x5E] = "^",
		[0x5F] = "_",
		[0x60] = "`",
		[0x61] = "a",
		[0x62] = "b",
		[0x63] = "c",
		[0x64] = "d",
		[0x65] = "e",
		[0x66] = "f",
		[0x67] = "g",
		[0x68] = "h",
		[0x69] = "i",
		[0x6A] = "j",
		[0x6B] = "k",
		[0x6C] = "l",
		[0x6D] = "m",
		[0x6E] = "n",
		[0x6F] = "o",
		[0x70] = "p",
		[0x71] = "q",
		[0x72] = "r",
		[0x73] = "s",
		[0x74] = "t",
		[0x75] = "u",
		[0x76] = "v",
		[0x77] = "w",
		[0x78] = "x",
		[0x79] = "y",
		[0x7A] = "z",
		[0x7B] = "{",
		[0x7C] = "|",
		[0x7D] = "}",
		[0x7E] = "~",
		[0xA0] = "&#x00A0;", // NO-BREAK SPACE
		[0xA1] = "&#x00A1;", // INVERTED EXCLAMATION MARK
		[0xA2] = "&#x00A2;", // CENT SIGN
		[0xA3] = "&#x00A3;", // POUND SIGN
		[0xA4] = "&#x00A4;", // CURRENCY SIGN
		[0xA5] = "&#x00A5;", // YEN SIGN
		[0xA6] = "&#x00A6;", // BROKEN BAR
		[0xA7] = "&#x00A7;", // SECTION SIGN
		[0xA8] = "&#x00A8;", // DIAERESIS
		[0xA9] = "&#x00A9;", // COPYRIGHT SIGN
		[0xAA] = "&#x00AA;", // FEMININE ORDINAL INDICATOR
		[0xAB] = "&#x00AB;", // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
		[0xAC] = "&#x00AC;", // NOT SIGN
		[0xAD] = "&#x00AD;", // SOFT HYPHEN
		[0xAE] = "&#x00AE;", // REGISTERED SIGN
		[0xAF] = "&#x00AF;", // MACRON
		[0xB0] = "&#x00B0;", // DEGREE SIGN
		[0xB1] = "&#x00B1;", // PLUS-MINUS SIGN
		[0xB2] = "&#x00B2;", // SUPERSCRIPT TWO
		[0xB3] = "&#x00B3;", // SUPERSCRIPT THREE
		[0xB4] = "&#x00B4;", // ACUTE ACCENT
		[0xB5] = "&#x00B5;", // MICRO SIGN
		[0xB6] = "&#x00B6;", // PILCROW SIGN
		[0xB7] = "&#x00B7;", // MIDDLE DOT
		[0xB8] = "&#x00B8;", // CEDILLA
		[0xB9] = "&#x00B9;", // SUPERSCRIPT ONE
		[0xBA] = "&#x00BA;", // MASCULINE ORDINAL INDICATOR
		[0xBB] = "&#x00BB;", // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
		[0xBC] = "&#x00BC;", // VULGAR FRACTION ONE QUARTER
		[0xBD] = "&#x00BD;", // VULGAR FRACTION ONE HALF
		[0xBE] = "&#x00BE;", // VULGAR FRACTION THREE QUARTERS
		[0xBF] = "&#x00BF;", // INVERTED QUESTION MARK
		[0xC0] = "&#x00C0;", // LATIN CAPITAL LETTER A WITH GRAVE
		[0xC1] = "&#x00C1;", // LATIN CAPITAL LETTER A WITH ACUTE
		[0xC2] = "&#x00C2;", // LATIN CAPITAL LETTER A WITH CIRCUMFLEX
		[0xC3] = "&#x00C3;", // LATIN CAPITAL LETTER A WITH TILDE
		[0xC4] = "&#x00C4;", // LATIN CAPITAL LETTER A WITH DIAERESIS
		[0xC5] = "&#x00C5;", // LATIN CAPITAL LETTER A WITH RING ABOVE
		[0xC6] = "&#x00C6;", // LATIN CAPITAL LETTER AE
		[0xC7] = "&#x00C7;", // LATIN CAPITAL LETTER C WITH CEDILLA
		[0xC8] = "&#x00C8;", // LATIN CAPITAL LETTER E WITH GRAVE
		[0xC9] = "&#x00C9;", // LATIN CAPITAL LETTER E WITH ACUTE
		[0xCA] = "&#x00CA;", // LATIN CAPITAL LETTER E WITH CIRCUMFLEX
		[0xCB] = "&#x00CB;", // LATIN CAPITAL LETTER E WITH DIAERESIS
		[0xCC] = "&#x00CC;", // LATIN CAPITAL LETTER I WITH GRAVE
		[0xCD] = "&#x00CD;", // LATIN CAPITAL LETTER I WITH ACUTE
		[0xCE] = "&#x00CE;", // LATIN CAPITAL LETTER I WITH CIRCUMFLEX
		[0xCF] = "&#x00CF;", // LATIN CAPITAL LETTER I WITH DIAERESIS
		[0xD0] = "&#x011E;", // LATIN CAPITAL LETTER G WITH BREVE
		[0xD1] = "&#x00D1;", // LATIN CAPITAL LETTER N WITH TILDE
		[0xD2] = "&#x00D2;", // LATIN CAPITAL LETTER O WITH GRAVE
		[0xD3] = "&#x00D3;", // LATIN CAPITAL LETTER O WITH ACUTE
		[0xD4] = "&#x00D4;", // LATIN CAPITAL LETTER O WITH CIRCUMFLEX
		[0xD5] = "&#x00D5;", // LATIN CAPITAL LETTER O WITH TILDE
		[0xD6] = "&#x00D6;", // LATIN CAPITAL LETTER O WITH DIAERESIS
		[0xD7] = "&#x00D7;", // MULTIPLICATION SIGN
		[0xD8] = "&#x00D8;", // LATIN CAPITAL LETTER O WITH STROKE
		[0xD9] = "&#x00D9;", // LATIN CAPITAL LETTER U WITH GRAVE
		[0xDA] = "&#x00DA;", // LATIN CAPITAL LETTER U WITH ACUTE
		[0xDB] = "&#x00DB;", // LATIN CAPITAL LETTER U WITH CIRCUMFLEX
		[0xDC] = "&#x00DC;", // LATIN CAPITAL LETTER U WITH DIAERESIS
		[0xDD] = "&#x0130;", // LATIN CAPITAL LETTER I WITH DOT ABOVE
		[0xDE] = "&#x015E;", // LATIN CAPITAL LETTER S WITH CEDILLA
		[0xDF] = "&#x00DF;", // LATIN SMALL LETTER SHARP S
		[0xE0] = "&#x00E0;", // LATIN SMALL LETTER A WITH GRAVE
		[0xE1] = "&#x00E1;", // LATIN SMALL LETTER A WITH ACUTE
		[0xE2] = "&#x00E2;", // LATIN SMALL LETTER A WITH CIRCUMFLEX
		[0xE3] = "&#x00E3;", // LATIN SMALL LETTER A WITH TILDE
		[0xE4] = "&#x00E4;", // LATIN SMALL LETTER A WITH DIAERESIS
		[0xE5] = "&#x00E5;", // LATIN SMALL LETTER A WITH RING ABOVE
		[0xE6] = "&#x00E6;", // LATIN SMALL LETTER AE
		[0xE7] = "&#x00E7;", // LATIN SMALL LETTER C WITH CEDILLA
		[0xE8] = "&#x00E8;", // LATIN SMALL LETTER E WITH GRAVE
		[0xE9] = "&#x00E9;", // LATIN SMALL LETTER E WITH ACUTE
		[0xEA] = "&#x00EA;", // LATIN SMALL LETTER E WITH CIRCUMFLEX
		[0xEB] = "&#x00EB;", // LATIN SMALL LETTER E WITH DIAERESIS
		[0xEC] = "&#x00EC;", // LATIN SMALL LETTER I WITH GRAVE
		[0xED] = "&#x00ED;", // LATIN SMALL LETTER I WITH ACUTE
		[0xEE] = "&#x00EE;", // LATIN SMALL LETTER I WITH CIRCUMFLEX
		[0xEF] = "&#x00EF;", // LATIN SMALL LETTER I WITH DIAERESIS
		[0xF0] = "&#x011F;", // LATIN SMALL LETTER G WITH BREVE
		[0xF1] = "&#x00F1;", // LATIN SMALL LETTER N WITH TILDE
		[0xF2] = "&#x00F2;", // LATIN SMALL LETTER O WITH GRAVE
		[0xF3] = "&#x00F3;", // LATIN SMALL LETTER O WITH ACUTE
		[0xF4] = "&#x00F4;", // LATIN SMALL LETTER O WITH CIRCUMFLEX
		[0xF5] = "&#x00F5;", // LATIN SMALL LETTER O WITH TILDE
		[0xF6] = "&#x00F6;", // LATIN SMALL LETTER O WITH DIAERESIS
		[0xF7] = "&#x00F7;", // DIVISION SIGN
		[0xF8] = "&#x00F8;", // LATIN SMALL LETTER O WITH STROKE
		[0xF9] = "&#x00F9;", // LATIN SMALL LETTER U WITH GRAVE
		[0xFA] = "&#x00FA;", // LATIN SMALL LETTER U WITH ACUTE
		[0xFB] = "&#x00FB;", // LATIN SMALL LETTER U WITH CIRCUMFLEX
		[0xFC] = "&#x00FC;", // LATIN SMALL LETTER U WITH DIAERESIS
		[0xFD] = "&#x0131;", // LATIN SMALL LETTER DOTLESS I
		[0xFE] = "&#x015F;", // LATIN SMALL LETTER S WITH CEDILLA
		[0xFF] = "&#x00FF;", // LATIN SMALL LETTER Y WITH DIAERESIS
	} /* }}} */
};

/* Quote the xml entities in the string passed in.
 * NB this is returned as a pointer to a string on the heap which will
 * be re-used on the next call to xmlify()
 * Patched by Nick Craig-Wood - nick craig-wood com for more chars with
 * strcat func for tidyness
 */
char *xmlify(const char *s, int len) {
	static char *xml = NULL;
	static unsigned bufsz = 0;
	char *r;
	unsigned int table = 0;
	int max_len = strlen(s) * 10 + 1; /* Max possible expansion of string n * &quot; + NULL */
		                         /* A little untidy but fast! */

	/*  Patch by Steve Davies <steve one47 co uk> for better memory management */
	if (bufsz < max_len || xml == NULL) {
		xml = realloc(xml, max_len);
		bufsz = max_len;
	}

	switch ((unsigned char)*s) {
		case 0x20 ... 0xFF: // if the first byte of the text field has a value in the range of "0x20" to "0xFF" then this and all subsequent bytes in the text item are coded using the default coding table (table 00 - Latin alphabet) of figure A.1
			table = 0;
			break;
		case 0x01 ... 0x05: // if the first byte of the text field is in the range "0x01" to "0x05" then the remaining bytes in the text item are coded in accordance with character coding table 01 to 05 respectively, which are given in figures A.2 to A.6 respectively
			table = *s++;
			break;
		case 0x10: // if the first byte of the text field has a value "0x10" then the following two bytes carry a 16-bit value (uimsbf) N to indicate that the remaining data of the text field is coded using the character code table specified by ISO Standard 8859, Parts 1 to 9.
			fprintf(stderr, "Unhandled encoding ISO 8859-%02x%02x\n", s[1], s[2]);
			s += 3;
			return NULL;
		case 0x11: // if the first byte of the text field has a value "0x11" then the ramaining bytes in the text item are coded in pairs in accordance with the Basic Multilingual Plane of ISO/IEC 10646-1
			fprintf(stderr, "Unhandled encoding ISO 10646-1\n");
			return NULL;
		case 0x06 ... 0x0F: case 0x12 ... 0x1F: // Values for the first byte of "0x00", "0x06" to "0x0F", and "0x12" to "0x1F" are reserved for future use.
			fprintf(stderr, "Reserved encoding: %02x\n", s[0]);
			return NULL;
		case 0x00: // empty string
			return "";
	}

	for (r = xml; *s != '\0'; s++) {
		unsigned int i = (unsigned char)*s;
		const char *entity = codeset[table][i];
		if (!entity[0]) {
			static char buf[10];
			snprintf(buf, 10, "<!--%02x-->", i);
			entity = buf;
		}
		while (*entity)
			*r++ = *entity++;
	}
	*r = '\0';
	return xml;
}
