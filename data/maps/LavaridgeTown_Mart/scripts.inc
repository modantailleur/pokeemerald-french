LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "Utilisez X SPEED pour augmenter la\n"
	.string "VITESSE d'un POKéMON au combat.\p"
	.string "Cela l’aidera à réussir dès le\n"
	.string "premier coup -- un avantage décisif\p"
	.string "!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "Sur MONT CHIMNEE Point culminant,\n"
	.string "il y a une spécialité locale que\p"
	.string "l'on peut acheter uniquement sur\n"
	.string "place. Donnez-le à un POKéMON, il\p"
	.string "sera ravi.$"
