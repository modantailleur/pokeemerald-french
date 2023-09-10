MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "C'est ici que nous, utilisateurs de\n"
	.string "DRAGON, effectuons notre formation.\p"
	.string "Le CHAMPION visite même.\n"
	.string "Maintenant, voyez-vous à quel point\p"
	.string "c'est spécial ici ?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh! Je ne m'attendais pas à ce\n"
	.string "que tu sois si fort !$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "Le chemin à parcourir reste long et\n"
	.string "difficile. Quand mon POKéMON et moi\p"
	.string "deviendrons-nous les meilleurs ?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Je veux en savoir plus sur ton\n"
	.string "pouvoir. Laissez-moi vous inscrire\p"
	.string "dans mon POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Depuis notre rencontre, nous nous\n"
	.string "sommes entraînés dur pour viser le\p"
	.string "numéro un. Aide-nous à voir à quel\n"
	.string "point nous sommes devenus plus\p"
	.string "forts !$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh! Je ne m'attendais pas à ce\n"
	.string "que tu sois si fort !$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Vous avez visiblement continué\n"
	.string "votre entraînement POKéMON. Tant\p"
	.string "que tu restes fort, moi aussi, je\n"
	.string "peux devenir plus fort !$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN : Nous avons toujours combattu\n"
	.string "POKéMON ensemble, en duo. Nous\p"
	.string "avons confiance en nous.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN : Oh, mon Dieu. Nous avons\n"
	.string "perdu, chère épouse.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN : Nous sommes mariés depuis\n"
	.string "cinquante ans. À bien y penser, je\p"
	.string "n'ai pas encore battu ma chère\n"
	.string "épouse au combat.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN : Eh bien, quel jeune DRESSEUR\n"
	.string "! Allez-vous vous battre avec nous\p"
	.string "? Si tel est le cas, vous devrez\n"
	.string "revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN : Jeune DRESSEUR, si\n"
	.string "l'occasion se présente,\p"
	.string "combattrez-vous à nouveau avec nous\n"
	.string "?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY : Nous sommes mariés depuis\n"
	.string "cinquante ans. Le lien que nous\p"
	.string "partageons en tant que couple ne\n"
	.string "pourra jamais être rompu.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY : Oh, chérie. Nous avons perdu,\n"
	.string "mon cher mari.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY : Cinquante ans de mariage… Si\n"
	.string "jamais on se disputait, on réglait\p"
	.string "toujours ça avec une bataille\n"
	.string "POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY : Eh bien, n'êtes-vous pas un\n"
	.string "jeune DRESSEUR ? Si vous souhaitez\p"
	.string "combattre avec nous, vous devrez\n"
	.string "revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN : Nous avons toujours combattu\n"
	.string "POKéMON ensemble, en duo. Nous\p"
	.string "avons confiance en nous.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN : Oh, mon Dieu. Nous avons\n"
	.string "perdu, chère épouse.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN : Marié depuis cinquante ans…\n"
	.string "A la réflexion, la chère épouse et\p"
	.string "moi, nous nous sommes battus jour\n"
	.string "après jour…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN : Eh bien, quel jeune DRESSEUR\n"
	.string "! Allez-vous vous battre avec nous\p"
	.string "? Si tel est le cas, vous devrez\n"
	.string "revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY : Nous sommes mariés depuis\n"
	.string "cinquante ans. Nous nous sommes\p"
	.string "soutenus tout ce temps. Nous nous\n"
	.string "sommes rendus forts.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY : Oh, chérie. Nous avons perdu,\n"
	.string "mon cher mari.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY : Cinquante ans de mariage…\n"
	.string "Beaucoup de choses se sont passées.\p"
	.string "J'espère que nous continuerons à\n"
	.string "créer de bons souvenirs ensemble.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY : Eh bien, n'êtes-vous pas un\n"
	.string "jeune DRESSEUR ? Si vous souhaitez\p"
	.string "combattre avec nous, vous devrez\n"
	.string "revenir avec plus de POKéMON.$"
