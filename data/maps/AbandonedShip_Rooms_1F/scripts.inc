AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Les navires de ce type sont rares,\n"
	.string "alors je jette un œil autour de\p"
	.string "moi. Hmhm… Il semble y avoir\n"
	.string "d'autres cabines…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Qu'est-ce qui pourrait vous pousser\n"
	.string "à venir ici ? Vous devez être\p"
	.string "curieux !$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Pas seulement curieux, mais aussi\n"
	.string "fort…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "L'homme d'à côté… Il dit qu'il fait\n"
	.string "juste du tourisme, mais je n'en\p"
	.string "sais rien.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Vous êtes un DRESSEUR tellement\n"
	.string "coriace ! Laissez-moi vous\p"
	.string "enregistrer comme souvenir !$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Qu’est-ce qui pourrait vous pousser\n"
	.string "à revenir ? Tu dois vraiment être\p"
	.string "curieux!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "N'es-tu pas trop fort ?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Je suis sûr que cet homme prépare\n"
	.string "quelque chose ! Il agit de manière\p"
	.string "tellement suspecte !$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah ! J'ai été trouvé ! …Hein ?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, tu n'es pas ma mère.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "J'ai des ennuis avec ma mère, alors\n"
	.string "j'ai couru. Gardez le secret là où\p"
	.string "je suis !$"
