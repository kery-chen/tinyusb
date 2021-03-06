/**************************************************************************/
/*!
    @file     hid.h
    @author   hathach (tinyusb.org)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, hathach (tinyusb.org)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    This file is part of the tinyusb stack.
*/
/**************************************************************************/

/** 
 *  \addtogroup Group_ClassDriver Class Driver
 *  @{
 *  \defgroup Group_HID Human Interface Device
 *  @{
 */

#ifndef _TUSB_HID_H_
#define _TUSB_HID_H_

#include "common/common.h"

#ifdef __cplusplus
 extern "C" {
#endif

enum {
  HID_SUBCLASS_NONE = 0,
  HID_SUBCLASS_BOOT = 1
};

enum {
  HID_PROTOCOL_NONE     = 0,
  HID_PROTOCOL_KEYBOARD = 1,
  HID_PROTOCOL_MOUSE    = 2
};

enum {
  HID_DESC_TYPE_HID      = 0x21,
  HID_DESC_TYPE_REPORT   = 0x22,
  HID_DESC_TYPE_PHYSICAL = 0x23
};

enum {
  HID_REQUEST_REPORT_INPUT = 1,
  HID_REQUEST_REPORT_OUTPUT,
  HID_REQUEST_REPORT_FEATURE
};

enum {
  HID_REQUEST_CONTROL_GET_REPORT   = 0x01,
  HID_REQUEST_CONTROL_GET_IDLE     = 0x02,
  HID_REQUEST_CONTROL_GET_PROTOCOL = 0x03,
  HID_REQUEST_CONTROL_SET_REPORT   = 0x09,
  HID_REQUEST_CONTROL_SET_IDLE     = 0x0a,
  HID_REQUEST_CONTROL_SET_PROTOCOL = 0x0b
};

typedef ATTR_PREPACKED struct ATTR_PACKED {
  uint8_t  bLength;         /**< Numeric expression that is the total size of the HID descriptor */
  uint8_t  bDescriptorType; /**< Constant name specifying type of HID descriptor. */

  uint16_t bcdHID;          /**< Numeric expression identifying the HID Class Specification release */
  uint8_t  bCountryCode;    /**< Numeric expression identifying country code of the localized hardware.  */
  uint8_t  bNumDescriptors; /**< Numeric expression specifying the number of class descriptors */

  uint8_t  bReportType;     /**< Type of HID class report. */
  uint16_t wReportLength;   /**< the total size of the Report descriptor. */
} tusb_hid_descriptor_hid_t;

/**
 *  \brief Standard HID Boot Protocol Mouse Report.
 *
 *  Type define for a standard Boot Protocol Mouse report
 */
typedef ATTR_PACKED_STRUCT(struct)
{
  uint8_t buttons; /**< buttons mask for currently pressed buttons in the mouse. */
  int8_t  x; /**< Current delta x movement of the mouse. */
  int8_t  y; /**< Current delta y movement on the mouse. */
} tusb_mouse_report_t;

/**
 *  \brief Standard HID Boot Protocol Keyboard Report.
 *
 *  Type define for a standard Boot Protocol Keyboard report
 */
typedef ATTR_PACKED_STRUCT(struct)
{
  uint8_t modifier; /**< Keyboard modifier byte, indicating pressed modifier keys (a combination of HID_KEYBOARD_MODIFER_* masks). */
  uint8_t reserved; /**< Reserved for OEM use, always set to 0. */
  uint8_t keycode[6]; /**< Key codes of the currently pressed keys. */
} tusb_keyboard_report_t;

/**
 * \brief buttons codes for HID mouse
 */
enum {
	HID_MOUSEBUTTON_LEFT   = BIT_(0),
	HID_MOUSEBUTTON_RIGHT  = BIT_(1),
	HID_MOUSEBUTTON_MIDDLE = BIT_(2)
};

/**
 * \brief KB modifier codes for HID KB
 */
enum {
	KEYBOARD_MODIFIER_LEFTCTRL   = BIT_(0),
	KEYBOARD_MODIFIER_LEFTSHIFT  = BIT_(1),
	KEYBOARD_MODIFIER_LEFTALT    = BIT_(2),
	KEYBOARD_MODIFIER_LEFTGUI    = BIT_(3),
	KEYBOARD_MODIFIER_RIGHTCTRL  = BIT_(4),
	KEYBOARD_MODIFIER_RIGHTSHIFT = BIT_(5),
	KEYBOARD_MODIFIER_RIGHTALT   = BIT_(6),
	KEYBOARD_MODIFIER_RIGHTGUI   = BIT_(7)
};

#define HID_KEYCODE_TABLE(ENTRY) \
    ENTRY( 0x04, 'a', 'A' )\
    ENTRY( 0x05, 'b', 'B' )\
    ENTRY( 0x06, 'c', 'C' )\
    ENTRY( 0x07, 'd', 'D' )\
    ENTRY( 0x08, 'e', 'E' )\
    ENTRY( 0x09, 'f', 'F' )\
    ENTRY( 0x0a, 'g', 'G' )\
    ENTRY( 0x0b, 'h', 'H' )\
    ENTRY( 0x0c, 'i', 'I' )\
    ENTRY( 0x0d, 'j', 'J' )\
    ENTRY( 0x0e, 'k', 'K' )\
    ENTRY( 0x0f, 'l', 'L' )\
    \
    ENTRY( 0x10, 'm', 'M' )\
    ENTRY( 0x11, 'n', 'N' )\
    ENTRY( 0x12, 'o', 'O' )\
    ENTRY( 0x13, 'p', 'P' )\
    ENTRY( 0x14, 'q', 'Q' )\
    ENTRY( 0x15, 'r', 'R' )\
    ENTRY( 0x16, 's', 'S' )\
    ENTRY( 0x17, 't', 'T' )\
    ENTRY( 0x18, 'u', 'U' )\
    ENTRY( 0x19, 'v', 'V' )\
    ENTRY( 0x1a, 'w', 'W' )\
    ENTRY( 0x1b, 'x', 'X' )\
    ENTRY( 0x1c, 'y', 'Y' )\
    ENTRY( 0x1d, 'z', 'Z' )\
    ENTRY( 0x1e, '1', '!' )\
    ENTRY( 0x1f, '2', '@' )\
    \
    ENTRY( 0x20, '3', '#' )\
    ENTRY( 0x21, '4', '$' )\
    ENTRY( 0x22, '5', '%' )\
    ENTRY( 0x23, '6', '^' )\
    ENTRY( 0x24, '7', '&' )\
    ENTRY( 0x25, '8', '*' )\
    ENTRY( 0x26, '9', '(' )\
    ENTRY( 0x27, '0', ')' )\
    ENTRY( 0x28, '\r', '\r' )\
    ENTRY( 0x29, '\e', '\e' )\
    ENTRY( 0x2a, '\b', '\b' )\
    ENTRY( 0x2b, '\t', '\t' )\
    ENTRY( 0x2c, ' ', ' '  )\
    ENTRY( 0x2d, '-', '_' )\
    ENTRY( 0x2e, '=', '+' )\
    ENTRY( 0x2f, '[', '{' )\
    \
    ENTRY( 0x30, ']', '}' )\
    ENTRY( 0x31, '\\', '|' )\
    ENTRY( 0x32, '#', '~' ) /* TODO non-US keyboard */ \
    ENTRY( 0x33, ';', ':' )\
    ENTRY( 0x34, '\'', '\"' )\
    ENTRY( 0x35, 0, 0 )\
    ENTRY( 0x36, ',', '<' )\
    ENTRY( 0x37, '.', '>' )\
    ENTRY( 0x38, '/', '?' )\
    ENTRY( 0x39, 0, 0 ) /* TODO CapsLock, non-locking key implementation*/ \
    \
    ENTRY( 0x54, '/', '/' )\
    ENTRY( 0x55, '*', '*' )\
    ENTRY( 0x56, '-', '-' )\
    ENTRY( 0x57, '+', '+' )\
    ENTRY( 0x58, '\r', '\r' )\
    ENTRY( 0x59, '1', 0 ) /* numpad1 & end */ \
    ENTRY( 0x5a, '2', 0 )\
    ENTRY( 0x5b, '3', 0 )\
    ENTRY( 0x5c, '4', 0 )\
    ENTRY( 0x5d, '5', '5' )\
    ENTRY( 0x5e, '6', 0 )\
    ENTRY( 0x5f, '7', 0 )\
    ENTRY( 0x60, '8', 0 )\
    ENTRY( 0x61, '9', 0 )\
    ENTRY( 0x62, '0', 0 )\
    ENTRY( 0x63, '0', 0 )\
    \
    ENTRY( 0x67, '=', '=' )\

// TODO HID complete keycode table

//enum
//{
//  KEYBOARD_KEYCODE_A     = 0x04,
//  KEYBOARD_KEYCODE_Z     = 0x1d,
//
//  KEYBOARD_KEYCODE_1     = 0x1e,
//  KEYBOARD_KEYCODE_0     = 0x27,
//
//  KEYBOARD_KEYCODE_ENTER = 0x28,
//  KEYBOARD_KEYCODE_ESCAPE = 0x29,
//  KEYBOARD_KEYCODE_BACKSPACE = 0x2a,
//  KEYBOARD_KEYCODE_TAB = 0x2b,
//  KEYBOARD_KEYCODE_SPACEBAR = 0x2c,
//
//};

/**
 * \brief Local Country code for HID
 */
enum USB_HID_LOCAL_CODE
{
  HID_Local_NotSupported = 0,
  HID_Local_Arabic,
  HID_Local_Belgian,
  HID_Local_Canadian_Bilingual,
  HID_Local_Canadian_French,
  HID_Local_Czech_Republic,
  HID_Local_Danish,
  HID_Local_Finnish,
  HID_Local_French,
  HID_Local_German,
  HID_Local_Greek,
  HID_Local_Hebrew,
  HID_Local_Hungary,
  HID_Local_International,
  HID_Local_Italian,
  HID_Local_Japan_Katakana,
  HID_Local_Korean,
  HID_Local_Latin_American,
  HID_Local_Netherlands_Dutch,
  HID_Local_Norwegian,
  HID_Local_Persian_Farsi,
  HID_Local_Poland,
  HID_Local_Portuguese,
  HID_Local_Russia,
  HID_Local_Slovakia,
  HID_Local_Spanish,
  HID_Local_Swedish,
  HID_Local_Swiss_French,
  HID_Local_Swiss_German,
  HID_Local_Switzerland,
  HID_Local_Taiwan,
  HID_Local_Turkish_Q,
  HID_Local_UK,
  HID_Local_US,
  HID_Local_Yugoslavia,
  HID_Local_Turkish_F
};

//--------------------------------------------------------------------+
// REPORT DESCRIPTOR
//--------------------------------------------------------------------+
//------------- ITEM & TAG -------------//
#define HID_REPORT_DATA_0(data)
#define HID_REPORT_DATA_1(data) , data
#define HID_REPORT_DATA_2(data) , U16_TO_U8S_LE(data)
#define HID_REPORT_DATA_3(data) , U32_TO_U8S_LE(data)

#define HID_REPORT_ITEM(data, tag, type, size) \
  ((tag << 4) | (type << 2) | size) HID_REPORT_DATA_##size(data)

#define RI_TYPE_MAIN   0
#define RI_TYPE_GLOBAL 1
#define RI_TYPE_LOCAL  2

//------------- MAIN ITEMS 6.2.2.4 -------------//
#define HID_INPUT(x)           HID_REPORT_ITEM(x, 8, RI_TYPE_MAIN, 1)
#define HID_OUTPUT(x)          HID_REPORT_ITEM(x, 9, RI_TYPE_MAIN, 1)
#define HID_COLLECTION(x)      HID_REPORT_ITEM(x, 10, RI_TYPE_MAIN, 1)
#define HID_FEATURE(x)         HID_REPORT_ITEM(x, 11, RI_TYPE_MAIN, 1)
#define HID_COLLECTION_END     HID_REPORT_ITEM(x, 12, RI_TYPE_MAIN, 0)

//------------- INPUT, OUTPUT, FEATURE 6.2.2.5 -------------//
#define HID_DATA             (0<<0)
#define HID_CONSTANT         (1<<0)

#define HID_ARRAY            (0<<1)
#define HID_VARIABLE         (1<<1)

#define HID_ABSOLUTE         (0<<2)
#define HID_RELATIVE         (1<<2)

#define HID_WRAP_NO          (0<<3)
#define HID_WRAP             (1<<3)

#define HID_LINEAR           (0<<4)
#define HID_NONLINEAR        (1<<4)

#define HID_PREFERRED_STATE  (0<<5)
#define HID_PREFERRED_NO     (1<<5)

#define HID_NO_NULL_POSITION (0<<6)
#define HID_NULL_STATE       (1<<6)

#define HID_NON_VOLATILE     (0<<7)
#define HID_VOLATILE         (1<<7)

#define HID_BITFIELD         (0<<8)
#define HID_BUFFERED_BYTES   (1<<8)

//------------- COLLECTION ITEM 6.2.2.6 -------------//
enum {
  HID_COLLECTION_PHYSICAL = 0,
  HID_COLLECTION_APPLICATION,
  HID_COLLECTION_LOGICAL,
  HID_COLLECTION_REPORT,
  HID_COLLECTION_NAMED_ARRAY,
  HID_COLLECTION_USAGE_SWITCH,
  HID_COLLECTION_USAGE_MODIFIER
};

//------------- GLOBAL ITEMS 6.2.2.7 -------------//
#define HID_USAGE_PAGE(x)         HID_REPORT_ITEM(x, 0, RI_TYPE_GLOBAL, 1)
#define HID_USAGE_PAGE_N(x, n)    HID_REPORT_ITEM(x, 0, RI_TYPE_GLOBAL, n)

#define HID_LOGICAL_MIN(x)        HID_REPORT_ITEM(x, 1, RI_TYPE_GLOBAL, 1)
#define HID_LOGICAL_MIN_N(x, n)   HID_REPORT_ITEM(x, 1, RI_TYPE_GLOBAL, n)

#define HID_LOGICAL_MAX(x)        HID_REPORT_ITEM(x, 2, RI_TYPE_GLOBAL, 1)
#define HID_LOGICAL_MAX_N(x, n)   HID_REPORT_ITEM(x, 2, RI_TYPE_GLOBAL, n)

#define HID_PHYSICAL_MIN(x)       HID_REPORT_ITEM(x, 3, RI_TYPE_GLOBAL, 1)
#define HID_PHYSICAL_MIN_N(x, n)  HID_REPORT_ITEM(x, 3, RI_TYPE_GLOBAL, n)

#define HID_PHYSICAL_MAX(x)       HID_REPORT_ITEM(x, 4, RI_TYPE_GLOBAL, 1)
#define HID_PHYSICAL_MAX_N(x, n)  HID_REPORT_ITEM(x, 4, RI_TYPE_GLOBAL, n)

#define HID_UNIT_EXPONENT(x)      HID_REPORT_ITEM(x, 5, RI_TYPE_GLOBAL, 1)
#define HID_UNIT_EXPONENT_N(x, n) HID_REPORT_ITEM(x, 5, RI_TYPE_GLOBAL, n)

#define HID_UNIT(x)               HID_REPORT_ITEM(x, 6, RI_TYPE_GLOBAL, 1)
#define HID_UNIT_N(x, n)          HID_REPORT_ITEM(x, 6, RI_TYPE_GLOBAL, n)

#define HID_REPORT_SIZE(x)        HID_REPORT_ITEM(x, 7, RI_TYPE_GLOBAL, 1)
#define HID_REPORT_SIZE_N(x, n)   HID_REPORT_ITEM(x, 7, RI_TYPE_GLOBAL, n)

#define HID_REPORT_ID(x)          HID_REPORT_ITEM(x, 8, RI_TYPE_GLOBAL, 1)
#define HID_REPORT_ID_N(x)        HID_REPORT_ITEM(x, 8, RI_TYPE_GLOBAL, n)

#define HID_REPORT_COUNT(x)       HID_REPORT_ITEM(x, 9, RI_TYPE_GLOBAL, 1)
#define HID_REPORT_COUNT_N(x, n)  HID_REPORT_ITEM(x, 9, RI_TYPE_GLOBAL, n)

#define HID_PUSH                  HID_REPORT_ITEM(x, 10, RI_TYPE_GLOBAL, 0)
#define HID_POP                   HID_REPORT_ITEM(x, 11, RI_TYPE_GLOBAL, 0)

//------------- LOCAL ITEMS 6.2.2.8 -------------//
#define HID_USAGE(x)              HID_REPORT_ITEM(x, 0, RI_TYPE_LOCAL, 1)
#define HID_USAGE_N(x, n)         HID_REPORT_ITEM(x, 0, RI_TYPE_LOCAL, n)

#define HID_USAGE_MIN(x)          HID_REPORT_ITEM(x, 1, RI_TYPE_LOCAL, 1)
#define HID_USAGE_MIN_N(x, n)     HID_REPORT_ITEM(x, 1, RI_TYPE_LOCAL, n)

#define HID_USAGE_MAX(x)          HID_REPORT_ITEM(x, 2, RI_TYPE_LOCAL, 1)
#define HID_USAGE_MAX_N(x, n)     HID_REPORT_ITEM(x, 2, RI_TYPE_LOCAL, n)

//--------------------------------------------------------------------+
// Usage Table
//--------------------------------------------------------------------+

/// HID Usage Table - Table 1: Usage Page Summary
enum {
  HID_USAGE_PAGE_DESKTOP         = 0x01,
  HID_USAGE_PAGE_SIMULATE        = 0x02,
  HID_USAGE_PAGE_VIRTUAL_REALITY = 0x03,
  HID_USAGE_PAGE_SPORT           = 0x04,
  HID_USAGE_PAGE_GAME            = 0x05,
  HID_USAGE_PAGE_GENERIC_DEVICE  = 0x06,
  HID_USAGE_PAGE_KEYBOARD        = 0x07,
  HID_USAGE_PAGE_LED             = 0x08,
  HID_USAGE_PAGE_BUTTON          = 0x09,
  HID_USAGE_PAGE_ORDINAL         = 0x0a,
  HID_USAGE_PAGE_TELEPHONY       = 0x0b,
  HID_USAGE_PAGE_CONSUMER        = 0x0c,
  HID_USAGE_PAGE_DIGITIZER       = 0x0d,
  HID_USAGE_PAGE_PID             = 0x0f,
  HID_USAGE_PAGE_UNICODE         = 0x10,
  HID_USAGE_PAGE_ALPHA_DISPLAY   = 0x14,
  HID_USAGE_PAGE_MEDICAL         = 0x40,
  HID_USAGE_PAGE_MONITOR         = 0x80, //0x80 - 0x83
  HID_USAGE_PAGE_POWER           = 0x84, // 0x084 - 0x87
  HID_USAGE_PAGE_BARCODE_SCANNER = 0x8c,
  HID_USAGE_PAGE_SCALE           = 0x8d,
  HID_USAGE_PAGE_MSR             = 0x8e,
  HID_USAGE_PAGE_CAMERA          = 0x90,
  HID_USAGE_PAGE_ARCADE          = 0x91,
  HID_USAGE_PAGE_VENDOR          = 0xFFFF // 0xFF00 - 0xFFFF
};

/// HID Usage Table - Table 6: Generic Desktop Page
enum {
  HID_USAGE_DESKTOP_POINTER                               = 0x01,
  HID_USAGE_DESKTOP_MOUSE                                 = 0x02,
  HID_USAGE_DESKTOP_JOYSTICK                              = 0x04,
  HID_USAGE_DESKTOP_GAMEPAD                               = 0x05,
  HID_USAGE_DESKTOP_KEYBOARD                              = 0x06,
  HID_USAGE_DESKTOP_KEYPAD                                = 0x07,
  HID_USAGE_DESKTOP_MULTI_AXIS_CONTROLLER                 = 0x08,
  HID_USAGE_DESKTOP_TABLET_PC_SYSTEM                      = 0x09,
  HID_USAGE_DESKTOP_X                                     = 0x30,
  HID_USAGE_DESKTOP_Y                                     = 0x31,
  HID_USAGE_DESKTOP_Z                                     = 0x32,
  HID_USAGE_DESKTOP_RX                                    = 0x33,
  HID_USAGE_DESKTOP_RY                                    = 0x34,
  HID_USAGE_DESKTOP_RZ                                    = 0x35,
  HID_USAGE_DESKTOP_SLIDER                                = 0x36,
  HID_USAGE_DESKTOP_DIAL                                  = 0x37,
  HID_USAGE_DESKTOP_WHEEL                                 = 0x38,
  HID_USAGE_DESKTOP_HAT_SWITCH                            = 0x39,
  HID_USAGE_DESKTOP_COUNTED_BUFFER                        = 0x3a,
  HID_USAGE_DESKTOP_BYTE_COUNT                            = 0x3b,
  HID_USAGE_DESKTOP_MOTION_WAKEUP                         = 0x3c,
  HID_USAGE_DESKTOP_START                                 = 0x3d,
  HID_USAGE_DESKTOP_SELECT                                = 0x3e,
  HID_USAGE_DESKTOP_VX                                    = 0x40,
  HID_USAGE_DESKTOP_VY                                    = 0x41,
  HID_USAGE_DESKTOP_VZ                                    = 0x42,
  HID_USAGE_DESKTOP_VBRX                                  = 0x43,
  HID_USAGE_DESKTOP_VBRY                                  = 0x44,
  HID_USAGE_DESKTOP_VBRZ                                  = 0x45,
  HID_USAGE_DESKTOP_VNO                                   = 0x46,
  HID_USAGE_DESKTOP_FEATURE_NOTIFICATION                  = 0x47,
  HID_USAGE_DESKTOP_RESOLUTION_MULTIPLIER                 = 0x48,
  HID_USAGE_DESKTOP_SYSTEM_CONTROL                        = 0x80,
  HID_USAGE_DESKTOP_SYSTEM_POWER_DOWN                     = 0x81,
  HID_USAGE_DESKTOP_SYSTEM_SLEEP                          = 0x82,
  HID_USAGE_DESKTOP_SYSTEM_WAKE_UP                        = 0x83,
  HID_USAGE_DESKTOP_SYSTEM_CONTEXT_MENU                   = 0x84,
  HID_USAGE_DESKTOP_SYSTEM_MAIN_MENU                      = 0x85,
  HID_USAGE_DESKTOP_SYSTEM_APP_MENU                       = 0x86,
  HID_USAGE_DESKTOP_SYSTEM_MENU_HELP                      = 0x87,
  HID_USAGE_DESKTOP_SYSTEM_MENU_EXIT                      = 0x88,
  HID_USAGE_DESKTOP_SYSTEM_MENU_SELECT                    = 0x89,
  HID_USAGE_DESKTOP_SYSTEM_MENU_RIGHT                     = 0x8A,
  HID_USAGE_DESKTOP_SYSTEM_MENU_LEFT                      = 0x8B,
  HID_USAGE_DESKTOP_SYSTEM_MENU_UP                        = 0x8C,
  HID_USAGE_DESKTOP_SYSTEM_MENU_DOWN                      = 0x8D,
  HID_USAGE_DESKTOP_SYSTEM_COLD_RESTART                   = 0x8E,
  HID_USAGE_DESKTOP_SYSTEM_WARM_RESTART                   = 0x8F,
  HID_USAGE_DESKTOP_DPAD_UP                               = 0x90,
  HID_USAGE_DESKTOP_DPAD_DOWN                             = 0x91,
  HID_USAGE_DESKTOP_DPAD_RIGHT                            = 0x92,
  HID_USAGE_DESKTOP_DPAD_LEFT                             = 0x93,
  HID_USAGE_DESKTOP_SYSTEM_DOCK                           = 0xA0,
  HID_USAGE_DESKTOP_SYSTEM_UNDOCK                         = 0xA1,
  HID_USAGE_DESKTOP_SYSTEM_SETUP                          = 0xA2,
  HID_USAGE_DESKTOP_SYSTEM_BREAK                          = 0xA3,
  HID_USAGE_DESKTOP_SYSTEM_DEBUGGER_BREAK                 = 0xA4,
  HID_USAGE_DESKTOP_APPLICATION_BREAK                     = 0xA5,
  HID_USAGE_DESKTOP_APPLICATION_DEBUGGER_BREAK            = 0xA6,
  HID_USAGE_DESKTOP_SYSTEM_SPEAKER_MUTE                   = 0xA7,
  HID_USAGE_DESKTOP_SYSTEM_HIBERNATE                      = 0xA8,
  HID_USAGE_DESKTOP_SYSTEM_DISPLAY_INVERT                 = 0xB0,
  HID_USAGE_DESKTOP_SYSTEM_DISPLAY_INTERNAL               = 0xB1,
  HID_USAGE_DESKTOP_SYSTEM_DISPLAY_EXTERNAL               = 0xB2,
  HID_USAGE_DESKTOP_SYSTEM_DISPLAY_BOTH                   = 0xB3,
  HID_USAGE_DESKTOP_SYSTEM_DISPLAY_DUAL                   = 0xB4,
  HID_USAGE_DESKTOP_SYSTEM_DISPLAY_TOGGLE_INT_EXT         = 0xB5,
  HID_USAGE_DESKTOP_SYSTEM_DISPLAY_SWAP_PRIMARY_SECONDARY = 0xB6,
  HID_USAGE_DESKTOP_SYSTEM_DISPLAY_LCD_AUTOSCALE          = 0xB7
};

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_HID_H__ */

/// @}
/// @}
