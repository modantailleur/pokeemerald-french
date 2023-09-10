MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "La riche atmosphère de la montagne\n"
	.string "a élevé mon pouvoir psychique ! Un\p"
	.string "simple enfant comme toi… Vous rêvez\n"
	.string "de gagner ?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Je me noie dans l'apitoiement sur\n"
	.string "moi-même…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Mes pouvoirs psychiques ont\n"
	.string "sûrement augmenté plusieurs fois,\p"
	.string "mais…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha ! Ce n'est pas un endroit\n"
	.string "pour les enfants, encore moins pour\p"
	.string "vous !$"

MtPyre_3F_Text_KaylaDefeat:
	.string "J'ai perdu ça proprement…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Cela veut dire que mon entraînement\n"
	.string "n'est toujours pas suffisant… Je\p"
	.string "dois continuer à travailler pour\n"
	.string "atteindre le sommet… Vas-y, moi !$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Pourquoi es-tu venu ici ?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "C'était incroyable ! Vous êtes un\n"
	.string "DRESSEUR très spécial.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON n'est plus de ce monde.\n"
	.string "POKéMON qui sont avec vous\p"
	.string "maintenant. Et les POKéMON que vous\n"
	.string "rencontrerez dans le futur… Ils\p"
	.string "doivent tous être également chéris.\n"
	.string "N'oubliez pas cela.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "J'aimerais voir vos POKéMON quand\n"
	.string "ils seront plus grands… S'il vous\p"
	.string "plaît, j'ai besoin de voir votre\n"
	.string "POKéNAV.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, c'est toi… Tu es venu me\n"
	.string "montrer ton POKéMON adulte ?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Comme c’est incroyable ! Vous êtes\n"
	.string "une personne spéciale.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON n'est plus de ce monde.\n"
	.string "POKéMON qui sont avec vous\p"
	.string "maintenant. Et les POKéMON que vous\n"
	.string "rencontrerez dans le futur… Ils\p"
	.string "doivent tous être également chéris.\n"
	.string "Je vois que tu t'en souviens.$"
