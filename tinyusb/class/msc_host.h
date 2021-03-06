/**************************************************************************/
/*!
    @file     msc_host.h
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

/** \ingroup TBD
 *  \defgroup TBD
 *  \brief TBD
 *
 *  @{
 */

#ifndef _TUSB_MSC_HOST_H_
#define _TUSB_MSC_HOST_H_

#include "common/common.h"
#include "host/usbh.h"
#include "msc.h"

#ifdef __cplusplus
 extern "C" {
#endif


//--------------------------------------------------------------------+
// MASS STORAGE Application API
//--------------------------------------------------------------------+
bool          tusbh_msc_scsi_is_supported(uint8_t dev_addr) ATTR_PURE ATTR_WARN_UNUSED_RESULT;
tusb_interface_status_t tusbh_msc_scsi_status(uint8_t dev_addr, uint8_t instance_num) ATTR_WARN_UNUSED_RESULT;

tusb_error_t  tusbh_msc_scsi_inquiry(uint8_t dev_addr, uint8_t instance_num, msc_scsi_inquiry_t * p_inquiry_data) ATTR_WARN_UNUSED_RESULT;
tusb_error_t  tusbh_msc_scsi_test_unit_ready(uint8_t dev_addr, uint8_t instance_num) ATTR_WARN_UNUSED_RESULT;
tusb_error_t  tusbh_msc_scsi_read_capacity10(uint8_t dev_addr, uint8_t instance_num, msc_scsi_read_capacity10_t * p_buffer) ATTR_WARN_UNUSED_RESULT;
tusb_error_t  tusbh_msc_scsi_read10(uint8_t dev_addr, uint8_t instance_num, void * p_buffer, uint32_t length) ATTR_WARN_UNUSED_RESULT;
tusb_error_t  tusbh_msc_scsi_write10(uint8_t dev_addr, uint8_t instance_num, void const * p_data, uint32_t length) ATTR_WARN_UNUSED_RESULT;

//--------------------------------------------------------------------+
// USBH-CLASS DRIVER API
//--------------------------------------------------------------------+
#ifdef _TINY_USB_SOURCE_FILE_

void         msch_init(void);
tusb_error_t msch_open_subtask(uint8_t dev_addr, tusb_descriptor_interface_t const *descriptor, uint16_t *p_length) ATTR_WARN_UNUSED_RESULT;
void         msch_isr(pipe_handle_t pipe_hdl, tusb_event_t event);
void         msch_close(uint8_t dev_addr);
#endif

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_MSC_HOST_H_ */

/** @} */
