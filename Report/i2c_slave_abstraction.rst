I2C slave abstraction documentation
##########################################

.. contents:: Table of Contents

Document History
********************

============= ================= ======== ===========================================
Date          Author            Revision Changes
------------- ----------------- -------- -------------------------------------------
2023.02.06    MicGr             V0.1     Creation of document
2023.02.27    Markus Straeter   V0.2     General updates

============= ================= ======== ===========================================

General
********************

Purpose of this Module
==========================
This is an abstraction layer between an application module (this example the Kinetis Bootloader protocol, but it should be useable in a generic context) and the hardware dependant layer (in this case the zephyr I2C library).
It provides generic usable I2C slave functions and uses callbacks (read/write) as an interface to the application module.



Module used for the following Applications
===========================================
.. toctree::
   :maxdepth: 1

   kinetis_protocol.rst


Dependencies
=============

Modules dependent on this Module
---------------------------------
.. toctree::
   :maxdepth: 1

   kinetis_protocol.rst

Modules this Module depends on
---------------------------------
Not dependant on any modules but dependent on the Zephyr OS including hw abstraction and I2C driver functionality


Requirement of this module
********************************************


Functional Requirement
=======================
The abstraction layer provides an init function and calls callback functions as i2c messages are
read and written by the i2c master.
Furthermore there is an de-init function, which removes the i2c slave from the bus (further read/write attempts get a NAK).


 .. uml:: uml_diagramms/i2c_slave_abstraction.puml

Functional Requirement 1 init
-----------------------------
The init function gets the pointers to read and write callback functions as arguments.
Those callbacks are stored module global, and are called later when the corresponding events happen.
As a third parameter the init function also receives the i2c slave address that should be used.
Also the register address size can be specified, which can be either 0, 8, 16, 24, or 32bit.
The module threat the first bytes received, that are within this range, as register address and pass it to the
read/write callback functions to the application.

The init function registers a i2c slave device to the zephyr i2c driver.

Functional Requirement 2 master write
-------------------------------------
 .. uml:: uml_diagramms/i2c_slave_master_write.puml

When the master writes data on the bus, for each byte sent, the abstraction layer gets a callback
from the zephyr module with the data byte (the callback function was given to zephyr in the i2c_slave_register function call).
Those data bytes have to be stored in a buffer.
The first bytes received, that are within the register address range, are stored as register address value.
After the last byte of a transmission is sent, the master will issue a stop condition, resulting in the stop callback being called.
When this happens the abstraction layer shall use the callback function given from the upper level, to provide the length of the received data and a reference to the buffer.

Functional Requirement 3 master read
------------------------------------

 .. uml:: uml_diagramms/i2c_slave_master_read.puml

When the master requests to read a byte the abstraction layer shall use the read callback function to get the requested byte from the upper module and forward it to the zephyr i2c driver.

Functional Requirement 4 de-init
-----------------------------
When the deinit function is called by the upper layer, the i2c slave get removed from the bus (further read/write attempts will be responded with a NAK).



API description
-----------------
`init(*write_callback, *read_callback, i2c_address)`

API description
************************

.. doxygengroup:: OSAL_I2C_SLAVE
   :project: doxy_api
   :path: ../doxygen/build/


Function description
*********************

Internal functions
===================

Functions
------------------------------

`write_requested_callback(*i2c_slave_config)`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This function is called when a write to the device is initiated.
It clears old data from the message buffer and resets the number of received bytes.

`write_received_callback(*i2c_slave_config, data_byte)`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This function is called when a write to the device is continued and a byte form the master is received.
the function stores the byte into the message buffer and increments the number of received bytes


`read_requested_callback(*i2c_slave_config, *data_byte)`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This function is called when a read from the device is initiated.
The master requests one byte of data. The abstraction module uses the read callback function provided by the application module to get the data byte from there.

`read_processed_callback(*i2c_slave_config, *data_byte)`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This function is called when a read from the device is continued.
The master requests one byte of data. the abstraction module uses the read callback function provided by the application module to get the data byte from there.

`stop_callback(*i2c_slave_config)`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This function is called when a stop condition is observed.
This indicates the end of a master write transmission
The abstraction module uses the write callback function provided by the application module to forward the number of received bytes and a pointer to the data buffer.


Release Notes
****************

`Tags <https://gitlab.endor.ag/endor-ee/fw/eufe/modules/endor-osal/-/tags>`_
