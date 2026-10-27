/*
 * Import stubs that vitasdk does not provide. Each entry has the same layout
 * vita-libs-gen emits for a weak, user-mode stub:
 *   word 0: library version (1) << 16 | flags (0x8 = weak)
 *   word 1: library NID
 *   word 2: function NID
 * Values taken from a working quickmenuplus.suprx and ScePaf-RE (c-compat).
 */
#define IMPORT_STUB(lib, libnid, name, nid) \
__asm__( \
	".pushsection .vitalink.fstubs." lib ",\"ax\",%progbits\n" \
	"\t.align 4\n" \
	"\t.global " name "\n" \
	"\t.type " name ", %function\n" \
	name ":\n" \
	"\t.word 0x00010008\n" \
	"\t.word " libnid "\n" \
	"\t.word " nid "\n" \
	"\t.align 4\n" \
	"\t.popsection\n" \
)

IMPORT_STUB("SceShellUtil",  "0xD2B1C8AE", "sceShellUtilRequestColdReset", "0x636544FB");

IMPORT_STUB("ScePafStdc",    "0xA7D28DAE", "sce_paf_vswprintf",            "0xFA5C2193");

IMPORT_STUB("ScePafToplevel","0x4D9A9DD0", "scePafPluginGetByName",        "0x004D98CC");
IMPORT_STUB("ScePafToplevel","0x4D9A9DD0", "scePafLabelFindById",          "0x19CEFDA7");

IMPORT_STUB("ScePafWidget",  "0x073F8C68", "scePafButtonSetRepeat",        "0x16479BA7");
IMPORT_STUB("ScePafWidget",  "0x073F8C68", "scePafWidgetSetFilterColor",   "0x627CDA4E");
IMPORT_STUB("ScePafWidget",  "0x073F8C68", "scePafWidgetFindById",         "0x9D304F4A");
