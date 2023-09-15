MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Souvenirs de mon SKITTY chéri… Mes\n"
	.string "yeux débordent en y pensant.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ooch, aïe… Il y a des trous dans le\n"
	.string "sol ici et là. Je ne l'ai pas\p"
	.string "remarqué et j'ai chuté de l'étage\n"
	.string "supérieur.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hé! Vous recherchez POKéMON ? Tu es\n"
	.string "venu après moi ! Tu es impoli !$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ayieeeeh ! Je suis désolé,\n"
	.string "pardonne-moi, s'il te plaît !$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Les gens ne viennent pas souvent\n"
	.string "ici, alors j'ai pensé qu'il y\p"
	.string "aurait des POKéMON rares.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE : Nous sommes ici pour un\n"
	.string "défi. Heheh, si je lui montre à\p"
	.string "quel point je suis cool, elle\n"
	.string "tombera amoureuse de moi. Je sais\p"
	.string "cela! Je sais! Je vais te crémer et\n"
	.string "lui montrer à quel point je suis\p"
	.string "cool !$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE : Oups ! $"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE : Eh bien, nous avons perdu\n"
	.string "mais ce n'est pas grave ! Je suis\p"
	.string "là, à tes côtés. Nous réussirons ce\n"
	.string "défi !$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE : Si tu veux m'affronter,\n"
	.string "apporte-moi encore quelques\p"
	.string "POKéMON. Si tu ne le fais pas, je\n"
	.string "ne pourrai pas montrer à ma copine\p"
	.string "à quel point je suis cool !$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ : Je suis venu ici pour un défi\n"
	.string "avec mon petit ami. C'est vraiment\p"
	.string "effrayant, mais je suis avec mon\n"
	.string "copain. C'est bon. Je sais! Je vais\p"
	.string "rendre mon petit-ami cool en te\n"
	.string "battant !$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ : Waaaah ! J'ai peur !$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ : Nous sommes amoureux, donc\n"
	.string "nous nous en foutons si nous\p"
	.string "perdons !$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ : Si vous voulez nous défier,\n"
	.string "vous devez apporter au moins deux\p"
	.string "POKéMON. Mon copain est fort. Un\n"
	.string "seul POKéMON ne suffira pas du\p"
	.string "tout.$"

MtPyre_2F_Text_LeahIntro:
	.string "Vous êtes un spectacle inconnu…\n"
	.string "Partez avant que quoi que ce soit\p"
	.string "ne vous arrive !$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm… Tu es durable.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Notre famille est DRESSEUR\n"
	.string "ici depuis l'époque de mon\p"
	.string "arrière-grand-mère… C'est mon\n"
	.string "devoir de protéger cette montagne…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyah ! Je suis terrifié !$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Noooooon ! J'ai perdu la tête !$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Je panique à chaque fois que je\n"
	.string "vois quelque chose bouger… Je\p"
	.string "n'aurais pas dû venir ici pour\n"
	.string "m'entraîner…$"
