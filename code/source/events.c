#include "events.h"

void Event_Init(GOBJ *gobj)
{
    int *eventData = gobj->userdata;
    EventData *eventInfo = eventData[0];
    OSReport("this is %s\n",eventInfo->eventName);
    return;
}

/////////////////////
// Mod Information //
/////////////////////

static char TM_Vers[] = {"Training Mode v3.0\n"};
static char TM_Compile[] = "COMPILED: " __DATE__ " " __TIME__;

////////////////////////
/// Event Defintions ///
////////////////////////

// L-Cancel Training
// Event Name
static char LCancel_Name[] = {"L-Cancel Training\n"};
// Event Description
static char LCancel_Desc[] = {"Practice L-Cancelling on\na stationary CPU.\n"};
// Event Tutorial Filename
static char LCancel_Tut[] = {"TvLC"};
// Event Menu Data
static char** LCancel_Stale[] = {"Off", "On"};
static char** LCancel_Intang[] = {"On", "Off"};
static MenuData LCancel_Menu[] =
{
    {
        "Stale Attacks",
        LCancel_Stale,
        sizeof(LCancel_Stale) / 4,
    },
    {
        "Option2",
        LCancel_Intang,
        sizeof(LCancel_Intang) / 4,
    },
};
// Match Data
static EventMatchData LCancel_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = false,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void LCancel_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData LCancel =
{
    // Event Name
    LCancel_Name,
    // Event Description
    LCancel_Desc,
    // Event Tutorial File Name
    LCancel_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    LCancel_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &LCancel_MatchData,
    // Menu Data
    &LCancel_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Ledgedash_Name[] = {"Ledgedash Training\n"};
// Event Description
static char Ledgedash_Desc[] = {"Practice Ledgedashes!\nUse D-Pad to change ledge.\n"};
// Event Tutorial Filename
static char Ledgedash_Tut[] = {"TvLedDa"};
// Event Menu Data
static char** Ledgedash_Stale[] = {"Off", "On"};
static char** Ledgedash_Intang[] = {"On", "Off"};
static MenuData Ledgedash_Menu[] =
{
    {
        "Stale Attacks",
        Ledgedash_Stale,
        sizeof(Ledgedash_Stale) / 4,
    },
    {
        "Option2",
        Ledgedash_Intang,
        sizeof(Ledgedash_Intang) / 4,
    },
};
// Match Data
static EventMatchData Ledgedash_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Ledgedash_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Ledgedash =
{
    // Event Name
    &Ledgedash_Name,
    // Event Description
    &Ledgedash_Desc,
    // Event Tutorial File Name
    &Ledgedash_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Ledgedash_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Ledgedash_MatchData,
    // Menu Data
    &Ledgedash_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Combo_Name[] = {"Combo Training\n"};
// Event Description
static char Combo_Desc[] = {"L+DPad adjusts percent | DPadDown moves CPU\nDPad right/left saves and loads positions."};
// Event Tutorial Filename
static char Combo_Tut[] = {"TvLC"};
// Event Menu Data
static char** Combo_Stale[] = {"Off", "On"};
static char** Combo_Intang[] = {"On", "Off"};
static MenuData Combo_Menu[] =
{
    {
        "Stale Attacks",
        Combo_Stale,
        sizeof(Combo_Stale) / 4,
    },
    {
        "Option2",
        Combo_Intang,
        sizeof(Combo_Intang) / 4,
    },
};
// Match Data
static EventMatchData Combo_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Combo_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Combo =
{
    // Event Name
    &Combo_Name,
    // Event Description
    &Combo_Desc,
    // Event Tutorial File Name
    &Combo_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Combo_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Combo_MatchData,
    // Menu Data
    &Combo_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char AttackOnShield_Name[] = {"Attack on Shield\n"};
// Event Description
static char AttackOnShield_Desc[] = {"Practice attacks on a shielding opponent\nPause to change their OoS option\n"};
// Event Tutorial Filename
static char AttackOnShield_Tut[] = {"TvLC"};
// Event Menu Data
static char** AttackOnShield_Stale[] = {"Off", "On"};
static char** AttackOnShield_Intang[] = {"On", "Off"};
static MenuData AttackOnShield_Menu[] =
{
    {
        "Stale Attacks",
        AttackOnShield_Stale,
        sizeof(AttackOnShield_Stale) / 4,
    },
    {
        "Option2",
        AttackOnShield_Intang,
        sizeof(AttackOnShield_Intang) / 4,
    },
};
// Match Data
static EventMatchData AttackOnShield_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void AttackOnShield_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData AttackOnShield =
{
    // Event Name
    &AttackOnShield_Name,
    // Event Description
    &AttackOnShield_Desc,
    // Event Tutorial File Name
    &AttackOnShield_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    AttackOnShield_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &AttackOnShield_MatchData,
    // Menu Data
    &AttackOnShield_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Reversal_Name[] = {"Reversal Training\n"};
// Event Description
static char Reversal_Desc[] = {"Practice OoS punishes! DPad left/right\nmoves characters close and further apart."};
// Event Tutorial Filename
static char Reversal_Tut[] = {"TvLC"};
// Event Menu Data
static char** Reversal_Stale[] = {"Off", "On"};
static char** Reversal_Intang[] = {"On", "Off"};
static MenuData Reversal_Menu[] =
{
    {
        "Stale Attacks",
        Reversal_Stale,
        sizeof(Reversal_Stale) / 4,
    },
    {
        "Option2",
        Reversal_Intang,
        sizeof(Reversal_Intang) / 4,
    },
};
// Match Data
static EventMatchData Reversal_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Reversal_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Reversal =
{
    // Event Name
    &Reversal_Name,
    // Event Description
    &Reversal_Desc,
    // Event Tutorial File Name
    &Reversal_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Reversal_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Reversal_MatchData,
    // Menu Data
    &Reversal_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char SDI_Name[] = {"SDI Training\n"};
// Event Description
static char SDI_Desc[] = {"Use Smash DI to escape\nFox's up-air attack!"};
// Event Tutorial Filename
static char SDI_Tut[] = {"TvLC"};
// Event Menu Data
static char** SDI_Stale[] = {"Off", "On"};
static char** SDI_Intang[] = {"On", "Off"};
static MenuData SDI_Menu[] =
{
    {
        "Stale Attacks",
        SDI_Stale,
        sizeof(SDI_Stale) / 4,
    },
    {
        "Option2",
        SDI_Intang,
        sizeof(SDI_Intang) / 4,
    },
};
// Match Data
static EventMatchData SDI_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void SDI_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData SDI =
{
    // Event Name
    &SDI_Name,
    // Event Description
    &SDI_Desc,
    // Event Tutorial File Name
    &SDI_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    SDI_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &SDI_MatchData,
    // Menu Data
    &SDI_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Powershield_Name[] = {"Powershield Training\n"};
// Event Description
static char Powershield_Desc[] = {"Powershield Falco's laser!\nPause to change to fire-rate."};
// Event Tutorial Filename
static char Powershield_Tut[] = {"TvLC"};
// Event Menu Data
static char** Powershield_Stale[] = {"Off", "On"};
static char** Powershield_Intang[] = {"On", "Off"};
static MenuData Powershield_Menu[] =
{
    {
        "Stale Attacks",
        Powershield_Stale,
        sizeof(Powershield_Stale) / 4,
    },
    {
        "Option2",
        Powershield_Intang,
        sizeof(Powershield_Intang) / 4,
    },
};
// Match Data
static EventMatchData Powershield_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Powershield_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Powershield =
{
    // Event Name
    &Powershield_Name,
    // Event Description
    &Powershield_Desc,
    // Event Tutorial File Name
    &Powershield_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Powershield_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Powershield_MatchData,
    // Menu Data
    &Powershield_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Ledgetech_Name[] = {"Ledge-Tech Training\n"};
// Event Description
static char Ledgetech_Desc[] = {"Practice ledge-teching\nFalco's down-smash"};
// Event Tutorial Filename
static char Ledgetech_Tut[] = {"TvLC"};
// Event Menu Data
static char** Ledgetech_Stale[] = {"Off", "On"};
static char** Ledgetech_Intang[] = {"On", "Off"};
static MenuData Ledgetech_Menu[] =
{
    {
        "Stale Attacks",
        Ledgetech_Stale,
        sizeof(Ledgetech_Stale) / 4,
    },
    {
        "Option2",
        Ledgetech_Intang,
        sizeof(Ledgetech_Intang) / 4,
    },
};
// Match Data
static EventMatchData Ledgetech_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Ledgetech_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Ledgetech =
{
    // Event Name
    &Ledgetech_Name,
    // Event Description
    &Ledgetech_Desc,
    // Event Tutorial File Name
    &Ledgetech_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Ledgetech_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Ledgetech_MatchData,
    // Menu Data
    &Ledgetech_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char AmsahTech_Name[] = {"Amsah-Tech Training\n"};
// Event Description
static char AmsahTech_Desc[] = {"Taunt to have Marth Up-B,\nthen ASDI down and tech!\n"};
// Event Tutorial Filename
static char AmsahTech_Tut[] = {"TvLC"};
// Event Menu Data
static char** AmsahTech_Stale[] = {"Off", "On"};
static char** AmsahTech_Intang[] = {"On", "Off"};
static MenuData AmsahTech_Menu[] =
{
    {
        "Stale Attacks",
        AmsahTech_Stale,
        sizeof(AmsahTech_Stale) / 4,
    },
    {
        "Option2",
        AmsahTech_Intang,
        sizeof(AmsahTech_Intang) / 4,
    },
};
// Match Data
static EventMatchData AmsahTech_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void AmsahTech_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData AmsahTech =
{
    // Event Name
    &AmsahTech_Name,
    // Event Description
    &AmsahTech_Desc,
    // Event Tutorial File Name
    &AmsahTech_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    AmsahTech_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &AmsahTech_MatchData,
    // Menu Data
    &AmsahTech_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char ShieldDrop_Name[] = {"Shield Drop Training\n"};
// Event Description
static char ShieldDrop_Desc[] = {"Counter with a shield-drop aerial!\nDPad left/right moves players apart."};
// Event Tutorial Filename
static char ShieldDrop_Tut[] = {"TvLC"};
// Event Menu Data
static char** ShieldDrop_Stale[] = {"Off", "On"};
static char** ShieldDrop_Intang[] = {"On", "Off"};
static MenuData ShieldDrop_Menu[] =
{
    {
        "Stale Attacks",
        ShieldDrop_Stale,
        sizeof(ShieldDrop_Stale) / 4,
    },
    {
        "Option2",
        ShieldDrop_Intang,
        sizeof(ShieldDrop_Intang) / 4,
    },
};
// Match Data
static EventMatchData ShieldDrop_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void ShieldDrop_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData ShieldDrop =
{
    // Event Name
    &ShieldDrop_Name,
    // Event Description
    &ShieldDrop_Desc,
    // Event Tutorial File Name
    &ShieldDrop_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    ShieldDrop_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &ShieldDrop_MatchData,
    // Menu Data
    &ShieldDrop_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char WaveshineSDI_Name[] = {"Waveshine SDI\n"};
// Event Description
static char WaveshineSDI_Desc[] = {"Use Smash DI to get out\nof Fox's waveshine!"};
// Event Tutorial Filename
static char WaveshineSDI_Tut[] = {"TvLC"};
// Event Menu Data
static char** WaveshineSDI_Stale[] = {"Off", "On"};
static char** WaveshineSDI_Intang[] = {"On", "Off"};
static MenuData WaveshineSDI_Menu[] =
{
    {
        "Stale Attacks",
        WaveshineSDI_Stale,
        sizeof(WaveshineSDI_Stale) / 4,
    },
    {
        "Option2",
        WaveshineSDI_Intang,
        sizeof(WaveshineSDI_Intang) / 4,
    },
};
// Match Data
static EventMatchData WaveshineSDI_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void WaveshineSDI_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData WaveshineSDI =
{
    // Event Name
    &WaveshineSDI_Name,
    // Event Description
    &WaveshineSDI_Desc,
    // Event Tutorial File Name
    &WaveshineSDI_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    WaveshineSDI_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &WaveshineSDI_MatchData,
    // Menu Data
    &WaveshineSDI_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char SlideOff_Name[] = {"Slide-Off Training\n"};
// Event Description
static char SlideOff_Desc[] = {"Use Slide-Off DI to slide off\nthe platform and counter attack!\n"};
// Event Tutorial Filename
static char SlideOff_Tut[] = {"TvLC"};
// Event Menu Data
static char** SlideOff_Stale[] = {"Off", "On"};
static char** SlideOff_Intang[] = {"On", "Off"};
static MenuData SlideOff_Menu[] =
{
    {
        "Stale Attacks",
        SlideOff_Stale,
        sizeof(SlideOff_Stale) / 4,
    },
    {
        "Option2",
        SlideOff_Intang,
        sizeof(SlideOff_Intang) / 4,
    },
};
// Match Data
static EventMatchData SlideOff_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void SlideOff_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData SlideOff =
{
    // Event Name
    &SlideOff_Name,
    // Event Description
    &SlideOff_Desc,
    // Event Tutorial File Name
    &SlideOff_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    SlideOff_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &SlideOff_MatchData,
    // Menu Data
    &SlideOff_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char GrabMash_Name[] = {"Grab Mash Training\n"};
// Event Description
static char GrabMash_Desc[] = {"Mash buttons to escape the grab\nas quickly as possible!\n"};
// Event Tutorial Filename
static char GrabMash_Tut[] = {"TvLC"};
// Event Menu Data
static char** GrabMash_Stale[] = {"Off", "On"};
static char** GrabMash_Intang[] = {"On", "Off"};
static MenuData GrabMash_Menu[] =
{
    {
        "Stale Attacks",
        GrabMash_Stale,
        sizeof(GrabMash_Stale) / 4,
    },
    {
        "Option2",
        GrabMash_Intang,
        sizeof(GrabMash_Intang) / 4,
    },
};
// Match Data
static EventMatchData GrabMash_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void GrabMash_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData GrabMash =
{
    // Event Name
    &GrabMash_Name,
    // Event Description
    &GrabMash_Desc,
    // Event Tutorial File Name
    &GrabMash_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    GrabMash_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &GrabMash_MatchData,
    // Menu Data
    &GrabMash_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char TechCounter_Name[] = {"Ledgetech Marth Counter\n"};
// Event Description
static char TechCounter_Desc[] = {"Practice ledge-teching\nMarth's counter!\n"};
// Event Tutorial Filename
static char TechCounter_Tut[] = {"TvLC"};
// Event Menu Data
static char** TechCounter_Stale[] = {"Off", "On"};
static char** TechCounter_Intang[] = {"On", "Off"};
static MenuData TechCounter_Menu[] =
{
    {
        "Stale Attacks",
        TechCounter_Stale,
        sizeof(TechCounter_Stale) / 4,
    },
    {
        "Option2",
        TechCounter_Intang,
        sizeof(TechCounter_Intang) / 4,
    },
};
// Match Data
static EventMatchData TechCounter_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void TechCounter_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData TechCounter =
{
    // Event Name
    &TechCounter_Name,
    // Event Description
    &TechCounter_Desc,
    // Event Tutorial File Name
    &TechCounter_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    TechCounter_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &TechCounter_MatchData,
    // Menu Data
    &TechCounter_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char ArmadaShine_Name[] = {"Armada-Shine Training\n"};
// Event Description
static char ArmadaShine_Desc[] = {"Finish the enemy Fox\nwith an Armada Shine!"};
// Event Tutorial Filename
static char ArmadaShine_Tut[] = {"TvLC"};
// Event Menu Data
static char** ArmadaShine_Stale[] = {"Off", "On"};
static char** ArmadaShine_Intang[] = {"On", "Off"};
static MenuData ArmadaShine_Menu[] =
{
    {
        "Stale Attacks",
        ArmadaShine_Stale,
        sizeof(ArmadaShine_Stale) / 4,
    },
    {
        "Option2",
        ArmadaShine_Intang,
        sizeof(ArmadaShine_Intang) / 4,
    },
};
// Match Data
static EventMatchData ArmadaShine_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void ArmadaShine_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData ArmadaShine =
{
    // Event Name
    &ArmadaShine_Name,
    // Event Description
    &ArmadaShine_Desc,
    // Event Tutorial File Name
    &ArmadaShine_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    ArmadaShine_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &ArmadaShine_MatchData,
    // Menu Data
    &ArmadaShine_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char SideBSweet_Name[] = {"Side-B Sweetspot\n"};
// Event Description
static char SideBSweet_Desc[] = {"Use a sweetspot Side-B to avoid Marth's\ndown-tilt and grab the ledge!"};
// Event Tutorial Filename
static char SideBSweet_Tut[] = {"TvLC"};
// Event Menu Data
static char** SideBSweet_Stale[] = {"Off", "On"};
static char** SideBSweet_Intang[] = {"On", "Off"};
static MenuData SideBSweet_Menu[] =
{
    {
        "Stale Attacks",
        SideBSweet_Stale,
        sizeof(SideBSweet_Stale) / 4,
    },
    {
        "Option2",
        SideBSweet_Intang,
        sizeof(SideBSweet_Intang) / 4,
    },
};
// Match Data
static EventMatchData SideBSweet_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void SideBSweet_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData SideBSweet =
{
    // Event Name
    &SideBSweet_Name,
    // Event Description
    &SideBSweet_Desc,
    // Event Tutorial File Name
    &SideBSweet_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    SideBSweet_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &SideBSweet_MatchData,
    // Menu Data
    &SideBSweet_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char EscapeSheik_Name[] = {"Escape Sheik Techchase\n"};
// Event Description
static char EscapeSheik_Desc[] = {"Practice escaping the tech chase with a\nframe perfect shine or jab SDI!\n"};
// Event Tutorial Filename
static char EscapeSheik_Tut[] = {"TvLC"};
// Event Menu Data
static char** EscapeSheik_Stale[] = {"Off", "On"};
static char** EscapeSheik_Intang[] = {"On", "Off"};
static MenuData EscapeSheik_Menu[] =
{
    {
        "Stale Attacks",
        EscapeSheik_Stale,
        sizeof(EscapeSheik_Stale) / 4,
    },
    {
        "Option2",
        EscapeSheik_Intang,
        sizeof(EscapeSheik_Intang) / 4,
    },
};
// Match Data
static EventMatchData EscapeSheik_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void EscapeSheik_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData EscapeSheik =
{
    // Event Name
    &EscapeSheik_Name,
    // Event Description
    &EscapeSheik_Desc,
    // Event Tutorial File Name
    &EscapeSheik_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    EscapeSheik_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &EscapeSheik_MatchData,
    // Menu Data
    &EscapeSheik_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Eggs_Name[] = {"Eggs-ercise\n"};
// Event Description
static char Eggs_Desc[] = {"Break the eggs! Only strong hits will\nbreak them. DPad down = free practice."};
// Event Tutorial Filename
static char Eggs_Tut[] = {"TvLC"};
// Event Menu Data
static char** Eggs_Stale[] = {"Off", "On"};
static char** Eggs_Intang[] = {"On", "Off"};
static MenuData Eggs_Menu[] =
{
    {
        "Stale Attacks",
        Eggs_Stale,
        sizeof(Eggs_Stale) / 4,
    },
    {
        "Option2",
        Eggs_Intang,
        sizeof(Eggs_Intang) / 4,
    },
};
// Match Data
static EventMatchData Eggs_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Eggs_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Eggs =
{
    // Event Name
    &Eggs_Name,
    // Event Description
    &Eggs_Desc,
    // Event Tutorial File Name
    &Eggs_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Eggs_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Eggs_MatchData,
    // Menu Data
    &Eggs_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Multishine_Name[] = {"Shined Blind\n"};
// Event Description
static char Multishine_Desc[] = {"How many shines can you\nperform in 10 seconds?"};
// Event Tutorial Filename
static char Multishine_Tut[] = {"TvLC"};
// Event Menu Data
static char** Multishine_Stale[] = {"Off", "On"};
static char** Multishine_Intang[] = {"On", "Off"};
static MenuData Multishine_Menu[] =
{
    {
        "Stale Attacks",
        Multishine_Stale,
        sizeof(Multishine_Stale) / 4,
    },
    {
        "Option2",
        Multishine_Intang,
        sizeof(Multishine_Intang) / 4,
    },
};
// Match Data
static EventMatchData Multishine_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Multishine_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Multishine =
{
    // Event Name
    &Multishine_Name,
    // Event Description
    &Multishine_Desc,
    // Event Tutorial File Name
    &Multishine_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Multishine_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Multishine_MatchData,
    // Menu Data
    &Multishine_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Reaction_Name[] = {"Reaction Test\n"};
// Event Description
static char Reaction_Desc[] = {"Test your reaction time by pressing\nany button when you see/hear Fox shine!"};
// Event Tutorial Filename
static char Reaction_Tut[] = {"TvLC"};
// Event Menu Data
static char** Reaction_Stale[] = {"Off", "On"};
static char** Reaction_Intang[] = {"On", "Off"};
static MenuData Reaction_Menu[] =
{
    {
        "Stale Attacks",
        Reaction_Stale,
        sizeof(Reaction_Stale) / 4,
    },
    {
        "Option2",
        Reaction_Intang,
        sizeof(Reaction_Intang) / 4,
    },
};
// Match Data
static EventMatchData Reaction_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Reaction_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Reaction =
{
    // Event Name
    &Reaction_Name,
    // Event Description
    &Reaction_Desc,
    // Event Tutorial File Name
    &Reaction_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Reaction_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Reaction_MatchData,
    // Menu Data
    &Reaction_Menu,
    // Default OSDs
    0xFFFFFFFF,
};

// L-Cancel Training
// Event Name
static char Ledgestall_Name[] = {"Under Fire\n"};
// Event Description
static char Ledgestall_Desc[] = {"Ledgestall to remain\ninvincible while the lava rises!\n"};
// Event Tutorial Filename
static char Ledgestall_Tut[] = {"TvLC"};
// Event Menu Data
static char** Ledgestall_Stale[] = {"Off", "On"};
static char** Ledgestall_Intang[] = {"On", "Off"};
static MenuData Ledgestall_Menu[] =
{
    {
        "Stale Attacks",
        Ledgestall_Stale,
        sizeof(Ledgestall_Stale) / 4,
    },
    {
        "Option2",
        Ledgestall_Intang,
        sizeof(Ledgestall_Intang) / 4,
    },
};
// Match Data
static EventMatchData Ledgestall_MatchData =
{
    .timer = MATCH_TIMER_COUNTUP,
    .matchType = MATCH_MATCHTYPE_TIME,
    .playMusic = true,
    .hideGo = true,
    .hideReady = true,
    .isCreateHUD = true,
    .isDisablePause = false,
    // byte 0x3
    .timerRunOnPause = false, // 0x01
    .isHidePauseHUD = true, // 0x02
    .isShowLRAStart = true, // 0x04
    .isCheckForLRAStart = true, // 0x08
    .isShowZRetry = true, // 0x10
    .isCheckForZRetry = true, // 0x20
    .isShowAnalogStick = true, // 0x40
    .isShowScore = false, // 0x80

    .isRunStockLogic = false, // 0x20
    .isDisableHit = false, // 0x20
    .useKOCounter = false,
    .fighter = -1,
    .cpuFighter = 8, // 0xFF=
    .stage = 16, // 0xFFFF
    .timerSeconds = 0, // 0xFFFFFFFF
    .timerSubSeconds = 0, // 0xFF
    .onCheckPause = 0,
    .onMatchEnd = 0,
};
// Think Function
void Ledgestall_Think (GOBJ* event)
{
    return;
}
// Event Struct
static EventData Ledgestall =
{
    // Event Name
    &Ledgestall_Name,
    // Event Description
    &Ledgestall_Desc,
    // Event Tutorial File Name
    &Ledgestall_Tut,
    // isChooseCPU
    true,
    // isSelectStage
    true,
    // Score Type
    0,
    // callback priority
    0,
    // Event Callback Function
    Ledgestall_Think,
    // Event Init Function
    Event_Init,
    // Match Data
    &Ledgestall_MatchData,
    // Menu Data
    &Ledgestall_Menu,
    // Default OSDs
    0xFFFFFFFF,
};







///////////////////////
/// Page Defintions ///
///////////////////////

// Minigames
static char Minigames_Name[] = {"Minigames"};
static EventData *Minigames_Events[] =
{
    &Eggs,
    &Multishine,
    &Reaction,
    &Ledgestall,
};
static EventPage Minigames_Page =
{
    Minigames_Name,
    (sizeof(Minigames_Events) / 4) - 1,
    Minigames_Events,
};

// Page 2 Events
static char General_Name[] = {"General Tech"};
static EventData *General_Events[] =
{
    // Event 1 - L-Cancel Training
    &LCancel,
    &Ledgedash,
    &Combo,
    &AttackOnShield,
    &Reversal,
    &SDI,
    &Powershield,
    &Ledgetech,
    &AmsahTech,
    &ShieldDrop,
    &WaveshineSDI,
    &SlideOff,
    &GrabMash,
};
static EventPage General_Page =
{
    General_Name,
    (sizeof(General_Events) / 4) - 1,
    General_Events,
};

// Page 3 Events
static char Spacie_Name[] = {"Spacie Tech"};
static EventData *Spacie_Events[] =
{
    &TechCounter,
    &ArmadaShine,
    &SideBSweet,
    &EscapeSheik,
};
static EventPage Spacie_Page =
{
    Spacie_Name,
    (sizeof(Spacie_Events) / 4) - 1,
    Spacie_Events,
};

///////////////////////
/// Page Order ///
///////////////////////

// Page Order
static EventPage **EventPages[] =
{
    &Minigames_Page,
    &General_Page,
    &Spacie_Page,
};


//////////////////////
/// Init Functions ///
//////////////////////

void EventInit(int page, int eventID, MatchData *matchData)
{

    // get event pointer
    EventData *event = GetEvent(page,eventID);

    //Init default match info
    matchData->unk1 = 4;
    matchData->timer_unk2 = 0;
    matchData->unk2 = 1;
    matchData->unk7 = 1;
    matchData->isCheckStockSteal = 1;
    matchData->unk10 = 3;
    matchData->isSkipEndCheck = 1;
    matchData->itemFreq = MATCH_ITEMFREQ_OFF;
    matchData->onStartMelee = EventLoad;

    //Copy event's match info struct
    EventMatchData *eventMatchData = event->matchData;
    matchData->timer = eventMatchData->timer;
    matchData->matchType = eventMatchData->matchType;
    matchData->playMusic = eventMatchData->playMusic;
    matchData->hideGo = eventMatchData->hideGo;
    matchData->hideReady = eventMatchData->hideReady;
    matchData->isCreateHUD = eventMatchData->isCreateHUD;
    matchData->isDisablePause = eventMatchData->isDisablePause;
    matchData->timerRunOnPause = eventMatchData->timerRunOnPause;
    matchData->isHidePauseHUD = eventMatchData->isHidePauseHUD;
    matchData->isShowLRAStart = eventMatchData->isShowLRAStart;
    matchData->isCheckForLRAStart = eventMatchData->isCheckForLRAStart;
    matchData->isShowZRetry = eventMatchData->isShowZRetry;
    matchData->isCheckForZRetry = eventMatchData->isCheckForZRetry;
    matchData->isShowAnalogStick = eventMatchData->isShowAnalogStick;
    matchData->isShowScore = eventMatchData->isShowScore;
    matchData->isRunStockLogic = eventMatchData->isRunStockLogic;
    matchData->isDisableHit = eventMatchData->isDisableHit;
    matchData->timerSeconds = eventMatchData->timerSeconds;
    matchData->timerSubSeconds = eventMatchData->timerSubSeconds;
    matchData->onCheckPause = eventMatchData->onCheckPause;
    matchData->onMatchEnd = eventMatchData->onMatchEnd;

    // Initialize all player data
    Memcard *memcard = R13_PTR(MEMCARD);
    CSSBackup eventBackup = memcard->EventBackup;
    for (int i = 0; i<6; i++)
    {
        // initialize data
        CSS_InitPlayerData(&matchData->playerData[i]);

        // set to enter fall on match start
        matchData->playerData[i].isEntry = false;

        // copy nametag id for the player
        if (i == 0)
        {
            // Update the player's nametag ID
            matchData->playerData[i].nametag = eventBackup.nametag;

            // Update the player's rumble setting
            int tagRumble = CSS_GetNametagRumble(0,matchData->playerData[0].nametag);
            matchData->playerData[0].isRumble = tagRumble;
        }
    }

    // Determine the Player
    int player_kind;
    int player_costume;
    Preload *preload = 0x80432078;
    // If fighter is -1, copy the player from event data
    if (eventMatchData->fighter == -1)
    {
        player_kind = eventMatchData->fighter;
        player_costume = 0;
    }
    // use the fighter chosen on the CSS
    else
    {
        player_kind = preload->fighters[0].kind;
        player_costume = preload->fighters[0].costume;
    }

    // Determine the CPU
    int cpu_kind;
    int cpu_costume;
    // If isChooseCPU is true, use the selected CPU
    if (event->isChooseCPU == true)
    {
        cpu_kind = preload->fighters[1].kind;
        cpu_costume = preload->fighters[1].costume;
    }
    // If isChooseCPU is false, copy the CPU from event data
    else
    {
        cpu_kind = eventMatchData->cpuFighter;
        cpu_costume = 0;
    }

    // Check if CPU is using the same character and color as P1
    if ((player_kind == cpu_kind) && (player_costume == cpu_costume))
    {
        // this doesnt account for if theyre both using the last costume
        cpu_costume +=1;
    }

    // Copy player data to match info struct (update their rumble setting 801bb1ec)
    matchData->playerData[0].kind = player_kind;
    matchData->playerData[0].costume = player_costume;
    matchData->playerData[0].status = 0;
    matchData->playerData[1].kind = cpu_kind;
    matchData->playerData[1].costume = cpu_costume;
    matchData->playerData[1].status = 1;

    // Determine the Stage
    int stage;
    // If isSelectStage is true, use the selected stage
    if (event->isChooseCPU == true)
    {
        stage = preload->stage;
    }
    // If isSelectStage is false, copy the stage from event data
    else
    {
        stage = eventMatchData->stage;
    }
    // Update match struct with this stage
    matchData->stage = stage;

    //Update preload table? (801bb63c)

    return;
};

void EventLoad()
{
    // get this event
    Memcard *memcard = R13_PTR(MEMCARD);
    int page = memcard->TM_EventPage;
    int eventID = memcard->EventBackup.event;
    EventData* event = GetEvent(page,eventID);

    // Create this event's gobj
    int pri = event->callbackPriority;
    void* cb = event->eventOnFrame;
    GOBJ *gobj = GObj_Create(0,0,0);
    int *userdata = HSD_MemAlloc(EVENT_DATASIZE);
    GObj_AddUserData(gobj,4,HSD_Free,userdata);
    GObj_AddProc(gobj,cb,pri);

    // store pointer to the event's data
    userdata[0] = event;

    // Run this event's init function
    if (event->eventOnInit != 0)
    {
        event->eventOnInit(gobj);
    }

    return;
};

//////////////////////
/// Hook Functions ///
//////////////////////

void DebugLogThink(GOBJ *gobj)
{
    int *userdata = gobj->userdata;
    DevText* text = userdata[0];
    MatchData *matchData = 0x804978a0;//0x80480530;

    // clear text
    DevelopText_EraseAllText(text);
    DevelopMode_ResetCursorXY(text,0,0);

    // update text
    DevelopText_AddString(text,"matchType: %d\n",matchData->matchType);
    DevelopText_AddString(text,"unk1: %d\n",matchData->unk1);
    DevelopText_AddString(text,"timer: %d\n",matchData->timer);
    DevelopText_AddString(text,"timer_unk2: %d\n",matchData->timer_unk2);
    DevelopText_AddString(text,"unk4: %d\n",matchData->unk4);
    DevelopText_AddString(text,"hideReady: %d\n",matchData->hideReady);
    DevelopText_AddString(text,"hideGo: %d\n",matchData->hideGo);
    DevelopText_AddString(text,"playMusic: %d\n",matchData->playMusic);
    DevelopText_AddString(text,"unk3: %d\n",matchData->unk3);
    DevelopText_AddString(text,"timer_unk: %d\n",matchData->timer_unk);
    DevelopText_AddString(text,"unk2: %d\n",matchData->unk2);
    DevelopText_AddString(text,"unk9: %d\n",matchData->unk9);
    DevelopText_AddString(text,"disableOffscreenDamage: %d\n",matchData->disableOffscreenDamage);
    DevelopText_AddString(text,"unk8: %d\n",matchData->unk8);
    DevelopText_AddString(text,"isSingleButtonMode: %d\n",matchData->isSingleButtonMode);
    DevelopText_AddString(text,"isDisablePause: %d\n",matchData->isDisablePause);
    DevelopText_AddString(text,"unk7: %d\n",matchData->unk7);
    DevelopText_AddString(text,"isCreateHUD: %d\n",matchData->isCreateHUD);
    DevelopText_AddString(text,"unk5: %d\n",matchData->unk5);
    DevelopText_AddString(text,"isShowScore: %d\n",matchData->isShowScore);
    DevelopText_AddString(text,"isShowAnalogStick: %d\n",matchData->isShowAnalogStick);
    DevelopText_AddString(text,"isCheckForZRetry: %d\n",matchData->isCheckForZRetry);
    DevelopText_AddString(text,"isShowZRetry: %d\n",matchData->isShowZRetry);
    DevelopText_AddString(text,"isCheckForLRAStart: %d\n",matchData->isCheckForLRAStart);
    DevelopText_AddString(text,"isShowLRAStart: %d\n",matchData->isShowLRAStart);
    DevelopText_AddString(text,"isHidePauseHUD: %d\n",matchData->isHidePauseHUD);
    DevelopText_AddString(text,"timerRunOnPause: %d\n",matchData->timerRunOnPause);
    DevelopText_AddString(text,"unk11: %d\n",matchData->unk11);
    DevelopText_AddString(text,"isCheckStockSteal: %d\n",matchData->isCheckStockSteal);
    DevelopText_AddString(text,"isRunStockLogic: %d\n",matchData->isRunStockLogic);
    DevelopText_AddString(text,"unk10: %d\n",matchData->unk10);
    DevelopText_AddString(text,"isSkipEndCheck: %d\n",matchData->isSkipEndCheck);
    DevelopText_AddString(text,"isSkipUnkStockCheck: %d\n",matchData->isSkipUnkStockCheck);
    DevelopText_AddString(text,"isDisableHit: %d\n",matchData->isDisableHit);
    DevelopText_AddString(text,"unk12: %d\n",matchData->unk12);

    return;
}

void OnSceneChange()
{
    return;
    // Create a gobj
    GOBJ *gobj = GObj_Create(0,0,0);
    int *userdata = HSD_MemAlloc(64);
    GObj_AddUserData(gobj,4,HSD_Free,userdata);
    GObj_AddProc(gobj,DebugLogThink,0);

    // Create some dev text
    DevText* text = DevelopText_CreateDataTable(13,0,0,28,40,HSD_MemAlloc(0x1000));
    DevelopText_Activate(0,text);
    text->cursorBlink = 0;
    userdata[0] = text;
    u8 color[] = {0x40,0x50,0x80,180};
    DevelopText_StoreBGColor(text,&color);
    DevelopText_StoreTextScale(text,7.5,10);

    return;
};

///////////////////////////////
/// Member-Access Functions ///
///////////////////////////////

EventData *GetEvent(int page, int event)
{
    EventPage *thisPage = EventPages[page];
    EventData *thisEvent = thisPage->events[event];
    return (thisEvent);
}
char *GetEventName(int page, int event)
{
    EventData *thisEvent = GetEvent(page,event);
    return (thisEvent->eventName);
}
char *GetEventDesc(int page, int event)
{
    EventData *thisEvent = GetEvent(page,event);
    return (thisEvent->eventDescription);
}
char *GetEventTut(int page, int event)
{
    EventData *thisEvent = GetEvent(page,event);
    return (thisEvent->eventTutorial);
}
char *GetPageName(int page)
{
    EventPage *thisPage = EventPages[page];
    return (thisPage->name);
}
int GetPageEventNum(int page)
{
    EventPage *thisPage = EventPages[page];
    return (thisPage->eventNum);
}
char *GetTMVers()
{
    return (TM_Vers);
}
char *GetTMCompile()
{
    return (TM_Compile);
}
int GetPageNum()
{
    int pageNum = (sizeof(EventPages) / 4) - 1;
    return (pageNum);
}
u8 GetIsChooseCPU(int page, int event)
{
    EventData *thisEvent = GetEvent(page,event);
    return(thisEvent->isChooseCPU);
}
u8 GetIsSelectStage(int page, int event)
{
    EventData *thisEvent = GetEvent(page,event);
    return(thisEvent->isSelectStage);
}
s8 GetFighter(int page, int event)
{
    EventData *thisEvent = GetEvent(page,event);
    return(thisEvent->matchData->fighter);
}
s8 GetCPUFighter(int page, int event)
{
    EventData *thisEvent = GetEvent(page,event);
    return(thisEvent->matchData->cpuFighter);
}
s16 GetStage(int page, int event)
{
    EventData *thisEvent = GetEvent(page,event);
    return(thisEvent->matchData->stage);
}
