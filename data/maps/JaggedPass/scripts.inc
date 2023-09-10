.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "MT. CHEMNEY'S SENTIER SINUROC…\n"
	.string "Voilà ce que j'ai toujours voulu en\p"
	.string "montagne. Ces bosses irrégulières…\n"
	.string "Ça me berce l’âme !$"

JaggedPass_Text_EricDefeat:
	.string "Perdre m'a laissé amer !$"

JaggedPass_Text_EricPostBattle:
	.string "Oui, j'ai perdu à POKéMON… Mais\n"
	.string "quand il s'agit d'amour de la\p"
	.string "montagne, je vous bats !$"

JaggedPass_Text_DianaIntro:
	.string "Cet endroit n'est pas une randonnée\n"
	.string "décontractée. Ce n'est pas adapté\p"
	.string "pour un pique-nique.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, non ! Le sol est trop\n"
	.string "cahoteux…$"

JaggedPass_Text_DianaPostBattle:
	.string "Saviez-vous? Certaines personnes\n"
	.string "montent intelligemment leur vélo\p"
	.string "sur ce col horriblement cahoteux.$"

JaggedPass_Text_DianaRegister:
	.string "Reviendrez-vous un jour dans ce\n"
	.string "domaine ? Si vous revenez,\p"
	.string "j'aimerais une revanche.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Les pique-niques sont amusants\n"
	.string "partout où vous allez. Tout comme\p"
	.string "POKéMON !$"

JaggedPass_Text_DianaRematchDefeat:
	.string "J'ai seulement perdu parce que le\n"
	.string "terrain est trop bosselé !$"

JaggedPass_Text_DianaPostRematch:
	.string "J'oublierai de perdre et je\n"
	.string "profiterai simplement de cette\p"
	.string "randonnée cahoteuse.$"

JaggedPass_Text_EthanIntro:
	.string "SENTIER SINUROC est difficile à\n"
	.string "parcourir. C'est un bon endroit\p"
	.string "pour s'entraîner.$"

JaggedPass_Text_EthanDefeat:
	.string "C’était fini alors qu’on essayait\n"
	.string "encore de trouver de bonnes bases…$"

JaggedPass_Text_EthanPostBattle:
	.string "Si j'avais un ACRO BIKE, je serais\n"
	.string "capable de sauter des rebords.$"

JaggedPass_Text_EthanRegister:
	.string "Quand je serai plus habitué à ces\n"
	.string "cahots, je serai sûr de gagner !\p"
	.string "Pouvez-vous m'inscrire dans votre\n"
	.string "POKéNAV ?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Je me suis habitué à cette bosse.\n"
	.string "Je chante en grimpant maintenant.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Ce n'est quand même pas facile de\n"
	.string "se battre sur ce terrain cahoteux…$"

JaggedPass_Text_EthanPostRematch:
	.string "Je devrais me procurer un ACRO BIKE\n"
	.string "chez RODOLPHE à LAVANDIA…$"

JaggedPass_Text_GruntIntro:
	.string "Waouh ! Que faites-vous ici?\n"
	.string "Qu'est-ce que je fais dans un\p"
	.string "endroit comme celui-ci ? De quelle\n"
	.string "affaire s'agit-il pour vous ?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh… J'aurais dû me cacher dans\n"
	.string "notre HIDEOUT tout de suite…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "D'accord, oh-d'accord ! Je\n"
	.string "l'admets, tu es fort ! Ne\p"
	.string "t'inquiète pas pour moi. Allez où\n"
	.string "vous voulez !$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Ce rocher tremble en réponse à\n"
	.string "l'EMBLÈME MAGMA !$"

JaggedPass_Text_JulioIntro:
	.string "Aiyeeh ! C'est terriblement\n"
	.string "effrayant d'abattre la montagne\p"
	.string "d'un seul coup !$"

JaggedPass_Text_JulioDefeat:
	.string "J'ai l'impression de m'effondrer…$"

JaggedPass_Text_JulioPostBattle:
	.string "Mon vélo a tellement rebondi, j'ai\n"
	.string "mal à l'arrière…$"

JaggedPass_Text_AutumnIntro:
	.string "Je gravis cette colline tous les\n"
	.string "jours. J'ai confiance en ma force\p"
	.string "!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm… Qu'est-ce qui n'a pas\n"
	.string "fonctionné ?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Quelle est cette étrange saillie\n"
	.string "rocheuse un peu en haut de la\p"
	.string "colline à partir d'ici ?$"
