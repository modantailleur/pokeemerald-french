.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe… Vous êtes déjà là, n'est-ce\n"
	.string "pas ? Nous vous avons sous-estimé !\p"
	.string "Mais c'est ça ! Je suis un cran\n"
	.string "au-dessus des GRUNTS que vous avez\p"
	.string "vus jusqu'à présent. Je ne gagne\n"
	.string "pas de temps. Je vais te pulvériser\p"
	.string "!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe… Alors, j'ai perdu aussi…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Héhéhé ! Pendant que je jouais avec\n"
	.string "toi, notre BOSS a terminé ses\p"
	.string "préparatifs !$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Héhéhé ! Notre BOSS est déjà parti\n"
	.string "vers une grotte sous la mer ! Si\p"
	.string "vous voulez vous lancer à sa\n"
	.string "poursuite, vous feriez mieux de\p"
	.string "fouiller la grande et vaste mer\n"
	.string "au-delà de LILYCOVE. Mais le\p"
	.string "trouverez-vous alors ? Héhéhé !$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, j'en avais marre\n"
	.string "d'attendre ! Tu me dois une\p"
	.string "bataille aussi !$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Fatigué d'attendre… Perdu et\n"
	.string "étourdi…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BOSS… Est-ce suffisant ?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Les panneaux Warp, la fierté et la\n"
	.string "joie de HIDEOUT ! Vous ne savez pas\p"
	.string "où vous êtes, n'est-ce pas ? Agite\n"
	.string "et fatigue l'ennemi, puis abaisse\p"
	.string "le boom ! C'est notre plan !$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Qu'est-ce qui ne va pas? Vous\n"
	.string "n'êtes pas fatigué du tout !$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Cela me rappelle… Je ne me souviens\n"
	.string "plus où j'ai mis le MASTER BALL. Si\p"
	.string "je ne parviens pas à le garder,\n"
	.string "notre BOSS me mâchera…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Lorsque j'ai rejoint TEAM AQUA, la\n"
	.string "première chose que j'ai dû\p"
	.string "apprendre était comment ces\n"
	.string "panneaux de chaîne se\p"
	.string "connectaient.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "J'étais trop occupé à penser aux\n"
	.string "panneaux de déformation…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Je vais devoir apprendre comment je\n"
	.string "peux me battre plus efficacement…$"
