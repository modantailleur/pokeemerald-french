.set LOCALID_SAILOR, 1
.set LOCALID_SCOTT, 5

SSTidalCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_OnFrame
	.byte 0

SSTidalCorridor_OnFrame:
	map_script_2 VAR_SS_TIDAL_SCOTT_STATE, 0, SSTidalCorridor_EventScript_ScottScene
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT, SSTidalCorridor_EventScript_DepartSlateportForLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE, SSTidalCorridor_EventScript_DepartLilycoveForSlateport
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_RIGHT, SSTidalCorridor_EventScript_HalfwayToLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_LEFT, SSTidalCorridor_EventScript_ArrivedInSlateport
	.2byte 0

SSTidalCorridor_EventScript_DepartSlateportForLilycove::
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_DepartLilycoveForSlateport::
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_HalfwayToSlateport::
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ArrivedInLilycove::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInLilycove, MSGBOX_DEFAULT
	return

SSTidalCorridor_EventScript_ReachedStepCount::
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT, SSTidalCorridor_EventScript_HalfwayToLilycove
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT, SSTidalCorridor_EventScript_ArrivedInSlateport
	end

SSTidalCorridor_EventScript_HalfwayToLilycove::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_ArrivedInSlateport::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_ArrivedInSlateport::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ProgessCruiseAfterBed::
	switch VAR_SS_TIDAL_STATE
	case SS_TIDAL_DEPART_SLATEPORT, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_HALFWAY_LILYCOVE, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_DEPART_LILYCOVE, SSTidalRooms_EventScript_HalfwayToSlateport
	case SS_TIDAL_HALFWAY_SLATEPORT, SSTidalRooms_EventScript_ArrivedInSlateport
	return

SSTidalCorridor_EventScript_Briney::
	msgbox SSTidalCorridor_Text_BrineyWelcomeAboard, MSGBOX_NPC
	end

SSTidalCorridor_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox SSTidalCorridor_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SSTidalCorridor_EventScript_Cabin1Sign::
	msgbox SSTidalCorridor_Text_Cabin1, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin2Sign::
	msgbox SSTidalCorridor_Text_Cabin2, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin3Sign::
	msgbox SSTidalCorridor_Text_Cabin3, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin4Sign::
	msgbox SSTidalCorridor_Text_Cabin4, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_ExitSailor::
	lock
	faceplayer
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE, SSTidalCorridor_EventScript_ExitLilycove
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT, SSTidalCorridor_EventScript_ExitSlateport
	msgbox SSTidalCorridor_Text_CanRestInCabin2, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_ExitLilycove::
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_ExitSlateport::
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_HideSnatchGiver::
	setflag FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER
	return

SSTidalCorridor_EventScript_Porthole::
	lockall
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT, SSTidalCorridor_EventScript_LookThroughPorthole
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT, SSTidalCorridor_EventScript_LookThroughPorthole
	msgbox SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_LookThroughPorthole::
	special LookThroughPorthole
	waitstate
	end

SSTidalCorridor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SS_TIDAL_TRAINERS, SSTidalCorridor_EventScript_EnjoyYourCruise
	call SSTidalCorridor_EventScript_CheckIfTrainersDefeated
	msgbox SSTidalCorridor_Text_VisitOtherCabins, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_EnjoyYourCruise::
	msgbox SSTidalCorridor_Text_EnjoyYourCruise, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_CheckIfTrainersDefeated::
	goto_if_not_defeated TRAINER_PHILLIP, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEONARD, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_COLTON, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_MICAH, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_THOMAS, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEA_AND_JED, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_GARRET, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_NAOMI, SSTidalCorridor_EventScript_TrainerNotDefeated
	setflag FLAG_DEFEATED_SS_TIDAL_TRAINERS
	goto SSTidalCorridor_EventScript_EnjoyYourCruise
	return

SSTidalCorridor_EventScript_TrainerNotDefeated::
	return

SSTidalCorridor_EventScript_ScottScene::
	lockall
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SSTidalCorridor_Text_ScottBattleFrontierInvite, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SSTidalCorridor_Movement_PlayerWatchScottExit
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorMoveForScott
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottExit
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_SCOTT
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorReturn
	waitmovement 0
	delay 30
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
	setvar VAR_SS_TIDAL_SCOTT_STATE, 1
	releaseall
	end

SSTidalCorridor_Movement_ScottApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SSTidalCorridor_Movement_ScottExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SSTidalCorridor_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_down
	step_end

SSTidalCorridor_Movement_SailorMoveForScott:
	delay_16
	walk_right
	walk_right
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_left
	step_end

SSTidalCorridor_Movement_SailorReturn:
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

SSTidalCorridor_Text_ScottBattleFrontierInvite:
	.string "SCOTT : Eh bien, salut, salut !\n"
	.string "{PLAYER}{KUN}, {PLAYER}{KUN} ! Il\p"
	.string "s'est passé quelque chose, je dois\n"
	.string "donc débarquer, mais je suis\p"
	.string "content de vous voir !\n"
	.string "Félicitations, CHAMPION DE LA LIGUE\p"
	.string "! Il y a un endroit où j'aimerais\n"
	.string "inviter quelqu'un comme vous. C'est\p"
	.string "la… ZONE DE COMBAT ! Comment est\n"
	.string "l'endroit ? Vous comprendrez en le\p"
	.string "voyant ! J'en ai parlé avec le\n"
	.string "CAPT. du navire. La prochaine fois\p"
	.string "que vous prendrez un ferry, vous\n"
	.string "devriez pouvoir naviguer jusqu'à\p"
	.string "ZONE DE COMBAT. D'accord,\n"
	.string "{PLAYER}{KUN}, je t'attendrai au\p"
	.string "ZONE DE COMBAT !$"

SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage:
	.string "Ce ferry est construit pour\n"
	.string "traverser des courants rapides.\p"
	.string "Nous espérons que vous apprécierez\n"
	.string "votre voyage avec nous. N'hésitez\p"
	.string "pas à explorer le navire.$"

SSTidal_Text_HopeYouEnjoyVoyage:
	.string "Nous espérons que vous apprécierez\n"
	.string "votre voyage sur notre ferry.$"

SSTidal_Text_MadeLandInSlateport:
	.string "Nous avons aménagé un terrain à\n"
	.string "POIVRESSEL. Merci d'avoir navigué\p"
	.string "avec nous.$"

SSTidal_Text_MadeLandInLilycove:
	.string "Nous avons aménagé un terrain à\n"
	.string "NENUCRIQUE. Merci d'avoir navigué\p"
	.string "avec nous.$"

SSTidalCorridor_Text_CanRestInCabin2:
	.string "Il nous faudra du temps avant\n"
	.string "d'atterrir, je pense. Vous pouvez\p"
	.string "vous reposer dans votre cabine si\n"
	.string "vous le souhaitez. Votre cabine est\p"
	.string "le numéro 2. Le lit y est doux et\n"
	.string "moelleux. Je peux attester à quel\p"
	.string "point c'est confortable !$"

SSTidalCorridor_Text_WeveArrived:
	.string "Nous sommes arrivés !$"

SSTidalCorridor_Text_VisitOtherCabins:
	.string "Allez visiter d'autres cabanes. LES\n"
	.string "DRESSEURS qui s'ennuient du\p"
	.string "voyage en bateau auront hâte de se\n"
	.string "battre.$"

SSTidalCorridor_Text_EnjoyYourCruise:
	.string "Bonne croisière!$"

SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole:
	.string "L'horizon s'étend au-delà du\n"
	.string "hublot.$"

SSTidalCorridor_Text_BrineyWelcomeAboard:
	.string "M. MARCO : Bienvenue à bord,\n"
	.string "{PLAYER}{KUN} ! Ils m'ont nommé\p"
	.string "CAPT. honoraire du S.S. TIDAL !\n"
	.string "Vous pouvez m'appeler CAPT. BRINEY\p"
	.string "maintenant ! Vous savez, j'ai déjà\n"
	.string "pris ma retraite une fois, mais\p"
	.string "quand j'ai vu ce navire majestueux…\n"
	.string "Laissez-moi juste vous dire que\p"
	.string "cela a remué mon âme endormie de\n"
	.string "marin !$"

SSTidalCorridor_Text_Peeko:
	.string "Peeko : Pihyo pihyohyo…$"

SSTidalCorridor_Text_Cabin1:
	.string "Cabane 1$"

SSTidalCorridor_Text_Cabin2:
	.string "Cabane 2$"

SSTidalCorridor_Text_Cabin3:
	.string "Cabane 3$"

SSTidalCorridor_Text_Cabin4:
	.string "Cabane 4$"
