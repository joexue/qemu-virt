/*
 * $QNXLicenseC: 
 * Copyright 2007, 2008, QNX Software Systems.  
 *  
 * Licensed under the Apache License, Version 2.0 (the "License"). You  
 * may not reproduce, modify or distribute this software except in  
 * compliance with the License. You may obtain a copy of the License  
 * at: http://www.apache.org/licenses/LICENSE-2.0  
 *  
 * Unless required by applicable law or agreed to in writing, software  
 * distributed under the License is distributed on an "AS IS" basis,  
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied. 
 * 
 * This file may contain contributions from others, either as  
 * contributors under the License or as licensors under other terms.   
 * Please review this entire file for other proprietary rights or license  
 * notices, as well as the QNX Development Suite License Guide at  
 * http://licensing.qnx.com/license-guide/ for other information. 
 * $ 
 */

#include <startup.h>
#include <hw/hwinfo_private.h>
#include <drvr/hwinfo.h>


/*******************************************************************************
* hwidev_add_uart
* 
* See sys/hwinfo.h for interface description
* 
* Returns: the offset in the hwinfo section of the added device or HWI_NULL_OFF
* 			on error
*/ 
unsigned hwidev_add_uart(const char *device_name, hwiattr_uart_t *attr, unsigned bus_hwi_off)
{
	/* we use the (unused) 'device.pnpid' as the device class identifier */ 
	unsigned hwi_off = hwidev_add(device_name, hwi_devclass_UART, bus_hwi_off);

	if ((hwi_off != HWI_NULL_OFF) && (attr != NULL))
	{
		unsigned i;
		hwitag_add_common(hwi_off, &attr->common);
		for (i=0; i<attr->num_clks; i++)
			hwitag_add_inputclk(hwi_off, 0, 1);		// make divisor 1, just in case ;)
	}
	return hwi_off;
}
