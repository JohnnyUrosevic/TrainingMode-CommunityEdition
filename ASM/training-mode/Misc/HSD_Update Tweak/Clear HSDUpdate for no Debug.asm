    # To be inserted at 801a4c08
    .include "../../../Globals.s"

    # Finish storing function (original code line)
    stw r0, 0x0028(r31)

    # Check if DBLevel
    lwz r0, DEBUGLV(r13)
    cmpwi r0, 3
    bge isDebug

NoDebug:
    # Clear these functions
    li r0, 0
    stw r0, 0x24(r31)
    stw r0, 0x28(r31)

isDebug:
# Run as normal
