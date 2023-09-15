.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "Où le cœur des DRESSEURS est\n"
	.string "mis à rude épreuve. Je vous\p"
	.string "souhaite la bienvenue au BATTLE\n"
	.string "PALACE. J'accepte les défis des\p"
	.string "SALLES DE COMBAT UNIQUES.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "Souhaitez-vous relever le défi\n"
	.string "SINGLE BATTLE HALL ?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "Dans le BATTLE PALACE, il y a\n"
	.string "plusieurs auditoriums pour les\p"
	.string "BATAILLES SINGLE qui sont nommés\n"
	.string "SINGLE BATTLE HALLS. Les BATAILLES\p"
	.string "SIMPLES se déroulent de la manière\n"
	.string "habituelle, sauf avec une règle\p"
	.string "cruciale qui doit être respectée.\n"
	.string "LES DRESSEURS sont autorisés\p"
	.string "uniquement à activer et désactiver\n"
	.string "leur POKéMON. Il est par ailleurs\p"
	.string "interdit aux dresseurs de commander\n"
	.string "leur POKéMON. Les POKéMON doivent\p"
	.string "se comporter selon leur nature et\n"
	.string "se battre seuls. Vous devez faire\p"
	.string "confiance à vos POKéMON et veiller\n"
	.string "sur eux. Si vous obtenez l'honneur\p"
	.string "de battre sept DRESSEURS à la\n"
	.string "suite, nous vous remettrons des\p"
	.string "Battle Points. Si vous souhaitez\n"
	.string "interrompre votre défi, vous devez\p"
	.string "sauvegarder la partie. Si vous ne\n"
	.string "sauvegardez pas avant\p"
	.string "d'interrompre, vous serez\n"
	.string "disqualifié.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Lorsque vous avez fortifié votre\n"
	.string "cœur et POKéMON, vous devez\p"
	.string "revenir.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Il y a deux SALLES DE COMBAT,\n"
	.string "niveau 50 et niveau ouvert. Quel\p"
	.string "est votre choix de défi ?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Soupir… Vous n'avez pas les trois\n"
	.string "POKéMON nécessaires au défi. Pour\p"
	.string "participer, vous devez fournir\n"
	.string "trois types différents de POKéMON.\p"
	.string "Ces POKéMON doivent tous être de\n"
	.string "niveau 50 ou inférieur. Ils ne\p"
	.string "doivent pas non plus détenir les\n"
	.string "mêmes types d’objets. EGGS{STR_VAR_1}\p"
	.string "n'est pas éligible. Revenez quand\n"
	.string "vous aurez fait vos préparatifs.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Soupir… Vous n'avez pas les trois\n"
	.string "POKéMON nécessaires au défi. Pour\p"
	.string "participer, vous devez fournir\n"
	.string "trois types différents de POKéMON.\p"
	.string "Ils ne doivent pas non plus détenir\n"
	.string "les mêmes types d’objets.\p"
	.string "EGGS{STR_VAR_1} n'est pas éligible.\n"
	.string "Revenez quand vous aurez fait vos\p"
	.string "préparatifs.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Bien. Maintenant, vous devez\n"
	.string "sélectionner vos trois POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Je dois sauvegarder avant de vous\n"
	.string "montrer le BATTLE HALL. Est-ce que\p"
	.string "ça va ?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Bien. Maintenant, suis-moi.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "Je me sens privilégié d'avoir vu\n"
	.string "les exploits de votre POKéMON. Les\p"
	.string "résultats seront enregistrés. Je\n"
	.string "dois vous demander d'attendre\p"
	.string "brièvement.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "Pour réaliser une séquence de 7\n"
	.string "victoires consécutives… Les liens\p"
	.string "qui unissent votre cœur à votre\n"
	.string "POKéMON semblent fermes et vrais.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "Votre exploit sera enregistré. Je\n"
	.string "dois vous demander d'attendre\p"
	.string "brièvement.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "Pour l'exploit de votre séquence de\n"
	.string "7 victoires consécutives, nous vous\p"
	.string "présentons des points de bataille.$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Vous semblez ne pas avoir de place\n"
	.string "pour notre prix. Vous devriez\p"
	.string "revenir lorsque vous aurez organisé\n"
	.string "votre BAG.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Nous vous attendions…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Je dois sauvegarder avant de vous\n"
	.string "montrer le BATTLE HALL. Est-ce que\p"
	.string "ça va ?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Soupir… Vous n'avez pas réussi à\n"
	.string "sauvegarder avant de terminer votre\p"
	.string "défi la dernière fois. En\n"
	.string "conséquence, votre défi a été\p"
	.string "disqualifié. C'est vraiment\n"
	.string "dommage.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} a reçu le prix {STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "Pour un homme courageux comme moi,\n"
	.string "les POKéMON robustes sont les\p"
	.string "meilleurs. L'offensive est la\n"
	.string "meilleure défense ! Une attaque\p"
	.string "implacable est l'ultime ! Mais ce\n"
	.string "n'est pas de cela dont je voulais\p"
	.string "parler. De temps en temps, une dame\n"
	.string "vraiment mignonne passe par ici.\p"
	.string "Elle dit qu'elle peut dire ce que\n"
	.string "pensent les POKéMON. Je ne sais pas\p"
	.string "pour cette partie, mais elle est\n"
	.string "vraiment mignonne. Hein? Pourquoi\p"
	.string "me regardes-tu comme ça ?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Hmm… Il semble que la nature des\n"
	.string "POKéMON et les mouvements qui leur\p"
	.string "ont été enseignés soient les clés\n"
	.string "du combat ici. Pour être plus\p"
	.string "précis, il s'agit de la façon dont\n"
	.string "les mouvements correspondent à la\p"
	.string "nature du POKéMON. Si votre POKéMON\n"
	.string "est en difficulté et incapable\p"
	.string "d'exploiter son potentiel, vous\n"
	.string "devrez peut-être examiner dans\p"
	.string "quelle mesure ses mouvements\n"
	.string "correspondent à sa nature.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "Mon POKéMON est généralement très\n"
	.string "docile. Mais lorsqu'il se trouve\p"
	.string "dans une SALLE DE COMBAT, il semble\n"
	.string "parfois se transformer en quelque\p"
	.string "chose de méchant ! Cela devient\n"
	.string "totalement intimidant. C'est même\p"
	.string "choquant.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Je me demande quel genre de nature\n"
	.string "aurait un POKéMON s'il privilégiait\p"
	.string "l'affaiblissement de ses\n"
	.string "adversaires et sa réduction lente.\p"
	.string "Je serais surpris si c'était une\n"
	.string "nature LAX. Mais non, ça ne peut\p"
	.string "pas être vrai.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "Où le cœur des DRESSEURS est\n"
	.string "mis à rude épreuve. Je vous\p"
	.string "souhaite la bienvenue au BATTLE\n"
	.string "PALACE. J'accepte les défis des\p"
	.string "DOUBLE SALLES DE BATAILLE.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "Vous souhaitez relever le défi\n"
	.string "DOUBLE BATTLE HALL ?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "Dans le BATTLE PALACE, il y a\n"
	.string "plusieurs auditoriums pour DOUBLE\p"
	.string "BATTLES qui sont nommés DOUBLE\n"
	.string "BATTLE HALLS. Les DOUBLE BATAILLES\p"
	.string "se déroulent de la manière\n"
	.string "habituelle, à l'exception d'une\p"
	.string "règle cruciale qui doit être\n"
	.string "respectée. LES DRESSEURS sont\p"
	.string "autorisés uniquement à activer et\n"
	.string "désactiver leur POKéMON. Il est par\p"
	.string "ailleurs interdit aux dresseurs de\n"
	.string "commander leur POKéMON. Les POKéMON\p"
	.string "doivent se comporter selon leur\n"
	.string "nature et se battre seuls. Vous\p"
	.string "devez faire confiance à vos POKéMON\n"
	.string "et veiller sur eux. Si vous obtenez\p"
	.string "l'honneur de battre sept DRESSEURS\n"
	.string "à la suite, nous vous remettrons\p"
	.string "des Battle Points. Si vous\n"
	.string "souhaitez interrompre votre défi,\p"
	.string "veuillez sauvegarder la partie. Si\n"
	.string "vous ne sauvegardez pas avant\p"
	.string "d'interrompre, vous serez\n"
	.string "disqualifié.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "Pour vaincre le PALACE MAVEN et\n"
	.string "sept DRESSEURS d'affilée…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "En l'honneur du lien que vous\n"
	.string "partagez avec votre POKéMON, nous\p"
	.string "vous présentons ce(s) Battle\n"
	.string "Point(s).$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "Souhaitez-vous enregistrer votre\n"
	.string "dernier match BATTLE PALACE sur\p"
	.string "votre FRONTIER PASS ?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "Les règles de BATTLE HALL sont\n"
	.string "répertoriées.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "Quelle rubrique souhaitez-vous lire\n"
	.string "?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Ici, les POKéMON doivent réfléchir\n"
	.string "et se battre par eux-mêmes.\p"
	.string "Contrairement à la nature, les\n"
	.string "POKéMON qui vivent avec les humains\p"
	.string "se comportent différemment selon\n"
	.string "leur nature.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Selon sa nature, un POKéMON peut\n"
	.string "préférer attaquer quoi qu'il\p"
	.string "arrive. Un autre POKéMON préférera\n"
	.string "peut-être se protéger de tout\p"
	.string "danger. Un autre encore peut aimer\n"
	.string "contrarier ou confondre ses\p"
	.string "ennemis. De par sa nature, un\n"
	.string "POKéMON aura des mouvements favoris\p"
	.string "qu'il sait bien utiliser. Il peut\n"
	.string "également ne pas aimer certains\p"
	.string "mouvements qu'il a du mal à\n"
	.string "utiliser.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Il existe des mouvements offensifs\n"
	.string "qui infligent des dégâts directs à\p"
	.string "l'ennemi. Il existe des mouvements\n"
	.string "défensifs qui sont utilisés pour se\p"
	.string "préparer aux attaques ennemies ou\n"
	.string "pour soigner des HP, etc. Il existe\p"
	.string "également d'autres mouvements\n"
	.string "quelque peu étranges qui peuvent\p"
	.string "affaiblir les ennemis avec des\n"
	.string "problèmes de statistiques,\p"
	.string "notamment le poison et la\n"
	.string "paralysie. POKéMON envisagera\p"
	.string "d'utiliser des mouvements dans ces\n"
	.string "trois catégories.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "Lorsqu'il n'est pas sous le\n"
	.string "commandement de son DRESSEUR, un\p"
	.string "POKéMON peut être incapable\n"
	.string "d'utiliser efficacement certaines\p"
	.string "capacités. Un POKéMON n'est pas\n"
	.string "doué pour utiliser les mouvements\p"
	.string "qu'il n'aime pas. Si un POKéMON ne\n"
	.string "connaît que des mouvements qui ne\p"
	.string "correspondent pas à sa nature, il\n"
	.string "sera souvent incapable d'exploiter\p"
	.string "tout son potentiel.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "Selon sa nature, un POKéMON peut\n"
	.string "commencer à utiliser des mouvements\p"
	.string "qui ne correspondent pas à sa\n"
	.string "nature lorsqu'il est en difficulté.\p"
	.string "Si un POKéMON commence à se\n"
	.string "comporter bizarrement,\p"
	.string "surveillez-le attentivement.$"
