.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hé, comment ça va, {PLAYER} CHAMPION\n"
	.string "? Le GYM LEADER ADRIANE de\p"
	.string "LAVARIDGE utilise des POKéMON de\n"
	.string "type FEU. Sa passion pour POKéMON\p"
	.string "brûle plus fort et plus chaud qu'un\n"
	.string "volcan. Ne vous approchez pas trop\p"
	.string "d'elle, vous allez brûler !\n"
	.string "Arrosez-la avec de l'eau et foncez\p"
	.string "!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Ouais ! Ce fut une bataille torride\n"
	.string "!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Owowowowow ! Ouais, c'est chaud !$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Je suis aveuglé par la sueur dans\n"
	.string "mes yeux…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Être enterré dans du sable chaud\n"
	.string "favorise la circulation. C'est\p"
	.string "efficace pour guérir les douleurs\n"
	.string "dans vos articulations.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "J'essaie de soulager mon stress. Ne\n"
	.string "viens pas me stresser !$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "J'espère que ADRIANE vous fera du\n"
	.string "bien !$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Ouf… Si tu passes trop de\n"
	.string "temps enfoui dans le sable chaud,\p"
	.string "ça t'énerve…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Tu dois être fatigué maintenant.\n"
	.string "Vous aimeriez vous reposer dans le\p"
	.string "sable chaud, n'est-ce pas ? Mais\n"
	.string "sachez que maintenir votre volonté\p"
	.string "est une capacité importante pour\n"
	.string "tous les FORMATTHIEUEURS.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Jouez avec le feu et soyez brûlé…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Votre compétence est réelle… Mais\n"
	.string "notre LEADER ADRIANE est solide. Si\p"
	.string "vous ne faites pas attention, vous\n"
	.string "serez gravement brûlé.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Votre POKéMON peut-il résister à\n"
	.string "une chaleur de 392 degrés ?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Il n'a pas brûlé assez fort…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "La température du magma est de 392\n"
	.string "degrés. Votre POKéMON m'a battu,\p"
	.string "donc ils devraient facilement\n"
	.string "survivre dans le magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Euh… D'accord, je vais me battre\n"
	.string "avec toi.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, mais tu es trop fort.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Je vais être une jolie et forte\n"
	.string "FORMATTHIEUEUR tout comme ADRIANE.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Allez, vas-y ! Allons-y avant que\n"
	.string "mes sentiments ne se refroidissent\p"
	.string "!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Il fait si chaud, et pourtant mon\n"
	.string "cœur est serré par la glace…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "La façon dont l'esprit de combat\n"
	.string "brûle en vous, vous pouvez avoir\p"
	.string "une chance contre notre LEADER.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Vous voyez comment les flammes\n"
	.string "flambent sauvagement ? Ils\p"
	.string "s'enflamment en prévision de ma\n"
	.string "victoire !$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Quelque chose ne s'est pas bien\n"
	.string "passé.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Eh bien, et alors ? Je dis et alors\n"
	.string "? Je peux marcher pieds nus sur des\p"
	.string "charbons ardents ! …Ne pensez même\n"
	.string "pas à l'essayer !$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Autant j'aime les montagnes, autant\n"
	.string "j'aime particulièrement les\p"
	.string "volcans.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Eh bien, il me semble que j'ai\n"
	.string "perdu sans jamais avoir le\p"
	.string "contrôle.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Je reste ici parce que je suis\n"
	.string "devenu fan du pouvoir de ADRIANE.\p"
	.string "Héhéhé.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Bienvenue… Non, attendez. Puny\n"
	.string "DRESSEUR, comme c'est bon de voir\p"
	.string "que vous êtes arrivé ici ! On m'a\n"
	.string "confié le… Non, attends. Je\p"
	.string "m'appelle ADRIANE et je suis le GYM\n"
	.string "LEADER ici ! Euh… N'osez pas me\p"
	.string "sous-estimer, même si je ne suis\n"
	.string "LEADER que depuis peu de temps !\p"
	.string "Avec les compétences héritées de\n"
	.string "mon grand-père, je vais, euh…\p"
	.string "démontrer les mouvements chauds que\n"
	.string "nous avons perfectionnés sur cette\p"
	.string "terre !$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh… je suppose que j'essayais trop\n"
	.string "fort… Je… je ne suis devenu que\p"
	.string "récemment un GYM LEADER. J'ai trop\n"
	.string "essayé d'être quelqu'un que je ne\p"
	.string "suis pas. Je dois faire les choses\n"
	.string "à ma manière naturelle. Si je ne le\p"
	.string "fais pas, mon POKéMON sera confus.\n"
	.string "Merci de m'avoir appris ça. Pour\p"
	.string "cela, vous méritez ça.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} a reçu le HEAT BADGE de\n"
	.string "ADRIANE.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Si vous possédez un HEAT BADGE,\n"
	.string "tous les POKéMON jusqu'au niveau\p"
	.string "50, même ceux que vous obtenez lors\n"
	.string "d'échanges avec d'autres personnes,\p"
	.string "vous obéiront complètement. Et cela\n"
	.string "permet à POKéMON d'utiliser la\p"
	.string "FORCE du mouvement HM en dehors du\n"
	.string "combat. Ceci est un gage de ma\p"
	.string "reconnaissance. N'hésitez pas à le\n"
	.string "prendre !$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "Ce TM50 contient une SURCHAUFFE. Ce\n"
	.string "mouvement inflige de sérieux dégâts\p"
	.string "à l'adversaire. Mais cela réduit\n"
	.string "aussi fortement le SP. ATK du\p"
	.string "POKéMON l'utilisant. Cela pourrait\n"
	.string "ne pas convenir aux batailles plus\p"
	.string "longues.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Inscrit GYM LEADER ADRIANE au\n"
	.string "POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Ton pouvoir me rappelle quelqu'un…\n"
	.string "Oh ! Je sais! Vous vous battez\p"
	.string "comme NORMAN, le GYM LEADER de\n"
	.string "PGUIDOALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "GYM$ POKéMON DE LAVARIDGE VILLE"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "DRESSEURS CERTIFIÉS DE VERMILAVA\n"
	.string "POKéMON GYM ADRIANE : {PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "ADRIANE : Perdre une bataille ne va\n"
	.string "pas me dégonfler. J'adore POKéMON.\p"
	.string "J'adore me battre. Et… j'adore ce\n"
	.string "GYM ! Échangeons des mouvements\p"
	.string "super chauds dans une autre\n"
	.string "bataille !$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Ouf! Au bord de l'éruption !$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "ADRIANE : J'ai perdu le match, mais\n"
	.string "je suis complètement satisfait. Ce\p"
	.string "n’est pas souvent que je profite\n"
	.string "d’une bataille aussi passionnée.\p"
	.string "Reprenons-en un autre comme\n"
	.string "celui-ci un jour !$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "ADRIANE : Perdre une bataille ne va\n"
	.string "pas me dégonfler. J'adore POKéMON.\p"
	.string "J'adore me battre. Et… j'adore ce\n"
	.string "GYM ! Échangeons des mouvements\p"
	.string "super chauds dans une autre\n"
	.string "bataille ! Oh, attendez. Avez-vous\p"
	.string "un seul POKéMON capable de\n"
	.string "combattre ? Je déteste dire ça,\p"
	.string "mais quand vous viendrez me voir,\n"
	.string "apportez au moins deux POKéMON.$"
