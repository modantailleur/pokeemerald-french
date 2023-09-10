FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "SUPER REPEL dure longtemps et fait\n"
	.string "le travail. C'est bien mieux qu'un\p"
	.string "REPEL ordinaire.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Je stocke toujours plus d’articles\n"
	.string "que ce dont je suis sûr d’en avoir\p"
	.string "besoin. Vous ne savez jamais ce qui\n"
	.string "pourrait arriver. Mieux vaut\p"
	.string "prévenir que guérir !$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "Un BONBON RARE fait grandir\n"
	.string "immédiatement un POKéMON d'un\p"
	.string "niveau.$"
