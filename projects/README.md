Overview of the projects
========================

Here're some basic informations about the differend projects and the actual states.

WARNING: This is work in progress! So it's possible that something is not working or possibly not implemented yet.


Active projects
---------------

Below you find active project where i active work on.



USB_serial-I2C-gateway (usb_i2c_gateway)
----------------------------------------

This is a small module based on an nanopi with USB_serial and i2c. It acts as something like an i2c extention via usb. The corresponding linux kernel driver is also located at github (TODO: add link).

		     usecase:

		     +----------------+                    +-------------+           +-----------------+
		     |                |                    |             |           |                 |
		     | Linux-board/pc |<-- USB (serial) -->|  usb<->i2c  |<-- I2C -->| some i2c device |
		     |                |                    |             |           |                 |
		     +----------------+                    +-------------+           +-----------------+

Subprojects:

	- LCD1602
	- BMP180
	- GPIO-Port-Expander (PCFxxx)
	- ...


Deprecated projects
-------------------

Below you find older projects which i do not active develop anymore. So there're something like templates for newer projects.


t.b.d
-------------------

t.b.d.

