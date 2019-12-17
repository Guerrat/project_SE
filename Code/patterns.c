//
// Created by Aurelien on 17/12/2019.
//
#include <avr/pgmspace.h>
#include "patterns.h"

PROGMEM const unsigned char charPatterns[] = {
        0x7F0, 0x880, 0x880, 0x880, 0x7F0, //  A
        0xFF0, 0x910, 0x910, 0x910, 0x6E0, //  B
        0x7E0, 0x810, 0x810, 0x810, 0x420, //  C
        0xFF0, 0x810, 0x810, 0x420, 0x3C0, //  D
        0xFF0, 0x910, 0x910, 0x910, 0x810, //  E
        0xFF0, 0x900, 0x900, 0x900, 0x800, //  F
        0x7E0, 0x810, 0x890, 0x890, 0x4E0, //  G
        0xFF0, 0x100, 0x100, 0x100, 0xFF0, //  H
        0x810, 0x810, 0xFF0, 0x810, 0x810, //  I
        0x060, 0x010, 0x010, 0x010, 0xFE0, //  J
        0xFF0, 0x180, 0x240, 0x420, 0x810, //  K
        0xFF0, 0x010, 0x010, 0x010, 0x010, //  L
        0xFF0, 0x400, 0x300, 0x400, 0xFF0, //  M
        0xFF0, 0x400, 0x300, 0x080, 0xFF0, //  N
        0x7E0, 0x810, 0x810, 0x810, 0x7E0, //  O
        0xFF0, 0x880, 0x880, 0x880, 0x700, //  P
        0x7E0, 0x810, 0x850, 0x820, 0x7D0, //  Q
        0xFF0, 0x880, 0x8C0, 0x8A0, 0x710, //  R
        0x610, 0x910, 0x910, 0x910, 0x8E0, //  S
        0x800, 0x800, 0xFF0, 0x800, 0x800, //  T
        0xFE0, 0x010, 0x010, 0x010, 0xFE0, //  U
        0xF00, 0x0C0, 0x030, 0x0C0, 0xF00, //  V
        0xFF0, 0x020, 0x0C0, 0x020, 0xFF0, //  W
        0xC30, 0x240, 0x180, 0x240, 0xC30, //  X
        0xE00, 0x100, 0x0F0, 0x100, 0xE00, //  Y
        0x830, 0x850, 0x990, 0xA10, 0xC10, //  Z


        0x060, 0x29, 0x29, 0x29, 0x1F, //  a
        0xFF0, 0x09, 0x11, 0x11, 0x0E, //  b
        0x1E0, 0x21, 0x21, 0x21, 0x12, //  c
        0x0E0, 0x11, 0x11, 0x09, 0xFF, //  d
        0x0E0, 0x15, 0x15, 0x15, 0x0C, //  e
        0x080, 0x7F, 0x88, 0x80, 0x40, //  f
        0x300, 0x49, 0x49, 0x49, 0x7E, //  g
        0xFF0, 0x08, 0x10, 0x10, 0x0F, //  h
        0x000, 0x00, 0x5F, 0x00, 0x00, //  i
        0x020, 0x01, 0x21, 0xBE, 0x00, //  j
        0xFF0, 0x04, 0x0A, 0x11, 0x00, //  k
        0x00, 0x81, 0xFF, 0x01, 0x00, //  l
        0x3F, 0x20, 0x18, 0x20, 0x1F, //  m
        0x3F, 0x10, 0x20, 0x20, 0x1F, //  n
        0x0E, 0x11, 0x11, 0x11, 0x0E, //  o
        0x3F, 0x24, 0x24, 0x24, 0x18, //  p
        0x10, 0x28, 0x28, 0x18, 0x3F, //  q
        0x1F, 0x08, 0x10, 0x10, 0x08, //  r
        0x09, 0x15, 0x15, 0x15, 0x02, //  s
        0x20, 0xFE, 0x21, 0x01, 0x02, //  t
        0x1E, 0x01, 0x01, 0x02, 0x1F, //  u
        0x1C, 0x02, 0x01, 0x02, 0x1C, //  v
        0x1E, 0x01, 0x0E, 0x01, 0x1E, //  w
        0x11, 0x0A, 0x04, 0x0A, 0x11, //  x
        0x00, 0x39, 0x05, 0x05, 0x3E, //  y
        0x11, 0x13, 0x15, 0x19, 0x11, //  z
        0x00, 0x41, 0xFF, 0x01, 0x00, //  1
        0x43, 0x85, 0x89, 0x91, 0x61, //  2
        0x42, 0x81, 0x91, 0x91, 0x6E, //  3
        0x18, 0x28, 0x48, 0xFF, 0x08, //  4
        0xF2, 0x91, 0x91, 0x91, 0x8E, //  5
        0x1E, 0x29, 0x49, 0x89, 0x86, //  6
        0x80, 0x8F, 0x90, 0xA0, 0xC0, //  7
        0x6E, 0x91, 0x91, 0x91, 0x6E, //  8
        0x70, 0x89, 0x89, 0x8A, 0x7C, //  9
        0  , 0  , 0  , 0  , 0  ,
        0x60, 0x80, 0x8D, 0x90, 0x60, //  ?
        0x00, 0x00, 0xFD, 0x00, 0x00, //  !
        0x7E, 0x89, 0x91, 0xA1, 0x7E, //  0
        0x66, 0x89, 0x8F, 0x81, 0x7E, //  @
        0x24, 0xFF, 0x24, 0xFF, 0x24, //  #
        0x76, 0x89, 0x95, 0x62, 0x05, //  &
        0x00, 0x3C, 0x42, 0x81, 0x00, //  (
        0x00, 0x81, 0x42, 0x3C, 0x00, //  )
        0x08, 0x08, 0x3E, 0x08, 0x08, //  "+"
        0x08, 0x08, 0x08, 0x08, 0x08, //  -
        0x14, 0x14, 0x14, 0x14, 0x14, //  =
        0x10, 0x10, 0x54, 0x38, 0x10, //  R arrow
        0x08, 0x1C, 0x2A, 0x08, 0x08, //  L arrow
        0x12, 0x2A, 0x7F, 0x2A, 0x24, //  $
        0x44, 0x02, 0x12, 0x02, 0x44, //  smile
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF //  5x8 block
};