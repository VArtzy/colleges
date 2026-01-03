OUTPUT_ARCH("riscv")
ENTRY(_entry)

SECTIONS
{
    /*
     * ensure that entry.S / _entry is at 0x80000000, 
     * where qemu's -kernel jumps.
     */
    . = 0x80000000;

    .text: {
        kernel/entry.o(_entry)
        *(.text .text.*)
        . = ALIGN(0x1000);
        _trampoline = .;
        *(trampsec)
        . = ALIGN(0x1000);
        ASSERT(. - _trampoline == 0x1000, "error: trampoline larger than one page");
        PROVIDE(etext = .);
    }
}
