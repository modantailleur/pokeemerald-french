SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Il y a un lit… Reposons-nous.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Je navigue souvent vers NENUCRIQUE.\n"
	.string "J'aime assister aux CONCOURS,\p"
	.string "voyez-vous.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "C'était un match agréable !$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Je suis tellement excité d'imaginer\n"
	.string "quels types de POKéMON je pourrai\p"
	.string "voir lors du prochain CONCOURS.\n"
	.string "L’attente est passionnante !$"

SSTidalRooms_Text_MicahIntro:
	.string "Vos amis sont-ils forts ?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Vos amis sont effectivement forts.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Les amis ne doivent pas\n"
	.string "nécessairement être humains. Pour\p"
	.string "moi, les POKéMON sont des amis\n"
	.string "précieux !$"

SSTidalRooms_Text_ThomasIntro:
	.string "Enfant… As-tu frappé à la porte ?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Une perte doit être acceptée sans\n"
	.string "hâte ni panique.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Ne jamais être gêné dans aucune\n"
	.string "situation est le code de conduite\p"
	.string "du GENTLEMAN.$"

SSTidalRooms_Text_JedIntro:
	.string "JED : Je me sens un peu timide à ce\n"
	.string "sujet, mais… Nous allons vous\p"
	.string "montrer notre pouvoir d'amoureux !$"

SSTidalRooms_Text_JedDefeat:
	.string "JED : Soupir…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED : C'est la première fois que\n"
	.string "notre pouvoir amoureux ne peut pas\p"
	.string "prévaloir ! Vous devez être un\n"
	.string "formidable DRESSEUR !$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED : Tu n'as qu'un seul POKéMON ?\n"
	.string "N'est-ce pas trop solitaire ?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA : Je me sens un peu bête, mais…\n"
	.string "On va te montrer notre pouvoir\p"
	.string "d'amoureux !$"

SSTidalRooms_Text_LeaDefeat:
	.string "LÉA : Oh, bouh !$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA : Je n'arrive pas à y croire !\n"
	.string "Notre pouvoir amoureux a échoué…\p"
	.string "Vous devez être un formidable\n"
	.string "DRESSEUR !$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA : Je voulais me battre… Mais tu\n"
	.string "n'as même pas deux POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, tu es arrivé juste à temps. Je\n"
	.string "m'ennuie, tu vois. Vous pouvez me\p"
	.string "divertir.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Ça fera l'affaire.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Peut-être que je demanderai à mon\n"
	.string "père de m'acquérir un yacht. Un\p"
	.string "yacht pour moi et POKéMON !$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, tu es un DRESSEUR tellement\n"
	.string "adorable. Voudrais-tu prendre le\p"
	.string "thé ? Ou préférez-vous vous battre\n"
	.string "?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Je vois. Vous êtes du genre actif.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Une croisière autour du monde sur\n"
	.string "un paquebot de luxe a ses charmes,\p"
	.string "je dois l'admettre… Mais j'avoue\n"
	.string "qu'il y a un côté attrayant à\p"
	.string "visiter HOENN en ferry.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Euh… Salut ! Je… je n'agis pas de\n"
	.string "manière suspecte ! Euh… Tu peux\p"
	.string "avoir ça ! Gratuitement! C'est…\n"
	.string "Honnêtement, je ne l'ai pas arraché\p"
	.string "à quelqu'un ! Je ne ferais jamais\n"
	.string "une chose pareille ! C'est propre!\p"
	.string "Vous pouvez l'utiliser !$"

SSTidalRooms_Text_ExplainSnatch:
	.string "SNATCH vole les effets bénéfiques\n"
	.string "de certains mouvements avant qu'ils\p"
	.string "ne puissent être utilisés par un\n"
	.string "ennemi ou un allié.$"
