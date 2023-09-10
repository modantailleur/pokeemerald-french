.set LOCALID_ATTENDANT, 1
.set LOCALID_HINT_GIVER, 2

BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Où le courage des FORMATTHIEUEURS\n"
	.string "est mis à l’épreuve ! Bienvenue\p"
	.string "dans la PYRAMIDE DE BATAILLE ! Je\n"
	.string "suis votre guide pour la Battle\p"
	.string "Quest.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Avez-vous le courage de vous lancer\n"
	.string "dans le défi Battle Quest ?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Nous attendons votre défi à\n"
	.string "l'avenir !$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "La Battle Quest est un événement de\n"
	.string "combat dans lequel vous devez\p"
	.string "explorer la PYRAMIDE et tenter\n"
	.string "d'atteindre le sommet. Dans la\p"
	.string "PYRAMIDE se trouvent sept étages de\n"
	.string "labyrinthes, tous remplis non\p"
	.string "seulement d'DRESSEURS qualifiés\n"
	.string "mais aussi de POKéMON sauvages.\p"
	.string "Vous devez entrer avec trois\n"
	.string "POKéMON, aucun d'entre eux ne\p"
	.string "détenant d'objet. Lors de votre\n"
	.string "ascension, vous recevrez un SAC DE\p"
	.string "COMBAT pour les objets. Si vous\n"
	.string "échouez à votre défi, tout objet\p"
	.string "placé dans le SAC DE COMBAT\n"
	.string "disparaît. Si vous souhaitez\p"
	.string "interrompre votre défi, vous devez\n"
	.string "sélectionner “ REST ” et\p"
	.string "sauvegarder la partie. Si vous ne\n"
	.string "sauvegardez pas avant\p"
	.string "d'interrompre, vous serez\n"
	.string "disqualifié.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "La PYRAMIDE propose deux cours,\n"
	.string "niveau 50 et niveau ouvert. Dans\p"
	.string "lequel entrerez-vous ?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Très bien. Maintenant, veuillez\n"
	.string "sélectionner les trois POKéMON que\p"
	.string "vous souhaitez vous accompagner.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Un léger problème, aventurier !\n"
	.string "Vous semblez ne pas avoir les trois\p"
	.string "POKéMON qualifiés pour le défi.\n"
	.string "N'oubliez pas également de prendre\p"
	.string "tous les objets de votre POKéMON.\n"
	.string "EGGS{STR_VAR_1} n'est pas éligible.\p"
	.string "Lorsque vous serez prêt, parlez-moi\n"
	.string "s'il vous plaît.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Un léger problème, aventurier !\n"
	.string "Vous semblez ne pas avoir les trois\p"
	.string "POKéMON qualifiés pour le défi. Les\n"
	.string "trois POKéMON doivent être\p"
	.string "différents et chacun ne doit pas\n"
	.string "dépasser le niveau 50. N'oubliez\p"
	.string "pas également de prendre tous les\n"
	.string "objets de votre POKéMON. EGGS{STR_VAR_1}\p"
	.string "n'est pas éligible. Lorsque vous\n"
	.string "serez prêt, parlez-moi s'il vous\p"
	.string "plaît.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Avant d'entrer dans la BATTLE\n"
	.string "PYRAMID, le jeu doit être\p"
	.string "sauvegardé. Est-ce que ça va ?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Très bien. Je vais maintenant vous\n"
	.string "montrer la PYRAMIDE DE BATAILLE.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Nous conserverons votre SAC en lieu\n"
	.string "sûr, {PLAYER}, pendant que vous\p"
	.string "explorez.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "En échange, veuillez prendre ce SAC\n"
	.string "DE COMBAT, celui que vous avez\p"
	.string "utilisé précédemment.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "En échange, veuillez prendre ce SAC\n"
	.string "DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} a échangé le SAC contre le\n"
	.string "SAC DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Lorsque vous montez sur ce panneau\n"
	.string "de plancher, vous serez transporté\p"
	.string "à un étage supérieur de la\n"
	.string "PYRAMIDE. J'espère pour vous que\p"
	.string "votre quête se déroulera sans\n"
	.string "encombre !$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Un problème majeur, explorateur !\n"
	.string "Vous n'avez pas sauvegardé avant de\p"
	.string "terminer votre défi la dernière\n"
	.string "fois. Par conséquent, votre défi a\p"
	.string "été disqualifié, je suis désolé de\n"
	.string "le dire. Voici le SAC que nous vous\p"
	.string "réservons. {PLAYER} a récupéré le\n"
	.string "SAC.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Ravie de vous revoir ! Vous avez\n"
	.string "conquis la PYRAMIDE ! Comme c'est\p"
	.string "magnifique!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, un petit problème. Au moins un\n"
	.string "POKéMON tient un objet. Je suis\p"
	.string "désolé de le dire, mais les objets\n"
	.string "obtenus dans la PYRAMIDE ne peuvent\p"
	.string "pas être emportés.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Tous les objets détenus par votre\n"
	.string "POKéMON seront déplacés vers votre\p"
	.string "SAC DE COMBAT, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Le BATTLE BAG ne peut pas contenir\n"
	.string "tous vos objets, je suis désolé de\p"
	.string "le dire. Veuillez choisir les\n"
	.string "objets que vous garderez dans le\p"
	.string "SAC DE COMBAT et avec votre\n"
	.string "POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Au moins un POKéMON détient\n"
	.string "toujours un objet.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Veuillez choisir les objets que\n"
	.string "vous garderez dans le SAC DE COMBAT\p"
	.string "et avec votre POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} a rendu tout ce que\n"
	.string "contenait le POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "Le BATTLE BAG que vous avez utilisé\n"
	.string "sera conservé prêt pour votre\p"
	.string "prochain défi. {PLAYER} a retourné le\n"
	.string "SAC DE COMBAT pour le retour du\p"
	.string "SAC.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Je dois enregistrer vos résultats.\n"
	.string "Veuillez patienter.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "En guise de souvenir de la conquête\n"
	.string "de la PYRAMIDE DE BATAILLE,\p"
	.string "veuillez prendre ceci.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} a reçu le prix {STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah… Votre SAC semble être rempli.\n"
	.string "Veuillez revenir après avoir\p"
	.string "organisé le contenu de votre SAC.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Quelle déception pour vous… Voici\n"
	.string "le SAC que nous vous réservions.\p"
	.string "{PLAYER} a récupéré le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Nous attendons avec impatience\n"
	.string "votre prochain défi !$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Nous attendions votre arrivée avec\n"
	.string "impatience ! Voici votre prix pour\p"
	.string "avoir conquis la PYRAMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Bienvenue… Il me fera plaisir de\n"
	.string "vous dire quels malheurs vous\p"
	.string "attendent dans la PYRAMIDE…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … … … … … … … … … … … … … …\n"
	.string "Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Je vois une pluie d'étincelles… …Et\n"
	.string "dedans, je vois ton POKéMON aux\p"
	.string "prises avec la paralysie…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Je vois du poison… …Et je vois\n"
	.string "votre POKéMON souffrir des effets\p"
	.string "du poison…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Je vois des flammes rouge vif… …Et,\n"
	.string "je vois ton POKéMON souffrant de\p"
	.string "brûlures…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Je sens l'énorme pression d'une\n"
	.string "colère non partagée… C'est une\p"
	.string "malédiction… …Et je vois votre\n"
	.string "POKéMON vidé de ses points de\p"
	.string "pouvoir et n'ayant d'autre recours\n"
	.string "que d'utiliser LA LUTTE…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Je vois POKéMON en l'air… …Et je\n"
	.string "vois votre POKéMON frustré par les\p"
	.string "mouvements impuissants de type\n"
	.string "SOL…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Je sens une énergie formidable\n"
	.string "monter du sol en contrebas… …Et je\p"
	.string "vois votre POKéMON incapable\n"
	.string "d'échapper aux griffes du pouvoir…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Je vois un POKéMON de type ICE… …Et\n"
	.string "je vois votre POKéMON combattant\p"
	.string "les effets glacials de la glace…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Je vois une série de mouvements qui\n"
	.string "mettent l'utilisateur en péril… …Et\p"
	.string "je vois votre POKéMON lui tomber\n"
	.string "dessus…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Je vois des POKéMON de type\n"
	.string "PSYCHIQUE… …Et, je vois votre\p"
	.string "POKéMON tourmenté par les\n"
	.string "mouvements PSYCHIQUES…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Je vois des POKéMON de type ROCK…\n"
	.string "…Et, je vois ton POKéMON souffrant\p"
	.string "de mouvements ROCK…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Je vois un POKéMON de type COMBAT…\n"
	.string "…Et je vois votre POKéMON frappé\p"
	.string "par des mouvements de COMBAT…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "GUIDOSE DE LA PLUIE… JOURNÉE\n"
	.string "ENSOLEILLÉE… TEMPÊTE DE SABLE…\p"
	.string "GRÊLE… Je vois des POKéMON qui\n"
	.string "deviennent plus forts avec la\p"
	.string "météo… …Et, je vois votre POKéMON\n"
	.string "confus par différents types de\p"
	.string "mouvements…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Je vois des POKéMON de type BUG…\n"
	.string "…Et, je vois votre POKéMON\p"
	.string "souffrant de différents types\n"
	.string "d'attaques…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Je vois un POKéMON de type\n"
	.string "TÉNÈBRES… …Et, je vois votre\p"
	.string "POKéMON souffrant de mouvements de\n"
	.string "type TÉNÈBRES…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Je vois un POKéMON de type EAU…\n"
	.string "…Et, je vois votre POKéMON\p"
	.string "souffrant de mouvements de type\n"
	.string "EAU…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Je vois un POKéMON de type FANTÔME…\n"
	.string "…Et, je vois votre POKéMON\p"
	.string "souffrant de mouvements de type\n"
	.string "FANTÔME…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Je vois un POKéMON de type ACIER…\n"
	.string "…Et je vois votre POKéMON souffrir\p"
	.string "de mouvements extrêmement\n"
	.string "puissants…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Je vois un POKéMON volant… …Et je\n"
	.string "vois votre POKéMON souffrir de\p"
	.string "mouvements extrêmement puissants…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Je vois ceux qui ont évolué grâce\n"
	.string "au pouvoir des pierres… Je sens\p"
	.string "aussi le feu, l'eau et\n"
	.string "l'électricité… …Et je vois votre\p"
	.string "POKéMON souffrant de ces trois\n"
	.string "pouvoirs…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Je vois un POKéMON de type NORMAL…\n"
	.string "…Et je vois votre POKéMON souffrir\p"
	.string "de mouvements extrêmement\n"
	.string "puissants…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Que vous croyiez ou non à ma\n"
	.string "fortune, le choix vous appartient…\p"
	.string "L'avenir peut être changé à tout\n"
	.string "moment… Je vous souhaite un bon\p"
	.string "passage…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Saviez-vous? Si vous courez vite,\n"
	.string "les DRESSEURS peuvent le remarquer\p"
	.string "et vous poursuivre pour une\n"
	.string "bataille. Donc, si vous voulez\p"
	.string "éviter les FORMATTHIEUEURS,\n"
	.string "n'attirez pas leur attention, mais\p"
	.string "faufilez-vous doucement et\n"
	.string "discrètement devant eux.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Awaaaaaarrrrgh ! J'avais beaucoup\n"
	.string "d'objets, mais je les ai tous\p"
	.string "perdus en perdant !\n"
	.string "Awaaaaaarrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Content de te revoir! Vous avez\n"
	.string "fait l'impensable ! Vous avez\p"
	.string "vaincu le PYRAMID KING et conquis\n"
	.string "la BATTLE PYRAMID !$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Jeune explorateur ! En guise de\n"
	.string "reconnaissance pour votre courage,\p"
	.string "nous vous offrons ces points de\n"
	.string "combat !$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Les règles de Battle Quest sont\n"
	.string "répertoriées.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Quelle rubrique souhaitez-vous lire\n"
	.string "?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Lorsque la PYRAMIDE est conquise,\n"
	.string "les POKéMON sauvages qui y\p"
	.string "apparaissent sont remplacés par\n"
	.string "différentes sortes. Explorez,\p"
	.string "observez et découvrez quels types\n"
	.string "de POKéMON sauvages vous pourriez\p"
	.string "rencontrer.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "DES FORMATTHIEUEURS vous attendent\n"
	.string "à l’intérieur de la PYRAMIDE. À\p"
	.string "chaque étage, il y a jusqu'à huit\n"
	.string "FORMATTHIEUEURS. Lorsque vous\p"
	.string "battez un DRESSEUR, vous recevrez\n"
	.string "un indice utile pour votre\p"
	.string "aventure.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Les labyrinthes de la PYRAMIDE se\n"
	.string "réorganisent à chaque fois que vous\p"
	.string "y entrez. Les labyrinthes sont mal\n"
	.string "éclairés. Il faut avancer avec\p"
	.string "prudence. La lumière devient plus\n"
	.string "brillante chaque fois que vous\p"
	.string "battez un POKéMON sauvage ou un\n"
	.string "DRESSEUR.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "Le SAC DE COMBAT vous sert de SAC\n"
	.string "lorsque vous êtes dans la PYRAMIDE.\p"
	.string "Il existe deux SACS DE COMBAT\n"
	.string "distincts : un pour les aventures\p"
	.string "de niveau 50 et de niveau ouvert.\n"
	.string "Ils peuvent chacun contenir jusqu'à\p"
	.string "99 pièces de dix types d'objets. Le\n"
	.string "contenu du SAC DE COMBAT est perdu\p"
	.string "si vous échouez dans votre quête.$"
