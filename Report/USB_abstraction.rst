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


Modules this Module depends on
---------------------------------



Requirement of this module
********************************************


Functional Requirement 1 init :


The abstraction layer provides an init function, The key functionalities of init functions are:

- Device binding - get a device pointer (here, we are getting USB device pointer)
- Register a device - registering USB device with appropriate report descriptor (Report descriptor tells about exact functionalities of device) 
- Set protocol code - USB HID Protocol code.
- Init and Enable - Initialize and Enabling it for Working.



Functional Requirement 
------------------------





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

