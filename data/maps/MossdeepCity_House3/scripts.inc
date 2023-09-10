MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Salut, FORMATTHIEUEUR ! Une SUPER\n"
	.string "ROD, c'est vraiment super ! Dites\p"
	.string "tout ce que vous voulez, mais ce\n"
	.string "bébé peut attraper des POKéMON sur\p"
	.string "le fond marin ! Qu'en penses-tu? Tu\n"
	.string "le veux, n'est-ce pas ?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Vous pariez, vous pariez ! Après\n"
	.string "tout, une SUPER ROD est vraiment\p"
	.string "super !$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "S'il y a de l'eau, essayez d'y\n"
	.string "déposer votre ROD et voyez ce qui\p"
	.string "mord !$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hein ? Vous n'aimez pas pêcher ?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Partez à la poursuite des POKéMON\n"
	.string "des fonds marins avec votre SUPER\p"
	.string "CANNE.$"
