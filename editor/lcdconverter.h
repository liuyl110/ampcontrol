#ifndef LCDCONVERTER_H
#define LCDCONVERTER_H

#include <QString>
#include <QMap>

class LcdConverter
{
public:
    LcdConverter();

    QByteArray encode(QString text);
    QString decode(QByteArray ba);

private:
    QMap<QChar, char> map_ks0066ru = {
        {0x0020, 0x20}, // space
        {0x0021, 0x21}, // !
        {0x0022, 0x22}, // "
        {0x0023, 0x23}, // #
        {0x0024, 0x24}, // $
        {0x0025, 0x25}, // %
        {0x0026, 0x26}, // &
        {0x0027, 0x27}, // '
        {0x0028, 0x28}, // (
        {0x0029, 0x29}, // )
        {0x002a, 0x2a}, // *
        {0x002b, 0x2b}, // +
        {0x002c, 0x2c}, // ,
        {0x002d, 0x2d}, // -
        {0x002e, 0x2e}, // .
        {0x002f, 0x2f}, // /

        {0x0030, 0x30}, // 0
        {0x0031, 0x31}, // 1
        {0x0032, 0x32}, // 2
        {0x0033, 0x33}, // 3
        {0x0034, 0x34}, // 4
        {0x0035, 0x35}, // 5
        {0x0036, 0x36}, // 6
        {0x0037, 0x37}, // 7
        {0x0038, 0x38}, // 8
        {0x0039, 0x39}, // 9
        {0x003a, 0x3a}, // :
        {0x003b, 0x3b}, // ;
        {0x003c, 0x3c}, // <
        {0x003d, 0x3d}, // =
        {0x003e, 0x3e}, // >
        {0x003f, 0x3f}, // ?

        {0x0040, 0x40}, // @
        {0x0041, 0x41}, {0x0410, 0x41}, // A
        {0x0042, 0x42}, {0x0412, 0x42}, // B
        {0x0043, 0x43}, {0x0421, 0x43}, // C
        {0x0044, 0x44}, // D
        {0x0045, 0x45}, {0x0415, 0x45}, // E
        {0x0046, 0x46}, // F
        {0x0047, 0x47}, // G
        {0x0048, 0x48}, {0x041d, 0x48}, // H
        {0x0049, 0x49}, // I
        {0x004a, 0x4a}, // J
        {0x004b, 0x4b}, {0x041a, 0x4b}, // K
        {0x004c, 0x4c}, // L
        {0x004d, 0x4d}, {0x041c, 0x4d}, // M
        {0x004e, 0x4e}, // N
        {0x004f, 0x4f}, {0x041e, 0x4f}, // O

        {0x0050, 0x50}, {0x0420, 0x50}, // P
        {0x0051, 0x51}, // Q
        {0x0052, 0x52}, // R
        {0x0053, 0x53}, // S
        {0x0054, 0x54}, {0x0422, 0x54}, // T
        {0x0055, 0x55}, // U
        {0x0056, 0x56}, // V
        {0x0057, 0x57}, // W
        {0x0058, 0x58}, {0x0425, 0x58}, // X
        {0x0059, 0x59}, // Y
        {0x005a, 0x5a}, // Z
        {0x005b, 0x5b}, // [
        {0x00a2, 0x5c}, // ¢
        {0x005d, 0x5d}, // ]
        {0x005e, 0x5e}, // ^
        {0x005f, 0x5f}, // -

        {0x0060, 0x60}, // `
        {0x0061, 0x61}, {0x0430, 0x61}, // a
        {0x0062, 0x62}, {0x042c, 0x62}, // b
        {0x0063, 0x63}, {0x0441, 0x63}, // c
        {0x0064, 0x64}, // d
        {0x0065, 0x65}, {0x0435, 0x65}, // e
        {0x0066, 0x66}, // f
        {0x0067, 0x67}, // g
        {0x0068, 0x68}, // h
        {0x0069, 0x69}, // i
        {0x006a, 0x6a}, // j
        {0x006b, 0x6b}, // k
        {0x006c, 0x6c}, // l
        {0x006d, 0x6d}, // m
        {0x006e, 0x6e}, // n
        {0x006f, 0x6f}, {0x043e, 0x6f}, // o

        {0x0070, 0x70}, {0x0440, 0x70}, // p
        {0x0071, 0x71}, // q
        {0x0072, 0x72}, // r
        {0x0073, 0x73}, // s
        {0x0074, 0x74}, // t
        {0x0075, 0x75}, // u
        {0x0076, 0x76}, // v
        {0x0077, 0x77}, // w
        {0x0078, 0x78}, {0x0445, 0x78}, // x
        {0x0079, 0x79}, {0x0443, 0x79}, // y
        {0x007a, 0x7a}, // z
        {0x2469, 0x7b}, // ⑩
        {0x246b, 0x7c}, // ⑫
        {0x246e, 0x7d}, // ⑮
        {0x21b5, 0x7e}, // ↵
        {0x2750, 0x7f}, //

        {0x0411, 0xa0}, // Б
        {0x0413, 0xa1}, // Г
        {0x0401, 0xa2}, // Ё
        {0x0416, 0xa3}, // Ж
        {0x0417, 0xa4}, // З
        {0x0418, 0xa5}, // И
        {0x0419, 0xa6}, // Й
        {0x041b, 0xa7}, // Л
        {0x041f, 0xa8}, // П
        {0x0423, 0xa9}, // У
        {0x0424, 0xaa}, // Ф
        {0x0427, 0xab}, // Ч
        {0x0428, 0xac}, // Ш
        {0x042a, 0xad}, // Ъ
        {0x042b, 0xae}, // Ы
        {0x042d, 0xaf}, // Э

        {0x042e, 0xb0}, // Ю
        {0x042f, 0xb1}, // Я
        {0x0431, 0xb2}, // б
        {0x0432, 0xb3}, // в
        {0x0433, 0xb4}, // г
        {0x0451, 0xb5}, // ё
        {0x0436, 0xb6}, // ж
        {0x0437, 0xb7}, // з
        {0x0438, 0xb8}, // и
        {0x0439, 0xb9}, // й
        {0x043a, 0xba}, // к
        {0x043b, 0xbb}, // л
        {0x043c, 0xbc}, // м
        {0x043d, 0xbd}, // н
        {0x043f, 0xbe}, // п
        {0x0442, 0xbf}, // т

        {0x0447, 0xc0}, // ч
        {0x0448, 0xc1}, // ш
        {0x044a, 0xc2}, // ъ
        {0x044b, 0xc3}, // ы
        {0x044c, 0xc4}, // ь
        {0x044d, 0xc5}, // э
        {0x044e, 0xc6}, // ю
        {0x044f, 0xc7}, // я
        {0x00ab, 0xc8}, {0x007b, 0xc8}, // « {
        {0x00bb, 0xc9}, {0x007d, 0xc9}, // » }
        {0x201e, 0xca}, // “
        {0x201d, 0xcb}, // ”
        {0x2116, 0xcc}, // Ṇ
        {0x00bf, 0xcd}, // ¿
        {0x2a0d, 0xce}, // ⨍
        {0x00a3, 0xcf}, // £

        {0x02cc, 0xd0}, // ˌ
        {0x2577, 0xd1}, // ╷
        {0x2963, 0xd2}, // ⥣
        {0x2965, 0xd3}, // ⥥
        {0x215f, 0xd4}, // ⅟
        {0x00d7, 0xd5}, // ×
        {0x2044, 0xd6}, // ⁄
        {0x2160, 0xd7}, // Ⅰ
        {0x2161, 0xd8}, // Ⅱ
        {0x2191, 0xd9}, // ↑
        {0x2193, 0xda}, // ↓
        {0x21e4, 0xdb}, // ⇤
        {0x21e5, 0xdc}, // ⇥
        {0x2920, 0xdd}, // ⤠
        {0x2358, 0xde}, // ⍘
        {0x00b7, 0xdf}, // °

        {0x0414, 0xe0}, // Д
        {0x0426, 0xe1}, // Ц
        {0x0429, 0xe2}, // Щ
        {0x0434, 0xe3}, // д
        {0x0444, 0xe4}, // ф
        {0x0446, 0xe5}, // ц
        {0x0449, 0xe6}, // щ
        {0x2018, 0xe7}, // ‘
        {0x00a8, 0xe8}, // ¨
        {0x007e, 0xe9}, // ~
        {0x00e9, 0xea}, // Ў
        {0x00e7, 0xeb}, // ў
        {0x0133, 0xec}, // Є
        {0x2669, 0xed}, {0x007c, 0xed}, // ♩ |
        {0x25cc, 0xee}, // Ї
        {0x25cb, 0xef}, // ї

        {0x00bc, 0xf0}, // ¼
        {0x2153, 0xf1}, // ⅓
        {0x00bd, 0xf2}, // ½
        {0x00be, 0xf3}, // ¾
        {0x2630, 0xf4}, // ☰
        {0x2234, 0xf5}, // ♥
        {0x23ce, 0xf6}, // ⏎
        {0x2045, 0xf7}, // ⁅
        {0x253c, 0xf8}, // ┼
        {0x253d, 0xf9}, // ┽
        {0x2046, 0xfa}, // ⁆
        {0x2058, 0xfb}, // ⁘
        {0x2059, 0xfc}, // ⁙
        {0x00a7, 0xfd}, {0x005c, 0xfd}, // § backslash
        {0x00b6, 0xfe}, // ¶
        {0x2588, 0xff}, // █
    };
};

#endif // LCDCONVERTER_H
