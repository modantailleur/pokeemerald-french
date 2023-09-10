.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "La puissance contenue dans la\n"
	.string "MÉTÉORITE… En amplifiant sa\p"
	.string "puissance avec cette machine, MT.\n"
	.string "L'activité volcanique de CHEMNEY va\p"
	.string "s'intensifier instantanément… Son\n"
	.string "énergie va croître au plus profond\p"
	.string "du cratère et… Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MAX : Hum ? Qui es-tu? … … … … … …\n"
	.string "… … … … … … J'avais entendu ARTHUR\p"
	.string "déplorer un enfant qui s'était mêlé\n"
	.string "des affaires de TEAM AQUA. Ce doit\p"
	.string "être toi qu'il voulait dire. Hum !\n"
	.string "Alors vous envisagez d'interférer\p"
	.string "avec nous, TEAM MAGMA ? Maintenant,\n"
	.string "écoutez. Il y a bien longtemps, les\p"
	.string "êtres vivants utilisaient la terre\n"
	.string "pour vivre et grandir. C'est\p"
	.string "pourquoi la terre est si importante\n"
	.string "! C'est le berceau de tout ! C'est\p"
	.string "pourquoi l'ÉQUIPE MAGMA se consacre\n"
	.string "à l'expansion du territoire. C'est\p"
	.string "pour le progrès de l'humanité et de\n"
	.string "POKéMON ! Et pour cela, nous avons\p"
	.string "besoin de la puissance de ce qui\n"
	.string "dort au sein de cette montagne… Oh\p"
	.string "! Vous n’aviez pas besoin d’en\n"
	.string "apprendre autant. Mais peu importe!\p"
	.string "Je vais vous apprendre les\n"
	.string "conséquences d'une ingérence dans\p"
	.string "notre grand dessein !$"

MtChimney_Text_MaxieDefeat:
	.string "Quoi?! Moi, MAX, j'ai été prise au\n"
	.string "dépourvu ?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAX : Mais ça suffit. Je vais\n"
	.string "reculer cette fois. Mais ne pensez\p"
	.string "pas que c'est la dernière fois que\n"
	.string "vous voyez TEAM MAGMA. Fufufu… Même\p"
	.string "sans la MÉTÉORITE, si on obtient\n"
	.string "cet ORB… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Héhéhé ! Alors vous êtes arrivé\n"
	.string "jusqu'ici ! Mais tu es trop tard !\p"
	.string "J'ai déjà livré la MÉTÉORITE de\n"
	.string "MGUIDOEOR FALLS au BOSS !$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe… Même si j'ai perdu, si\n"
	.string "notre chef réveille cette chose…$"

MtChimney_Text_TabithaPostBattle:
	.string "Patron, dépêchez-vous ! Donnez-lui\n"
	.string "l'énergie de la MÉTÉORITE !\p"
	.string "Héhéhé…$"

MtChimney_Text_Grunt2Intro:
	.string "Nous, de TEAM MAGMA, travaillons\n"
	.string "dur pour le bien de tous. Par\p"
	.string "exemple, si le pouvoir de cette\n"
	.string "chose créait plus de terres, il y\p"
	.string "aurait plus d'endroits où vivre.\n"
	.string "Tout le monde serait content !$"

MtChimney_Text_Grunt2Defeat:
	.string "Hein ? Comment ça, j'ai perdu ?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Notre BOSS dit : “ Cela rendra tout\n"
	.string "le monde heureux. ” Mais pourquoi\p"
	.string "tout le monde continue-t-il à nous\n"
	.string "gêner ?$"

MtChimney_Text_Grunt1Intro:
	.string "S’il y avait plus de terrain, je\n"
	.string "pourrais avoir ma propre grande\p"
	.string "maison ! Je vais le construire sur\n"
	.string "de la lave durcie !$"

MtChimney_Text_Grunt1Defeat:
	.string "Mon rêve d'une grande maison…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Un enfant comme toi, tu devrais\n"
	.string "barboter dans les vagues !$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Cette ennuyeux TEAM AQUA… Ils\n"
	.string "gâchent toujours nos plans !$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "LES MÉTÉORITES ont une puissance\n"
	.string "incroyable !$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Tu ferais mieux de ne pas nous\n"
	.string "embêter ! Nous essayons de\p"
	.string "réveiller cette chose pour le\n"
	.string "bénéfice de tous !$"

MtChimney_Text_AquasNameSimilar:
	.string "Nous sommes l'ÉQUIPE MAGMA ! C'est\n"
	.string "la TEAM AQUA ! Cela m'énerve\p"
	.string "totalement qu'ils utilisent un nom\n"
	.string "comme le nôtre !$"

MtChimney_Text_DouseThemInFire:
	.string "Ouais! Éteignez-les dans le feu !$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Nous allons continuer à créer plus\n"
	.string "de terres !$"

MtChimney_Text_Bufoh:
	.string "Boufoh !$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARTHUR : Grr, {PLAYER} ! J'aurais dû\n"
	.string "deviner que tu viendrais ! Voyez\p"
	.string "par vous-même ce que font les\n"
	.string "fanatiques de la TEAM MAGMA ! Ils\p"
	.string "essaient d'injecter la puissance de\n"
	.string "la MÉTÉORITE volée dans le volcan !\p"
	.string "Faire quelque chose comme ça\n"
	.string "provoquerait l'éruption du volcan\p"
	.string "!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARTHUR : Grrr… Je veux arrêter ce\n"
	.string "MAX, mais je ne peux pas ! Pas\p"
	.string "quand j’ai les mains pleines face à\n"
	.string "trois adversaires à la fois !$"

MtChimney_Text_ArchieThankYou:
	.string "ARTHUR : {PLAYER} ! Merci! Avec votre\n"
	.string "aide, nous avons déjoué le plan\p"
	.string "destructeur de la TEAM MAGMA !\n"
	.string "Mais… Vous… De quel côté es-tu ?\p"
	.string "Ah, ça n'a pas d'importance. Nous\n"
	.string "resterons vigilants et poursuivrons\p"
	.string "notre poursuite de la TEAM MAGMA.\n"
	.string "{PLAYER}, nous nous reverrons !$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Bon sang… L'ÉQUIPE MAGMA nous\n"
	.string "dépasse en nombre ! Nous ne pouvons\p"
	.string "pas les suivre !$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "S'ils agrandissent les terres, il y\n"
	.string "aura moins d'habitats pour les\p"
	.string "POKéMON EAU !$"

MtChimney_Text_MagmasNameSimilar:
	.string "Nous sommes l'ÉQUIPE AQUA ! C'est\n"
	.string "la TEAM MAGMA ! Ça me brûle qu'ils\p"
	.string "utilisent un nom aussi déroutant !$"

MtChimney_Text_Bushaa:
	.string "Buisson!$"

MtChimney_Text_LavaCookiesJust200:
	.string "LES BISCUITS DE LAVE sont MT. La\n"
	.string "spécialité locale de CHEMINÉE.\p"
	.string "Essayez-en un. C'est juste 200 ¥.$"

MtChimney_Text_ThankYouDear:
	.string "Merci, chérie !$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh cher. Vous ne pouvez pas acheter\n"
	.string "quelque chose si vous n’avez pas\p"
	.string "d’argent.$"

MtChimney_Text_OhFineThen:
	.string "Oh, bien alors.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "UNE MÉTÉORITE est installée sur une\n"
	.string "mystérieuse machine… La machine\p"
	.string "semble stocker de l'énergie dans la\n"
	.string "MÉTÉORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "UNE MÉTÉORITE est installée sur une\n"
	.string "mystérieuse machine… Voulez-vous\p"
	.string "retirer la MÉTÉORITE ?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} a retiré la MÉTÉORITE de la\n"
	.string "mystérieuse machine.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} a laissé la MÉTÉORITE là où\n"
	.string "elle se trouvait.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Cette mystérieuse machine… Elle ne\n"
	.string "répond absolument pas.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} CHEMIN DÉCHIQUGUIDOÉ\n"
	.string "VERMILAVA AVANT$"

MtChimney_Text_ShelbyIntro:
	.string "Je suis allé aux sources chaudes et\n"
	.string "j'ai rafraîchi mes os fatigués. En\p"
	.string "ce moment, je me sens fort !$"

MtChimney_Text_ShelbyDefeat:
	.string "Oh mon Dieu. Maintenant, n'es-tu\n"
	.string "pas quelque chose !$"

MtChimney_Text_ShelbyPostBattle:
	.string "Eh bien, j'ai perdu. Je ne peux pas\n"
	.string "me qualifier d'EXPERT maintenant,\p"
	.string "n'est-ce pas ?$"

MtChimney_Text_ShelbyRegister:
	.string "Merci, mon enfant. C'était amusant,\n"
	.string "comme si je combattais mon propre\p"
	.string "petit-enfant. S'il vous plaît,\n"
	.string "revenez me voir pour une revanche.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Si vous parvenez à associer votre\n"
	.string "cœur à celui de votre POKéMON, eh\p"
	.string "bien, vous devriez être capable de\n"
	.string "réaliser de grandes choses.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Oh mon Dieu. Maintenant, n'es-tu\n"
	.string "pas quelque chose !$"

MtChimney_Text_ShelbyPostRematch:
	.string "Peut-être que votre cœur ne fait\n"
	.string "plus qu'un avec celui de votre\p"
	.string "POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "J'ai le feu en moi, bébé. Je ne\n"
	.string "peux pas le supporter ! Je dois me\p"
	.string "battre !$"

MtChimney_Text_MelissaDefeat:
	.string "Ooh, c'était un match torride !$"

MtChimney_Text_MelissaPostBattle:
	.string "La chaleur de MT. LA CHEMINÉE me\n"
	.string "réchauffe, bébé !$"

MtChimney_Text_SheilaIntro:
	.string "Je suis enfin arrivé à MONT\n"
	.string "CHIMNEE. Je veux faire mon combat\p"
	.string "POKéMON !$"

MtChimney_Text_SheilaDefeat:
	.string "La façon dont vous combattez… C'est\n"
	.string "comme un MT. Éruption de CHEMINÉE\p"
	.string "!$"

MtChimney_Text_SheilaPostBattle:
	.string "Comme je l'ai dit, je suis enfin\n"
	.string "arrivé à MONT CHIMNEE. Ce serait\p"
	.string "dommage de faire seulement un peu\n"
	.string "de tourisme… J'ai envie de\p"
	.string "participer à quelques batailles et\n"
	.string "d'acheter des COOKIES comme\p"
	.string "souvenirs.$"

MtChimney_Text_ShirleyIntro:
	.string "Depuis que je me suis baigné dans\n"
	.string "les sources chaudes, je me sens\p"
	.string "bien ! Je suis sûr que je vais\n"
	.string "gagner !$"

MtChimney_Text_ShirleyDefeat:
	.string "Ouah! Je prends froid en sortant de\n"
	.string "l'eau.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Je vais devoir me baigner à nouveau\n"
	.string "dans les sources chaudes. Veut me\p"
	.string "rejoindre? Je plaisante !$"

MtChimney_Text_SawyerIntro:
	.string "C'est une belle montagne ! Beaucoup\n"
	.string "de gens sexy pour avoir de la\p"
	.string "compagnie !$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, tu es aussi un véritable tison\n"
	.string "!$"

MtChimney_Text_SawyerPostBattle:
	.string "Je pense que j'ai besoin d'un\n"
	.string "plongeon à LAVARIDGE HOT SPRING\p"
	.string "avec les locaux !$"

MtChimney_Text_SawyerRegister:
	.string "J'aime les petites boules de feu\n"
	.string "comme toi. Laissez-moi vous\p"
	.string "inscrire dans mon POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Je suis joyeusement entouré de gens\n"
	.string "sexy dans ces régions. Je ne\p"
	.string "perdrai pas !$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Mon Dieu, tu es toujours le même\n"
	.string "tison qu'avant !$"

MtChimney_Text_SawyerPostRematch:
	.string "En fait, il fait vraiment chaud\n"
	.string "ici. Je suis trop habillé pour ces\p"
	.string "pièces.$"
