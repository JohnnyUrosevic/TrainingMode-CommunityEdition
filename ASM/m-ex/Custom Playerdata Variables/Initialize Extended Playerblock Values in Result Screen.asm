    # To be inserted at 800BE830
    .include "../../Globals.s"
    .include "../Header.s"

    # Backup Data Pointer After Creation
    addi r30, r3, 0

    # Get Player Data Length
    load r4, 0x80458fd0
    lwz r4, 0x20(r4)
    # Zero Entire Data Block
    branchl r12, ZeroAreaLength

exit:
    mr r3, r30
    lis r4, 0x8046
