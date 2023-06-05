USB abstraction documentation
##########################################

.. contents:: Table of Contents

Document History
********************

============= ================= ======== ===========================================
Date          Author            Revision Changes
------------- ----------------- -------- -------------------------------------------


============= ================= ======== ===========================================

General
********************

Purpose of this Module
==========================
This is an abstraction layer between an application module (this is an example of USB Bootloader protocol, but it should be useable in a generic context) and the hardware dependant layer (in this case the zephyr USB library). It provides generic USB functions and uses read/write functions as an interface to the application module.


Module used for the following Applications
===========================================


Dependencies
=============

Modules dependent on this Module
---------------------------------


This Module depends on
---------------------------------



Requirement of this module
********************************************


Functional Requirement :
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
The abstraction layer provides an read function, The key functionalities are :

- The OutEndpoint Callback is triggered whenever data is available on device EndpointBuffer
- Data is read by zephyr-read API. with data payload of 64 Bytes
- In our use case, data to be read with length of 320 Bytes per transfer.
- Timeout - timeout option is available when data is failed to receive within specified time.
- On success the data will be filled on read buffer.

Functional Requirement 2 write:
-------------------------------
The abstraction layer provides Write function, The key functionalities are :

- Write function will be called from application module
- write operation performed by zephyr-write API, with fixed data payload of 64 bytes.



API description
-----------------


API description
************************



Function description
*********************

Internal functions
===================

Functions
------------------------------




Release Notes
****************

