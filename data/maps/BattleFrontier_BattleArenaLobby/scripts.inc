.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "Où l'esprit combatif des\n"
	.string "DRESSEURS est mis à l'épreuve\p"
	.string "! Je vous souhaite la bienvenue\n"
	.string "dans la BATTLE ARENA ! Je suis\p"
	.string "votre guide pour le tournoi Set KO\n"
	.string "!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Maintenant, souhaitez-vous relever\n"
	.string "le défi BATTLE ARENA ?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Nous attendons votre défi à une\n"
	.string "autre occasion!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "Dans la BATTLE ARENA, nous\n"
	.string "entreprenons le Set KO Tourney.\p"
	.string "Tous les participants entrent avec\n"
	.string "une équipe de trois POKéMON. Les\p"
	.string "trois POKéMON doivent être alignés\n"
	.string "dans l'ordre dans lequel ils\p"
	.string "doivent apparaître. Pendant la\n"
	.string "bataille, les POKéMON apparaîtront\p"
	.string "un par un dans l'ordre prédéfini.\n"
	.string "Une fois qu'un POKéMON entre en\p"
	.string "combat, il doit rester dehors\n"
	.string "jusqu'à ce que le match soit\p"
	.string "décidé. Si un match reste indécis\n"
	.string "après trois tours, il est soumis au\p"
	.string "jugement. Si vous souhaitez\n"
	.string "interrompre votre défi, veuillez\p"
	.string "sauvegarder la partie. Si vous ne\n"
	.string "sauvegardez pas, vous ne pourrez\p"
	.string "pas continuer votre défi. Si vous\n"
	.string "réussissez l'exploit de battre sept\p"
	.string "DRESSEURS à la suite, nous vous\n"
	.string "remettrons des Battle Points.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Avant de vous montrer la BATTLE\n"
	.string "ARENA, vous devez sauvegarder.\p"
	.string "Est-ce que ça va ?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "La BATTLE ARENA propose deux\n"
	.string "niveaux de défi, le niveau 50 et le\p"
	.string "niveau ouvert. Quel est votre choix\n"
	.string "?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Très bien, sélectionnez maintenant\n"
	.string "vos trois POKéMON, s'il vous\p"
	.string "plaît.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Mon cher challenger ! Vous ne\n"
	.string "possédez pas les trois POKéMON\p"
	.string "requis pour participer. Pour vous\n"
	.string "qualifier, vous devez apporter\p"
	.string "trois types différents de POKéMON.\n"
	.string "Ils ne doivent pas non plus détenir\p"
	.string "les mêmes types d’objets.\n"
	.string "EGGS{STR_VAR_1} n'est pas éligible.\p"
	.string "Lorsque vous aurez fait vos\n"
	.string "préparatifs, veuillez revenir.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Mon cher challenger ! Vous ne\n"
	.string "possédez pas les trois POKéMON\p"
	.string "requis pour participer. Pour vous\n"
	.string "qualifier, vous devez apporter\p"
	.string "trois types différents de POKéMON.\n"
	.string "Les trois POKéMON différents\p"
	.string "doivent tous être de niveau 50 ou\n"
	.string "inférieur. Ils ne doivent pas non\p"
	.string "plus détenir les mêmes types\n"
	.string "d’objets. EGGS{STR_VAR_1} n'est pas\p"
	.string "éligible. Lorsque vous aurez fait\n"
	.string "vos préparatifs, veuillez revenir.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Je vais maintenant vous guider vers\n"
	.string "la BATTLE ARENA.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Mon cher challenger ! Vous n'avez\n"
	.string "pas sauvegardé le jeu avant de\p"
	.string "l'arrêter, n'est-ce pas ? C'est\n"
	.string "malheureux, mais cela a entraîné\p"
	.string "votre disqualification de votre\n"
	.string "défi. Vous pouvez bien sûr repartir\p"
	.string "avec un nouveau défi.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Nous vous félicitons pour votre\n"
	.string "splendide série de victoires sur\p"
	.string "sept DRESSEURS !$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Votre réussite sera enregistrée.\n"
	.string "Veuillez patienter pendant que je\p"
	.string "sauvegarde le jeu.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "En commémoration de votre séquence\n"
	.string "de 7 victoires consécutives, nous\p"
	.string "vous remettons ce prix.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} a reçu le prix {STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Oh? Votre BAG semble être plein. Je\n"
	.string "vous exhorte à libérer de l'espace\p"
	.string "et à revenir chercher votre prix.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Merci beaucoup pour avoir\n"
	.string "participé! Veuillez patienter\p"
	.string "pendant que je sauvegarde le jeu.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Nous attendons votre défi à une\n"
	.string "autre occasion!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Nous attendions votre arrivée avec\n"
	.string "impatience. Avant de vous montrer\p"
	.string "la BATTLE ARENA, je dois\n"
	.string "sauvegarder la partie. Veuillez\p"
	.string "patienter.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Dois-je enregistrer votre dernier\n"
	.string "match BATTLE ARENA sur votre\p"
	.string "FRONTIER PASS ?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "J'ai perdu sur la décision de\n"
	.string "l'ARBITRE… Je ne pense pas que ce\p"
	.string "soit une bonne idée de n'utiliser\n"
	.string "que des mouvements défensifs et de\p"
	.string "ne pas attaquer…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "J'ai gagné au jugement !\n"
	.string "L'atterrissage des coups sur le\p"
	.string "POKéMON de l'adversaire a\n"
	.string "fonctionné !$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Notre match a été déclaré nul.\n"
	.string "Lorsque nous avons manqué de temps,\p"
	.string "mon POKéMON et celui de\n"
	.string "l'adversaire avaient à peu près la\p"
	.string "même quantité de HP.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "Dans la BATTLE ARENA, l'ordre des\n"
	.string "POKéMON est totalement important.\p"
	.string "Par exemple, si votre premier\n"
	.string "POKéMON présente certains\p"
	.string "inconvénients de type, essayez de\n"
	.string "créer votre deuxième POKéMON avec\p"
	.string "des mouvements super efficaces\n"
	.string "contre le premier. Je pense que ce\p"
	.string "sera une bonne manière de\n"
	.string "constituer une équipe efficace.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Les règles du Set KO Tourney sont\n"
	.string "répertoriées.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Quelle rubrique souhaitez-vous lire\n"
	.string "?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "Le Set KO Tourney a des règles\n"
	.string "spéciales, contrairement aux\p"
	.string "batailles standards. Premièrement,\n"
	.string "une bataille ne dure que trois\p"
	.string "tours. Si le résultat n'est pas\n"
	.string "décidé après trois tours, il est\p"
	.string "soumis au jugement. L'ARBITRE\n"
	.string "choisira le gagnant en fonction de\p"
	.string "la façon dont le POKéMON s'est\n"
	.string "battu. De plus, un POKéMON ne peut\p"
	.string "pas être éteint tant que l'issue de\n"
	.string "sa bataille n'est pas décidée.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "Le premier facteur de jugement est\n"
	.string "“ l’esprit ”. Ce facteur évalue le\p"
	.string "degré d'agressivité des\n"
	.string "combattants. Le jugement est basé\p"
	.string "sur la fréquence à laquelle les\n"
	.string "DRESSEURS ont ordonné l'utilisation\p"
	.string "de mouvements offensifs.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "Le deuxième facteur de jugement est\n"
	.string "la “ compétence ”. Ce facteur\p"
	.string "évalue l'efficacité avec laquelle\n"
	.string "les mouvements POKéMON ont été\p"
	.string "utilisés. Si un mouvement a\n"
	.string "fonctionné avec succès, le niveau\p"
	.string "de compétence augmente. Si un\n"
	.string "mouvement échoue, le niveau de\p"
	.string "compétence est réduit. S'il s'agit\n"
	.string "d'un mouvement offensif, la valeur\p"
	.string "de compétence augmente si le\n"
	.string "mouvement est “ super efficace ” et\p"
	.string "diminue s'il n'est “ pas très\n"
	.string "efficace ”. Le niveau de compétence\p"
	.string "n'augmentera pas pour des\n"
	.string "mouvements tels que PROTÉGER et\p"
	.string "DÉTECTER. Si l'adversaire a utilisé\n"
	.string "PROTÉGER ou DÉTECTER et que votre\p"
	.string "POKéMON n'a pas réussi à toucher\n"
	.string "avec un mouvement, sa valeur de\p"
	.string "compétence ne diminuera pas.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "Le troisième facteur de jugement\n"
	.string "est le “ corps ”. Ce facteur est\p"
	.string "basé sur la quantité de PV restant\n"
	.string "à la fin d'une bataille. La note\p"
	.string "prend en compte la quantité de PV\n"
	.string "d'un POKéMON au début de la\p"
	.string "bataille et ce qui lui restait à la\n"
	.string "fin.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Une victoire arrachée à l'ARENA\n"
	.string "TYCOON et un balayage de sept\p"
	.string "DRESSEUR ! Nous vous félicitons\n"
	.string "pour votre plus beau défi !$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Mon cher challenger, en\n"
	.string "reconnaissance de votre esprit\p"
	.string "infatigable, veuillez accepter ces\n"
	.string "points de bataille.$"
