.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MAMAN : Vous voyez, {PLAYER} ?\n"
	.string "N'est-ce pas agréable ici aussi ?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Les POKéMON du déménageur font tout\n"
	.string "le travail de déménagement et de\p"
	.string "nettoyage après. C'est tellement\n"
	.string "pratique ! {PLAYER}, votre chambre\p"
	.string "est à l'étage. Allez voir, chérie !\n"
	.string "Papa t'a acheté une nouvelle\p"
	.string "horloge pour marquer notre\n"
	.string "déménagement ici. N'oubliez pas de\p"
	.string "le régler !$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MAMAN : Eh bien, {PLAYER} ?\n"
	.string "N'êtes-vous pas intéressé à voir\p"
	.string "votre propre chambre ?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MAMAN : {PLAYER}. Va régler l'horloge\n"
	.string "dans ta chambre, chérie.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MAMAN : Oh ! {PLAYER}, {PLAYER} !\n"
	.string "Rapide! Venez vite!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MAMAN : Regarde ! C'est\n"
	.string "PGUIDOALBURG GYM ! Peut-être que\p"
	.string "papa sera là !$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MAMAN : Oh… C'est fini. Je pense\n"
	.string "que papa était là, mais il nous a\p"
	.string "manqué. Dommage.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Oh oui. Un des amis de papa habite\n"
	.string "en ville. PROF. SEKO est son nom.\p"
	.string "Il habite juste à côté, alors tu\n"
	.string "devrais y aller et te présenter.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MAMAN : À bientôt, chérie !$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MAMAN : Vous êtes-vous présenté au\n"
	.string "PROF. SEKO ?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MAMAN : Comment vas-tu, {PLAYER} ? Tu\n"
	.string "as l'air un peu fatigué. Je pense\p"
	.string "que tu devrais te reposer un peu.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MAMAN : Prends soin de toi, chérie\n"
	.string "!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MAMAN : Ah ? Est-ce que papa t'a\n"
	.string "donné ce BADGE ? Alors voici\p"
	.string "quelque chose de ta MAMAN !$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Ne vous forcez pas trop, chérie. Tu\n"
	.string "peux toujours venir à la maison.\p"
	.string "Vas-y, chérie !$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MAMAN : Qu'est-ce que c'est, chérie\n"
	.string "? Un POKéNAV ? Quelqu'un du DEVON\p"
	.string "vous l'a donné ? Et bien, chérie,\n"
	.string "que dirais-tu d'inscrire ta mère ?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "MAMAN enregistrée dans le POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWEUR : …Nous vous avons\n"
	.string "apporté ce rapport devant le\p"
	.string "PGUIDOALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Il y a un film à la télé. Deux\n"
	.string "hommes dansent sur un gros clavier\p"
	.string "de piano. Mieux vaut y aller !$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "C'est le livret d'instructions des\n"
	.string "CHAUSSURES DE RUNNING. “ Appuyez\p"
	.string "sur le bouton B pour courir en\n"
	.string "portant vos CHAUSSURES DE RUNNING.\p"
	.string "“ Enfilez vos CHAUSSURES DE COURSE\n"
	.string "et prenez la route en courant ! ”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "PAPA : Hm ? Hé, c'est {PLAYER} ! Cela\n"
	.string "fait un moment que je ne t'ai pas\p"
	.string "vu, mais tu as l'air… plus fort,\n"
	.string "d'une manière ou d'une autre. C'est\p"
	.string "l'impression que j'ai. Mais ton\n"
	.string "vieux n'a pas encore abandonné !\p"
	.string "Oh, oui, j'ai quelque chose pour\n"
	.string "toi. Cela vous est venu d'un\p"
	.string "certain M. MARCO.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAPA : Hm, un BILLGUIDO pour un\n"
	.string "ferry ? Si je me souviens bien, il\p"
	.string "y a des ports de ferry à SLATEPORT\n"
	.string "et LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Je ferais mieux de retourner au\n"
	.string "PGUIDOALBURG GYM. MAMAN, merci de\p"
	.string "t'occuper de la maison pendant mon\n"
	.string "absence.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MAMAN : Ton papa… Il rentre à la\n"
	.string "maison pour la première fois depuis\p"
	.string "longtemps, mais tout ce dont il\n"
	.string "parle, c'est de POKéMON. Il devrait\p"
	.string "se détendre et rester un peu plus\n"
	.string "longtemps.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM : Est-ce une nouvelle de\n"
	.string "dernière heure ?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Nous vous proposons ce flash\n"
	.string "d'information d'urgence ! Dans\p"
	.string "divers endroits de HOENN, il y a eu\n"
	.string "des rapports d'un POKéMON de\p"
	.string "couleur BZZT… en vol. L'identité de\n"
	.string "ce POKéMON est actuellement\p"
	.string "inconnue. Nous vous revenons\n"
	.string "maintenant au programme régulier du\p"
	.string "cinéma.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MAMAN : {PLAYER}, tu as compris ? De\n"
	.string "quelle couleur l'annonceur a-t-il\p"
	.string "dit qu'il était POKéMON ?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MAMAN : Eh bien, n'est-ce pas\n"
	.string "quelque chose ! Il existe encore\p"
	.string "des POKéMON inconnus.$"
