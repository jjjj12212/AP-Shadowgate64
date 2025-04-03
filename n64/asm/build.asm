.n64
.relativeinclude on

;version guard, prevent people from building with older armips versions
.if (version() < 110)
.notice version()
.error   "Detected armips build is too old. Please install https://github.com/Kingcom/armips version 0.11 or later."
.endif

.create patchedfile, 0
.incbin romfile

;replace game init with code that loads payload
.orga 0x0616E0
.area 0x40, 0
.align 0x10
.importobj bootbundle
.endarea

.headersize (0x80400000 - 0x1000000)

.org    0x80400000
.area   0x00200000 ;payload max memory

;modify replaced code and add back to run later
init_game:
  .incbin romfile,0x0616E0,0x44
  JAL inject_hooks
  NOP
  .incbin romfile,(0x0616E0+0x44),0x14

PAYLOAD_START:

.align 0x10
.importobj srcbundle

.align 0x08
obtain_ingame_npc_check_displaced:
ADDIU SP, SP, -0x08
SW RA, 0x0000 (SP)
JAL obtain_ingame_npc_check
NOP
LW RA, 0x0000 (SP)
J 0x80030E84
ADDIU SP, SP, 0x08




PAYLOAD_END:
.endarea ; payload max memory


.close
