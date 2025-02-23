.set LOCALID_CAPT_STERN, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_GRUNT_1, 3
.set LOCALID_GRUNT_2, 4

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_GRUNT_1
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Oui? Si vous cherchez POUPE, ce\n"
	.string "serait moi. Ah ! Ce doivent être\p"
	.string "les pièces que j'ai commandées chez\n"
	.string "MR. PIERRE du DEVON. Merci! C'est\p"
	.string "super! Nous pouvons préparer notre\n"
	.string "expédition maintenant.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Héhéhé, attends ! Nous prendrons\n"
	.string "ces pièces !$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPT. POUPE : Quoi-quoi ? Qui\n"
	.string "êtes-vous ?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Nous sommes l'ÉQUIPE AQUA ! Notre\n"
	.string "BOSS veut ces pièces ! Fermez votre\p"
	.string "japper et déboursez-les !$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Awaaaah ! Un enfant m'a battu !$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh, mec, quel désastre… Le BOSS va\n"
	.string "être furieux…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Humph, mauviette pleurnicheuse !\n"
	.string "Laissez-moi m'occuper de ça !$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Quoi?! J'ai perdu aussi !$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Maintenant quoi? Si nous n’obtenons\n"
	.string "pas les pièces, nous y serons !\p"
	.string "Arrgh, je ne m'attendais pas à me\n"
	.string "faire embêter par un gamin intrusif\p"
	.string "!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Je suis venu voir pourquoi il\n"
	.string "fallait si longtemps pour récupérer\p"
	.string "certaines pièces, et vous, les\n"
	.string "simps, êtes retenus par un simple\p"
	.string "enfant ?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Nous sommes TEAM AQUA et nous\n"
	.string "aimons la mer ! Et je suis le\p"
	.string "leader de TEAM AQUA, ARTHUR !\n"
	.string "Qu'est-ce qui vous fait interférer\p"
	.string "avec nous ? …Non! Vous ne pouvez\n"
	.string "pas l'être ! Vous ne faites pas\p"
	.string "partie de la TEAM MAGMA ? Attends,\n"
	.string "ça ne peut pas être vrai. Vous\p"
	.string "n'êtes pas habillé pour le rôle. …\n"
	.string "… … … … … … … … … … POKéMON, les\p"
	.string "gens… Toute vie dépend de la mer.\n"
	.string "Ainsi, TEAM AQUA se consacre à\p"
	.string "l’expansion de la mer. Vous n'êtes\n"
	.string "pas d'accord ? Ce que nous faisons\p"
	.string "est une entreprise magnifique. Ah,\n"
	.string "très bien… Vous êtes encore trop\p"
	.string "jeune pour comprendre notre noble\n"
	.string "objectif. Mais je vous préviens,\p"
	.string "n'envisagez même pas de perturber à\n"
	.string "nouveau nos plans. Les conséquences\p"
	.string "vous coûteront cher ! Et ne\n"
	.string "l'oubliez pas !$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPT. POUPE : Vous êtes... Ah,\n"
	.string "d'accord, vous êtes {PLAYER}{KUN}...\p"
	.string "Quoi qu'il en soit, c'était une\n"
	.string "situation tendue ! Merci de nous\p"
	.string "avoir sauvés ! Oh, oui, j'ai\n"
	.string "presque oublié que tu as même\p"
	.string "apporté les pièces du DEVON !$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPT. POUPE : Oups ! Il n'y a pas\n"
	.string "de temps à perdre ! Nous devons\p"
	.string "très bientôt partir pour notre\n"
	.string "expédition au fond des océans.\p"
	.string "Merci encore, mais maintenant je\n"
	.string "dois y aller ! N'hésitez pas à vous\p"
	.string "promener et à consulter nos\n"
	.string "installations.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "J'ai vu une maquette de bateau ici.\n"
	.string "Cela m'a rappelé le EPAVE près de\p"
	.string "VILLAGE MYOKARA…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "N'osez pas courir à l'intérieur du\n"
	.string "MUSÉE !$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Wow, le sous-marin est génial ! Je\n"
	.string "veux faire un tour !$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“ ÉCHANTILLON DE QUALITÉ DE L'EAU 1\n"
	.string "”, indique l'étiquette. La mer est\p"
	.string "entièrement connectée, mais l'eau\n"
	.string "semble différer selon les régions.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“ ÉCHANTILLON DE QUALITÉ DE L'EAU 2\n"
	.string "”, indique l'étiquette. La salinité\p"
	.string "de l’eau de mer diffère-t-elle\n"
	.string "également selon les régions ?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Une balle en caoutchouc se dilate\n"
	.string "et se rétrécit. “ Dans la mer, le\p"
	.string "poids de l’eau lui-même exerce une\n"
	.string "pression. “ En eau peu profonde, la\p"
	.string "pression n’est pas très forte.\n"
	.string "“Cependant, dans des eaux\p"
	.string "extrêmement profondes, la pression\n"
	.string "peut même atteindre des dizaines de\p"
	.string "milliers de tonnes sur une petite\n"
	.string "zone.“$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“ MODÈLE DE LA RÉGION DE HOENN ”\n"
	.string "C'est un diorama miniature de la\p"
	.string "région de HOENN. Où en est\n"
	.string "BOURG-EN-VOL à ce sujet ?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "C'est un affichage sur le flux de\n"
	.string "l'eau de mer. “ Près du fond de la\p"
	.string "mer, l'eau s'écoule en raison de\n"
	.string "différences dans des facteurs tels\p"
	.string "que la température et la salinité.\n"
	.string "”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "C'est un affichage sur le flux de\n"
	.string "l'eau de mer. “ Vers la surface,\p"
	.string "l’eau de mer s’écoule sous la forme\n"
	.string "de courants poussés par les vents.\p"
	.string "”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“THE FERRY S.S. TIDAL “Une réplique\n"
	.string "à l'échelle du navire en\p"
	.string "construction au POUPE'S SHIPYARD.“$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“ SUBMARINE EXPLORER 1 “ Une\n"
	.string "réplique du sous-marin\p"
	.string "d'exploration des fonds marins\n"
	.string "haute performance. ”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“ POD SUBMERSIBLE “ Une réplique\n"
	.string "d'un pod compact et sans pilote\p"
	.string "pour l'exploration des fonds\n"
	.string "marins. ” $"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“ S.S. ANNE “ Une réplique du\n"
	.string "paquebot de luxe qui fait le tour\p"
	.string "du globe. ”$"
