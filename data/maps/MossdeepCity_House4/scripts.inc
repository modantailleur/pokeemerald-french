MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "Mon petit frère dit qu'il aime\n"
	.string "aller à la recherche des BASES\p"
	.string "SECRGUIDOES des gens.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "Mon petit frère dit qu'il aime\n"
	.string "visiter les BASES SECRGUIDOES des\p"
	.string "gens et participer à des combats\n"
	.string "POKéMON.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "Est-ce vous qui avez créé une BASE\n"
	.string "SECRGUIDO près de {STR_VAR_1} ?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "Vous devriez créer une BASE SECRETE\n"
	.string "quelque part. Je vais le trouver !$"

MossdeepCity_House4_Text_Skitty:
	.string "SKITTY : Vraiment ?$"
