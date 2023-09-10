SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh! J'en ai marre et j'en ai\n"
	.string "marre de nettoyer cet immense\p"
	.string "endroit ! Menons une bataille\n"
	.string "rapide !$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Petit frère, j'ai perdu !$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Nous sommes les FRÈRES DU\n"
	.string "NGUIDOTOYAGE ! Le vieux jette le\p"
	.string "détergent et le jeune nettoie !$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "C'est le fond de la coque du\n"
	.string "navire. Il y a beaucoup de place.\p"
	.string "Tout ira bien pour une bataille\n"
	.string "POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Grand frère, j'ai perdu !$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Nous sommes les FRÈRES DU\n"
	.string "NGUIDOTOYAGE ! Le vieux jette le\p"
	.string "détergent et le jeune nettoie !$"
