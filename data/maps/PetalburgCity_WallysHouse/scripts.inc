.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Vous êtes... Ah, vous devez être\n"
	.string "{PLAYER}{KUN}, n'est-ce pas ? Merci\p"
	.string "d'avoir joué avec TIMMY il y a\n"
	.string "quelques temps. Il est fragile et\p"
	.string "malade depuis qu'il est bébé. Nous\n"
	.string "l'avons envoyé chez mes proches à\p"
	.string "VERGUIDOTURF TOWN pendant un\n"
	.string "certain temps. L’air y est beaucoup\p"
	.string "plus pur qu’ici. Qu'est ce que\n"
	.string "c'est? Où est Wally? Il est déjà\p"
	.string "parti, notre TIMMY. Je me demande\n"
	.string "où il aurait pu se retrouver\p"
	.string "maintenant ?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Je me demande comment va notre\n"
	.string "TIMMY ?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN} ! Veuillez nous\n"
	.string "excuser de vous avoir entraîné ici\p"
	.string "de cette façon. Mais notre TIMMY\n"
	.string "est devenu en très bonne santé\p"
	.string "depuis qu'il est allé à\n"
	.string "VERGUIDOTURF TOWN. Nous vous devons\p"
	.string "tout ! Quand TIMMY a quitté la\n"
	.string "ville, vous l'avez aidé à attraper\p"
	.string "un POKéMON, n'est-ce pas ? Je pense\n"
	.string "que cela a rendu TIMMY vraiment\p"
	.string "heureux. En fait, pas seulement\n"
	.string "TIMMY. Cela m'a rendu heureux\p"
	.string "aussi, moi et son père. Heureux\n"
	.string "qu'il ait gagné un si grand ami\p"
	.string "comme toi. Ce n'est pas un\n"
	.string "pot-de-vin ou quoi que ce soit,\p"
	.string "mais j'aimerais vraiment que vous\n"
	.string "ayez ça.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Si votre POKéMON peut SURFER, vous\n"
	.string "pourrez aller dans toutes sortes\p"
	.string "d'endroits.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "TIMMY rentre bientôt à la maison.\n"
	.string "J'attends ça avec impatience.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh? Vous avez rencontré TIMMY dans\n"
	.string "ETERNARA ? Oh, {PLAYER}{KUN}, ne\p"
	.string "sois pas stupide. Il a peut-être\n"
	.string "retrouvé la santé, mais il ne peut\p"
	.string "pas aller seul dans un endroit\n"
	.string "aussi éloigné.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "TIMMY était vraiment content\n"
	.string "lorsqu'il nous a annoncé qu'il\p"
	.string "avait attrapé un POKéMON. Cela\n"
	.string "faisait des lustres que je ne\p"
	.string "l'avais pas vu sourire comme ça.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Je veux que tu gardes cela secret\n"
	.string "pour mon mari… Mais notre TIMMY a\p"
	.string "quitté VERGUIDOTURF TOWN sans en\n"
	.string "parler à personne. Vous savez,\p"
	.string "TIMMY est fragile, mais il est\n"
	.string "étonnamment volontaire. Je suis sûr\p"
	.string "qu'il reviendra sain et sauf un\n"
	.string "jour !$"
