LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Ma femme réchauffe un ŒUF dans les\n"
	.string "sources chaudes. C'est ce qu'elle\p"
	.string "m'a dit. Elle a laissé deux POKéMON\n"
	.string "à la DAY CARE. Et ils ont découvert\p"
	.string "que EGG!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON : Pshoo !$"
