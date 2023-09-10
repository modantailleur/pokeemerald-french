AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "GUIDO : En cherchant des trésors,\n"
	.string "nous avons découvert un DRESSEUR !$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "GUIDO : Nous ne pouvions pas gagner\n"
	.string "même si nous travaillions\p"
	.string "ensemble…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "GUIDO : Nous ne trouvons aucun\n"
	.string "trésor… Je me demande si quelqu'un\p"
	.string "les a déjà eu ?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "GUIDO : Tu n'as même pas deux\n"
	.string "POKéMON. Vous ne pouvez pas espérer\p"
	.string "nous battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA : Ah ? Nous cherchions des\n"
	.string "trésors. Mais nous avons découvert\p"
	.string "un DRESSEUR à la place !$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA : Ooh, c'est si fort !$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA : Où pourraient être les\n"
	.string "trésors ? J'ai déjà décidé ce que\p"
	.string "j'achèterai lorsque nous trouverons\n"
	.string "les trésors !$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA : Oh, tu n'as pas deux POKéMON\n"
	.string "? Nous devrons nous battre une\p"
	.string "autre fois !$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA : Oh, tu me mets tellement en\n"
	.string "colère ! Je vais vous inscrire pour\p"
	.string "ça !$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "GUIDO : Nous avons cherché des\n"
	.string "trésors tout ce temps. Nos POKéMON\p"
	.string "sont également devenus plus forts.\n"
	.string "Laissez-nous vous montrer, d'accord\p"
	.string "?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "GUIDO : Tu es fort, comme\n"
	.string "d'habitude !$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "GUIDO : On ne trouve pas de\n"
	.string "trésors, on perd à POKéMON… Je veux\p"
	.string "rentrer à la maison… Mais si je dis\n"
	.string "ça, elle se met toute en colère\p"
	.string "contre moi…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "GUIDO : Tu n'as même pas deux\n"
	.string "POKéMON. Vous ne pouvez pas espérer\p"
	.string "nous battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA : Ah ? On se revoit! Tout\n"
	.string "comme nous, vous n’avez toujours\p"
	.string "pas renoncé à la recherche de\n"
	.string "trésors, n’est-ce pas ? Voulez-vous\p"
	.string "faire en sorte que le perdant doive\n"
	.string "abandonner ses recherches ?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA : Oh, nous avons encore\n"
	.string "perdu…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA : Nous ne partirons pas tant\n"
	.string "que nous n'aurons pas augmenté\p"
	.string "notre POKéMON et trouvé les trésors\n"
	.string "ici !$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA : Oh, tu n'as pas deux POKéMON\n"
	.string "? Nous devrons nous battre une\p"
	.string "autre fois !$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Je ne suis pas bon en natation,\n"
	.string "mais je suis bon en combat !$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Oops. Cela ne s'est pas très bien\n"
	.string "passé.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Se promener pieds nus dans ce\n"
	.string "navire est plutôt dégoûtant.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Force et compassion… Ce sont les\n"
	.string "trésors d'un FORMATTHIEUEUR !$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, il y a quelque chose chez toi\n"
	.string "qui scintille.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Dans une cabine quelque part à\n"
	.string "bord, j'ai vu quelque chose\p"
	.string "briller.$"
