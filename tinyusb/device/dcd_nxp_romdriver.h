/**************************************************************************/
/*!
    @file     dcd_nxp_romdriver.h
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
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    This file is part of the tinyusb stack.
*/
/**************************************************************************/

/** \ingroup TBD
 *  \defgroup TBD
 *  \brief TBD
 *
 *  @{
 */

#ifndef _TUSB_DCD_NXP_ROMDRIVER_H_
#define _TUSB_DCD_NXP_ROMDRIVER_H_

#include "common/common.h"

#ifdef __cplusplus
 extern "C" {
#endif


#define USB_MAX_IF_NUM          8 // maximum interface number supported, should be fixed to 8

#if (MCU == MCU_LPC18XX) || (MCU == MCU_LPC43XX)
  #define ROM_API                 ( * ((USBD_API_T**) NXP_ROMDRIVER_FUNCTION_ADDR) )
  #define USB_MAX_EP_NUM          6
#elif (MCU == MCU_LPC13UXX) || (MCU == MCU_LPC11UXX)
  #define ROM_API                 ( * (*((USBD_API_T***) NXP_ROMDRIVER_FUNCTION_ADDR)) )
  #define USB_MAX_EP_NUM          5
#else
  #error forgot something, thach ?
#endif

#include "romdriver/mw_usbd_rom_api.h"

extern USBD_HANDLE_T romdriver_hdl;

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_DCD_NXP_ROMDRIVER_H_ */

/** @} */
