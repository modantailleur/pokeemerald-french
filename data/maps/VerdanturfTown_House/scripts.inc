VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_Woman1::
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2::
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague:
	.string "Au loin, au cœur d'ETERNARA, se\n"
	.string "trouve la LIGUE POKéMON. Les\p"
	.string "DRESSEURS qui s'y rassemblent\n"
	.string "sont tous terriblement compétents.$"

VerdanturfTown_House_Text_DefeatEliteFourInARow:
	.string "Dans la POKéMON LEAGUE, je pense\n"
	.string "que les règles disent que vous\p"
	.string "devez affronter les ELITE QUATRE\n"
	.string "tous à la suite. Si vous perdez\p"
	.string "contre l'un d'entre eux, vous\n"
	.string "devrez recommencer votre défi\p"
	.string "depuis le premier.$"
