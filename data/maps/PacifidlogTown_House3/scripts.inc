PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Découvrez ce {STR_VAR_2} ! C'est le\n"
	.string "{STR_VAR_2} que j'ai attrapé hier pour\p"
	.string "fêter mon anniversaire ! Oh, je\n"
	.string "vois que tu le veux ! Après tout,\p"
	.string "ça n'a pas de prix ! Je vais vous\n"
	.string "dire ce que. Je serais peut-être\p"
	.string "prêt à l'échanger contre un\n"
	.string "{STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, donc c'est un {STR_VAR_1} ? C'est un\n"
	.string "peu comme un {STR_VAR_2}, et pourtant\p"
	.string "c'est subtilement différent.\n"
	.string "Merci!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Non non Non! Je n'accepterai rien\n"
	.string "de moins qu'un vrai {STR_VAR_1} !$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, donc tu ne vas pas jusqu'au\n"
	.string "bout ? C'est super. Je ne suis pas\p"
	.string "désespéré de faire un échange ou\n"
	.string "quoi que ce soit.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Je sais que je pourrais en chercher\n"
	.string "un par moi-même, mais… Mais je\p"
	.string "voulais vraiment me procurer un\n"
	.string "BAGON qu'un autre DRESSEUR a\p"
	.string "attrapé…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "C'est un POKéDEX ? Avez-vous\n"
	.string "rencontré beaucoup de POKéMON\p"
	.string "différents ? J'aurais aimé être\n"
	.string "comme toi.$"
