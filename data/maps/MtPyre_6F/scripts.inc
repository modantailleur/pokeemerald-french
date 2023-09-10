MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Quand je suis là… Un curieux\n"
	.string "pouvoir afflue en moi…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Le pouvoir diminue…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Peut-être que le pouvoir vient des\n"
	.string "esprits de POKéMON dans un sommeil\p"
	.string "agité ici…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… J'ai perdu le match, mais…\n"
	.string "J'ai cette petite capacité… Sans\p"
	.string "jamais mettre la main sur ton\n"
	.string "POKéNAV… Salut !$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Derrière toi… Qu'est-ce qu'il y a…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Quelque chose s'est évanoui…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Les POKéMON au repos ici… Parfois,\n"
	.string "ils jouent…$"

MtPyre_6F_Text_CedricIntro:
	.string "Vous avez perdu vos repères ?\n"
	.string "N'ayez crainte car je suis là !$"

MtPyre_6F_Text_CedricDefeat:
	.string "N'étais-tu pas perdu ?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "J'avais le sentiment qu'un DRESSEUR\n"
	.string "perdu serait paniqué et facile à\p"
	.string "battre. C'est sale et je ne\n"
	.string "réessayerai pas…$"
