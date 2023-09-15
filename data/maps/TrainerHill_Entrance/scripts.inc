.set LOCALID_ATTENDANT, 1
.set LOCALID_NURSE, 2
.set LOCALID_GIRL, 4
.set LOCALID_MAN, 5

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_NURSE
	addobject LOCALID_ATTENDANT
	addobject LOCALID_MAN
	addobject LOCALID_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_Text_StillGettingReady:
	.string "C'est la DRESSEUR HILL où vous\n"
	.string "pourrez participer à des combats de\p"
	.string "tags avec de nombreux DRESSEURS.\n"
	.string "Malheureusement, nous sommes encore\p"
	.string "en train de préparer les choses.\n"
	.string "S'il vous plaît, revenez plus tard\p"
	.string "!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Accueillir! C'est la DRESSEUR HILL\n"
	.string "où vous pourrez participer à des\p"
	.string "combats de tags avec de nombreux\n"
	.string "DRESSEURS !$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Est-ce votre première visite ici ?\n"
	.string "Avant de participer, veuillez\p"
	.string "sauvegarder votre partie.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Voyons voir… Les DRESSEURS\n"
	.string "ici maintenant sont… Jusqu'à\p"
	.string "l'étage no. {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Voyons voir… Les DRESSEURS\n"
	.string "ici maintenant sont… Il semble y\p"
	.string "avoir des DRESSEURS\n"
	.string "rassemblés dans chaque pièce.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Aimeriez-vous défier les\n"
	.string "DRESSEURS en attente ?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Je chronométrerai vos progrès.\n"
	.string "Bonne chance! À vos marques… Prêts…\p"
	.string "Partez!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "S'il vous plaît, revenez nous\n"
	.string "rendre visite !$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "C'était dommage. Je pense que vous\n"
	.string "avez déployé d'énormes efforts dans\p"
	.string "vos combats. Veuillez revenir et\n"
	.string "réessayer !$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "J'espère que vous ferez de votre\n"
	.string "mieux.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Lorsque les DRESSEURS\n"
	.string "changent de place, le mouvement\p"
	.string "peut être mouvementé. Pour éviter\n"
	.string "la bousculade, nous avons déplacé\p"
	.string "le comptoir de réception ici. Je\n"
	.string "suis désolé pour le désagrément.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Merci d'avoir joué !$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Ici, au DRESSEUR HILL, nous\n"
	.string "organisons un événement appelé Time\p"
	.string "Attack. Il s'agit d'une course qui\n"
	.string "mesure le temps qu'il vous faut\p"
	.string "pour rejoindre notre propriétaire\n"
	.string "sur le toit depuis ce comptoir. Les\p"
	.string "temps les plus rapides sont\n"
	.string "affichés sur le Time Board. Essayez\p"
	.string "de rivaliser avec vos amis. Dans\n"
	.string "les batailles DRESSEUR en cours de\p"
	.string "route, ni Exp. Des points ni de\n"
	.string "l'argent ne seront attribués.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, je suis désolé, mais vous\n"
	.string "semblez n'avoir qu'un seul POKéMON\p"
	.string "avec vous. Vous aurez besoin d'au\n"
	.string "moins deux POKéMON pour participer\p"
	.string "à cet événement.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hum ! Hum ! Tu es enfin venu ! Oui,\n"
	.string "vous êtes arrivé ! Attendez! Ne le\p"
	.string "dis pas ! Je sais pourquoi tu es\n"
	.string "venu jusqu'ici tout seul ! Vous\p"
	.string "vouliez me voir, le propriétaire du\n"
	.string "DRESSEUR HILL, parce que… Vous\p"
	.string "voulez former une équipe avec moi !\n"
	.string "Wa-hoo ! …Euh? Ce n'est pas ça?\p"
	.string "Quoi qu'il en soit, je t'ai regardé\n"
	.string "monter. Merveilleux combat ! Bravo,\p"
	.string "en effet !$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Pour quelqu'un de merveilleux comme\n"
	.string "toi, j'ai le cadeau le plus\p"
	.string "merveilleux !$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh non, plein de choses ! Vous\n"
	.string "reviendrez plus tard pour ça !$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, attends ici ! Etes-vous arrivé\n"
	.string "ici merveilleusement vite ? Comme\p"
	.string "c'est splendide ! Il ne fallait pas\n"
	.string "se dépêcher pour me voir ! C'est\p"
	.string "tellement délicieux. Je ferai\n"
	.string "mettre à jour le Time Board à la\p"
	.string "réception !$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Mais, oh… Tu n'es pas arrivé très\n"
	.string "vite ici.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Peut-être que cela me plairait\n"
	.string "davantage si vous arriviez plus\p"
	.string "zippé la prochaine fois. Alors, je\n"
	.string "serais ravi de former une équipe\p"
	.string "avec vous ! En attendant de nous\n"
	.string "revoir, amigo !$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "J'ai fait construire le DRESSEUR\n"
	.string "HILL pour une seule et unique\p"
	.string "raison ! Pour trouver le partenaire\n"
	.string "le plus approprié avec lequel je\p"
	.string "pourrais former une équipe !$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} secondes\n"
	.string "$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Qui sait quels types de combos de\n"
	.string "dresseurs et de POKéMON vous\p"
	.string "attendent ? Tout ce que je sais,\n"
	.string "c'est que je repousserai tous ceux\p"
	.string "qui se mettront en travers de mon\n"
	.string "chemin !$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "J'ai entendu des DRESSEURS\n"
	.string "coriaces venir de partout à ce\p"
	.string "DRESSEUR HILL. J'ai hâte de tester\n"
	.string "le terrain ! Je repousserai tous\p"
	.string "ceux qui se mettront en travers de\n"
	.string "mon chemin !$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Voyez-vous le Time Board là-bas ?\n"
	.string "Mes amis et moi essayons de voir\p"
	.string "qui peut atteindre le sommet en un\n"
	.string "minimum de temps.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Savez-vous quand ils ouvriront cet\n"
	.string "endroit ? J'attends ici d'être le\p"
	.string "premier challenger de tous les\n"
	.string "temps !$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Souhaitez-vous retourner au\n"
	.string "comptoir de réception?$"
