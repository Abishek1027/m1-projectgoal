.. _Endor USB Protocol:

Endor USB Protocol
#################################

.. contents:: Table of Contents

Document History
******************

============= ================= ======== ===========================================
Date          Author            Revision Changes
------------- ----------------- -------- -------------------------------------------
05.06.2023    Aravindh.R        V0.1     Creation of documentation
============= ================= ======== ===========================================

Functional Scope
===================
The functionality of the ``USB Protocol`` is to translate and forward USB data packets 
from the ``endor-os-abstraction`` to the ``Diagnosis and Update Unit`` and backwards.

Requirements
=================

Requirement 1
--------------------
The function shall receive USB data packets with fixed data length of n bytes.

Requirement 2
--------------------
The USB data packets has to be translated to request or data chunk that can be used by ``Diagnosis and Update Unit``-API.

Requirement 3
--------------------
The USB packet processed from ``Diagnosis and Update Unit``-API, to be send as a response to the ``endor-os-abstraction``.

Overview and concept
=============================
The ``USB Protocol`` is run by the ``usb_prot_task`` with uses API functions of ``endor_diag_prot``-module.
The task is a thread that is initialized and started by the device manager and running with a delay of n. When 
a new data is received in the task, it will be parsed und translated. After a valid command is found, it will be forwarded to the 
``Diagnosis and Update Unit``. A response will be sent b to the ``endor-os-abstraction``.

.. uml:: uml_diagramms/usb_proto.puml

API Reference
******************
Endor USB Protocol
=============================

.. doxygengroup:: USB_PROT
   :project: doxy_api
   :path: ../doxygen/build/

Endor USB Protocol Task
==================================

.. doxygengroup:: USB_PROT_TASK
   :project: doxy_api
   :path: ../doxygen/build/

Bibliography
******************************************

Links and References
====================

Glossary
===============

Abbreviations
===============


