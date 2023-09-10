.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Vous êtes le premier DRESSEUR que\n"
	.string "je vois qui déploie POKéMON avec\p"
	.string "autant de maîtrise. Mais je dois\n"
	.string "vous le dire : mon fils est plus\p"
	.string "fort que vous. Il a même relevé le\n"
	.string "défi POKéMON LEAGUE, je vous le\p"
	.string "ferai savoir.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Nous utilisons ce MACHO BRACE pour\n"
	.string "renforcer plus efficacement notre\p"
	.string "POKéMON à l'entraînement. Puisque\n"
	.string "vous nous avez tous battus ici, je\p"
	.string "ne sais pas si vous en avez besoin,\n"
	.string "mais nous aimerions que vous ayez\p"
	.string "notre MACHO BRACE.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Quand il s'agit de batailles\n"
	.string "POKéMON, nous avons tendance à être\p"
	.string "plutôt passionnés.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Maman est plus forte que papa. Je\n"
	.string "suis plus fort que maman. Et\p"
	.string "grand-mère est plus forte que moi !\n"
	.string "Mais mon grand frère est encore\p"
	.string "plus fort que grand-mère.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Il ne fait aucun doute que tu es\n"
	.string "fort. Mais si tu combattais mon\p"
	.string "petit-fils, tu finirais par pleurer\n"
	.string "de frustration. Il est beaucoup\p"
	.string "plus fort que n'importe quel\n"
	.string "DRESSEUR que notre famille connaît.\p"
	.string "Il doit maintenant défier le\n"
	.string "CHAMPION DE LA LIGUE POKéMON.\p"
	.string "Connaissant mon petit-fils, il\n"
	.string "pourrait déjà être le CHAMPION !$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Mon petit-fils doit déjà défier le\n"
	.string "CHAMPION DE LA LIGUE POKéMON.\p"
	.string "Connaissant mon petit-fils, il\n"
	.string "pourrait déjà être le CHAMPION !$"
