OUTPUT_ARCH(mips)
ENTRY(startup)
SECTIONS {
	. = 0x80300000;
	.text : {
		_ftext = . ;
		text_start = .;
		*(.text.startup)
		*(.init)
		*(.text)
		*(.text.*)
		*(.fini)
		*(.glue_7t)
		*(.glue_7)
		*(.rdata)
		*(.rdata.*)
		*(.rodata)
		*(.rodata.*)
		_etext = .;
		text_end = .;
	}

	.data : {
		data_start = .;
		_fdata = .;
		*(.data)
		*(.data.*)
		*(.sdata)
		data_end = .;
		_edata = .;
	}

	.bss : {
		_fbss = .;
		bss_start = .;
		*(.sbss)
		*(.scommon)
		*(.bss)
		*(.bss.*)
		*(COMMON)
		bss_end = .;
	}

	/* Reclaim region 1 for BCMINITFN/BCMINITDATA */
	.textrc1 : {
		_rstart1 = .;
		*(.textini1.*)
		. = ALIGN(16);
		_retext1 = .;
	}

	.datarc1 : {
		*(.dataini1.*)
		. = ALIGN(4);
		_rend1 = .;
	}

	/* Reclaim region 2 for BCMATTACHFN/BCMATTACHDATA */
	.textrc2 : {
		_rstart2 = .;
		*(.textini2.*)
		. = ALIGN(16);
		_retext2 = .;
	}

	.datarc2 : {
		*(.dataini2.*)
		. = ALIGN(4);
		_rend2 = .;
	}
	_end = .;
}
