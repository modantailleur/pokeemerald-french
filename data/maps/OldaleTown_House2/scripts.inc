OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Lorsque les POKéMON combattent, ils\n"
	.string "finissent par monter de niveau et\p"
	.string "devenir plus forts.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Si le POKéMON qui vous accompagne\n"
	.string "devient plus fort, vous pourrez\p"
	.string "vous éloigner d'ici.$"
