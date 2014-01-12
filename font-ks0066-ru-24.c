#include <avr/pgmspace.h>

const uint8_t font_ks0066_ru_24[] PROGMEM = {

	0x03,	// font height in bytes
	0x7F,	// position of symbol-space between letters
	0xC0,	// count of chars
	0x20,	// ascii char offset
	0x40,	// non-ascii char offset

	// char widths
	0x0A, 0x02, 0x06, 0x0A, 0x0A, 0x0A, 0x0A, 0x02, 0x05, 0x05, 0x08, 0x0A, 0x03, 0x0A, 0x02, 0x0A,
	0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x02, 0x03, 0x06, 0x0A, 0x06, 0x0A,
	0x0B, 0x09, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x06, 0x0A, 0x0A, 0x0A, 0x0B, 0x0A, 0x0A,
	0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x09, 0x0B, 0x0A, 0x0A, 0x0A, 0x04, 0x0A, 0x04, 0x09, 0x0A,
	0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x09, 0x09, 0x02, 0x07, 0x09, 0x06, 0x0A, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x08, 0x09, 0x09, 0x0B, 0x09, 0x09, 0x09, 0x05, 0x02, 0x05, 0x0A, 0x02,
	0x0A, 0x09, 0x0A, 0x0C, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0B, 0x0B, 0x0A,
	0x0A, 0x0A, 0x09, 0x09, 0x08, 0x09, 0x0A, 0x09, 0x09, 0x09, 0x08, 0x09, 0x09, 0x09, 0x09, 0x08,
	0x09, 0x0A, 0x09, 0x0A, 0x08, 0x09, 0x0A, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0C, 0x0B, 0x0C, 0x0A, 0x0A, 0x0A, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A,


	// font data
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 32  space
	0xF8, 0xF8, 0xFF, 0xFF, 0x33, 0x33, // 33  !
	0x78, 0x38, 0x00, 0x00, 0x78, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34  "
	0x00, 0x00, 0xF0, 0xF0, 0x00, 0x00, 0xF0, 0xF0, 0x00, 0x00, 0x83, 0x83, 0xFF, 0xFF, 0x83, 0x83, 0xFF, 0xFF, 0x83, 0x83, 0x01, 0x01, 0x1F, 0x1F, 0x01, 0x01, 0x1F, 0x1F, 0x01, 0x01, // 35  #
	0xE0, 0xF0, 0x38, 0x18, 0xFC, 0xFC, 0x18, 0x38, 0xF0, 0xE0, 0x01, 0x03, 0x07, 0x0E, 0xFF, 0xFF, 0x70, 0xE0, 0xC0, 0x80, 0x0E, 0x1E, 0x38, 0x30, 0x7F, 0x7F, 0x30, 0x38, 0x1F, 0x0F, // 36  dollar
	0x70, 0xD8, 0x88, 0xD8, 0x70, 0x00, 0x80, 0xE0, 0xF8, 0x38, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x3E, 0x0F, 0x03, 0x00, 0x00, 0x38, 0x3E, 0x0F, 0x03, 0x00, 0x1C, 0x36, 0x22, 0x36, 0x1C, // 37  %
	0x00, 0xE0, 0xF0, 0x38, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x00, 0xC0, 0xE3, 0x77, 0x3E, 0x7C, 0xFE, 0xC7, 0x03, 0x01, 0x00, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x39, 0x1F, 0x0F, 0x3F, 0x3B, // 38  &
	0x78, 0x38, 0x00, 0x00, 0x00, 0x00, // 39  '
	0x00, 0xC0, 0xF0, 0x78, 0x18, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x3C, 0x30, // 40  (
	0x18, 0x78, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x30, 0x3C, 0x1F, 0x07, 0x01, // 41  )
	0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x66, 0x66, 0x3C, 0xFF, 0xFF, 0x3C, 0x66, 0x66, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, // 42  *
	0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, // 43  +
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x70, 0x30, // 44  ,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 45  –
	0x00, 0x00, 0x00, 0x00, 0x30, 0x30, // 46  .
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x38, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x3E, 0x0F, 0x03, 0x00, 0x00, 0x38, 0x3E, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 47  /
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0xFF, 0xFF, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 48  0
	0x00, 0x00, 0x60, 0x60, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x3F, 0x3F, 0x30, 0x30, 0x00, 0x00, // 49  1
	0x60, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1F, 0x0F, 0x3C, 0x3E, 0x37, 0x33, 0x31, 0x30, 0x30, 0x30, 0x30, 0x30, // 50  2
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x3C, 0x7E, 0xE7, 0xC3, 0x0E, 0x1E, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 51  3
	0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0xF8, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x9E, 0x87, 0x81, 0xFF, 0xFF, 0x80, 0x80, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3F, 0x3F, 0x01, 0x01, // 52  4
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3F, 0x3F, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0xF8, 0xF0, 0x0E, 0x1E, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x07, // 53  5
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0xF8, 0xF0, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 54  6
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x98, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0x3E, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x01, 0x00, 0x00, 0x00, 0x00, // 55  7
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0xC3, 0xE7, 0x7E, 0x3C, 0x18, 0x18, 0x3C, 0x7E, 0xE7, 0xC3, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 56  8
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x18, 0xFF, 0xFF, 0x0E, 0x1E, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 57  9
	0xC0, 0xC0, 0x00, 0x00, 0x30, 0x30, // 58  "
	0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x70, 0x30, // 59  ;
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x7C, 0xEE, 0xC7, 0x83, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, // 60  <
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61  =
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xC7, 0xEE, 0x7C, 0x38, 0x10, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, // 62  >
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0x78, 0x1C, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, // 63  ?
	0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xFE, 0xFF, 0x03, 0xF9, 0xFC, 0x9C, 0xF8, 0xFC, 0x01, 0xFF, 0xFF, 0x07, 0x0F, 0x1C, 0x39, 0x33, 0x33, 0x31, 0x33, 0x33, 0x3B, 0x19, // 64  @
	0x00, 0xC0, 0xE0, 0x70, 0x38, 0x70, 0xE0, 0xC0, 0x00, 0xFF, 0xFF, 0x31, 0x30, 0x30, 0x30, 0x31, 0xFF, 0xFF, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 65  A
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x00, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x1C, 0x3E, 0x77, 0xE3, 0xC0, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 66  B
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0x70, 0x60, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1E, 0x0E, // 67  C
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 68  D
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, // 69  E
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70  F
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0x70, 0x60, 0xFF, 0xFF, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 71  G
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 72  H
	0x18, 0x18, 0xF8, 0xF8, 0x18, 0x18, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x30, 0x30, 0x3F, 0x3F, 0x30, 0x30, // 73  I
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0E, 0x1E, 0x38, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, // 74  J
	0xF8, 0xF8, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x18, 0xFF, 0xFF, 0xEE, 0xC7, 0x83, 0x01, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x30, // 75  K
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, // 76  L
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xFF, 0xFF, 0x0F, 0x3C, 0xF0, 0xC0, 0xF0, 0x3C, 0x0F, 0xFF, 0xFF, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 77  M
	0xF8, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xFF, 0xFF, 0x03, 0x0F, 0x3C, 0xF0, 0xC0, 0x00, 0xFF, 0xFF, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x3F, 0x3F, // 78  N
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 79  O
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80  P
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x36, 0x3E, 0x1C, 0x3F, 0x37, // 81  Q
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0xF0, 0xF0, 0xB0, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x3F, 0x3F, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x30, // 82  R
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80, 0x0C, 0x1C, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 83  S
	0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, // 84  T
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 85  U
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x07, 0x3F, 0xFC, 0xE0, 0x00, 0xE0, 0xFC, 0x3F, 0x07, 0x00, 0x00, 0x01, 0x0F, 0x3E, 0x0F, 0x01, 0x00, 0x00, // 86  V
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x1F, 0xFF, 0xF0, 0x00, 0xF0, 0xFE, 0xF0, 0x00, 0xF0, 0xFF, 0x1F, 0x00, 0x01, 0x0F, 0x3E, 0x0F, 0x03, 0x0F, 0x3E, 0x0F, 0x01, 0x00, // 87  W
	0x38, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x38, 0x00, 0x00, 0x83, 0xEF, 0xFE, 0xFE, 0xEF, 0x83, 0x00, 0x00, 0x38, 0x3E, 0x0F, 0x03, 0x00, 0x00, 0x03, 0x0F, 0x3E, 0x38, // 88  X
	0xF8, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF8, 0xF8, 0x00, 0x03, 0x0F, 0x3E, 0xF8, 0xF8, 0x3E, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, // 89  Y
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x98, 0xF8, 0xF8, 0x38, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x3E, 0x0F, 0x03, 0x00, 0x00, 0x38, 0x3E, 0x3F, 0x33, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, // 90  Z
	0xF8, 0xF8, 0x18, 0x18, 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, // 91  [
	0x00, 0x80, 0xC0, 0xC0, 0xF8, 0xF8, 0xC0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0x01, 0x00, 0xFF, 0xFF, 0x00, 0x01, 0xC7, 0xC7, 0x01, 0x03, 0x07, 0x06, 0x3F, 0x3F, 0x06, 0x07, 0x03, 0x01, // 92  ¢
	0x18, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x30, 0x30, 0x3F, 0x3F, // 93  ]
	0x30, 0x38, 0x1C, 0x0E, 0x07, 0x0E, 0x1C, 0x38, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94  ^
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, // 95  _
	0x0E, 0x1E, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 96  `
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xCC, 0xEE, 0x66, 0x66, 0x66, 0x6E, 0xFE, 0xFC, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x18, 0x3F, 0x3F, // 97  a
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x1C, 0x0E, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x3F, 0x3F, 0x18, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 98  b
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0x18, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x0C, // 99  c
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0x1C, 0xFF, 0xFF, 0x0F, 0x1F, 0x30, 0x30, 0x30, 0x30, 0x18, 0x3F, 0x3F, // 100  d
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x8E, 0x86, 0x86, 0x86, 0xCE, 0xFC, 0x78, 0x0F, 0x1F, 0x39, 0x31, 0x31, 0x31, 0x39, 0x1C, 0x0C, // 101  e
	0x00, 0xE0, 0xF0, 0x38, 0x18, 0x38, 0x70, 0x60, 0x0C, 0xFF, 0xFF, 0x0C, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, // 102  f
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0x0C, 0xFE, 0xFE, 0x03, 0x67, 0xEE, 0xCC, 0xCC, 0xCC, 0xEC, 0x7F, 0x3F, // 103  g
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x0E, 0xFE, 0xFC, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 104  h
	0x60, 0x60, 0xFE, 0xFE, 0x3F, 0x3F, // 105  i
	0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x06, 0xFE, 0xFE, 0x0C, 0x1C, 0x38, 0x30, 0x38, 0x1F, 0x0F, // 106  j
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x06, 0x3F, 0x3F, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x30, // 107  k
	0x18, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x30, 0x30, 0x3F, 0x3F, 0x30, 0x30, // 108  l
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x0C, 0x06, 0xFE, 0xFC, 0x0E, 0x06, 0xFE, 0xFC, 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x3F, // 109  m
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x0C, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 110  n
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 111  o
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0xFF, 0xFF, 0x18, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 112  p
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0x0C, 0xFE, 0xFE, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x18, 0xFF, 0xFF, // 113  q
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x38, 0x1C, 0x0E, 0x06, 0x0E, 0x1C, 0x18, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 114  r
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x7C, 0x6E, 0xC6, 0xC6, 0x86, 0x8E, 0x1C, 0x18, 0x0C, 0x1C, 0x30, 0x30, 0x30, 0x31, 0x3B, 0x1F, 0x0E, // 115  s
	0x00, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0xFF, 0xFF, 0x0C, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x38, 0x30, 0x38, 0x1C, 0x0C, // 116  t
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x38, 0x1C, 0x3F, 0x3F, // 117  u
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0xFE, 0xE0, 0x80, 0x00, 0x80, 0xE0, 0xFE, 0x3E, 0x00, 0x00, 0x03, 0x0F, 0x3E, 0x0F, 0x03, 0x00, 0x00, // 118  v
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x80, 0xE0, 0x80, 0x00, 0x00, 0xFE, 0xFE, 0x03, 0x0F, 0x3C, 0x0E, 0x07, 0x01, 0x07, 0x0E, 0x3C, 0x0F, 0x03, // 119  w
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x1E, 0x78, 0xE0, 0xC0, 0xE0, 0x78, 0x1E, 0x06, 0x30, 0x3C, 0x0F, 0x03, 0x01, 0x03, 0x0F, 0x3C, 0x30, // 120  x
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x03, 0x67, 0xEE, 0xCC, 0xCC, 0xCC, 0xE6, 0x7F, 0x3F, // 121  y
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x86, 0xC6, 0xE6, 0x76, 0x3E, 0x1E, 0x3C, 0x3E, 0x37, 0x33, 0x31, 0x30, 0x30, 0x30, 0x30, // 122  z
	0x00, 0x00, 0xF0, 0xF8, 0x18, 0x10, 0x38, 0xFF, 0xEF, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x30, // 123  {
	0xF8, 0xF8, 0xFF, 0xFF, 0x3F, 0x3F, // 124  |
	0x00, 0x00, 0xF8, 0xFC, 0x1C, 0x10, 0x38, 0xFF, 0xEF, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x30, // 125  }
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1C, 0x0C, 0x0C, 0x1C, 0x38, 0x30, 0x30, 0x38, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126  ~
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 127  ❐
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0xF8, 0xF0, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 128  Б
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 129  Г
	0xF8, 0xF8, 0x1B, 0x1B, 0x18, 0x18, 0x1B, 0x1B, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, // 130  Ё
	0x38, 0xF8, 0xE0, 0x80, 0x00, 0xF8, 0xF8, 0x00, 0x80, 0xE0, 0xF8, 0x38, 0x00, 0x00, 0x83, 0xEF, 0xFE, 0xFF, 0xFF, 0xFE, 0xE7, 0x83, 0x00, 0x00, 0x38, 0x3E, 0x0F, 0x03, 0x00, 0x3F, 0x3F, 0x00, 0x03, 0x0F, 0x3E, 0x38, // 131  Ж
	0x60, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1C, 0x3E, 0x77, 0xE3, 0xC1, 0x0C, 0x1C, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 132  З
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0xF8, 0xFF, 0xFF, 0x80, 0xE0, 0xF8, 0x3E, 0x0F, 0x03, 0xFF, 0xFF, 0x3F, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 133  И
	0xF8, 0xF9, 0x03, 0x06, 0x04, 0x04, 0x86, 0xE3, 0xF9, 0xF8, 0xFF, 0xFF, 0x80, 0xE0, 0xF8, 0x3E, 0x0F, 0x03, 0xFF, 0xFF, 0x3F, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 134  Й
	0x00, 0x00, 0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 135  Л
	0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 136  П
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0xFF, 0xFF, 0x18, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 137  У
	0xE0, 0xF0, 0x38, 0x18, 0xFE, 0xFE, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x1F, 0x38, 0x30, 0xFF, 0xFF, 0x30, 0x38, 0x1F, 0x0F, // 138  Ф
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 139  Ч
	0xF8, 0xF8, 0x00, 0x00, 0xF8, 0xF8, 0x00, 0x00, 0xF8, 0xF8, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x3F, 0x3F, 0x30, 0x30, 0x3F, 0x3F, 0x30, 0x30, 0x3F, 0x3F, // 140  Ш
	0x18, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 141  Ъ
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x00, 0xFF, 0xFF, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x3F, 0x3F, // 142  Ы
	0x60, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x0C, 0x1C, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 143  Э
	0xF8, 0xF8, 0x00, 0xE0, 0xF0, 0x38, 0x18, 0x38, 0xF0, 0xE0, 0xFF, 0xFF, 0x18, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3F, 0x3F, 0x00, 0x0F, 0x1F, 0x38, 0x30, 0x38, 0x1F, 0x0F, // 144  Ю
	0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0xB0, 0xF0, 0xF0, 0xFF, 0xFF, 0x30, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x01, 0x00, 0x3F, 0x3F, // 145  Я
	0x00, 0x00, 0xE0, 0xF0, 0xB8, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xFC, 0x0E, 0x07, 0x07, 0x06, 0x0E, 0xFC, 0xF8, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 146  б
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xEE, 0xFC, 0xB8, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1F, 0x0F, // 147  в
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 148  г
	0x00, 0x00, 0xC0, 0xC0, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0xF8, 0xFC, 0x8E, 0x86, 0x86, 0x86, 0xCE, 0xFC, 0x78, 0x0F, 0x1F, 0x39, 0x31, 0x31, 0x31, 0x39, 0x1C, 0x0C, // 149  ё
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x1E, 0x38, 0x70, 0xFE, 0xFE, 0x70, 0x38, 0x1E, 0x0E, 0x38, 0x3C, 0x0E, 0x07, 0x3F, 0x3F, 0x07, 0x0E, 0x3C, 0x38, // 150  ж
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1C, 0x0E, 0x06, 0x86, 0xC6, 0xEE, 0x7C, 0x38, 0x0C, 0x1C, 0x38, 0x30, 0x30, 0x31, 0x3B, 0x1F, 0x0E, // 151  з
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0xFE, 0xFE, 0x3F, 0x3F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x3F, 0x3F, // 152  и
	0x00, 0x40, 0xC0, 0x80, 0x00, 0x80, 0xC0, 0x40, 0x00, 0xFE, 0xFE, 0x00, 0x81, 0xC1, 0xE1, 0x70, 0xFE, 0xFE, 0x3F, 0x3F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x3F, 0x3F, // 153  й
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x06, 0x3F, 0x3F, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x30, // 154  к
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x0E, 0x06, 0x06, 0xFE, 0xFE, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 155  л
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xF0, 0xC0, 0x00, 0xC0, 0xF0, 0xFE, 0xFE, 0x3F, 0x3F, 0x00, 0x03, 0x0F, 0x03, 0x00, 0x3F, 0x3F, // 156  м
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFE, 0xFE, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 157  н
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, // 158  п
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, // 159  т
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xFE, 0xC0, 0x80, 0x80, 0x80, 0x80, 0xFE, 0xFE, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3F, 0x3F, // 160  ч
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0xFE, 0xFE, 0x3F, 0x3F, 0x30, 0x30, 0x3F, 0x3F, 0x30, 0x30, 0x3F, 0x3F, // 161  ш
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0xFE, 0xFE, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 162  ъ
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0xFE, 0xFE, 0x3F, 0x3F, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x3F, 0x3F, // 163  ы
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 164  ь
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1C, 0x0E, 0xC6, 0xC6, 0xC6, 0xCE, 0xFC, 0xF8, 0x0C, 0x1C, 0x38, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, // 165  э
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xC0, 0xF8, 0xFC, 0x0E, 0x06, 0x0E, 0xFC, 0xF8, 0x3F, 0x3F, 0x00, 0x0F, 0x1F, 0x38, 0x30, 0x38, 0x1F, 0x0F, // 166  ю
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xFC, 0xCE, 0x86, 0x86, 0x86, 0xFE, 0xFE, 0x30, 0x38, 0x1D, 0x0F, 0x07, 0x03, 0x3F, 0x3F, // 167  я
	0x00, 0xE0, 0xF0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xF0, 0xFF, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3F, 0xFF, 0xF0, // 192  Д
	0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3F, 0x3F, 0xF0, 0xF0, // 193  Ц
	0xF8, 0xF8, 0x00, 0x00, 0xF8, 0xF8, 0x00, 0x00, 0xF8, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x3F, 0x3F, 0x30, 0x30, 0x3F, 0x3F, 0xF0, 0xF0, // 194  Щ
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x00, 0xF0, 0xFF, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x3F, 0xFF, 0xF0, // 195  д
	0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0x0E, 0x06, 0xFF, 0xFF, 0x06, 0x0E, 0xFC, 0xF8, 0x0F, 0x1F, 0x38, 0x30, 0xFF, 0xFF, 0x30, 0x38, 0x1F, 0x0F, // 196  ф
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3F, 0xFF, 0xF0, // 197  ц
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x3F, 0x3F, 0x30, 0x30, 0x3F, 0xFF, 0xF0, // 198  щ
	0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F // 223  fillrect



};