.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Je suis le GURU DE L'ÉNERGIE ! Je\n"
	.string "vais y aller et je te vends ce dont\p"
	.string "tu as besoin !$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh? Votre {STR_VAR_1}… $"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "J'y suis allé à merveille ! En\n"
	.string "récompense, donnez-lui ce RUBAN\p"
	.string "D'EFFORT.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} a reçu le RUBAN D'EFFORT.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} a mis le RUBAN D'EFFORT sur\n"
	.string "{STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Il faut y aller un peu plus fort.\n"
	.string "Si vous le faites, je donnerai à\p"
	.string "votre POKéMON quelque chose de\n"
	.string "sympa.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Votre {STR_VAR_1}, ce RUBAN D'EFFORT\n"
	.string "lui va bien !$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La lumière du phare s’étend à des\n"
	.string "dizaines de kilomètres. Je me\p"
	.string "demande si cela ne fait pas\n"
	.string "sursauter POKéMON dans la mer.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Ooh, regarde ça ! Les algues que\n"
	.string "vous pouvez trouver dans ces\p"
	.string "régions sont fraîches et pleines de\n"
	.string "vie. Eh bien, on dirait qu'il peut\p"
	.string "même se cabrer et attaquer !$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Là où l’eau est propre, les fruits\n"
	.string "d’une récolte abondante se\p"
	.string "rassemblent. Et là où les gens se\n"
	.string "rassemblent, un marché commence\p"
	.string "bientôt. C'est ainsi qu'une ville\n"
	.string "naît et grandit.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Du shopping où vous pourrez\n"
	.string "respirer le parfum de l'océan…\p"
	.string "SLATEPORT est un endroit tellement\n"
	.string "merveilleux!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Si vous posez des POUPÉES ou des\n"
	.string "COUSSINS par terre, ils se\p"
	.string "saliront. Je vais acheter des\n"
	.string "BRIQUES pour que mes POUPÉES et\p"
	.string "COUSSINS ne se salissent pas\n"
	.string "lorsque je les laisse de côté.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Waouh ! Je vais aussi participer à\n"
	.string "la TENTE DE COMBAT ! Mais avant ça,\p"
	.string "je dois attraper des POKéMON !$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Ouf… je suis juste dans le pétrin…\n"
	.string "J'ai fait une randonnée depuis\p"
	.string "LAVANDIA. Mais mon garçon, cette\n"
	.string "ville est immense. Si j'avais su\p"
	.string "cela, j'aurais fait du vélo ici.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "POUPE, l'homme qui a construit le\n"
	.string "MUSÉE, se trouve également être le\p"
	.string "chef d'une équipe d'exploration\n"
	.string "sous-marine. Alors tout le monde\p"
	.string "l'appelle CAPT. POUPE.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Qu'est-ce que c'est là-bas ? Cette\n"
	.string "longue file d'attente…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Quand j'étais enfant, je visitais\n"
	.string "souvent le MUSÉE. Je rêvais des\p"
	.string "mystères de la mer après avoir vu\n"
	.string "les expositions.$"

SlateportCity_Text_QuitPushing:
	.string "Salut! Arrêtez de pousser ! C'est\n"
	.string "la ligne, tu ne vois pas ?$"

SlateportCity_Text_AquaHasPolicy:
	.string "TEAM AQUA a une politique de\n"
	.string "rassemblement et de dispersion sur\p"
	.string "le site d'exploitation.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Notre BOSS est génial. Que\n"
	.string "voudrait-il faire d'un MUSÉE\p"
	.string "maintenant ?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Quel est le nouveau schéma, je me\n"
	.string "demande ? Notre BOSS fait peur\p"
	.string "quand il est en colère, alors je\n"
	.string "ferais mieux de ne pas tout\p"
	.string "gâcher…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "S’il y a quelque chose dont nous\n"
	.string "avons besoin au MUSÉE, nous\p"
	.string "devrions tout prendre !$"

SlateportCity_Text_DontButtIn:
	.string "Hé, tu es là ! Ne vous mêlez pas !$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Une longue file d'attente, hein ?\n"
	.string "Cela me rappelle les fois où je\p"
	.string "faisais la queue pour acheter des\n"
	.string "jeux à succès…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Pourquoi faisons-nous la queue et\n"
	.string "payons-nous ? Nous devrions\p"
	.string "simplement entrer !$"

SlateportCity_Text_WhatDoYouWant:
	.string "Quoi? Que veux-tu ?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Tu veux lire ce panneau ? Je vais\n"
	.string "le lire pour vous !$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Voyons… Euh… Je pense que cela dit\n"
	.string "quelque chose comme “ la vie dans\p"
	.string "la mer est infinie ”. Ouais, je\n"
	.string "suis presque sûr que c'est ce que\p"
	.string "ça dit.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Grognement… J'aurais dû apporter ma\n"
	.string "Game Boy Advance pour ne pas\p"
	.string "m'ennuyer en faisant la queue…\n"
	.string "Grognement…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Une fois cette opération terminée,\n"
	.string "je vous emmènerai dans un spa\p"
	.string "thermal ! C'est ce qu'a dit notre\n"
	.string "chef. J'ai hâte !$"

SlateportCity_Text_SeaIsSoWet:
	.string "La mer est tellement vaste… La mer\n"
	.string "aurait-elle pu être créée par les\p"
	.string "larmes versées par POKéMON ?$"

SlateportCity_Text_SinkOldBoats:
	.string "Savez-vous ce qu'ils font avec les\n"
	.string "vieux navires qui grincent trop\p"
	.string "pour naviguer ? Ils les coulent\n"
	.string "dans la mer et deviennent ainsi des\p"
	.string "habitats pour POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Chaque fois que je visite ici, je\n"
	.string "me laisse emporter et j'achète\p"
	.string "trop.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Si vous souhaitez changer le pseudo\n"
	.string "de votre POKéMON, vous devrez\p"
	.string "demander l'aide du NAME RATER.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Tout POKéMON que vous obtenez lors\n"
	.string "d'un échange, vous ne pouvez pas\p"
	.string "changer son surnom. L'amour du\n"
	.string "DRESSEUR original pour ce POKéMON\p"
	.string "est dans le surnom.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Récemment, une TENTE DE COMBAT a\n"
	.string "été construite à SLATEPORT. Les\p"
	.string "gymnases sont amusants, mais la\n"
	.string "TENTE DE COMBAT est géniale à sa\p"
	.string "manière. Tu devrais aller chercher\n"
	.string "des POKéMON coriaces pour la TENTE\p"
	.string "DE COMBAT !$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "J'espérais que ce soit une star\n"
	.string "célèbre pour pouvoir obtenir un\p"
	.string "autographe. Mais qui est-ce qui est\n"
	.string "interviewé ? N'est-ce pas le CAPT.\p"
	.string "POUPE ?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Cette intervieweuse est tellement\n"
	.string "cool et jolie. Quand je serai\p"
	.string "grand, je serai journaliste\n"
	.string "international !$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "LE CAPT. POUPE dit qu'ils ont\n"
	.string "découvert quelque chose au fond de\p"
	.string "la mer. Je me demande ce que c'est?\n"
	.string "Qu'est-ce que ça pourrait être ?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Que se passe t-il ici? Le bon CAPT.\n"
	.string "est-il revenu avec un gros poisson\p"
	.string "du fond de l'océan ?$"

SlateportCity_Text_AmIOnTV:
	.string "Hé! Es-tu en train de regarder?\n"
	.string "Suis-je à la télé ?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Une interview télévisée ! Ici! Le\n"
	.string "CAPT. est une célébrité !$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY : D'accord, CAPT. POUPE, un\n"
	.string "grand sourire pour la caméra !$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY : Je vois, je vois. Vous avez\n"
	.string "vécu une expérience des plus\p"
	.string "inestimables…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPT. POUPE : Oui, en effet. Nous\n"
	.string "avons l’intention de poursuivre\p"
	.string "notre exploration.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY : C'est merveilleux, CAPT.\n"
	.string "POUPE ! Merci d'avoir pris le temps\p"
	.string "malgré votre emploi du temps chargé\n"
	.string "pour nous parler. Nous espérons\p"
	.string "pouvoir vous interviewer à nouveau\n"
	.string "avec des nouvelles de plus de\p"
	.string "découvertes !$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPT. POUPE : Ouf… C'était la\n"
	.string "première fois que j'étais filmé\p"
	.string "pour la télévision. C'était\n"
	.string "angoissant.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh! {PLAYER}{KUN} ! Vous êtes\n"
	.string "superbe ! Nous avons fait une\p"
	.string "énorme découverte lors de notre\n"
	.string "dernière exploration des fonds\p"
	.string "marins. Nous avons trouvé une\n"
	.string "caverne sous-marine sur la ROUTE\p"
	.string "128. Nous pensons que c'est\n"
	.string "l'habitat d'un POKéMON dont on dit\p"
	.string "qu'il a disparu depuis longtemps.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu… CAPT. POUPE, je présume.\n"
	.string "Nous, de TEAM AQUA, prendrons le\p"
	.string "contrôle de votre sous-marin ! Vos\n"
	.string "objections n'ont aucun sens ! Nous\p"
	.string "attendons votre totale coopération\n"
	.string "! Fufufu… Regardez et découvrez ce\p"
	.string "que TEAM AQUA a prévu !$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPT. POUPE : De quoi s'agissait-il\n"
	.string "? On aurait dit que quelqu'un\p"
	.string "utilisait un mégaphone… D'où ça\n"
	.string "vient ?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Ça vient du PORT ! Le sous-marin !\n"
	.string "Ils essaient de le prendre !$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN} ! S'il vous plaît,\n"
	.string "venez avec moi !$"

SlateportCity_Text_BattleTentSign:
	.string "SITE DE SLATEPORT DE TENTE DE\n"
	.string "COMBAT “ Trouvez-le ! Le POKéMON\p"
	.string "ultime ! ” $"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "POUPE'S SHIPYYARD “ Recherché : Un\n"
	.string "marin capable de naviguer dans tous\p"
	.string "les courants. ”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "CHANTIER NAVAL DE POUPE “Le ferry\n"
	.string "S.S. TIDAL est en voie d'achèvement\p"
	.string "pour desservir les ports de\n"
	.string "SLATEPORT et LILYCOVE.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "POUPE'S SHIPYYARD “ L'embarquement\n"
	.string "du ferry SLATEPORT-LILYCOVE S.S.\p"
	.string "TIDAL s'effectue au PORT. ”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "POKéMON FAN CLUB “ Appel à tous les\n"
	.string "fans de POKéMON ! ”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“ La mer sans fin soutient toute\n"
	.string "vie. ” MUSÉE OCÉANIQUE$"

SlateportCity_Text_CitySign:
	.string "POIVRESSEL “ Le port où les gens et\n"
	.string "les POKéMON se croisent. ”$"

SlateportCity_Text_MarketSign:
	.string "SLATEPORT MARKGUIDO “ Des objets\n"
	.string "uniques que l'on ne trouve nulle\p"
	.string "part ailleurs ! ”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "SLATEPORT HARBOUR “ Le ferry S.S.\n"
	.string "TIDAL est en construction dans le\p"
	.string "CHANTIER NAVAL. “Le service devrait\n"
	.string "commencer sous peu.”$"

SlateportCity_Text_HarborSign:
	.string "SLATEPORT HARBOUR “Profitez d'une\n"
	.string "charmante croisière sur le ferry\p"
	.string "S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "MAISON DE L'ÉVALUATEUR DE NOM “\n"
	.string "Surnoms POKéMON notés. ” $"

SlateportCity_Text_ExplainBerries:
	.string "Si un POKéMON sauvage est blessé,\n"
	.string "il se soigne tout seul en mâchant\p"
	.string "des BAIES. Le saviez-vous ?\n"
	.string "Quelqu'un a vu cela et a eu l'idée\p"
	.string "de fabriquer des médicaments à\n"
	.string "partir de BAIES. Le saviez-vous ?\p"
	.string "Pour transformer les BAIES en\n"
	.string "médicament, il faut les réduire en\p"
	.string "poudre. Le saviez-vous ? Vous\n"
	.string "semblez vous intéresser aux BAIES !\p"
	.string "J'ai quelque chose de bien pour\n"
	.string "quelqu'un comme toi.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "J'ai récemment fait installer des\n"
	.string "machines aux POKéMON CENTERS pour\p"
	.string "broyer les BAIES. Les machines\n"
	.string "BERRY CRUSH se trouvent au DIRECT\p"
	.string "CORNER à l'étage. Saviez-vous?\n"
	.string "Pourriez-vous me fabriquer de la\p"
	.string "POUDRE DE BAIES en utilisant ces\n"
	.string "machines ? Je peux vous préparer\p"
	.string "toutes sortes de médicaments si\n"
	.string "vous m'apportez beaucoup de POUDRE\p"
	.string "DE BAIES.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "M'avez-vous apporté de la POUDRE DE\n"
	.string "BAIES ?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Contre quoi souhaiteriez-vous\n"
	.string "l’échanger ?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "D'accord, vous souhaitez échanger\n"
	.string "votre POUDRE DE BAIES contre un\p"
	.string "{STR_VAR_1} ? $"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Oh cher. Vous n'avez pas assez de\n"
	.string "POUDRE DE BAIES.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "C'est une bonne POUDRE DE BAIES.\n"
	.string "Cela fera un excellent médicament.\p"
	.string "Souhaitez-vous échanger davantage\n"
	.string "de votre POUDRE DE BAIES contre\p"
	.string "autre chose ?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "D'accord! Lorsque vous aurez un peu\n"
	.string "plus de POUDRE DE BAIES,\p"
	.string "apportez-la-moi, s'il vous plaît !$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Revenez si vous souhaitez échanger\n"
	.string "votre POUDRE DE BAIES contre des\p"
	.string "médicaments. Je tiens toujours un\n"
	.string "bazar ici. Le saviez-vous ?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT : Hein ? Je suis sûr de\n"
	.string "t'avoir déjà rencontré quelque\p"
	.string "part. Est-ce que je me suis\n"
	.string "présenté à vous ? Sinon, je\p"
	.string "m'appelle SCOTT. Je viens de voir\n"
	.string "TEAM AQUA s'enfuir d'ici comme\p"
	.string "s'ils étaient piqués. Laissez-moi\n"
	.string "deviner : vous les avez chassés ?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT : Hmm… Peut-être, juste\n"
	.string "peut-être, cet DRESSEUR…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT : Très bien ! Je pense que tu\n"
	.string "vas devenir un bon ami. Alors\p"
	.string "inscrivons-nous les uns aux autres\n"
	.string "dans nos POKéNAVS. … … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "A enregistré cette personne SCOTT\n"
	.string "dans le POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT : Ce que j'aimerais faire,\n"
	.string "c'est vous suivre, mais je veux\p"
	.string "aussi garder un œil sur les talents\n"
	.string "des autres. Je vais donc partir\p"
	.string "parcourir un peu plus d'autres\n"
	.string "villes. À bientôt, {PLAYER}{KUN} !$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT : Oh, hé ! Si ce n'est pas\n"
	.string "{PLAYER}{KUN} ! {PLAYER}{KUN},\p"
	.string "laissez-moi deviner : allez-vous\n"
	.string "relever le défi BATTLE TENT ?\p"
	.string "Ouais! C'est une bonne idée! C'est\n"
	.string "vraiment une excellente idée !\p"
	.string "Après tout, un DRESSEUR robuste est\n"
	.string "la solution idéale pour la TENTE DE\p"
	.string "COMBAT ! Faites de votre mieux !$"
