MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hmm! Votre {STR_VAR_1}… $"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Il aime {STR_VAR_1}S, n'est-ce pas ?\n"
	.string "Non, j'en suis sûr ! Il aime\p"
	.string "vraiment {STR_VAR_1}S !$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Il ne semble pas aimer ou détester\n"
	.string "les {POKEBLOCK}S.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Mon mari peut dire d'un seul coup\n"
	.string "d'œil quel type de {POKEBLOCK}S un\p"
	.string "POKéMON aime.$"
