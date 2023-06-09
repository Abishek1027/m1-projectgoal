USB abstraction documentation
##########################################
 
.. contents:: Table of Contents

Document History
********************

============= ================= ======== ===========================================
Date          Author            Revision Changes
------------- ----------------- -------- -------------------------------------------
05.06.2023    Aravindh.R        V0.1     Creation of documentation

============= ================= ======== ===========================================

General
********************

Purpose of this Module
==========================
This is an ``USB abstraction`` layer between an application module (this is an example of USB Bootloader protocol, but it should be useable in a generic context) and the hardware dependant layer (in this case the zephyr USB library). It provides generic USB functions and uses read/write functions as an interface to the application module.

Module used for the following Applications
===========================================

Dependencies
=============

Modules dependent on this Module
---------------------------------
``USB Protocol`` module is dependent on ``USB abstraction`` module

Modules this Module depends on
---------------------------------
Not dependent on any modules but dependent on the Zephyr OS including Hardware abstraction and USB driver functionality

Requirement of this module
********************************************

Functional Requirements:
==================================

Functional Requirement 1 init:
-------------------------------
The abstraction layer provides an init function, The key functionalities of init functions are:

- Device binding - get a device pointer (here, we are getting USB device pointer)
- Register a device - registering USB device with appropriate report descriptor (Report descriptor tells about exact functionalities of device) 
- Set protocol code - USB HID Protocol code.
- Init and Enable - Initialize and Enabling it for Working.


Functional Requirement 2 read:
-----------------------------

 .. uml:: uml_diagrams/usb_abstraction_read.puml
 
The abstraction layer provides an read function, The key functionalities are:

- The OutEndpoint Callback is triggered whenever data is available on device Endpoint Buffer
- Data shall read by zephyr-read API. with data payload of 64 Bytes
- In our use case, data to be read with length of 320 Bytes per transfer.
- Timeout - timeout option is available when data is failed to receive within specified time.
- On success the data will be filled on read buffer.

Functional Requirement 3 write:
-------------------------------

 .. uml:: uml_diagrams/usb_abstraction_write.puml
 
The abstraction layer provides Write function, The key functionalities are:

- Write function will be called from application module
- write operation performed by zephyr-write API, with fixed data payload of 64 bytes.


API description
************************

osal_usb_hid_return_t osal_usb_hid_init(void);

osal_usb_hid_return_t osal_usb_hid_write(uint8_t *p_usb_data_write_buffer, uint16_t usb_data_write_length);

osal_usb_hid_return_t osal_usb_hid_read(uint8_t *p_usb_data_read_buffer, uint16_t usb_data_read_length, uint16_t usb_timeout);



API description
==================================

.. doxygengroup:: USB_HID_OS_ABSTRACTION
   :project: doxy_api
   :path: ../doxygen/build/


Function description
*********************

Internal functions
===================

Functions
----------------------------

`int_in_ready_cb()`
^^^^^^^^^^^^^^^^^^^^^^

This function is called when IN-endpoint buffer is cleared, write to the host is sucess when the buffer is empty.

`int_out_ready_cb()`
^^^^^^^^^^^^^^^^^^^^^^

This function is called when OUT-endpoint buffer is full, data is ready to read when the buffer is full.


Release Notes
****************

