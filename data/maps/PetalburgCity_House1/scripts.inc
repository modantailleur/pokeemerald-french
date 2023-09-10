PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_TravelingIsWonderful:
	.string "Voyager, c'est merveilleux ! Quand\n"
	.string "j'étais jeune, je parcourais les\p"
	.string "mers et les montagnes !$"

PetalburgCity_House1_Text_GoOnAdventure:
	.string "Soupir… J'aimerais pouvoir partir à\n"
	.string "l'aventure avec des POKéMON… Ramper\p"
	.string "dans l'herbe humide… Escalader des\n"
	.string "montagnes rocheuses et escarpées…\p"
	.string "Traverser les mers déchaînées… Se\n"
	.string "promener dans des grottes sombres…\p"
	.string "Et, parfois, avoir même un peu le\n"
	.string "mal du pays… Ça doit être fabuleux\p"
	.string "de voyager!$"
