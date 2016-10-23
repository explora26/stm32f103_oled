MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
	RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		KEEP(*(.isr_vector))
		*(.text)
		*(.text.*)
		*(.rodata)
		_sidata = .;
	} > FLASH

	.data : AT(_sidata)
	{
		__data_start__ = .;
		*(.data)
		*(.data*)
		__data_end__ = .;
	} > RAM

	.bss :
	{
		__bss_start__ = .;
		*(.bss)
		__bss_end__ = .;
	} > RAM

    _estack = ORIGIN(RAM) + LENGTH(RAM);
}

