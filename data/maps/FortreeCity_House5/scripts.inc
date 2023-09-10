FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Les cabanes dans les arbres de\n"
	.string "FORTREE sont géniales ! Je pense\p"
	.string "que c'est la ville numéro un pour\n"
	.string "vivre ensemble avec POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "POKéMON et les humains se sont\n"
	.string "adaptés à la nature pour survivre.\p"
	.string "Il n'est pas nécessaire de rendre\n"
	.string "la nature conforme à la façon dont\p"
	.string "nous voulons vivre.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON : Bufu !$"
