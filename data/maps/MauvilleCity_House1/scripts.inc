MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Waouh ! J'entends les gens\n"
	.string "m'appeler le ROCK SMASH GUY, mais\p"
	.string "je trouve cela un peu dégradant. Je\n"
	.string "pense que je mérite un peu plus de\p"
	.string "respect, comme peut-être le ROCK\n"
	.string "SMASH DUDE. Waouh ! En tout cas,\p"
	.string "ton POKéMON a l'air plutôt fort.\n"
	.string "J'aime ça! Tiens, prends cette\p"
	.string "MACHINE CACHÉE !$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Ce HM contient ROCK SMASH. Si vous\n"
	.string "rencontrez de gros rochers qui\p"
	.string "bloquent votre chemin… Eh bien,\n"
	.string "utilisez ce mouvement HM et\p"
	.string "écrasez-les hors de votre chemin !\n"
	.string "Oui Monsieur! Écrasez les pierres,\p"
	.string "dis-je ! Waouh !$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Oh, oui, si vous brisez un rocher,\n"
	.string "un POKéMON pourrait surgir de sa\p"
	.string "cachette. Waouh !$"
