MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Hé, comment ça va, {PLAYER} CHAMPION\n"
	.string "? VOLTÈRE, le LEADER de MAUVILLE\p"
	.string "GYM, utilise des POKéMON de type\n"
	.string "ÉLECTRIQUE. Si vous le défiez avec\p"
	.string "des POKéMON de type EAU, il les\n"
	.string "zappera ! Bzzt! Et il a installé\p"
	.string "des portes commandées par\n"
	.string "interrupteur partout dans son GYM !\p"
	.string "Excentrique! Hé, vas-y !$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa, tu es électrisant ! Vous avez\n"
	.string "ouvert la porte !$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Mon âme électrique, ça va briser\n"
	.string "tes rêves, whoa-ouais !$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "C'était branché, amplifié,\n"
	.string "électrique surchargé, mec !$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON et rock, c'est une question\n"
	.string "de cœur, whoa-ouais !$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Je me suis entraîné avec VOLTÈRE !\n"
	.string "Je ne peux pas perdre facilement !$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Débranché et éteint…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "VOLTÈRE, notre GYM LEADER, existe\n"
	.string "depuis très, très longtemps. Il se\p"
	.string "battait avant même la naissance de\n"
	.string "ton papa, ce dur à cuire.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "Ce GYM contient des énigmes !\n"
	.string "N'est-ce pas amusant ?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Ce n'est pas amusant de perdre…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "VOLTÈRE dit qu'il aime installer\n"
	.string "des petits pièges avec des\p"
	.string "interrupteurs.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Avec mon charme et les mouvements\n"
	.string "de mon POKéMON, vous serez choqué\p"
	.string "!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Je suis choqué par ton pouvoir !$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "J'ai entendu dire que MAUVILLE\n"
	.string "avait été fondée par VOLTÈRE. Il\p"
	.string "était FORMATTHIEUEUR bien avant que\n"
	.string "nous ne devenions FORMATTHIEUEURS.\p"
	.string "Il doit savoir toutes sortes de\n"
	.string "choses !$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "J'adore les choses brillantes !$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh… Mes yeux sont épuisés…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "VOLTÈRE de MAUVILLE GYM a un front\n"
	.string "brillant. Ça me fait plaisir !$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "J'ai abandonné mes projets de\n"
	.string "conversion de la ville, c'est vrai.\p"
	.string "Et donc, j’ai consacré mon temps à\n"
	.string "fabriquer des pièges de porte dans\p"
	.string "mon GYM. Oh? Maintenant, qu'est-ce\n"
	.string "que tu fais ici ? Qu'est ce que\p"
	.string "c'est? Vous dites que vous avez\n"
	.string "franchi toutes mes portes truquées\p"
	.string "? Wahahahah ! Maintenant, c'est\n"
	.string "amusant ! Alors, MOI, VOLTÈRE, LE\p"
	.string "LEADER de MAUVILLE GYM, je vais\n"
	.string "vous électrifier !$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah ! Très bien, j'ai perdu !\n"
	.string "Tu as fini par me faire plaisir !\p"
	.string "Prenez ce BADGE !$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} a reçu le BADGE DYNAMO de\n"
	.string "VOLTÈRE.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Grâce au DYNAMO BADGE, POKéMON peut\n"
	.string "utiliser ROCK SMASH hors combat. Et\p"
	.string "cela rendra également votre POKéMON\n"
	.string "un peu plus rapide. Hmm… Tu devrais\p"
	.string "prendre ça aussi !$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "Ce TM34 contient SHOCK WAVE. C'est\n"
	.string "un geste fiable qui ne manque\p"
	.string "jamais ! Tu peux compter dessus! …\n"
	.string "… … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Inscrit GYM LEADER VOLTÈRE dans le\n"
	.string "POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Je gonfle d'optimisme en voyant un\n"
	.string "jeune FORMATTHIEUEUR prometteur\p"
	.string "comme toi !$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah ! Allez-y et\n"
	.string "efforcez-vous, jeune !$"

MauvilleCity_Gym_Text_GymStatue:
	.string "LAVANDIA POKéMON GYM$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "LAVANDIA POKéMON GYM VOLTÈRE\n"
	.string "DRESSEURS CERTIFIÉS : {PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "VOLTÈRE : Ah-ha ! Enfin là ! Je\n"
	.string "sais ce que vous voulez. Vous\p"
	.string "voulez combattre mon POKéMON !\n"
	.string "Wahahahaha ! Je ferai jaillir des\p"
	.string "étincelles de toi ! Ne dites pas\n"
	.string "que je ne vous ai pas prévenu !$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Oof… Nos batteries se sont\n"
	.string "épuisées…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "VOLTÈRE : Nous devrons à nouveau\n"
	.string "recharger nos batteries. Lorsque\p"
	.string "nous serons complètement chargés,\n"
	.string "nous accepterons volontiers votre\p"
	.string "défi. Alors, reviens un jour,\n"
	.string "n'est-ce pas ?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "VOLTÈRE : Ah-ha ! Enfin là ! Je\n"
	.string "sais ce que vous voulez. Vous\p"
	.string "voulez combattre mon POKéMON !\n"
	.string "Wahahahaha ! Oops! Attendez! Vous\p"
	.string "n'avez qu'un seul POKéMON avec vous\n"
	.string "! Viens me voir avec deux POKéMON\p"
	.string "ou plus, d'accord ?$"
