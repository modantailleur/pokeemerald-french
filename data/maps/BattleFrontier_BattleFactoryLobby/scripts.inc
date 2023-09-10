.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "Où l'intelligence des\n"
	.string "FORMATTHIEUEURS est mise à\p"
	.string "l'épreuve ! Bienvenue à la BATTLE\n"
	.string "FACTORY ! Je suis votre guide pour\p"
	.string "le tournoi Battle Swap Single.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "Souhaitez-vous relever le défi\n"
	.string "Battle Swap Single ?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "Le Battle Swap Single Tournament\n"
	.string "est une compétition de COMBAT\p"
	.string "UNIQUE utilisant uniquement des\n"
	.string "POKéMON de location. Dans un\p"
	.string "premier temps, trois POKéMON vous\n"
	.string "seront prêtés spécifiquement pour\p"
	.string "cet événement. En utilisant le\n"
	.string "POKéMON de location fourni, vous\p"
	.string "devez mener une SEULE BATAILLE. Si\n"
	.string "vous gagnez, vous êtes autorisé à\p"
	.string "échanger l'un de vos POKéMON de\n"
	.string "location. Répétez ce cycle de\p"
	.string "combats et d'échanges : si vous\n"
	.string "gagnez sept fois de suite, vous\p"
	.string "gagnerez des points de combat. Si\n"
	.string "vous souhaitez interrompre votre\p"
	.string "défi, veuillez sauvegarder la\n"
	.string "partie. Si vous n'enregistrez pas,\p"
	.string "vous serez disqualifié de votre\n"
	.string "défi.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Nous attendons avec impatience\n"
	.string "votre prochaine visite.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "Quel niveau souhaitez-vous défier ?\n"
	.string "Niveau 50 ou niveau ouvert ?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Avant de commencer votre défi, je\n"
	.string "dois sauvegarder la partie. Est-ce\p"
	.string "que ça va ?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "D'accord, je garderai votre POKéMON\n"
	.string "en sécurité pendant votre\p"
	.string "compétition.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "Veuillez passer par ici.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "Merci d'avoir participé! Je vous\n"
	.string "rendrai votre POKéMON en échange de\p"
	.string "notre POKéMON de location. Je dois\n"
	.string "également sauvegarder les résultats\p"
	.string "de l'événement. Veuillez\n"
	.string "patienter.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Je vous rendrai votre POKéMON en\n"
	.string "échange de notre POKéMON de\p"
	.string "location.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "Toutes nos félicitations! Vous avez\n"
	.string "remporté sept matchs Battle Swap\p"
	.string "consécutifs !$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "En reconnaissance de votre séquence\n"
	.string "de 7 victoires consécutives, nous\p"
	.string "vous attribuons ces points de\n"
	.string "bataille.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "Oh oh oh! Vos points de combat sont\n"
	.string "au maximum. Veuillez revenir après\p"
	.string "avoir utilisé quelques points de\n"
	.string "combat.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "Nous vous attendions ! Avant de\n"
	.string "reprendre votre défi, je dois\p"
	.string "sauvegarder la partie.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Je suis désolé de le dire, mais\n"
	.string "vous n'avez pas sauvegardé avant\p"
	.string "d'arrêter de jouer la dernière\n"
	.string "fois. En conséquence, vous avez été\p"
	.string "disqualifié de votre défi.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Nous vous rendrons votre POKéMON\n"
	.string "personnel.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} a reçu le prix {STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "Où l'intelligence des\n"
	.string "FORMATTHIEUEURS est mise à\p"
	.string "l'épreuve ! Bienvenue à la BATTLE\n"
	.string "FACTORY ! Je suis votre guide pour\p"
	.string "le tournoi Battle Swap Double.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "Souhaitez-vous relever le défi\n"
	.string "Battle Swap Double ?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "Le Battle Swap Double Tournament\n"
	.string "est une compétition DOUBLE BATTLE\p"
	.string "utilisant uniquement des POKéMON de\n"
	.string "location. Dans un premier temps,\p"
	.string "trois POKéMON vous seront prêtés\n"
	.string "spécifiquement pour cet événement.\p"
	.string "En utilisant le POKéMON de location\n"
	.string "fourni, vous devez mener une DOUBLE\p"
	.string "BATAILLE. Si vous gagnez, vous êtes\n"
	.string "autorisé à échanger l'un de vos\p"
	.string "POKéMON de location. Répétez ce\n"
	.string "cycle de combats et d'échanges : si\p"
	.string "vous gagnez sept fois de suite,\n"
	.string "vous gagnerez des points de combat.\p"
	.string "Si vous souhaitez interrompre votre\n"
	.string "défi, veuillez sauvegarder la\p"
	.string "partie. Si vous ne sauvegardez pas\n"
	.string "avant d'interrompre, vous serez\p"
	.string "disqualifié.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "Félicitations pour avoir vaincu le\n"
	.string "FACTORY HEAD et remporté sept\p"
	.string "matchs d'affilée !$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "En reconnaissance de la richesse de\n"
	.string "vos connaissances et de votre\p"
	.string "intelligence approfondie, nous vous\n"
	.string "attribuons ces points de bataille.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Laissez-moi échanger votre POKéMON\n"
	.string "contre notre POKéMON de location.\p"
	.string "Je dois sauvegarder les données de\n"
	.string "combat, alors veuillez patienter.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "Souhaitez-vous enregistrer votre\n"
	.string "dernier match BATTLE FACTORY sur\p"
	.string "votre FRONTIER PASS ?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "Salut! Toi là! Pensez-vous que les\n"
	.string "événements ici sont faciles puisque\p"
	.string "vous n'avez pas besoin d'avoir une\n"
	.string "équipe de POKéMON élevée ? Je ne\p"
	.string "serais pas sûr de gagner aussi\n"
	.string "facilement. Si vous n'avez pas une\p"
	.string "connaissance approfondie des\n"
	.string "POKéMON et de leurs mouvements, il\p"
	.string "sera difficile de continuer à\n"
	.string "gagner.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "J'ai échangé contre un POKéMON\n"
	.string "faible… Je pensais que c'était un\p"
	.string "bon type à avoir… Ils ont essuyé le\n"
	.string "sol avec nous…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Les choses ne se passent pas du\n"
	.string "tout comme je le souhaite. Vous\p"
	.string "devez vérifier le POKéMON de votre\n"
	.string "adversaire pendant le combat pour\p"
	.string "voir s'il est bon.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "Vous savez comment le staff ici\n"
	.string "vous donne quelques indices sur\p"
	.string "votre prochain adversaire ? Eh\n"
	.string "bien, je suis un homme adulte, mais\p"
	.string "j'ai du mal à comprendre leurs\n"
	.string "indices.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Je suis vraiment dur, mais je\n"
	.string "m'ennuie très facilement, alors\p"
	.string "j'ai continué à échanger et à me\n"
	.string "battre encore et encore. Quoi qu'il\p"
	.string "en soit, lorsque j'ai continué à\n"
	.string "participer aux événements Battle\p"
	.string "Swap, j'ai remarqué qu'ils\n"
	.string "variaient les POKéMON de location.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "Les règles de Battle Swap sont\n"
	.string "répertoriées.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "Quelle rubrique souhaitez-vous lire\n"
	.string "?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "Dans un événement Battle Swap, vous\n"
	.string "ne pouvez utiliser que trois\p"
	.string "POKéMON. Que vous louiez ou\n"
	.string "échangeiez, votre équipe peut ne\p"
	.string "pas avoir deux ou plusieurs POKéMON\n"
	.string "identiques.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Vous ne pouvez échanger des POKéMON\n"
	.string "qu'avec l'DRESSEUR que vous venez\p"
	.string "de vaincre. Vous pouvez échanger\n"
	.string "uniquement contre les POKéMON\p"
	.string "utilisés par l'DRESSEUR battu.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "Après chaque bataille que vous\n"
	.string "gagnez, vous pouvez échanger contre\p"
	.string "l'un des POKéMON de votre\n"
	.string "adversaire vaincu. Vous ne pourrez\p"
	.string "pas échanger de POKéMON avec le\n"
	.string "septième DRESSEUR de l'événement.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Il y a deux points clés à prendre\n"
	.string "en compte lors d'un échange de\p"
	.string "POKéMON. Premièrement, lors d'un\n"
	.string "échange, vous ne pouvez pas\p"
	.string "vérifier les statistiques du\n"
	.string "POKéMON que vous êtes sur le point\p"
	.string "de recevoir. Deuxièmement, les\n"
	.string "POKéMON de votre équipe sont\p"
	.string "alignés dans l'ordre, en fonction\n"
	.string "de l'ordre dans lequel vous les\p"
	.string "avez loués. Cette séquence reste\n"
	.string "inchangée même lorsque des échanges\p"
	.string "sont effectués.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "Dans le Niveau Ouvert, le POKéMON\n"
	.string "de location et le POKéMON DES\p"
	.string "DRESSEURS adverses sont tous de\n"
	.string "Niveau 100.$"
