SECTIONS
{
	.func_table :
	{
		_table_start = .;
		KEEP(*(.func_table))
		_table_end = .;
	}
}
INSERT AFTER .data;
